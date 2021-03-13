/*
    Autor: Everton da Silva(@studTon)

    Código feito para aplicar o conceito de modularização
*/

/*Bibliotecas*/
#include <stdio.h>
#include <time.h>
#include "estoque.h"
#include "venda.h"
#include "mini-calculadora.h"
/*Fim das bibliotecas*/

int main()
{
    int escolha = 1;
    int input;
    while(escolha != 0)
    {
        printf("==========================\n\tSupermercado\n==========================\n");
        printf("Digite a operacao que deseja realizar:\n");
        printf("0 - Sair\n1 - Estoque\n2 - Venda\n3 - Calculadora\n::");
        scanf("%d", &escolha);
        switch(escolha)
        {
            case 0:{
                printf("Sair.\n");
                break;
            }break;
            case 1:{
                estocagem();
            }break;
            case 2:{
                adicionar_produto();
            }break;
            case 3:{
                calcular();
            }
        }
        
    }
}