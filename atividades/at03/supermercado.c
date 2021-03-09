/*
    Autor: Everton da Silva(@studTon)

    Código feito para aplicar o conceito de modularização
*/

/*Bibliotecas*/
#include <stdio.h>
#include <time.h>
#include "estoque.h"
/*Fim das bibliotecas*/

int main()
{
    int escolha = 1;
    int input;
    while(escolha != 0)
    {
        printf("Digite a operacao que deseja realizar: ");
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
        }
        
    }
}