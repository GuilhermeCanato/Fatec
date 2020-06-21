#define ex1
#include <stdio.h>
#include <stdlib.h>

#ifdef ex1
char c = '127';
short int shortInt = 32767;
long int longInt= 2147483647;
unsigned char unsignedChar = '255';
unsigned short int unsignedShortInt= 65535;
unsigned int unsignedInt= 65535;
unsigned long int unsignedLongInt= 4294967295;

int main()
{
    char negativeC = '127';
    short int negativeShortInt = -32768;
    long int negativeLongInt= -2147483648;
    unsigned char negativeUnsignedchar = '0';
    unsigned short int negativeUnsignedshortInt= 0;
    unsigned int negativeUnsignedint= 0;
    unsigned long int negativeUnsignedlongInt= 0;

    printf("\t MAIOR VALOR \n");
    printf("Char: %c \n", c);
    printf("Short int: %hd \n", shortInt);
    printf("long int: %ld \n", longInt);
    printf("unsigned char: %u \n", unsignedChar);
    printf("unsigned short int: %hu \n", unsignedShortInt);
    printf("unsigned int: %u \n", unsignedInt);
    printf("long int: %ul \n", unsignedLongInt);

    printf("\n\n\t MENOR VALOR \n");
    printf("Char: %c \n", negativeC);
    printf("short int: %hd \n", negativeShortInt);
    printf("long int: %ld \n", negativeLongInt);
    printf("unsigned char: %u \n", negativeUnsignedchar);
    printf("unsigned short int: %hu \n", negativeUnsignedshortInt);
    printf("unsigned int: %u \n", negativeUnsignedint);
    printf("long int: %ul \n", negativeUnsignedlongInt);
}
#endif

#ifdef ex2

int main()
{
    char C = ' ';
    int Int = 0;
    short int shortInt = 0;
    long int longInt = 0;
    float Float = 0;
    double Double = 0;

    printf("Digite um valor para char: ");
    scanf("%c",&C);

    printf("Digite um valor para int: ");
    scanf("%d",&Int);

    printf("Digite um valor para short int: ");
    scanf("%hd",&shortInt);

    printf("Digite um valor para long int: ");
    scanf("%ld",&longInt);

    printf("Digite um valor para float: ");
    scanf("%f",&Float);

    printf("Digite um valor para Double: ");
    scanf("%lf",&Double);

    printf("        10        20        30        40        50        60\n");
    printf("12345678901234567890123456789012345678901234567890123456789012345\n");
    printf("%5hd %19ld %19d\n", shortInt, longInt, Int);
    printf("\n %17.2f %28e %7c\n", Float, Double, C);
}
#endif
#ifdef ex3
int main()
{
    char C = ' ';
    int Int = 0;
    short int shortInt = 0;
    long int longInt = 0;
    float Float = 0;
    double Double = 0;
    unsigned char uC = ' ';
    unsigned int uInt = 0;
    unsigned long int uLongInt = 0;

    printf("Digite um valor para char: ");
    scanf("%c", &C);

    printf("Digite um valor para int: ");
    scanf("%d", &Int);

    printf("Digite um valor para short int: ");
    scanf("%hd", &shortInt);

    printf("Digite um valor para long int: ");
    scanf("%ld", &longInt);

    printf("Digite um valor para float: ");
    scanf("%f", &Float);

    printf("Digite um valor para Double: ");
    scanf("%lf", &Double);

    printf("Digite o valor para unsigned char :");
    scanf("%c", &uC);

    printf("Digite o valor para unsigned int :");
    scanf("%d", &uInt);

    printf("Digite o valor para unsigned long int:");
    scanf("%d", &uLongInt);

    printf("        10        20        30        40        50        60\n");
    printf("12345678901234567890123456789012345678901234567890123456789012345\n");
    printf("%5hd %19ld %19d\n", shortInt, longInt, Int);
    printf("%17.2f %28e %7c\n", Float, Double, C);
    printf("%10c %9ld %28d\n", uC, uInt, uLongInt);
}
#endif

#ifdef ex4
int main()
{
    int A = 0;
    int B = 0;

    printf("Digite o Valor de A: ");
    scanf("%d",&A);

    printf("Digite o Valor de B: ");
    scanf("%d",&B);

    A = A + B;
    B = A - B;
    A = A - B;

    printf("A: %d", A);
    printf("\nB: %d", B);
}

#endif // ex4

#ifdef ex5
int main()
{
    int Num = 0;
    int limMinimo = 0;

    printf("Digite um numero inteiro: ");
    scanf("%d",&Num);
    printf("\nDigite o numero limite minimo: ");
    scanf("%d",&limMinimo);

    printf("\nmenor multipo de %d maior que %d: ",Num, limMinimo);

    while(limMinimo % Num != 0){
            limMinimo++;
    }

    printf("%d", limMinimo);

}

#endif

#ifdef ex6
int main()
{
    int tempo = 0;
    int hora = 0;
    int min = 0;
    int seg = 0;

    printf("Digite o tempo em segundos: ");
    scanf("%d",&tempo);

    seg = tempo;

    hora = seg / 3600;
    seg = seg - (hora*3600);

    min = seg / 60;
    seg = seg - (min*60);

    printf("%d segundos eh igual a %dh %dmim %ds", tempo, hora, min, seg);
}
#endif

#ifdef ex7
int main()
{
    int n1, n2, n3, num = 0;

    printf("Digite um numero de 3 digitos: ");
    scanf("%d",&num);

    n1 = num % 10;
    n2 = (num % 100)/10;
    n3 = num / 100;

    printf("%d", n2);
    printf("o valor invertido fica: %d%d%d", n1, n2, n3);
}
#endif

#ifdef ex8
int main()
{
    int n100, n50, n10, n1, saldo, saldoInit = 0;

    printf("Digite um valor: ");
    scanf("%d", &saldoInit);

    saldo = saldoInit;

    printf("\n%d", saldo);

    if(saldo >= 100){
        n100 = saldo / 100;
        saldo = saldo - (n100 * 100);
    }

    else{
        n100 = 0;
    }

    if(saldo >= 50){
        n50 = saldo / 50;
        saldo = saldo - (n50 * 50);
    }

    else{
        n50 = 0;
    }

    if(saldo >= 10){
        n10 = saldo / 10;
        saldo = saldo - (n10 * 10);
    }

    else{
        n10 = 0;
    }

    n1 = saldo;

    printf("\npara decompor R$%d,00, foram precisas de %d nota(s) de 100, %d nota(s) de 50, %d nota(s) de 10 e %d nota(s) de 1", saldoInit, n100, n50, n10, n1);

}
#endif
