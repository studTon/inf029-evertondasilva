#include <stdio.h>
void Ler3numeros(int *numA, int *numB, int *numC);

int main(void)
{
    int valores[3];
    Ler3numeros(&valores[0], &valores[1], &valores[2]);
    printf("Valores: %d | %d | %d\n", valores[0], valores[1], valores[2]);
    return 0;
}

void Ler3numeros(int *numA, int *numB, int *numC)
{

    printf("Digite 3 valores:\n");
    scanf("%d %d %d", &*numA, &*numB, &*numC);

}