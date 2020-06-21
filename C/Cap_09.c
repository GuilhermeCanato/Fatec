#define ex1
#include <stdio.h>
#include <stdlib.h>

#ifdef ex1
struct variaveis{
    char Char;
    int Int;
    long Long;
    float Float;
    double Double;
    unsigned char uChar;
    unsigned int uInt;
    unsigned long uLong;
};

int main()
{
    int Sair = 1;
    while(Sair == 1){

        struct variaveis var;

        getVariaveis(&var);
        printVariaveis (&var);

        printf("\n Digite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);
    }
}

void getVariaveis(struct variaveis *var){

    printf("Digite um char: ");
    scanf("%c", &var->Char);

    printf("Digite um int: ");
    scanf("%d", &var->Int);

    printf("Digite um long: ");
    scanf("%ld", &var->Long);

    printf("Digite um float: ");
    scanf("%f", &var->Float);

    printf("Digite um double: ");
    scanf("%lf", &var->Double);

    printf("Digite um unsigned char: ");
    scanf("%u", &var->uChar);

    printf("Digite um unsigned int: ");
    scanf("%u", &var->uInt);

    printf("Digite um unsigned long: ");
    scanf("%u", &var->uLong);
}

void printVariaveis(struct variaveis *var){
    printf("        10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("%5c %10d %10ld %20.2f %20.2lf\n", var->Char, var->Int, var->Long, var->Float, var->Double);
    printf("%10u %20u %20u\n", var->uChar, var->uInt, var->uLong);
}
#endif

#ifdef ex2
int getOperacao(int *valor, char *operation){

    printf("Escolha a operacao: +, -, /, * ou = : ");
    *operation = getchar();

    if(*operation == '='){
        return 0;
    }
    getchar();

    printf("Digite um valor: " );
    scanf("%d", valor);

    return 1;
}

int calcular(int *valor, char *operation, int *result){
    switch(*operation){
        case '+':
            *result += *valor;
            break;
        case '-':
            *result -= *valor;
            break;
        case '/':
            *result /= *valor;
            break;
        case '*':
            *result *= *valor;
            break;
    }
    getchar();
}

int main()
{
    int Sair = 1;
    while(Sair == 1){

        int valor = 0;
        char operation;
        int result = 0;

        while(1){
            if(getOperacao(&valor, &operation)){
                calcular(&valor, &operation, &result);
            }
            else{
                break;
            }
        }

        printf("O resultado das operacoes deu: %d \n", result);

        printf("\n Digite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);
    }
}
#endif

#ifdef ex3
int findLetra(char *letras, char *letra){

    for(int i = 0; letras[i] != '\0'; i++){
        if(letras[i] == *letra){
            return 1;
        }
    }
    return 0;
}

int main()
{
    char letras[] = "bdfhjkmoqsuwv";
    char letra;

    int Sair = 1;
    while(Sair == 1){

        printf("Digite uma letra: ");
        letra = getchar();

        if(findLetra(&letras, &letra)){
            printf("Letra encontrada\n");
        }

        else{
            printf("Letra nao encontrada\n");
        }

        printf("\nDigite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);
    }
}
#endif

#ifdef ex4
int verifica(char *string1, char *string2){
    int resultado = 0;

    for(int i = 0; string1[i] != '\0' || string2[i] != '\0'; i++){
        if(string1[i] != string2[i]){
            resultado = 4;

            if(string1[i] == '\0' && string2 != '\0'){
                resultado = 3;
                break;
            }

            else if(string1[i] != '\0' && string2 == '\0'){
                resultado = 2;
                break;
            }
        }

        else{
            resultado = 1;
        }
    }

    return resultado;
}

int main()
{
    int Sair = 1;
    while(Sair == 1){

        char string1[20];
        char string2[20];

        printf("Digite uma string: ");
        scanf("%s", &string1);

        printf("Digite outra string: ");
        scanf("%s", &string2);

        int resultado = verifica(&string1, &string2);

        switch(resultado){
            case 1:
                printf("As strings sao iguais\n");
            break;
            case 2:
                printf("A primeira string e maior que a segunda\n");
            break;
            case 3:
                printf("A segunda string e maior que a primeira\n");
            break;
            case 4:
                printf("As strings sao diferentes, porem tem o mesmo tamanho\n");
            break;
        }

        printf("\nDigite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);
    }
}
#endif

#ifdef ex5
struct user {
    char nome[50];
    char end[50];
    char cidade[50];
    char estado[50];
    char cep[50];
};

int main()
{
    struct user users[4];
    int qntUser = 0;
    int escolha = 1;
    while(escolha != 0){

        printf("\n1 - Listar usuarios\n2 - Adicionar usuario\n0 - Sair\n");
        scanf("%d", &escolha);

        switch(escolha){
        case 1:
            if(qntUser != 0){
                getUser(&users);
            }

            else{
                printf("Voce ainda nao inseriu nenhum usuario\n");
            }
            break;
        case 2:
            addUser(&users);
            qntUser++;
            break;
        }
    }
}

int getUser(struct user *users){

    for(int i = 0; i < 4; i++){
        printf("Usuario %d/4: %s %s %s %s %s \n", i + 1, users[i].nome, users[i].end, users[i].cidade, users[i].estado, users[i].cep);
    }
}

int addUser(struct user *users){
    for(int i = 0; i < 4; i++){
        printf("user %d/4 - Digite o nome: ", i + 1);
        scanf("%s", users[i].nome);

        printf("user %d/4 - Digite o endereco: ", i + 1);
        scanf("%s", users[i].end);

        printf("user %d/4 - Digite a cidade: ", i + 1);
        scanf("%s", users[i].cidade);

        printf("user %d/4 - Digite o estado: ", i + 1);
        scanf("%s", users[i].estado);

        printf("user %d/4 - Digite o CEP: ", i + 1);
        scanf("%s", users[i].cep);
    }
}
#endif

#ifdef ex6
struct user {
    char nome[50];
    char end[50];
    char cidade[50];
    char estado[50];
    char cep[50];
};

int main()
{
    struct user users[4];
    int qntUser = 0;
    int escolha = 1;
    while(escolha != 0){

        printf("\n1 - Listar usuarios\n2 - Adicionar usuario\n3 - Procurar usuario\n4 - Alterar usuario\n5 - Deletar usuario\n0 - Sair\n");
        scanf("%d", &escolha);

        switch(escolha){
        case 1:
            if(qntUser != 0){
                getUser(&users);
            }

            else{
                printf("Voce ainda nao inseriu nenhum usuario\n");
            }
            break;
        case 2:
            addUser(&users);
            qntUser++;
            break;
        case 3:
            procurar(&users);
            break;
        case 4:
            alterar(&users);
            break;
        case 5:
            deletar(&users);
            break;
        }
    }
}

int getUser(struct user *users){

    for(int i = 0; i < 4; i++){
        printf("Usuario %d/4: %s %s %s %s %s \n", i + 1, users[i].nome, users[i].end, users[i].cidade, users[i].estado, users[i].cep);
    }
}

int addUser(struct user *users){
    for(int i = 0; i < 4; i++){
        printf("user %d/4 - Digite o nome: ", i + 1);
        scanf("%s", users[i].nome);

        printf("user %d/4 - Digite o endereco: ", i + 1);
        scanf("%s", users[i].end);

        printf("user %d/4 - Digite a cidade: ", i + 1);
        scanf("%s", users[i].cidade);

        printf("user %d/4 - Digite o estado: ", i + 1);
        scanf("%s", users[i].estado);

        printf("user %d/4 - Digite o CEP: ", i + 1);
        scanf("%s", users[i].cep);
    }
}

void deletar(struct user *users){
    char nome[50];
    int ehIgual = 0;

    printf("Digite o nome do usuario: ");
    scanf("%s", &nome);

    for(int i = 0; i < 4; i++){
        ehIgual = comparaString(&nome, &users[i].nome);

        if(ehIgual == 1){
            users[i].nome[0] = '\0';
            users[i].end[0] = '\0';
            users[i].cidade[0] = '\0';
            users[i].estado[0] = '\0';
            users[i].cep[0] = '\0';
            break;
        }
    }

    if(ehIgual == 1){
        printf("Usuario excluido com sucesso");
    }

    else{
        printf("Usuario nao encontrado");
    }
}

int procurar(struct user *users){
    char nome[50];
    int ehIgual = 0;

    printf("Digite o nome do usuario: ");
    scanf("%s", &nome);

    for(int i = 0; i < 4; i++){
        ehIgual = comparaString(&nome, &users[i].nome);

        if(ehIgual == 1){
             printf("Usuario %d: %s %s %s %s %s \n", i + 1, users[i].nome, users[i].end, users[i].cidade, users[i].estado, users[i].cep);
            break;
        }
    }

    if(ehIgual != 1){
        printf("Usuario nao encontrado");
    }
}

int alterar(struct user *users){
    char nome[50];
    int ehIgual = 0;

    printf("Digite o nome do usuario: ");
    scanf("%s", &nome);

    for(int i = 0; i < 4; i++){
        ehIgual = comparaString(&nome, &users[i].nome);

        if(ehIgual == 1){

            printf("Digite as novas informacoes do usuario. \n");

            printf("Digite o nome do usuario: ");
            scanf("%s", users[i].nome);
            printf("Digite o endereco do usuario: ");
            scanf("%s", users[i].end);
            printf("Digite a cidade do usuario: ");
            scanf("%s", users[i].cidade);
            printf("Digite o estado do usuario: ");
            scanf("%s", users[i].estado);
            printf("Digite o CEP do usuario: ");
            scanf("%s", users[i].cep);

            printf("Usuario atualizado: \n");
            printf("Usuario %d: %s %s %s %s %s \n", i + 1, users[i].nome, users[i].end, users[i].cidade, users[i].estado, users[i].cep);
            break;
        }
    }

    if(ehIgual != 1){
        printf("Usuario nao encontrado");
    }
}

int comparaString(char *string1, char *string2){
    int result = 0;
    for(int i = 0; string1[i] != '\0' || string2[i] != '\0'; i++){
        if(string1[i] != string2[i]){
            result = 4;
            if(string1[i] == '\0' && string2[i] != '\0'){
                result = 3;
                break;
            }
            else{
                if(string1[i] != '\0' && string2[i] == '\0'){
                    result = 2;
                    break;
                }
            }
        }
        else{
            result = 1;
        }
    }
    return result;
}
#endif
