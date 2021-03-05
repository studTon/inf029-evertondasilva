struct produto
{
    int codigo;
    char nomeProduto[128];
    int qtde;//Quantidade de produtos
};

struct produto ProdutoEstoque;

produto Estoque(int codigo)