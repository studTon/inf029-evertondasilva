#include <stdio.h>
#include "calculadora/operacoes.h"

void calcular(void)
{
    int a;
    int b;
    int operacao;
    while()
    {
        printf("==========================\n\tMini calculadora\n==========================\n");
        printf("Qual operacao deseja realizar:\n");
        printf("1 - Somar\n2 - Subtrair\n3 - Multiplicar\n4 - Dividir\n");
        scanf("%d", &operacao);
        printf("Digite o primeiro valor: ");
        scanf("%d", &a);
        printf("Digite o segundo valor: ");
        scanf("%d", &b);
        
        switch (operacao)
        {
            case 1:{
                somar(a, b);
            }break;
            case 2:{
                subtrair(a, b);
            }break;
            case 3:{
                multiplicar(a, b);
            }break;
            case 4:{
                dividir(a, b);
            }break;
            default: break;
        }

        printf("Deseja realizar outra operacao?\n0 - NAO\n1 - SIM\n::");
        scanf("%d", &operacao);
        if (operacao == 0)
        {
            break;
        }
    }
    
    
}