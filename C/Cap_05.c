#define ex1
#include <stdio.h>
#include <stdlib.h>

#ifdef ex1

int Verificar(char letra)
{
    char *vetor[13] = {'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's' , 'u', 'w', 'y'};
    for(int i = 0; i < 13; i++){
        if(vetor[i] == letra){
            return i;
        }
    }
}

int main()
{
    int Sair = 1;
    while(Sair == 1){

        char Letra = "";

        printf("Digite uma letra: ");
        scanf("%c", &Letra);
        getchar();

        int resposta = Verificar(Letra);

        if(resposta >= 0 && resposta < 13){
            printf("A letra escolhida esta na posicao %d do vetor", resposta + 1);
        }

        else{
            printf("A letra nao foi encontrada no vetor");
        }

        printf("\n Digite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);
    }
}
#endif

#ifdef ex2

int soma(int numA, int numB)
{
    return numA + numB;
}

int subtracao(int numA, int numB)
{
    return numA - numB;
}

float multiplica(int numA, int numB)
{
    return numA * numB;
}

float divisao(float numA, float numB)
{
    float resultado = numA / numB;
    return resultado;
}

int main()
{
    int Sair = 1;
    while(Sair == 1){
        int numA, numB;

        printf("Digite um numero: ");
        scanf("%d", &numA);

        printf("Digite outro numero: ");
        scanf("%d", &numB);

        printf("\nA soma dos numeros deu: %d", soma(numA, numB));
        printf("\nA subtracao dos numeros deu: %d", subtracao(numA, numB));
        printf("\nA multiplicacao dos numeros deu: %.2f", multiplica(numA, numB));
        printf("\nA divisao dos numeros deu: %.2f", divisao(numA, numB));

        printf("\n Digite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);
    }
}
#endif

#ifdef ex3
int soma(int numA, int numB)
{
    return numA + numB;
}

int subtracao(int numA, int numB)
{
    return numA - numB;
}

float multiplica(int numA, int numB)
{
    return numA * numB;
}

float divisao(float numA, float numB)
{
    float resultado = numA / numB;
    return resultado;
}

int main()
{
    int Sair = 1;
    while(Sair == 1){

        int quantidade = 0;
        int numA, numB;

        printf("Digite o numero de vezes que voce quer fazer as operacoes: ");
        scanf("%d", &quantidade);

        for(int i = 0; i < quantidade; i++){
            printf("\nvez: %d", i + 1);
            printf("\nDigite o primeiro numero: ");
            scanf("%d", &numA);

            printf("Digite o segundo numero: ");
            scanf("%d", &numB);

            printf("\nA soma dos numeros deu: %d", soma(numA, numB));
            printf("\nA subtracao dos numeros deu: %d", subtracao(numA, numB));
            printf("\nA multiplicacao dos numeros deu: %.2f", multiplica(numA, numB));
            printf("\nA divisao dos numeros deu: %.2f", divisao(numA, numB));
        }

    printf("\n Digite 1 para continuar\nVoce deseja sair? ");
    scanf("%d", &Sair);
    }

}
#endif

#ifdef ex4
int soma(int numA, int numB)
{
    return numA + numB;
}

int subtracao(int numA, int numB)
{
    return numA - numB;
}

float multiplica(int numA, int numB)
{
    return numA * numB;
}

float divisao(float numA, float numB)
{
    float resultado = numA / numB;
    return resultado;
}

int main()
{
    int Sair = 1;
    while(Sair == 1){

        int quantidade = 0;
        int escolha = 0;
        int numA, numB;

        printf("Digite o numero de vezes que voce quer fazer as operacoes: ");
        scanf("%d", &quantidade);

        for(int i = 0; i < quantidade; i++){
            printf("\nvez: %d", i + 1);
            printf("\nDigite o primeiro numero: ");
            scanf("%d", &numA);

            printf("Digite o segundo numero: ");
            scanf("%d", &numB);

            printf("\nDigite 1 para somar");
            printf("\nDigite 2 para subtrair");
            printf("\nDigite 3 para multiplicar");
            printf("\nDigite 4 para dividir");
            printf("\nescolha: ");
            scanf("%d", &escolha);

            if(escolha == 1){
                printf("\nA soma dos numeros deu: %d", soma(numA, numB));
            }

            if(escolha == 2){
                printf("\nA subtracao dos numeros deu: %d", subtracao(numA, numB));
            }

            if(escolha == 3){
                printf("\nA multiplicacao dos numeros deu: %.2f", multiplica(numA, numB));
            }

            if(escolha == 4){
                printf("\nA divisao dos numeros deu: %.2f", divisao(numA, numB));
            }
        }

    printf("\n Digite 1 para continuar\nVoce deseja sair? ");
    scanf("%d", &Sair);
    }

}
#endif

#ifdef ex5
char stringA[10];
char stringB[10];

int compara(char stringA[10], char stringB[10])
{
    int igual = 1;

    for(int i = 0; i < 10; i++){
        if(stringA[i] != stringB[i]){
            igual = 0;
        }
    }

    if(igual == 0){
        int tamanhoA = 0, tamanhoB = 0;

        for(int i = 0; i < 10; i++){
            if(stringA[i] != ""){
                tamanhoA++;
            }
        }

        printf("\ntamanho A: %d", tamanhoA);

        for(int i = 0; i < 10; i++){
            if(stringB[i] != ""){
                tamanhoB++;
            }
        }

        if(tamanhoA > tamanhoB){
            return 2;
        }

        else{
            return 3;
        }
    }

    if(igual == 1){
        return 1;
    }
}

int main()
{
    int Sair = 1;
    while(Sair == 1){

        printf("digite uma palavra de ate 10 caracteres: ");
        scanf("%s", stringA);

        printf("digite outra palavra de ate 10 caracteres: ");
        scanf("%s", stringB);

        printf("resultado da comparacao: %d", compara(stringA, stringB));

        printf("\n Digite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);

    }
}
#endif

#ifdef ex6

int somaFatorial(int num)
{
    int fatorial = 1;
    int resultado = 0;

    for(int i = num; i > 1; i--){
        fatorial = fatorial * i;
    }

    while(fatorial > 0){
        resultado += fatorial % 10;
        fatorial /= 10;
    }

    return resultado;
}

int main()
{
    int Sair = 1;
    while(Sair == 1){

        int num;

        printf("Digite um numero: ");
        scanf("%d", &num);

        printf("A soma do fatorial deu: %d", somaFatorial(num));

        printf("\nDigite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);
    }
}
#endif

#ifdef ex7

float exponencial(int base, int exp)
{
    int resultado = base;

    for(int i = 1; i < exp; i++){
        resultado *= base;
    }

    return resultado;
}

int main()
{
    int Sair = 1;
    while(Sair == 1){

        int numA = 0, numB = 0;

        printf("Digite um numero: ");
        scanf("%d", &numA);

        printf("Digite um numero: ");
        scanf("%d", &numB);

        printf("O resultado deu: %.2f", exponencial(numA, numB));

        printf("\nDigite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);
    }

}
#endif

#ifdef ex8

int verifica(int num)
{
    if(num > 0){
        return 1;
    }

    else if (num == 0){
        return -1;
    }

    else{
        return 0;
    }
}

int soma(int numA, int numB){
    int menor = 0;
    int maior = 0;
    int soma = 0;

    if(numA == numB){
        return numA;
    }

    if(numA > numB){
        menor = numB;
        maior = numA;
    }

    else{
        menor = numA;
        maior = numB;
    }

    for(int i = menor; i <= maior; i++){
        soma += i;
    }

    return soma;
}

float multiplica(int numA, int numB){
    int menor = 0;
    int maior = 0;
    float multiplicacao = 1;

    if(numA == numB){
        return numA;
    }

    if(numA > numB){
        menor = numB;
        maior = numA;
    }

    else{
        menor = numA;
        maior = numB;
    }

    for(int i = menor; i <= maior; i++){
        multiplicacao *= i;
    }

    return multiplicacao;

}

int main()
{
    int Sair = 1;
    while(Sair == 1){

        int numA = 0, numB = 0;
        int verificaNumA, verificaNumB;

        printf("Digite um numero: ");
        scanf("%d", &numA);

        printf("Digite um numero: ");
        scanf("%d", &numB);

        verificaNumA = verifica(numA);
        verificaNumB = verifica(numB);

        if(verificaNumA == 1 && verificaNumB == 1){
            printf("\nA soma dos numeros entre %d e %d eh: %d", numA, numB, soma(numA, numB));
        }

        else if (verificaNumA == 0 && verificaNumB == 0){
            printf("\nA multiplicacao dos numeros entre %d e %d eh: %.2f", numA, numB, multiplica(numA, numB));
        }

        else{
            printf("\nUm dos numeros digitados foi 0;");
        }

    printf("\n Digite 1 para continuar\nVoce deseja sair? ");
    scanf("%d", &Sair);
    }

}
#endif
