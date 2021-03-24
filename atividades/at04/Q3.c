#include <stdio.h>
int fatorial(int valor);
int validaInput = 0;/*0 - Inválido|1 - Válido*/
int main(void)
{
    int numero;
    printf("===Fatorial===\n\nDigite um valor: ");
    scanf("%d", &numero);
    numero = fatorial(numero);
    if(validaInput == 1)
    {
        printf("Fatorial = %d\n", numero);
    }
    return 0;
}

int fatorial(int valor)
{
    if(valor < 0 || valor > 12){
        printf("Valor invalido(muito acima ou muito abaixo do esperado!)\n");
    }
    else{
        validaInput++;//Validação
        int acumulador;
        int fat;
        if(valor == 0)
            fat = 1;
        else{
            fat = valor;
            while(valor > 1)
            {   
                fat *= (valor - 1);
                valor--;
            }    
        }
        
        return fat;
    }
    

}