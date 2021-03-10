#include <stdio.h>

/*Registro do struct*/
typedef struct
{
    int codigo;
    int qtde;//Quantidade do produto
}Produto;

Produto estoqueproduto[10];
/*Fim do struct*/

/*Função para encontrar o estoque*/
void estocagem(void)
{   
    printf("==================================\n\tEstoque\n==================================\n\n");

    int quantidadeProduto;

    /*Lista de produtos em estoque*/
    estoqueproduto[0].codigo = 1010;
    estoqueproduto[0].qtde = 95;
    estoqueproduto[1].codigo = 1011;
    estoqueproduto[1].qtde = 63;
    estoqueproduto[2].codigo = 2000;
    estoqueproduto[2].qtde = 16;
    estoqueproduto[3].codigo = 2010;
    estoqueproduto[3].qtde = 29;
    estoqueproduto[4].codigo = 2025;
    estoqueproduto[4].qtde = 51;
    estoqueproduto[5].codigo = 2080;
    estoqueproduto[5].qtde = 42;
    estoqueproduto[6].codigo = 3010;
    estoqueproduto[6].qtde = 33;
    estoqueproduto[7].codigo = 3062;
    estoqueproduto[7].qtde = 141;
    estoqueproduto[8].codigo = 3099;
    estoqueproduto[8].qtde = 12;
    estoqueproduto[9].codigo = 4125;
    estoqueproduto[9].qtde = 78;
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

/*Checagem de produtos*/
void checarProduto(int codigoProduto)
{
    /*Lista de produtos em estoque*/
    estoqueproduto[0].codigo = 1010;
    estoqueproduto[0].qtde = 95;
    estoqueproduto[1].codigo = 1011;
    estoqueproduto[1].qtde = 63;
    estoqueproduto[2].codigo = 2000;
    estoqueproduto[2].qtde = 16;
    estoqueproduto[3].codigo = 2010;
    estoqueproduto[3].qtde = 29;
    estoqueproduto[4].codigo = 2025;
    estoqueproduto[4].qtde = 51;
    estoqueproduto[5].codigo = 2080;
    estoqueproduto[5].qtde = 42;
    estoqueproduto[6].codigo = 3010;
    estoqueproduto[6].qtde = 33;
    estoqueproduto[7].codigo = 3062;
    estoqueproduto[7].qtde = 141;
    estoqueproduto[8].codigo = 3099;
    estoqueproduto[8].qtde = 12;
    estoqueproduto[9].codigo = 4125;
    estoqueproduto[9].qtde = 78;
    /*Fim da lista*/

    printf("==================================\n\tChecagem de produto\n==================================\n\n");
    
}