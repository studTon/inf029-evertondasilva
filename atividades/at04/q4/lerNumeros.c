#include <stdio.h>
int Ler3numeros(void);
typedef struct
{
    int numeroA;
    int numeroB;
    int numeroC;
}numeros;



int main(void)
{
    printf("Numeros = %d, %d, %d\n", Ler3numeros());
    return 0;
}

int Ler3numeros(void)
{
    int* numA = numeros.numeroA;
    printf("Digite 3 numeros:\n");
    scanf("%d %d %d",);
    return numeros;
}