#define ex1
#include <stdio.h>
#include <stdlib.h>

#ifdef ex1
int main()
{
    int Sair = 1;
    while(Sair == 1){

        char stringA[7], stringB[7], stringC[7], stringD[7], stringE[7];

        printf("Digite a primeira string de ate 7 caracteres: ");
        scanf("%s", &stringA);

        printf("Digite a segunda string de ate 7 caracteres: ");
        scanf("%s", &stringB);

        printf("Digite a terceira string de ate 7 caracteres: ");
        scanf("%s", &stringC);

        printf("Digite a quarta string de ate 7 caracteres: ");
        scanf("%s", &stringD);

        printf("Digite a quinta string de ate 7 caracteres: ");
        scanf("%s", &stringE);

        printf("\n        10        20        30        40        50");
        printf("\n12345678901234567890123456789012345678901234567890");
        printf("\n   %-8s                       %-8s", stringA, stringE);
        printf("\n            %-8s            %-8s", stringB, stringD);
        printf("\n                      %-8s", stringC);


    printf("\n Digite 1 para continuar\nVoce deseja sair? ");
    scanf("%d", &Sair);
    }
}
#endif

#ifdef ex2
int main()
{
    int Sair = 1;
    while(Sair == 1){

        char string[3][10];

        for(int i = 0; i < 3; i ++){
            printf("Digite um nome de ate 10 caracteres: ");
            scanf("%s", &string[i]);
        }

        printf("\n        10        20        30        40        50        60");
        printf("\n123456789012345678901234567890123456789012345678901234567890");
        printf("\n    %-10s               %-10s               %-10s", string[0], string[1], string[2]);

    printf("\n Digite 1 para continuar\nVoce deseja sair? ");
    scanf("%d", &Sair);
    }
}
#endif

#ifdef ex3
int main()
{
    int Sair = 1;
    while(Sair == 1){

        char stringA[10], stringB[10];
        int igual = 1;

        printf("Digite um nome: ");
        scanf("%s", &stringA);

        printf("Digite um nome: ");
        scanf("%s", &stringB);

        for(int i = 0; i < 10; i++){
            if(stringA[i] != stringB[i]){
                igual = 0;
            }
        }

        if(igual == 1){
            printf("As strings sao iguais");
        }

        else{
            printf("As strings sao diferentes");
        }

    printf("\n Digite 1 para continuar\nVoce deseja sair? ");
    scanf("%d", &Sair);
    }
}
#endif

#ifdef ex4
int main()
{
    int Sair = 1;
    while(Sair == 1){

        char dia[3];

        printf("Digite um dia da semana abreviado pelas suas 3 primeiras letras");
        printf("\nEx: sab = Sabado\n");

        printf("\nDigite um dia da semana: ");
        scanf("%s", &dia);

        if (dia[0] == 's' && dia[1] == 'e' && dia[2] == 'g')
        {
            printf("\nSegunda-Feira!");
        }

        else if (dia[0] == 't' && dia[1] == 'e' && dia[2] == 'r')
        {
            printf("\nTerca-Feira!");
        }

        else if (dia[0] == 'q' && dia[1] == 'u' && dia[2] == 'a')
        {
            printf("\nQuarta-Feira!");
        }

        else if (dia[0] == 'q' && dia[1] == 'u' && dia[2] == 'i')
        {
            printf("\nSQuinta-Feira!");
        }

        else if (dia[0] == 's' && dia[1] == 'e' && dia[2] == 'x')
        {
            printf("\nSexta-Feira!");
        }

        else if (dia[0] == 's' && dia[1] == 'a' && dia[2] == 'b')
        {
            printf("\nSabado!");
        }

        else if (dia[0] == 'd' && dia[1] == 'o' && dia[2] == 'm')
        {
            printf("\nDomingo!");
        }

        else{
            printf("\nAbreviacao invalida");
        }

    printf("\n Digite 1 para continuar\nVoce deseja sair? ");
    scanf("%d", &Sair);
    }
}
#endif

#ifdef ex5
int main()
{
    int Sair = 1;
    while(Sair == 1){

        char string[10];

        printf("Digite uma string de ate 10 caracteres: ");
        scanf("%s", &string);

        for (int i = 0; string[i] != '\0'; i++)
        {
            if (string[i] >= 97 && string[i] <= 122)
            {
                string[i] -= 32;
            }
        }

        printf("%s", string);

    printf("\n Digite 1 para continuar\nVoce deseja sair? ");
    scanf("%d", &Sair);
    }
}
#endif

#ifdef ex6
int main()
{
    int Sair = 1;
    while(Sair == 1){

        char string[10];

        printf("Digite uma string de ate 10 caracteres: ");
        scanf("%s", &string);

        for (int i = 0; string[i] != '\0'; i++)
        {
            if (string[i] >= 65 && string[i] <= 89)
            {
                string[i] += 32;
            }
        }

        printf("%s", string);

    printf("\n Digite 1 para continuar\nVoce deseja sair? ");
    scanf("%d", &Sair);
    }
}
#endif

#ifdef ex7
int main()
{
    int Sair = 1;
    while(Sair == 1){
        char string[50];

        printf("Digite uma string de ate 50 caracteres: ");
        scanf("%s", &string);

        for (int i = 0; string[i] != '\0'; i++)
        {
            string[i]++;
        }

        printf("%s", string);

    printf("\n Digite 1 para continuar\nVoce deseja sair? ");
    scanf("%d", &Sair);
    }
}
#endif

#ifdef ex8
int main()
{
    int Sair = 1;
    while(Sair == 1){

        char string[10];
        int qntCaracter = 0;

        printf("Digite uma string de ate 50 caracteres: ");
        scanf("%s", &string);

        while(string[qntCaracter] != '\0'){
            qntCaracter++;
        }

        printf("A palavra %s possui %d caracteres.\n", string, qntCaracter);

    printf("\n Digite 1 para continuar\nVoce deseja sair? ");
    scanf("%d", &Sair);

    }
}
#endif

