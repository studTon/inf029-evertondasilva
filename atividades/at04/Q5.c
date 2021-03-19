#include <stdio.h>
typedef struct
{
    int valor[4];
}registro;
void Ler4numeros();

int main(void)
{
    registro Estrutura;
    Ler4numeros();
    printf("Valores:\n%d | %d | %d | %d\n",);
    return 0;
}

void Ler4numeros()
{
    printf("Digite 4 valores:\n");
    scanf("%d %d %d %d",);
}