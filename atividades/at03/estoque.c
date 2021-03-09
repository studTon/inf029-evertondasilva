#include <stdio.h>

void estocagem(void)
{   
    printf("==================================\n\tEstoque\n==================================\n\n");

    int quantidadeProduto;
    typedef struct
    {
        int codigo;
        int qtde;//Quantidade do produto
    } Produto;

    Produto estoqueproduto[10];

    /*Lista de produtos em estoque*/
    estoqueproduto[0].codigo = 1010;
    estoqueproduto[0].qtde = 95;
    /*Fim da lista*/

    int codigoProduto;
    printf("Digite o codigo do produto que deseja saber a quantidade: ");
    scanf("%d", &codigoProduto);

    switch(codigoProduto)
    {
        case 1010:{
            quantidadeProduto = estoqueproduto[0].qtde;
        }break;
        default:{
            quantidadeProduto = 0;
        }
    }
    printf("O produto %d tem %d unidades em estoque.\n", codigoProduto, quantidadeProduto);
}