#define ex1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef ex1
int main()
{
    int soma, count = 0;
    int num;
    float media = 0;

    while(num > 0){
        printf("digite um numero positivo: ");
        scanf("%d", &num);
        soma = soma + num;
        count++;
    }

    media = soma / count;

    printf("a media dos numeros positivos e: %.2f", media);
}
#endif

#ifdef ex2
int main()
{
    float num = 0;
    int max = 99;
    int min = 1;
    char c;

    printf("Pense em um numero entre 1 e 99: ");

    while(c != '='){

        num = (max + min) / 2;

        printf("\nO numero e maior, menor ou igual a %.1f ? ", num);
        scanf("%c", &c);

        if(c == '>'){
            min = num;
            num = (max + min) / 2;
            getchar();
        }

        else if(c == '<'){
            max = num;
            num = (max + min) / 2;
            getchar();
        }
    }

    if( c == '='){
        printf("numero escolhido: %.1f", num);
    }

}
#endif

#ifdef ex3
int main()
{
    float num = 0;
    int count = 0;
    int max = 99;
    int min = 1;
    char c;

    printf("Pense em um numero entre 1 e 99: ");

    while(c != '='){

        num = (max + min) / 2;

        printf("\nO numero e maior, menor ou igual a %.1f ? ", num);
        scanf("%c", &c);

        switch(c){
            case '>':
                {
                    min = num;
                    num = (max + min) / 2;
                    count++;
                    getchar();
                    break;
                }

            case '<':
                {
                    max = num;
                    num = (max + min) / 2;
                            count++;
                    getchar();
                    break;
                }
        }
    }

    if( c == '='){
        printf("\nNumero escolhido: %.1f", num);
        printf("\nForam necessarias %d tentativa(s)", count);
    }
}
#endif

#ifdef ex4

struct ITime
{
   int h, min, seg;
};

int main()
{
    typedef struct ITime ITime;

    ITime timeI;
    ITime timeF;

    printf("Digite a hora de inicio: ");
    scanf("%d", &timeI.h);

    printf("Digite os minutos de inicio: ");
    scanf("%d", &timeI.min);

    printf("Digite os segundos de inicio: ");
    scanf("%d", &timeI.seg);

    printf("Digite a hora do final: ");
    scanf("%d", &timeF.h);

    printf("Digite os minutos do final: ");
    scanf("%d", &timeF.min);

    printf("Digite os segundos do final: ");
    scanf("%d", &timeF.seg);

    timeF.h = timeF.h - timeI.h;
    timeF.min = timeF.min - timeI.min;
    timeF.seg = timeF.seg - timeI.seg;

    printf("\nA chamada durou %d:%d:%d", timeF.h, timeF.min, timeF.seg);

}
#endif

#ifdef ex5
int main()
{
    int numerador = 0, denominador = 0;
    float decimal = 0, resto = 0, fracionario = 0;

    printf("digite o numerador: ");
    scanf("%d", &numerador);

    while(denominador == 0){
        printf("digite o denominador: ");
        scanf("%d", &denominador);
    }

    decimal = (float)numerador / (float)denominador;
    resto = numerador % denominador;
    fracionario = resto / (float)denominador;

    printf("decimal: %f, resto: %f, fracionario: %f", decimal, resto, fracionario);

    if(fracionario <= 0.24){
        fracionario = 0;
    }

    else if (fracionario >= 0.25 && fracionario <= 0.74){
        fracionario = 0.5;
    }

    else{
        fracionario = 1;
    }

    float arrendondamento = (int)decimal + fracionario;

    printf("\nO numero arrendondado fica: %.2f", arrendondamento);
}
#endif

#ifdef ex6
int main()
{
    int Litros = 0;
    char Tipo = 0;
    float PrecoG = 3.88, PrecoA = 3.18, Desconto = 0, Total = 0;

    printf("Digite quantos litros deseja abastecer: ");
    scanf("%d", &Litros);

    printf("\nDigite G para gasolina e A para alcool");
    printf("\nDigite o tipo de Combustivel: ");
    scanf("%c", &Tipo);
    getchar();

    if(Tipo == "G" || Tipo == "g"){
        if(Litros > 20){
            Desconto = 0.94;
        }

        else{
            Desconto = 0.96;
        }

        Total = (PrecoG * Litros) * Desconto;
    }

    else{
        if(Litros > 20){
            Desconto = 0.95;
        }

        else{
            Desconto = 0.97;
        }

        Total = (PrecoA * Litros) * Desconto;
    }

    printf("O total deu: R$ %.2f", Total);

}
#endif

#ifdef ex7
int main()
{
    float Km = 0, Litros = 0, Consumo = 0;

    printf("digite a distancia percorrida em km: " );
    scanf("%f", &Km);

    printf("digite quantos litros foram consumidos: " );
    scanf("%f", &Litros);

    Consumo = Km / Litros;

    if(Consumo > 8){
        printf("Economico!");
    }

    else if(Consumo > 14){
        printf("Super economico!");
    }

    else{
        printf("Venda o carro!");
    }

}
#endif

#ifdef ex8
int main()
{
    float IMC =0, Peso = 0, Altura = 0;

    printf("digite o seu Peso: ");
    scanf("%f", &Peso);

    printf("digite a sua altura: " );
    scanf("%f", &Altura);

    IMC = Peso / (Altura * 2);

    printf("\nO seu IMC deu: %.2f", IMC);

    if(IMC < 18.5){
        printf("\nAbaixo do Peso");
    }

    if(IMC > 18.5 && IMC <= 24.9){
        printf("\nSaudavel");
    }

    if(IMC > 24.9 && IMC <= 29.9){
        printf("\nPeso em excesso");
    }

    if(IMC > 29.9 && IMC <= 34.9){
        printf("\nObesidade Grau I");
    }

    if(IMC > 34.9 && IMC <= 39.9){
        printf("\nObesidade Grau II(severa)");
    }

    if(IMC > 40){
        printf("\nObesidade Grau III(morbida)");
    }

}
#endif
