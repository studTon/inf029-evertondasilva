#include <stdio.h>
typedef struct
{
    int valor[4];
}registro;
void Ler4numeros(int *numA, int *numB, int *numC, int *numD);

int main(void)
{
    registro Estrutura;
    Ler4numeros(&Estrutura.valor[0], &Estrutura.valor[1], &Estrutura.valor[2], &Estrutura.valor[3]);
    printf("Valores:\n%d | %d | %d | %d\n", Estrutura.valor[0], Estrutura.valor[1], Estrutura.valor[2], Estrutura.valor[3]);
    return 0;
}

void Ler4numeros(int *numA, int *numB, int *numC, int *numD)
{
    printf("Digite 4 valores:\n");
    scanf("%d %d %d %d", &*numA, &*numB, &*numC, &*numD);
}