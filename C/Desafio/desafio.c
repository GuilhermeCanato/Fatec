#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Feito por Guilherme Mazzitelli Canato

/*
Escreva um programa que tem a estrutura de dados abaixo. O programa tem as seguintes opções de menu:

1 – entra dados.
2 – lista dados na tela.
3 – pesquisar um registro por nome.
4 – pesquisa por estado civil
5 – pesquisar os aniversariantes de um determinado mês.
6 – pesquisa por faixa salarial
7 -  altera valor do salário
8 – altera dados.
9 – exclui dados.
10 - saída

Todas as operações devem ser feitas direto no arquivo. (utilize a funcao fseek).

Estrutura: nome, data de nascimento, estado civil,  salário.

Obs: a estrutura de dados deve ser variável local na função main().

Obs: o programa deve ser finalizado pelo usuário.
*/

struct User {
    char nome[64];
    char dtNascimento[64];
    char estadoCivil[64];
    float salario;
};

int main(){
    struct User user;
    struct User *pUser;
    int opcao, tamanho;

    pUser = &user;
    tamanho = sizeof(user);

    while(1){
        system("cls");
        printf("\n MENU\n");
        printf("\n 1 - Adicionar um novo usuario \n 2 - Listar usuarios ");
        printf("\n 3 - Pesquisar um usuario por nome \n 4 - Pesquisar um usuario por estado civil");
        printf("\n 5 - Pesquisar os aniversariantes de um determinado mes \n 6 - Pesquisar usuarios por faixa salarial");
        printf("\n 7 - Atualizar salario de um usuario \n 8 - Atualizar dados de um usuario \n 9 - Deletar um usuario \n 0 - Sair");
        printf("\n Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 1:
                system("cls");
                Insert(pUser, tamanho);
                break;
            case 2:
                system("cls");
                GetAll(pUser, tamanho);
                break;
            case 3:
                system("cls");
                GetByName(pUser, tamanho);
                break;
            case 4:
                system("cls");
                GetByEstadoCivil(pUser, tamanho);
                break;
            case 5:
                system("cls");
                GetByMonth(pUser, tamanho);
                break;
            case 6:
                system("cls");
                GetByFaixaSalarial(pUser, tamanho);
                break;
            case 7:
                system("cls");
                UpdateSalario(pUser, tamanho);
                break;
            case 8:
                system("cls");
                Update(pUser, tamanho);
                break;
            case 9:
                system("cls");
                Delete(pUser, tamanho);
                break;
            case 0:
                exit(1);
                break;
            default:
                system("cls");
                printf("\n Por Favor! Digite um numero entre 0 e 9.\n");
                break;
        }
    }
}

//Função para adicionar um novo usuário
void Insert(struct User *user, int tamanho){
    printf("\n ADICIONAR UM NOVO USUARIO\n");

    FILE *DataBase;
    int count = OpenContador();

    DataBase = fopen("DataBase.txt", "a");

    if(DataBase == NULL){
        printf("\nERRO ao abrir o arquivo!");
        exit(1);
    }

    printf("\n Digite o nome do usuario: ");
    gets(user -> nome);

    printf(" Digite a data de nascimento(dd/mm/yyyy) do usuario: ");
    gets(user -> dtNascimento);

    printf(" Digite o estado civil do usuario: ");
    gets(user -> estadoCivil);

    printf(" Digite o salario do usuario: ");
    scanf("%f", &user -> salario);
    getchar();

    fwrite(user, tamanho, 1, DataBase);
    fclose(DataBase);

    count++;
    AddContador(count);

    printf("\n Usuario adicionado com sucesso");
    printf("\n Aperta a tecla ENTER para continuar...\n");
    getchar();
}

//Função para listar todos os usuários
void GetAll(struct User *user, int tamanho){
    printf("\n LISTAR TODOS OS USUARIOS\n");

    FILE *DataBase;
    int posicao;
    int count = OpenContador();

    DataBase = fopen("DataBase.txt", "r");

    if(DataBase == NULL){
        printf("\n ERRO ao abrir o arquivo!");
        exit(1);
    }

    for(int i = 0; i < count; i++){
        posicao = i * tamanho;

        fseek(DataBase, posicao, 0);
        fread(user, tamanho, 1, DataBase);

        if(user -> nome[0] != '*'){
            printf("\n USUARIO %d\n", i + 1);
            printf(" Nome: %s \n Data de Nascimento: %s \n Estado civil: %s \n Salario: %.2f \n\n", user -> nome, user -> dtNascimento, user -> estadoCivil, user -> salario);
        }
    }

    fclose(DataBase);

    printf("\n Aperta a tecla ENTER para continuar...\n");
    getchar();
}

//Função para pesquisar um usuario pelo nome
void GetByName(struct User *user, int tamanho){
    printf("\n PROCURAR USUARIO PELO NOME\n");

    FILE *DataBase;
    int posicao;
    char nome[64];

    printf("\n Digite o nome do usuario: ");
    gets(nome);

    DataBase = fopen("DataBase.txt", "r");

    if(DataBase == NULL){
        printf("\n ERRO ao abrir o arquivo!");
        exit(1);
    }

    char *pNome = &nome;

    int numRegistro = ComparaString(user, pNome, tamanho);

    if(numRegistro != -1){
        posicao = numRegistro * tamanho;

        fseek(DataBase, posicao, 0);
        fread(user, tamanho, 1, DataBase);

        if(user -> nome[0] != '*'){
            printf("\n USUARIO %d\n", numRegistro + 1);
            printf(" Nome: %s \n Data de Nascimento: %s \n Estado civil: %s \n Salario: %.2f \n\n", user -> nome, user -> dtNascimento, user -> estadoCivil, user -> salario);
        }
    }

    fclose(DataBase);

    printf("\n Aperta a tecla ENTER para continuar...\n");
    getchar();
}

//Função para pesquisar usuarios pelo estado civil
void GetByEstadoCivil(struct User *user, int tamanho){
    printf("\n PROCURAR USUARIO PELO ESTADO CIVIL\n");

    FILE *DataBase;
    int posicao;
    char estadoCivil[64];
    int count = OpenContador();

    printf("\n Digite o estado civil do usuario: ");
    gets(estadoCivil);

    DataBase = fopen("DataBase.txt", "r");

    if(DataBase == NULL){
        printf("\n ERRO ao abrir o arquivo!");
        exit(1);
    }

    for(int i = 0; i < count; i++)
    {
        fread(user, tamanho, 1, DataBase);
        int j;
        for(j = 0; estadoCivil[j] != '\0'; j++){
            if(estadoCivil[j] != user -> estadoCivil[j]){
                break;
            }
        }

        if(estadoCivil[j] == '\0' && user -> estadoCivil[j] == '\0')
        {
            posicao = i * tamanho;

            fseek(DataBase, posicao, 0);
            fread(user, tamanho, 1, DataBase);

            if(user -> nome[0] != '*'){
                printf("\n USUARIO %d\n", i + 1);
                printf(" Nome: %s \n Data de Nascimento: %s \n Estado civil: %s \n Salario: %.2f \n\n", user -> nome, user -> dtNascimento, user -> estadoCivil, user -> salario);
            }
        }
    }

    fclose(DataBase);

    printf("\n Aperta a tecla ENTER para continuar...\n");
    getchar();
}

//Função para pesuisar usuarios pelo mes de nascimento
void GetByMonth(struct User *user, int tamanho){
    printf("\n PROCURAR USUARIOS PELO MES DE NASCIMENTO\n");

    FILE *DataBase;
    int posicao;
    char mes[2];
    int count = OpenContador();

    printf("\n Digite o mes de nascimento do usuario(de 01 a 12): ");
    gets(mes);

    DataBase = fopen("DataBase.txt", "r");

    if(DataBase == NULL){
        printf("\n ERRO ao abrir o arquivo!");
        exit(1);
    }

    for(int i = 0; i < count; i++)
    {
        fread(user, tamanho, 1, DataBase);

        if(mes[0] == user -> dtNascimento[3] && mes[1] == user -> dtNascimento[4]){
            posicao = i * tamanho;

            fseek(DataBase, posicao, 0);
            fread(user, tamanho, 1, DataBase);

            if(user -> nome[0] != '*')
            {
                printf("\n USUARIO %d\n", i + 1);
                printf(" Nome: %s \n Data de Nascimento: %s \n Estado civil: %s \n Salario: %.2f \n\n", user -> nome, user -> dtNascimento, user -> estadoCivil, user -> salario);
            }
        }
    }

    fclose(DataBase);

    printf("\n Aperta a tecla ENTER para continuar...\n");
    getchar();
}

//Função para pesquisa usuarios por uma determinada faixa salarial
void GetByFaixaSalarial(struct User *user, int tamanho){
    printf("\n PROCURAR USUARIO POR UMA FAIXA SALARIAL\n");

    FILE *DataBase;
    int posicao;
    float maiorSalario = 0, menorSalario = 0;
    float salario1 = 0, salario2 = 0;
    int count = OpenContador();

    while(salario1 == salario2){
        printf("\n Digite o primeiro salario: ");
        scanf("%f", &salario1);

        printf("\n Digite o segundo salario: ");
        scanf("%f", &salario2);
        getchar();

        if(salario1 == salario2){
            printf("\n Digite um valor diferente para cada salario\n");
        }
    }

    if(salario2 > salario1){
        maiorSalario = salario2;
        menorSalario = salario1;
    }

    else{
        maiorSalario = salario1;
        menorSalario = salario2;
    }

    DataBase = fopen("DataBase.txt", "r");

    if(DataBase == NULL){
        printf("\n ERRO ao abrir o arquivo!");
        exit(1);
    }

    for(int i = 0; i < count; i++)
    {
        fread(user, tamanho, 1, DataBase);

        if(user -> nome[0] != '*'){
            posicao = i * tamanho;

            fseek(DataBase, posicao, 0);
            fread(user, tamanho, 1, DataBase);
            if(user -> salario >= menorSalario & user -> salario <= maiorSalario){
                printf("\n USUARIO %d\n", i + 1);
                printf(" Nome: %s \n Data de Nascimento: %s \n Estado civil: %s \n Salario: %.2f \n\n", user -> nome, user -> dtNascimento, user -> estadoCivil, user -> salario);
            }
        }
    }

    fclose(DataBase);

    printf("\n Aperta a tecla ENTER para continuar...\n");
    getchar();
}

//Função que altera apenas o salario de um usuario
void UpdateSalario(struct User *user, int tamanho){
    printf("\n ALTERAR SALARIO DO USUARIO\n");

    FILE *DataBase;
    int posicao, escolha;
    char nome[64];

    printf("\n Digite o nome do usuario que deseja alterar: ");
    gets(nome);

    DataBase = fopen("DataBase.txt", "r+");

    if(DataBase == NULL){
        printf("\n ERRO ao abrir o arquivo!");
        exit(1);
    }

    char *pNome = &nome;
    int numRegistro = ComparaString(user, pNome, tamanho);

    if(numRegistro != -1){
        posicao = numRegistro * tamanho;

        fseek(DataBase, posicao, 0);
        fread(user, tamanho, 1, DataBase);

        if(user -> nome[0] != '*'){
            printf("\n USUARIO %d \n", numRegistro + 1);
            printf(" Nome: %s \n Data de Nascimento: %s \n Estado civil: %s \n Salario: %.2f \n\n", user -> nome, user -> dtNascimento, user -> estadoCivil, user -> salario);

            printf("\n Tem certeza que deseja alterar ? 1 - SIM || 2 - NAO\n ");
            scanf("%d", &escolha);
            getchar();

            if(escolha == 1){

                printf(" Digite o novo do usuario: ");
                scanf("%f", &user -> salario);
                getchar();

                fseek(DataBase, posicao, 0);
                fwrite(user, tamanho, 1, DataBase);

                printf("\n Usuario alterado com sucesso");
            }
        }
    }

    fclose(DataBase);

    printf("\n Aperta a tecla ENTER para continuar...\n");
    getchar();
}

//Função que altera todos os dados de um usuario
void Update(struct User *user, int tamanho){
    printf("\n ALTERAR DADOS DO USUARIO\n");

    FILE *DataBase;
    int posicao, escolha;
    char nome[64];

    printf("\n Digite o nome do usuario que deseja alterar: ");
    gets(nome);

    DataBase = fopen("DataBase.txt", "r+");

    if(DataBase == NULL){
        printf("\n ERRO ao abrir o arquivo!");
        exit(1);
    }

    char *pNome = &nome;
    int numRegistro = ComparaString(user, pNome, tamanho);

    if(numRegistro != -1){
        posicao = numRegistro * tamanho;

        fseek(DataBase, posicao, 0);
        fread(user, tamanho, 1, DataBase);

        if(user -> nome[0] != '*'){
            printf("\n USUARIO %d \n", numRegistro + 1);
            printf(" Nome: %s \n Data de Nascimento: %s \n Estado civil: %s \n Salario: %.2f \n\n", user -> nome, user -> dtNascimento, user -> estadoCivil, user -> salario);

            printf("\n Tem certeza que deseja alterar ? 1 - SIM || 2 - NAO\n ");
            scanf("%d", &escolha);
            getchar();

            if(escolha == 1){

                printf(" Digite o novo nome do usuario: ");
                gets(user -> nome);

                printf(" Digite a nova data de nascimento(dd/mm/yyyy) do usuario: ");
                gets(user -> dtNascimento);

                printf(" Digite o novo estado civil do usuario: ");
                gets(user -> estadoCivil);

                printf(" Digite o novo salario do usuario: ");
                scanf("%f", &user -> salario);
                getchar();

                fseek(DataBase, posicao, 0);
                fwrite(user, tamanho, 1, DataBase);

                printf("\n Usuario alterado com sucesso");
            }
        }
    }

    fclose(DataBase);

    printf("\n Aperta a tecla ENTER para continuar...\n");
    getchar();
}

//Função para deleter um usuário pelo nome
void Delete(struct User *user, int tamanho){
    printf("\n EXCLUINDO USUARIO PELO NOME\n");

    FILE *DataBase;
    int posicao, escolha;
    char nome[64];

    printf("\n Digite o nome do usuario que deseja excluir: ");
    gets(nome);

    DataBase = fopen("DataBase.txt", "r+");

    if(DataBase == NULL){
        printf("\n ERRO ao abrir o arquivo!");
        exit(1);
    }

    char *pNome = &nome;
    int numRegistro = ComparaString(user, pNome, tamanho);

    if(numRegistro != -1){
        posicao = numRegistro * tamanho;

        fseek(DataBase, posicao, 0);
        fread(user, tamanho, 1, DataBase);

        if(user -> nome[0] != '*'){
            printf("\n O USUARIO %d com os seguintes dados sera excluido \n", numRegistro + 1);
            printf(" Nome: %s \n Data de Nascimento: %s \n Estado civil: %s \n Salario: %.2f \n\n", user -> nome, user -> dtNascimento, user -> estadoCivil, user -> salario);

            printf("\n Tem certeza que deseja excluir ? 1 - SIM || 2 - NAO\n ");
            scanf("%d", &escolha);
            getchar();

            if(escolha == 1){
                user -> nome[0] = '*';
                user -> estadoCivil[0] = '*';
                user -> dtNascimento[0] = '*';
                user -> salario = '*';

                fseek(DataBase, posicao, 0);
                fwrite(user, tamanho, 1, DataBase);

                printf("\n Usuario excluido com sucesso");
            }
        }
    }

    fclose(DataBase);

    printf("\n Aperta a tecla ENTER para continuar...\n");
    getchar();
}

//Função que retorna o numero de registros
int OpenContador(){
    FILE *Contador;
    int count = 0;

    Contador = fopen("contador.txt", "r");
    fscanf(Contador, "%d", &count);
    fclose(Contador);

    //printf(" Numeros de registros atuais: %d\n", count);
    fclose(Contador);
    return count;
}

//Função que adiciona um numero de registro
void AddContador(int count){
    FILE *Contador;

    Contador = fopen("contador.txt", "w");
    fprintf(Contador, "%d", count);
    fclose(Contador);

    //printf("\n Numero de usuarios atuais: %d\n", count);

    fclose(Contador);
}

//Função que retorna o numero do registro da comparacao de strings
int ComparaString(struct User *user, char *nome, int tamanho){
    FILE *DataBase;
    int count = OpenContador();

    DataBase = fopen("DataBase.txt", "r");

    if(DataBase == NULL){
        printf("\nERRO ao abrir o arquivo!");
        exit(1);
    }

    for(int i = 0; i < count; i++)
    {
        fread(user, tamanho, 1, DataBase);
        int j;
        for(j = 0; nome[j] != '\0'; j++){
            if(nome[j] != user -> nome[j]){
                break;
            }
        }

        if(nome[j] == '\0' && user -> nome[j] == '\0')
        {
            return i;
        }
    }

    fclose(DataBase);

    printf("\n Nao foi encontrado o usuario %s\n", nome);
    return -1;
}
