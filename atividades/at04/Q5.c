#include <stdio.h>
#define QTD_NUMEROS 4
void Ler4numeros();
/*Definição da struct*/
typedef struct
{
    float numero[QTD_NUMEROS];
}registro;
registro Estrutura;
/********************/

int main(void)
{
    Ler4numeros();

    for (int jContador = 0; jContador < QTD_NUMEROS; jContador++)
    {
        printf("%.2f", Estrutura.numero[jContador]);
        if(jContador < QTD_NUMEROS - 1)
            printf(" | ");
    }
    printf("\n");
    return 0;
}

void Ler4numeros()
{   
    int iContador = 0;
    while (iContador < QTD_NUMEROS)
    {
        printf("Digite o numero(indice %d): ", iContador);
        scanf("%f", &Estrutura.numero[iContador]);
        iContador++;
    }
}