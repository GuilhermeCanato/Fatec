#define ex1
#include <stdio.h>
#include <stdlib.h>

#ifdef ex1
int main()
{
    int Sair = 1;
    while(Sair == 1){

        int vetorInt[3];
        long vetorLong[3];
        unsigned vetorUnsigned[3];
        float vetorFloat[3];
        double vetorDouble[3];

        for (int i = 0; i < 3; i++){
            printf("Digite um valor para o numero int: ");
            scanf("%d", &vetorInt[i]);
        }

        for (int i = 0; i < 3; i++){
            printf("Digite um valor para o numero long: ");
            scanf("%ld", &vetorLong[i]);
        }

        for (int i = 0; i < 3; i++){
            printf("Digite um valor para o numero Unsigned: ");
            scanf("%u", &vetorUnsigned[i]);
        }

        for (int i = 0; i < 3; i++){
            printf("Digite um valor para o numero Float: ");
            scanf("%f", &vetorFloat[i]);
        }

        for (int i = 0; i < 3; i++){
            printf("Digite um valor para o numero double: ");
            scanf("%lf", &vetorDouble[i]);
        }

        printf("         10        20        30        40        50 \n");
        printf("12345678901234567890123456789012345678901234567890 \n");

        for(int i = 0; i < 3; i++){
            printf("%3d %20ld %20u \n", vetorInt[i], vetorLong[i], vetorUnsigned[i]);
            printf("%10.1f %24.1lf \n", vetorFloat[i], vetorDouble[i]);
        }

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

        int vetor[10];
        int vetorComp[10];
        int count = 9;
        int ehPalindromo = 1;

        for(int i = 0; i < 10; i++){
            printf("Digite um numero: ");
            scanf("%d", &vetor[i]);
            vetorComp[i] = vetor[i];
        }

        for(int i = 0; i < 10; i++){
            if(vetor[i] != vetorComp[count]){
                ehPalindromo = 0;
            }

            count--;
        }

        if(ehPalindromo == 0){
            printf("o vetor nao eh palindromo");
        }

        else{
            printf("o vetor eh palindromo");
        }

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

        int vetor[2][3][3];

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    printf("Digite um numero: ");
                    scanf("%d", &vetor[i][j][k]);
                }
            }
        }

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    printf("\nvetor[%d][%d][%d] = %d ", i, j, k, vetor[i][j][k]);
                }
            }
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

        int VetorA[2][3], VetorB[2][3], VetorC[2][3];

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                printf("Digite um valor para o vetor A: ");
                scanf("%d", &VetorA[i][j]);

                printf("Digite um valor para o vetor B: ");
                scanf("%d", &VetorB[i][j]);

                VetorC[i][j] = VetorA[i][j] * VetorB[i][j];
            }
        }

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                printf("\nA multiplicacao dos vetores A e B eh: VetorC[%d][%d] = %d", i, j, VetorC[i][j]);
            }
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

        int tamanhoVetor = 0;
        int countP = 0;
        int countI = 1;

        printf("Digite o tamanho do vetor: ");
        scanf("%d", &tamanhoVetor);

        int Vetor[tamanhoVetor], Par[tamanhoVetor], Impar[tamanhoVetor];

        for(int i = 0; i < tamanhoVetor; i++){
            printf("Digite um numero para o vetor[%d]: ", i + 1);
            scanf("%d", &Vetor[i]);
        }

        Impar[0] = Vetor[0];

        for(int i = 1; i < tamanhoVetor; i++){

            if(i % 2 == 1){
                Par[countP] = Vetor[i];
                countP++;
            }

            if(i % 2 == 0){
                Impar[countI] = Vetor[i];
                countI++;
            }
        }

        for(int i = 0; i < countP; i++){
            printf("\nPar[%d] : %d", i, Par[i]);
        }

        for(int i = 0; i < countI; i++){
            printf("\nImpar[%d] : %d", i, Impar[i]);
        }

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

        int tamanhoVetor = 0;
        int countP = 0;
        int countI = 0;

        printf("Digite o tamanho do vetor: ");
        scanf("%d", &tamanhoVetor);

        int Vetor[tamanhoVetor], Par[tamanhoVetor], Impar[tamanhoVetor];

        for(int i = 0; i < tamanhoVetor; i++){
            printf("Digite um numero para o vetor[%d]: ", i + 1);
            scanf("%d", &Vetor[i]);
        }

        for(int i = 0; i < tamanhoVetor; i++){
            if(Vetor[i] % 2 == 0){
                Par[countP] = Vetor[i];
                countP++;
            }

            else{
                Impar[countI] = Vetor[i];
                countI++;
            }
        }

        for(int i = 0; i < countP; i++){
            printf("\nPar[%d] : %d", i, Par[i]);
        }

        for(int i = 0; i < countI; i++){
            printf("\nImpar[%d] : %d", i, Impar[i]);
        }

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

        int vetor[10], rev[10];
        int maior = 0, atual = 0, menor = 0;
        int countMenorNum = 0;
        int countMaiorNum = 9;

        for(int i = 0; i < 10; i++){
            printf("Digite um numero para o vetor[%d]: ", i + 1);
            scanf("%d", &vetor[i]);
        }

        maior = vetor[0];

        for(int i = 0; i < 10; i++){
            if(vetor[i] >= maior){
                maior = vetor[i];
                atual = maior;
            }
        }

        for(int i = 0; i < 10; i++){

            if(vetor[i] <= menor){
                menor = vetor[i];
                rev[countMenorNum] = menor;
                countMenorNum++;
            }

            else if(vetor[i] >= maior){
                maior = vetor[i];
                atual = maior;
                rev[countMaiorNum] = maior;
                countMaiorNum--;
            }
        }

        for(int i = countMenorNum; i <= countMaiorNum; i++){
            for(int j = 0; j < 10; j++){

                if(vetor[j] == maior){
                    rev[i] = vetor[j];
                }

                else if(vetor[j] > menor && vetor[j] < maior){
                    maior = vetor[j];
                }
            }
            rev[i] = maior;
            menor = maior;
            maior = atual;
        }

        for(int i = 0; i < 10; i++){
            printf("\nvetor[%d]: %d", i, rev[i]);
        }

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

        int matriz[5][5];
        int num = 0;
        int achou = 0;

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                printf("Digite o valor da matriz[%d][%d]: ", i, j);
                scanf("%d", &matriz[i][j]);
            }
        }

        printf("Digite o numero que voce deseja procurar: ");
        scanf("%d", &num);


        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(matriz[i][j] == num){
                    achou = 1;
                    printf("O numero digitado esta na posicao do vetor[%d][%d]", i, j);
                }
            }
        }

        if(achou == 0){
            printf("O numero digitado nao foi achado na matriz");
        }

        printf("\n Digite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);
    }
}
#endif
