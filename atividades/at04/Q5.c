#include <stdio.h>
#define MAXIMO 4
void Ler4numeros();
/*Definição da struct*/
typedef struct
{
    int numero[MAXIMO];
}registro;
registro Estrutura;
/********************/

int main(void)
{
    
    Ler4numeros();

    for (int jContador = 0; jContador < MAXIMO; jContador++)
    {
        printf("%d", Estrutura.numero[jContador]);
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
        printf("Digite o numero(indice %d): ", iContador);
        scanf("%d", &Estrutura.numero[iContador]);
        iContador++;
    }
}