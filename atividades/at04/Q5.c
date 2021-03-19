#include <stdio.h>
#define MAXIMO 4
void Ler4numeros();
/*Definição da struct*/
typedef struct
{
    int valor[MAXIMO];
}registro;
registro Estrutura;
/********************/

int main(void)
{
    
    Ler4numeros();

    for (int jContador = 0; jContador < MAXIMO; jContador++)
    {
        printf("%d", Estrutura.valor[jContador]);
        if(jContador < MAXIMO - 1)
            printf(" | ");
    }
    
    return 0;
}

void Ler4numeros()
{   
    int iContador = 0;
    while (iContador < MAXIMO)
    {
        printf("Digite o valor(indice %d): ", iContador);
        scanf("%d", &Estrutura.valor[iContador]);
        iContador++;
    }
}