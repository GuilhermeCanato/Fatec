#define ex1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef ex1
struct tipos{
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
    struct tipos tipos;

    int Sair = 1;
    while(Sair == 1){

        printf("Digite um char: ");
        scanf("%c", &tipos.Char);

        printf("Digite um int: ");
        scanf("%d", &tipos.Int);

        printf("Digite um long: ");
        scanf("%ld", &tipos.Long);

        printf("Digite um float: ");
        scanf("%f", &tipos.Float);

        printf("Digite um double: ");
        scanf("%lf", &tipos.Double);

        printf("Digite um unsigned char: ");
        scanf("%u", &tipos.uChar);

        printf("Digite um unsigned int: ");
        scanf("%hu", &tipos.uInt);

        printf("Digite um unsigned long: ");
        scanf("%ul", &tipos.uLong);

        printf("\n        10        20        30        40        50        60        70");
        printf("\n1234567890123456789012345678901234567890123456789012345678901234567890");
        printf("\n     %c         %d        %ld                  %f               %lf", tipos.Char, tipos.Int, tipos.Long, tipos.Float, tipos.Double);
        printf("\n         %u                  %hu                 %ul", tipos.uChar, tipos.uInt, tipos.uLong);

        printf("\nDigite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);
    }
}
#endif

#ifdef ex2
struct endereco{
    char nome[45];
    char end[45];
    char cidade[45];
    char estado[45];
    char cep[45];
};

int main()
{
    struct endereco endereco[4];

    int Sair = 1;
    while(Sair == 1){

        for(int i = 0; i < 4; i++){
            printf("Digite o nome: ");
            scanf("%s", &endereco[i].nome);

            printf("Digite a rua: ");
            scanf("%s", &endereco[i].end);

            printf("Digite a cidade: ");
            scanf("%s", &endereco[i].cidade);

            printf("Digite o estado: ");
            scanf("%s", &endereco[i].estado);

            printf("Digite o cep: ");
            scanf("%s", &endereco[i].cep);

            printf("\n\n");
        }

        for(int i = 0; i < 4; i++){
            printf("\nNome : %s", endereco[i].nome);
            printf("\nEnd : %s", endereco[i].end);
            printf("\nCidade : %s", endereco[i].cidade);
            printf("\nEstado : %s", endereco[i].estado);
            printf("\nCEP : %s", endereco[i].cep);
            printf("\n\n");
        }

        printf("\nDigite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);
    }
}
#endif

#ifdef ex3
struct cordenada{
    int x;
    int y;
};

int main()
{
    struct cordenada ponto;

    int Sair = 1;
    while(Sair == 1){

        float distancia = 0;

        printf("Digite o ponto X: ");
        scanf("%d", &ponto.x);

        printf("Digite o ponto Y: ");
        scanf("%d", &ponto.y);

        distancia = sqrt(pow((ponto.x - 0), 2) + pow((ponto.y - 0), 2));

        printf("A distancia do ponto (0,0) ao (%d,%d) eh: %f", ponto.x, ponto.y, distancia);

        printf("\nDigite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);
    }
}
#endif
