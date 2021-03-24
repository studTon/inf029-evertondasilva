#include <stdio.h>
#define QTD_NUM 3
void Ler3numeros(float num[]);

int main(void)
{
    float numeros[QTD_NUM];
    Ler3numeros(numeros);
    printf("\n*Numeros:");
    for(int iContador = 0; iContador < QTD_NUM; iContador++)
    {
        printf("%.2f", numeros[iContador]);
        if(iContador < QTD_NUM - 1)
            printf(" | ");
    }
    printf("\n");    
    return 0;
}

void Ler3numeros(float num[])
{
    printf("===Ler 3 numeros===\n");
    for(int jContador = 0; jContador < QTD_NUM; jContador++)
    {
        printf("Digite o numero(indice %d): ", jContador);
        scanf("%f", &num[jContador]);
    }
        
}