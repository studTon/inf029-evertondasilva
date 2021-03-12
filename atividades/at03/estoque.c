#include <stdio.h>

/*Registro do struct*/
typedef struct
{
    int codigo;
    char *nome;
    int qtde;//Quantidade do produto
    float preco;
}Produto;

Produto estoqueproduto[10];
/*Fim do struct*/

/*Função para encontrar o estoque*/
void estocagem(void)
{   
    printf("==========================\n\tEstoque\n==========================\n");
    int quantidadeProduto;

    /*Lista de produtos em estoque*/
    estoqueproduto[0].codigo = 1010;
    estoqueproduto[0].nome = "PAPEL HIGIENICO";
    estoqueproduto[0].qtde = 95;
    estoqueproduto[0].preco = 12.99;
    estoqueproduto[1].codigo = 1011;
    estoqueproduto[1].nome = "CREME DENTAL";
    estoqueproduto[1].qtde = 63;
    estoqueproduto[1].preco = 7.99;
    estoqueproduto[2].codigo = 2000;
    estoqueproduto[2].nome = "DESINFETANTE";
    estoqueproduto[2].qtde = 16;
    estoqueproduto[2].preco = 18.99;
    estoqueproduto[3].codigo = 2010;
    estoqueproduto[3].nome = "AGUA SANITARIA";
    estoqueproduto[3].qtde = 29;
    estoqueproduto[3].preco = 6.99;
    estoqueproduto[4].codigo = 2025;
    estoqueproduto[4].nome = "LIMPA VIDROS";
    estoqueproduto[4].qtde = 51;
    estoqueproduto[4].preco = 20.99;
    estoqueproduto[5].codigo = 2080;
    estoqueproduto[5].nome = "DETERGENTE";
    estoqueproduto[5].qtde = 42;
    estoqueproduto[5].preco = 2.99;
    estoqueproduto[6].codigo = 3010;
    estoqueproduto[6].nome = "FARINHA DE TRIGO";
    estoqueproduto[6].qtde = 33;
    estoqueproduto[7].codigo = 3062;
    estoqueproduto[7].nome = "ACUCAR CRISTAL";
    estoqueproduto[7].qtde = 141;
    estoqueproduto[7].preco = 1.99;
    estoqueproduto[8].codigo = 3099;
    estoqueproduto[8].nome = "CHOCOLATE EM PO";
    estoqueproduto[8].qtde = 12;
    estoqueproduto[8].preco = 26.99;
    estoqueproduto[9].codigo = 4125;
    estoqueproduto[9].nome = "FILE DE PEITO DE FRANGO";
    estoqueproduto[9].qtde = 78;
    estoqueproduto[9].preco = 11.99;
    /*Fim da lista*/

    int codigoProduto;
    printf("Digite o codigo do produto que deseja saber a quantidade: ");
    scanf("%d", &codigoProduto);
    char *nomeProduto;
    switch(codigoProduto)
    {
        case 1010:{
            quantidadeProduto = estoqueproduto[0].qtde;
            nomeProduto = estoqueproduto[0].nome;
        }break;
        case 1011:{
            quantidadeProduto = estoqueproduto[1].qtde;
            nomeProduto = estoqueproduto[1].nome;
        }break;
        case 2000:{
            quantidadeProduto = estoqueproduto[2].qtde;
            nomeProduto = estoqueproduto[2].nome;
        }break;
        case 2010:{
            quantidadeProduto = estoqueproduto[3].qtde;
            nomeProduto = estoqueproduto[3].nome;
        }break;
        case 2025:{
            quantidadeProduto = estoqueproduto[4].qtde;
            nomeProduto = estoqueproduto[4].nome;
        }break;
        case 2080:{
            quantidadeProduto = estoqueproduto[5].qtde;
            nomeProduto = estoqueproduto[5].nome;
        }break;
        case 3010:{
            quantidadeProduto = estoqueproduto[6].qtde;
            nomeProduto = estoqueproduto[6].nome;
        }break;
        case 3062:{
            quantidadeProduto = estoqueproduto[7].qtde;
            nomeProduto = estoqueproduto[7].nome;
        }break;
        case 3099:{
            quantidadeProduto = estoqueproduto[8].qtde;
            nomeProduto = estoqueproduto[8].nome;
        }break;
        case 4125:{
            quantidadeProduto = estoqueproduto[9].qtde;
            nomeProduto = estoqueproduto[9].nome;
        }break;
        default:{
            quantidadeProduto = 0;
        }break;
    }
    printf("O produto %s tem %d unidades em estoque.\n", nomeProduto, quantidadeProduto);
}
