#include <stdio.h>

float soma(float numA, float numB);

int main()
{
    float a, b;
    printf("Digite o primeiro valor: ");
    scanf("%f", &a);
    printf("Digite o segundo valor: ");
    scanf("%f", &b);
    printf("Soma = %.2f\n", soma(a, b));

    return 0;
}

float soma(float numA, float numB)
{
    return numA + numB;
}