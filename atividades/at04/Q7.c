#include <stdio.h>
#define NUM_STRINGS 3
#define TAM_STRING 16
void ler3palavras();
typedef struct
{
    char palavra[NUM_STRINGS][TAM_STRING];
}registro;
registro Estrutura;

/*Principal*/
int main(void)
{
    ler3palavras();
    int iContador = 0;
    printf("\n======3 Palavras======\n");//Linha para separar input do output
    while (iContador < NUM_STRINGS)
    {
        printf("%s\n", Estrutura.palavra[iContador]);
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
        gets(Estrutura.palavra[jContador]);
        jContador++;
    }
    
}