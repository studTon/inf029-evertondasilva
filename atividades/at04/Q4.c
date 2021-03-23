#include <stdio.h>
#define QTD_NUM 3
void Ler3numeros(int num[]);

int main(void)
{
    int numeros[QTD_NUM];
    Ler3numeros(numeros);
    printf("\n*Numeros:");
    for(int iContador = 0; iContador < QTD_NUM; iContador++)
    {
        printf("%d", numeros[iContador]);
        if(iContador < QTD_NUM - 1)
            printf(" | ");
    }
        
    return 0;
}

void Ler3numeros(int num[])
{
    printf("===Ler 3 numeros===\n");
    for(int jContador = 0; jContador < QTD_NUM; jContador++)
    {
        printf("Digite o numero(indice %d): ", jContador);
        scanf("%d", &num[jContador]);
    }
        
}