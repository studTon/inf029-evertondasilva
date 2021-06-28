#include <stdio.h>
#define NUM_STRINGS 3
#define TAM_STRING 21
void ler3palavras();
typedef struct
{
    char palavra[NUM_STRINGS][TAM_STRING];
}registro;
registro No;

/*Principal*/
int main(void)
{
    ler3palavras();
    
    printf("\n======3 Palavras======\n");//Linha para separar input do output
    int iContador = 0;
    while (iContador < NUM_STRINGS)
    {
        printf("%s\n", No.palavra[iContador]);
        iContador++;
    }
    printf("\n");
    return 0;
}

void ler3palavras()
{
    int jContador = 0;
    while (jContador < NUM_STRINGS)
    {
        printf("Digite a palavra(indice %d): ", jContador);
        scanf("%[^\n]%*c", No.palavra[jContador]);

        jContador++;
    }
}