#include <stdio.h>
#define QTD_NUM 2
float soma(float valores[]);

int main(int argc, char *argv[])
{
    float numeros[QTD_NUM];
    int iContador = 0;
    while(iContador < QTD_NUM)
    {
        printf("Digite o numero(indice %d): ", iContador);
        scanf("%f", &numeros[iContador]);
        iContador++;
    }
    
    float resultadoProcessado = soma(numeros);
    printf("Soma = %.2f\n", resultadoProcessado);

    return 0;
}

float soma(float valores[])
{
    float resultado = 0;
    int jContador = 0;
    while(jContador < QTD_NUM)
    {
        resultado += valores[jContador];
        jContador++;
    }
        
    return resultado;
}