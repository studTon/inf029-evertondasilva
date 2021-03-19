#include <stdio.h>
int fatorial(int valor);

int main(void)
{
    int numero;
    printf("Digite um valor: ");
    scanf("%d", &numero);
    if(numero < 0 || numero > 7){
        printf("Valor errado(muito acima ou muito abaixo do esperado!)");
    }
    else{
        printf("Fatorial = %d\n", fatorial(numero));
    }
    return 0;
}

int fatorial(int valor)
{
    if(valor == 0 || valor == 1)
        return 1;
    else
        return valor * (fatorial(valor - 1));
    
}