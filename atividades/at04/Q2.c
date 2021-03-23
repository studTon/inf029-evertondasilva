#include <stdio.h>
#define NUM_VALORES 3

float subtrairTresValores(float vetorNum[]);

int main(void)
{
    float valores[NUM_VALORES];
    printf("=======Subtracao=======\n\n");
    /*Input*/
    int iContador = 0;
    while(iContador < NUM_VALORES)
    {
        printf("Digite o valor(indice %d):", iContador);
        scanf("%f", &valores[iContador]);
        iContador++;
    }
    float resultadoProcessado = subtrairTresValores(valores);
    /*Output*/
    printf("Resultado: %.2f\n", resultadoProcessado);

    return 0;
}

float subtrairTresValores(float vetorNum[])
{
    float resultado;
    int jContador = 0;
    resultado = vetorNum[jContador];
    while(jContador++ < NUM_VALORES)
    {
        resultado -= vetorNum[jContador];
    }
    return resultado;
}