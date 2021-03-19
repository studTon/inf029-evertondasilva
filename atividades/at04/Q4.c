#include <stdio.h>
void Ler3numeros(int *num);

int main(void)
{
    int valores[3];
    Ler3numeros(valores);
    printf("Valores: %d | %d | %d\n", valores[0], valores[1], valores[2]);
    return 0;
}

void Ler3numeros(int *num)
{
    printf("Digite 3 valores:\n");
    scanf("%d %d %d", &*(num), &*(num + 1), &*(num + 2));
}