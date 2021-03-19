#include <stdio.h>

float subtrairTresValores(float numA, float numB, float numC);

int main(void)
{
    float valorA, valorB, valorC;
    printf("Digite 3 valores:\n");
    scanf("%f %f %f", &valorA, &valorB, &valorC);
    printf("Resultado: %.2f\n", subtrairTresValores(valorA, valorB, valorC));

    return 0;
}

float subtrairTresValores(float numA, float numB, float numC)
{
    return numA - numB - numC;
}