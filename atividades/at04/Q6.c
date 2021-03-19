#include <stdio.h>
#define MAXIMO 3
void ler3letras();
/*Definição de uma struct*/
typedef struct
{
    char Letra[MAXIMO];
}registro;
registro Estrutura;
/************************/

int main(void)
{
    ler3letras();
    for (int jContador = 0; jContador < MAXIMO; jContador++)
    {
        printf("%c", Estrutura.Letra[jContador]);
        if(jContador < MAXIMO - 1)
            printf(" | ");
    }

    return 0;
}

void ler3letras()
{
    int iContador = 0;
    while(iContador < MAXIMO)
    {
        printf("Digite uma letra: ");
        Estrutura.Letra[iContador] = getchar();
        /*Pular uma linha*/
        while(getchar() != '\n' );
        iContador++;
    }
}