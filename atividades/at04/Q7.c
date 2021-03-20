#include <stdio.h>
#include <string.h>
#define NUM_STRINGS 3
#define TAM_STRING 16
void ler3palavras();
typedef struct
{
    char palavra[NUM_STRINGS][TAM_STRING];
}registro;
registro Estrutura;

int main(void)
{
    ler3palavras();
    int iContador = 0;
    while (iContador < NUM_STRINGS)
    {
        puts(*Estrutura.palavra[iContador]);
        iContador++;
    }
    
    return 0;
}

void ler3palavras()
{
    int jContador = 0;
    while (jContador < NUM_STRINGS)
    {
        printf("Digite a palavra(indice %d): ", jContador);
        while(getchar() != '\n' );
        gets(Estrutura.palavra[jContador][0]);
        jContador++;
    }
    
}