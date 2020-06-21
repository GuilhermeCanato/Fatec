#define ex1
#include <stdio.h>
#include <stdlib.h>

#ifdef ex1
int main()
{
    char Char;
    int Int;
    long Long;
    float Float;
    double Double;
    unsigned char uChar;
    unsigned Unsigned;
    unsigned long uLong;

    int Sair = 1;
    while(Sair == 1){

        printf("Digite um char: ");
        scanf("%c", &Char);

        printf("Digite um int: ");
        scanf("%d", &Int);

        printf("Digite um long: ");
        scanf("%ld", &Long);

        printf("Digite um float: ");
        scanf("%f", &Float);

        printf("Digite um double: ");
        scanf("%lf", &Double);

        printf("Digite um unsigned char: ");
        scanf("%u", &uChar);

        printf("Digite um unsigned: ");
        scanf("%hu", &Unsigned);

        printf("Digite um unsigned long: ");
        scanf("%ul", &uLong);

        char *pChar = &Char;
        int *pInt = &Int;
        long *pLong = &Long;
        float *pFloat = &Float;
        double *pDouble = &Double;
        unsigned char *puChar = &uChar;
        unsigned *pUnsigned = &Unsigned;
        unsigned long *puLong = &uLong;

        printf("\n        10        20        30        40        50        60        70");
        printf("\n1234567890123456789012345678901234567890123456789012345678901234567890");
        printf("\n    %d                  %ld                  %hu", *pInt, *pLong, *pUnsigned);
        printf("\n              %f                  %lf              %c", *pFloat, *pDouble, *pChar);
        printf("\n         %ul                 %u", *puLong, *puChar);

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
    struct endereco *pendereco;

    int Sair = 1;
    while(Sair == 1){

        pendereco = &endereco;

        for(int i = 0; i < 4; i++){
            printf("Digite o nome: ");
            scanf("%s", pendereco[i].nome);

            printf("Digite o end: ");
            scanf("%s", pendereco[i].end);

            printf("Digite o cidade: ");
            scanf("%s", pendereco[i].cidade);

            printf("Digite o estado: ");
            scanf("%s", pendereco[i].estado);

            printf("Digite o cep: ");
            scanf("%s", pendereco[i].cep);

            printf("\n\n");
        }

        for(int i = 0; i < 4; i++){
            printf("\nNome : %s", pendereco[i].nome);
            printf("\nEnd : %s", pendereco[i].end);
            printf("\nCidade : %s", pendereco[i].cidade);
            printf("\nEstado : %s", pendereco[i].estado);
            printf("\nCEP : %s", pendereco[i].cep);
            printf("\n\n");
        }

        printf("\nDigite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);
    }
}
#endif

#ifdef ex3
int main()
{
    int Sair = 1;
    while(Sair == 1){

        char caracter;
        char *pCaracter = &caracter;
        char vetor[13] = {'b', 'd', 'f', 'h', 'j', 'l', 'm', 'o', 'q', 's', 'u', 'w', 'y'};
        int igual = 0;

        printf("Digite um caracter: ");
        scanf("%s", pCaracter);

        for(int i = 0; i < 14; i++){
            if(*pCaracter == vetor[i]){
                igual = 1;
            }
        }

        if(igual == 1){
            printf("sao iguais");
        }

        else{
            printf("nao sao iguais");
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

        char stringA[10];
        char stringB[10];
        char *pStringA[10];
        char *pStringB[10];
        int igual = 1;

        printf("Digite a primeira string: ");
        gets(stringA);
        for(int i = 0; i < 10; i++){
            pStringA[i] = &stringA[i];
        }

        printf("Digite a segunda string: ");
        gets(stringB);
        for(int i = 0; i < 10; i++){
            pStringB[i] = &stringB[i];
        }

        for(int i = 0; *pStringA[i] != '\0'; i++){
            if(*pStringA[i] != *pStringB[i]){
                igual = 0;
            }
        }

        if(igual == 1){
            printf("\nsao iguais");
        }

        else{
            printf("\nnao sao iguais");
        }

        printf("\nDigite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);
    }
}
#endif

#ifdef ex5
int main()
{
    int Sair = 1;
    while(Sair == 1){

        int soma = 0, count = 0;
        int num;
        int *pnum = &num;
        float media = 0;

        while(1){
            printf("digite um numero positivo: ");
            scanf("%d", pnum);

            if(*pnum < 0){
                break;
            }

            soma += *pnum;
            count++;
        }

        media = soma / count;

        printf("a media dos numeros positivos e: %.2f", media);

        printf("\n Digite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);
    }
}
#endif

struct Date{
    int day;
    int month;
    int year;
};
#ifdef ex6
int main()
{
    int Sair = 1;
    while(Sair == 1){

        struct Date dates[2];
        struct Date *pDates = &dates;

        long diffInDays = 0;
        long *pDiffInDays = &diffInDays;
        for(int i = 0; i < 2; i++){
            do{
                printf("Digite o %do dia: ", i+1);
                scanf("%d", &pDates[i].day);
            }while(pDates[i].day <= 0 || pDates[i].day > 31);
            do{
                printf("Digite o %do mes: ", i+1);
                scanf("%d", &pDates[i].month);
            }while(pDates[i].month <= 0 || pDates[i].month > 12);
            do{
                printf("Digite o %do ano: ", i+1);
                scanf("%d", &pDates[i].year);
            }while(pDates[i].year <= 0 || pDates[i].year > 3000);
            printf("Data %d: %d/%d/%d \n", i+1, pDates[i].day, pDates[i].month, pDates[i].year);
        }

        if(pDates[0].year > pDates[1].year){
            if(pDates[0].month > pDates[1].month){
                if(pDates[0].day > pDates[1].day) //Ex 1: 20/4/2018 - 10/3/2017 = 405
                {
                    diffInDays += pDates[0].day - pDates[1].day;
                    diffInDays += 30 * (pDates[0].month - pDates[1].month);
                    diffInDays += 365 * (pDates[0].year - pDates[1].year);
                }
                else{
                    if(pDates[0].day < pDates[1].day){ //Ex 2: 10/4/2018 - 20/3/2017 = 385
                        diffInDays += (pDates[0].day + 30) - pDates[1].day;
                        diffInDays += 30 * (pDates[0].month - pDates[1].month - 1);
                        diffInDays += 365 * (pDates[0].year - pDates[1].year);
                    }
                    else{ //Ex 3: 10/4/2018 - 10/3/2017 = 395
                        diffInDays += 30 * (pDates[0].month - pDates[1].month);
                        diffInDays += 365 * (pDates[0].year - pDates[1].year);
                    }
                }
            }
            else{
                if(pDates[0].day > pDates[1].day) //Ex 4: 20/3/2018 - 10/4/2017 = 340
                {
                    diffInDays += pDates[0].day - pDates[1].day;
                    diffInDays += 30 * ((pDates[0].month + 12) - pDates[1].month);
                    diffInDays += 365 * (pDates[0].year - pDates[1].year - 1);
                }
                else{
                    if(pDates[0].day < pDates[1].day){ //Ex 5: 10/3/2018 - 20/4/2017 = 320
                        diffInDays += (pDates[0].day + 30) - pDates[1].day;
                        diffInDays += 30 * ((pDates[0].month + 12) - pDates[1].month - 1);
                        diffInDays += 365 * (pDates[0].year - pDates[1].year - 1);
                    }
                    else{ //Ex 6: 10/3/2018 - 10/4/2017 = 330
                        diffInDays += 30 * ((pDates[0].month + 12) - pDates[1].month);
                        diffInDays += 365 * (pDates[0].year - pDates[1].year - 1);
                    }
                }
            }
        }
        else{
            if(pDates[0].year < pDates[1].year){
                if(pDates[0].month < pDates[1].month){
                    if(pDates[0].day < pDates[1].day) //Ex 7: 10/3/2018 - 20/4/2019 = 405
                    {
                        diffInDays += pDates[1].day - pDates[0].day;
                        diffInDays += 30 * (pDates[1].month - pDates[0].month);
                        diffInDays += 365 * (pDates[1].year - pDates[0].year);
                    }
                    else{
                        if(pDates[0].day > pDates[1].day){ //Ex 8: 20/3/2018 - 10/4/2019 = 385
                            diffInDays += (pDates[1].day + 30) - pDates[0].day;
                            diffInDays += 30 * (pDates[1].month - pDates[0].month - 1);
                            diffInDays += 365 * (pDates[1].year - pDates[0].year);
                        }
                        else{ //Ex 9: 10/3/2018 - 10/4/2019 = 395
                            diffInDays += 30 * (pDates[1].month - pDates[0].month);
                            diffInDays += 365 * (pDates[1].year - pDates[0].year);
                        }
                    }
                }
                else{
                    if(pDates[0].day < pDates[1].day) //Ex 10: 10/4/2017 - 20/3/2018  = 340
                    {
                        diffInDays += pDates[1].day - pDates[0].day;
                        diffInDays += 30 * ((pDates[1].month + 12) - pDates[0].month);
                        diffInDays += 365 * (pDates[1].year - pDates[0].year - 1);
                    }
                    else{
                        if(pDates[0].day > pDates[1].day){ //Ex 11: 20/4/2017 - 10/3/2018 = 320
                            diffInDays += (pDates[1].day + 30) - pDates[0].day;
                            diffInDays += 30 * ((pDates[1].month + 12) - pDates[0].month - 1);
                            diffInDays += 365 * (pDates[1].year - pDates[0].year - 1);
                        }
                        else{ //Ex 12: 10/4/2017 - 10/3/2018 = 330
                            diffInDays += 30 * ((pDates[1].month + 12) - pDates[0].month);
                            diffInDays += 365 * (pDates[1].year - pDates[0].year - 1);
                        }
                    }
                }
            }
            else{
                if(pDates[0].month > pDates[1].month){
                    if(pDates[0].day > pDates[1].day){  // Ex 13: 20/4/2018 - 10/3/2018 = 40
                        diffInDays += pDates[0].day - pDates[1].day;
                        diffInDays += 30 * (pDates[0].month - pDates[1].month);
                    }
                    else{
                        if(pDates[0].day < pDates[1].day){ // Ex 1=4: 10/4/2018 - 20/3/2018 = 20
                            diffInDays += (pDates[0].day + 30) - pDates[1].day;
                            diffInDays += 30 * (pDates[0].month - pDates[1].month - 1);
                        }
                        else{   // Ex 15 : 10/4/2018 - 10/3/2018 = 30
                            diffInDays += 30 * (pDates[0].month - pDates[1].month);
                        }
                    }
                }
                else{
                    if(pDates[0].day < pDates[1].day){ // Ex 16: 20/3/2018 - 10/4/2018 = 20
                        diffInDays += pDates[1].day - pDates[0].day;
                        diffInDays += 30 * (pDates[1].month - pDates[0].month);
                    }
                    else{
                        if(pDates[0].day > pDates[1].day){ // Ex 17: 10/3/2018 - 20/4/2018 = 40
                            diffInDays += (pDates[1].day + 30) - pDates[0].day;
                            diffInDays += 30 * (pDates[1].month - pDates[0].month - 1);
                        }
                        else{    // Ex 18 : 10/3/2018 - 10/4/2018 = 30
                            diffInDays += 30 * (pDates[1].month - pDates[0].month);
                        }
                    }
                }
            }
        }

        printf("Diferenca entre datas em dias: %ld\n", *pDiffInDays);


        printf("\n Digite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);
    }
}
#endif
