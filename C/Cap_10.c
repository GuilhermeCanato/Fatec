#define ex4
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

#ifdef ex1
int main()
{
    FILE *p;
    char c;
    int count = 0;

    if((p = fopen("arq.txt", "w")) == NULL){
            printf("erro na abertura do arquivo \n");
            exit(0);
        }

    while(1){

        printf("Digite um caractere: ");
        scanf("%c", &c);

        if(c == '0'){
            fclose(p);
            break;
        }

        putc(c, p);
        count++;

        getchar();
    }

    if((p = fopen("arq.txt","r"))==NULL)
	{
        printf("erro na abertura do arquivo \n");
        exit(0);
	}

    char resultado[count];
    fscanf(p,"%s ",resultado);
    printf("%s", resultado);
}
#endif

#ifdef ex2
struct contato{
    char nome[64];
    char cel[15];
    int dia;
    int mes;
};

FILE *arq;

int main()
{
    struct contato contato;
    int escolha = 1;
    while(escolha != 0){

        printf("1 - Inserir contato\n2 - Deletar contato\n3 - Procurar contato pelo nome\n4 - Listar todos os contatos\n5 - Listar contatos que comecam com a letra\n6 - Listar aniversariantes do mes\n0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                adicionar(&contato);
                break;
            case 2:
                deletar(&contato);
                break;
            case 3:
                getNome(&contato);
                break;
            case 4:
                getAll(&contato);
                break;
            case 5:
                getInicial(&contato);
                break;
            case 6:
                getMes(&contato);
                break;
        }

    }
}

void adicionar(struct contato *contato){

    if((arq = fopen("arq.txt", "a")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    getchar();

    printf("Digite o nome do contato: ");
    scanf("%s", &contato->nome);

    printf("Digite o telefone do contato: ");
    scanf("%s", &contato->cel);

    printf("Digite o mes do nascimento do contato: ");
    scanf("%d", &contato->mes);

    printf("Digite o dia do nascimento do contato: ");
    scanf("%d", &contato->dia);

    fwrite(contato, sizeof(struct contato), 1, arq);
    fclose(arq);
}

void deletar(struct contato *contato){

    if((arq = fopen("arq.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }

    char nome[64];
    int resultadoado = 0;
    int i = 0;

    printf("Digite o nome do contato: ");
    scanf("%s", &nome);

    while(fread(contato, sizeof(struct contato), 1, arq)){
        resultadoado = comparaString(&nome, contato->nome);

        if(resultadoado == 1){
            *contato->nome = '\0';
            fseek(arq, sizeof(struct contato) * i, 0);
            fwrite(contato, sizeof(struct contato), 1, arq);
            break;
        }
        i++;
    }
    if(resultadoado != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(arq);
}

void getAll(struct contato *contato){

    if((arq = fopen("arq.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }

    while(fread(contato, sizeof(struct contato), 1, arq)){

        if(*contato->nome != '\0'){
            printf("%s, %s, %d/%d \n", contato->nome, contato->cel, contato->dia, contato->mes);
        }
    }
    fclose(arq);
}

void getNome(struct contato *contato){

    if((arq = fopen("arq.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }

    char nome[64];
    int resultadoado = 0;

    printf("Digite o nome do contato: ");
    scanf("%s", &nome);

    while(fread(contato, sizeof(struct contato), 1, arq)){
        resultadoado = comparaString(&nome, contato->nome);

        if(resultadoado == 1){
            printf("%s, %s, %d/%d \n", contato->nome, contato->cel, contato->dia, contato->mes);
            break;
        }
    }

    if(resultadoado != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(arq);
}

void getInicial(struct contato *contato){

    if((arq = fopen("arq.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }

    char inicial;
    int resultadoado = 0;

    printf("Digite uma letra: ");
    scanf("%s", &inicial);

    while(fread(contato, sizeof(struct contato), 1, arq)){
        resultadoado = contato->nome[0] == inicial ? 1 : 0;

        if(resultadoado == 1){
            printf("%s, %s, %d/%d \n", contato->nome, contato->cel, contato->dia, contato->mes);
        }
    }
    if(resultadoado != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(arq);
}

void getMes(struct contato *contato){

    time_t s, val = 1;
    struct tm* current_time;
    s = time(NULL);
    current_time = localtime(&s);
    int resultadoado = 0;

    if((arq = fopen("arq.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }

    while(fread(contato, sizeof(struct contato), 1, arq)){
        resultadoado = contato->mes == current_time->tm_mon + 1 ? 1 : 0;

        if(resultadoado == 1){
            printf("%s, %s, %d/%d \n", contato->nome, contato->cel, contato->dia, contato->mes);
        }
    }

    if(resultadoado != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(arq);
}

int comparaString(char *string1, char *string2){
    int resultado = 0;
    for(int i = 0; string1[i] != '\0' || string2[i] != '\0'; i++){
        if(string1[i] != string2[i]){
            resultado = 4;
            if(string1[i] == '\0' && string2[i] != '\0'){
                resultado = 3;
                break;
            }
            else{
                if(string1[i] != '\0' && string2[i] == '\0'){
                    resultado = 2;
                    break;
                }
            }
        }
        else{
            resultado = 1;
        }
    }
    return resultado;
}
#endif

#ifdef ex3
struct produto{
    int id;
    char descricao[255];
    int qnt;
};

FILE *arq;
main(){
    struct produto produto;
    int escolha = 1;

    while(escolha != 0){

        printf("1 - Inserir produto\n2 - Retirar produto\n3 - Procurar produto pela descricao\n4 - Listar todos os produtos\n5 - Listar produtos nao disponiveis\n0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch(escolha){
            case 1:
                adicionar(&produto);
                break;
            case 2:
                deletar(&produto);
                break;
            case 3:
                getDescricao(&produto);
                break;
            case 4:
                getAll(&produto);
                break;
            case 5:
                getInd(&produto);
                break;
        }
    }
}
void adicionar(struct produto *produto){

    if((arq = fopen("arq.txt", "a")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }

    getchar();
    printf("Digite o codigo do produto: ");
    scanf("%d", &produto->id);
    getchar();
    printf("Digite a descricao do produto: ");
    gets(produto->descricao);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &produto->qnt);
    fwrite(produto, sizeof(struct produto), 1, arq);
    fclose(arq);
}

void deletar(struct produto *produto){
    if((arq = fopen("arq.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }

    int code = 0;
    int quantity = 0;
    int resultado, resultado2;
    int i = 0;

    printf("Digite o codigo do produto: ");
    scanf("%d", &code);
    printf("Digite quanto quer retirar: ");
    scanf("%d", &quantity);

    while(fread(produto, sizeof(struct produto), 1, arq)){
        resultado = code == produto->id ? 1 : 0;

        if(resultado == 1){
            resultado2 = produto->qnt >= quantity ? 1 : 0;
            if(resultado2)
            {
                produto->qnt -= quantity;
                fseek(arq, sizeof(struct produto) * i, 0);
                fwrite(produto, sizeof(struct produto), 1, arq);
                break;
            }
            else{
                printf("Você não tem essa quantidade desse produto\n");
            }
        }
        i++;
    }
    if(resultado != 1 && resultado2 != 0){
        printf("Produto nao encontrado\n");
    }
    fclose(arq);
}

void getDescricao(struct produto *produto){
    if((arq = fopen("arq.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char description[64];
    int resultado;

    printf("Digite a descrição do produto: ");
    scanf("%s", &description);

    while(fread(produto, sizeof(struct produto), 1, arq)){
        resultado = comparaString(&description, produto->descricao);

        if(resultado == 1){
            printf("%d, %s, %d \n", produto->id, produto->descricao, produto->qnt);
            break;
        }
    }
    if(resultado != 1){
        printf("Produto nao encontrado\n");
    }
    fclose(arq);
}
void getAll(struct produto *produto){

    if((arq = fopen("arq.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    while(fread(produto, sizeof(struct produto), 1, arq)){
        printf("%d, %s, %d \n", produto->id, produto->descricao, produto->qnt);
    }
    fclose(arq);
}

void getInd(struct produto *produto){

    if((arq = fopen("arq.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    while(fread(produto, sizeof(struct produto), 1, arq)){
        if(produto->qnt == 0){
            printf("%d, %s, %d \n", produto->id, produto->descricao, produto->qnt);
        }
    }
    fclose(arq);
}

int comparaString(char *string1, char *string2){
    int resultado = 0;
    for(int i = 0; string1[i] != '\0' || string2[i] != '\0'; i++){
        if(string1[i] != string2[i]){
            resultado = 4;
            if(string1[i] == '\0' && string2[i] != '\0'){
                resultado = 3;
                break;
            }
            else{
                if(string1[i] != '\0' && string2[i] == '\0'){
                    resultado = 2;
                    break;
                }
            }
        }
        else{
            resultado = 1;
        }
    }
    return resultado;
}

#endif

#ifdef ex4
struct User{
    char nome[64];
    char end[255];
    char cidade[64];
    char estado[64];
    char cep[64];
};

FILE *arq;
main(){
    struct User user;
    int escolha = 0;
    while(1){
        printf("1 - Inserir usuario\n2 - Listar usuarios\n3 - Procurar usuario\n4 - Alterar usuario\n5 - Deletar usuario\n0 - Sair\n");        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                adicionar(&user);
                break;
            case 2:
                getAll(&user);
                break;
            case 3:
                getNome(&user);
                break;
            case 4:
                atualizar(&user);
                break;
            case 5:
                deletar(&user);
                break;
        }
    }
}
void adicionar(struct User *user){
    if((arq = fopen("arq.txt", "a")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }

    getchar();
    printf("Digite o nome do usuario: ");
    gets(user->nome);
    printf("Digite o endereco do usuario: ");
    gets(user->end);
    printf("Digite a cidade do usuario: ");
    gets(user->cidade);
    printf("Digite o estado do usuario: ");
    gets(user->estado);
    printf("Digite o CEP do usuario: ");
    gets(user->cep);
    fwrite(user, sizeof(struct User), 1, arq);
    fclose(arq);
}

void deletar(struct User *user){
    if((arq = fopen("arq.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }

    char nome[64];
    int resultado;
    int i = 0;

    printf("Digite o nome do usuario: ");
    scanf("%s", &nome);

    while(fread(user, sizeof(struct User), 1, arq)){
        resultado = comparaString(&nome, user->nome);
        if(resultado == 1){
            *user->nome = '\0';
            fseek(arq, sizeof(struct User) * i, 0);
            fwrite(user, sizeof(struct User), 1, arq);
            break;
        }
        i++;
    }
    if(resultado != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(arq);
}


void atualizar(struct User *user){

    if((arq = fopen("arq.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }

    char nome[64];
    int resultado;
    int i = 0;
    printf("Digite o nome do usuario: ");
    scanf("%s", &nome);

    while(fread(user, sizeof(struct User), 1, arq)){
        resultado = comparaString(&nome, user->nome);
        if(resultado == 1){
            printf("Alterando usuario...\n");
            getchar();
            printf("Digite o nome do usuario: ");
            gets(user->nome);
            printf("Digite o endereco do usuario: ");
            gets(user->end);
            printf("Digite a cidade do usuario: ");
            gets(user->cidade);
            printf("Digite o estado do usuario: ");
            gets(user->estado);
            printf("Digite o CEP do usuario: ");
            gets(user->cep);
            fseek(arq, sizeof(struct User) * i, 0);
            fwrite(user, sizeof(struct User), 1, arq);
            break;
        }
        i++;
    }
    if(resultado != 1){
        printf("Usuario nao encontrado\n");
    }
    fclose(arq);
}

void getNome(struct User *user){
    if((arq = fopen("arq.txt", "r+")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    char nome[64];
    int resultado;
    printf("Digite a descrição do produto: ");
    scanf("%s", &nome);

    while(fread(user, sizeof(struct User), 1, arq)){
        resultado = comparaString(&nome, user->nome);
        if(resultado == 1){
            printf("%s, %s, %s, %s, %s \n", user->nome, user->end, user->cidade, user->estado, user->cep);
            break;
        }
    }
    if(resultado != 1){
        printf("Produto nao encontrado\n");
    }
    fclose(arq);
}
void getAll(struct User *user){
    if((arq = fopen("arq.txt", "r")) == NULL){
        printf("erro na abertura do arquivo \n");
        exit(0);
    }
    while(fread(user, sizeof(struct User), 1, arq)){
        if(user->nome[0] != '\0'){
            printf("%s, %s, %s, %s, %s \n", user->nome, user->end, user->cidade, user->estado, user->cep);
        }
    }
    fclose(arq);
}

int comparaString(char *string1, char *string2){
    int resultado = 0;
    for(int i = 0; string1[i] != '\0' || string2[i] != '\0'; i++){
        if(string1[i] != string2[i]){
            resultado = 4;
            if(string1[i] == '\0' && string2[i] != '\0'){
                resultado = 3;
                break;
            }
            else{
                if(string1[i] != '\0' && string2[i] == '\0'){
                    resultado = 2;
                    break;
                }
            }
        }
        else{
            resultado = 1;
        }
    }
    return resultado;
}
#endif

