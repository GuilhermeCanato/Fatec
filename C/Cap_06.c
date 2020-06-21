#define ex1
#include <stdio.h>
#include <stdlib.h>

#ifdef ex1
int main()
{
    int Sair = 1;
    while(Sair == 1){

        float numA = 0, numB = 0;

        printf("Digite o primeiro numero: ");
        scanf("%f", &numA);

        printf("Digite o segundo numero: ");
        scanf("%f", &numB);

        printf("\nA soma deu: %.2f", numA + numB);

        printf("\nA subtração deu: %.2f", numA - numB);

        printf("\nA multiplicação deu: %.2f", numA * numB);

        printf("\nA divisão deu: %.2f", numA / numB);

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

        int numA = 0, numB = 0;

        printf("Digite o primeiro numero: ");
        scanf("%d", &numA);

        printf("Digite o segundo numero: ");
        scanf("%d", &numB);

        int soma, subtracao;
        float multiplicacao, divisao;

        soma = numA;
        subtracao = numA;
        multiplicacao = numA;
        divisao = numA;

        soma +=  numB;
        subtracao -= numB;
        multiplicacao *= numB;
        divisao /= numB;

        printf("\nA soma deu: %d", soma);

        printf("\nA subtração deu: %d", subtracao);

        printf("\nA multiplicação deu: %.2f", multiplicacao);

        printf("\nA divisão deu: %.2f", divisao);

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

        float numA = 0, numB = 0;

        printf("Digite o primeiro numero: ");
        scanf("%f", &numA);

        printf("Digite o segundo numero: ");
        scanf("%f", &numB);

        float soma, subtracao;
        float multiplicacao, divisao;

        soma = numA;
        subtracao = numA;
        multiplicacao = numA;
        divisao = numA;

        soma +=  numB;
        subtracao -= numB;
        multiplicacao *= numB;
        divisao /= numB;

        printf("\nA soma deu: %.2f", soma);

        printf("\nA subtração deu: %.2f", subtracao);

        printf("\nA multiplicação deu: %.2f", multiplicacao);

        printf("\nA divisão deu: %.2f", divisao);

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

        int numA = 0, numB = 0;

        printf("Digite o primeiro numero: ");
        scanf("%d", &numA);

        printf("\nDigite o segundo numero: ");
        scanf("%d", &numB);

        printf("\n\n\nAND");
        printf("\nDecimal: %d", numA & numB);
        printf("\nHexadecimal: %x", numA & numB);

        printf("\n\n\nOR");
        printf("\nDecimal: %d", numA | numB);
        printf("\nHexadecimal: %x", numA | numB);

        printf("\n\n\nOR EXCLUSIVE");
        printf("\nDecimal: %d", numA ^ numB);
        printf("\nHexadecimal: %x", numA ^ numB);

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

        int numA = 0;

        printf("Digite um numero: ");
        scanf("%d", &numA);

        printf("\nO numero eh: %d", numA);
        printf("\nMultiplicao: %d", numA << 3);
        printf("\nDivisao: %d", numA >> 3);

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

        int a = 0, b = 0;

        printf("Digite o primeiro numero: ");
        scanf("%d", &a);

        printf("\nDigite o segundo numero: ");
        scanf("%d", &b);

        printf("%d", a >= 120 && b < 240);

        printf("\n%d", a != 60 || b == 120);

        printf("\n%d", (a*25) == 100 && (b+10) >= 100);

        printf("\n%d", ((a+300)/5) >= 100 || (b-200) <= 200);

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

        int escolha = 0;
        float C = 0, F = 0, K = 0;

        printf("Digite 1 o para converter graus Celsius em Fahrenheit e Kelvin");
        printf("\nDigite 2 o para converter graus Fahrenheit e Celsius e Kelvin");
        printf("\nDigite 3 o para converter graus Kelvin e Celsius e Fahrenheit\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        if(escolha == 1){

            printf("Digite os graus em Celsius: ");
            scanf("%f", &C);

            K = C + 273;
            F = (1.8 * C) + 32;

            printf("%.2f graus Celsius sao %.2f graus Kelvin e %.2f Graus em Fahrenheit", C, K, F);
        }

        else if (escolha == 2){
            printf("Digite os graus em Fahrenheit: ");
            scanf("%f", &F);

            C = (F - 32) / 1.8;
            K = C + 273;

            printf("%.2f graus Fahrenheit sao %.2f graus Kelvin e %.2f Graus em Celsius", F, K, C);
        }

        else if (escolha == 3){
            printf("Digite os graus em Kelvin: ");
            scanf("%f", &K);

            C = K - 273;
            F = (1.8 * C) + 32;

            printf("%.2f graus Kelvin sao %.2f graus Fahrenheit e %.2f Graus em Celsius", K, F, C);
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

        int anoNasc = 0;
        int mesNasc = 0;
        int diaNasc = 0;
        int anoAtual = 0;
        int mesAtual = 0;
        int diaAtual = 0;
        int ano = 0;
        int mes = 0;
        int dia = 0;

        printf("Digite o ano do seu nascimento: ");
        scanf("%d", &anoNasc);

        printf("Digite o mes do seu nascimento: ");
        scanf("%d", &mesNasc);

        printf("Digite o dia do seu nascimento: ");
        scanf("%d", &diaNasc);

        printf("Digite o ano atual: ");
        scanf("%d", &anoAtual);

        printf("Digite o mes atual: ");
        scanf("%d", &mesAtual);

        printf("Digite o dia atual: ");
        scanf("%d", &diaAtual);

        ano = anoAtual - anoNasc;
        mes = mesAtual - mesNasc;

        if(mes < 0){
            ano -= 1;
        }

        dia = diaAtual - diaNasc;

        if (dia < 0){
            dia += 31;
            mes -= 1;
        }

        printf("\nvoce tem: %d ano(s), %d mes(es) e %d dia(s) ", ano, mes, dia);

        printf("\n Digite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);
    }
}
#endif

#ifdef ex9
int main()
{
    int Sair = 1;
    while(Sair == 1){

        int ano = 0, mes = 0, dia = 0;
        int calc1, calc2, calc3, res;

        printf("Digite um ano: ");
        scanf("%d", &ano);

        printf("Digite um mes: ");
        scanf("%d", &mes);

        printf("Digite um dia: ");
        scanf("%d", &dia);

        calc1 = ano - 1900;
        calc2 = calc1 / 4;

        if (mes == 1 || mes == 10){
           mes = 0;
        }

        else if (mes == 2 || mes == 3 || mes == 11){
            mes = 6;
        }

        else if (mes == 4 || mes == 7){
            mes = 6;
        }

        else if (mes == 5){
            mes = 1;
        }

        else if (mes == 6){
            mes = 4;
        }

        else if (mes == 8){
            mes = 2;
        }

        else if (mes == 9 || mes == 12){
            mes = 5;
        }

        calc3 = dia - 1;
        res = calc1 + calc2 + mes + calc3;
        res = (res % 7);

        if(res == 0){
            printf("\nSegunda-Feira!");
        }

        if(res == 1){
            printf("\nTerça-Feira!");
        }

        if(res == 2){
            printf("\nQuarta-Feira!");
        }

        if(res == 3){
            printf("\nQuinta-Feira!");
        }

        if(res == 4){
            printf("\nSexta-Feira!");
        }

        if(res == 5){
            printf("\nSabado!");
        }

        if(res == 6){
            printf("\nDomingo!");
        }

        printf("\n Digite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);

    }

}
#endif

#ifdef ex10
int main()
{
    int Sair = 1;
    while(Sair == 1){

        int escolha = 0;
        float Preco = 0, PrecoAjustado = 0;

        printf("Digite o preco do produto: ");
        scanf("%f", &Preco);

        printf("Digite 1 caso o produto for vendido em MG");
        printf("\nDigite 2 caso o produto for vendido em SP");
        printf("\nDigite 3 caso o produto for vendido em RJ");
        printf("\nDigite 4 caso o produto for vendido em MS\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        if(escolha == 1){
            PrecoAjustado = Preco * 1.07;
        }

        else if(escolha == 2){
            PrecoAjustado = Preco * 1.12;
        }

        else if(escolha == 3){
            PrecoAjustado = Preco * 1.15;
        }

        else if(escolha == 4){
            PrecoAjustado = Preco * 1.08;
        }

        else{
            printf("\nOpcao para o estado inválida!");
        }

        printf("O preco do produto ajustado ficara: %.2f", PrecoAjustado);

        printf("\n Digite 1 para continuar\nVoce deseja sair? ");
        scanf("%d", &Sair);
    }

}
#endif
