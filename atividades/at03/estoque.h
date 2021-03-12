/*Protótipo da função para verificar estoque*/
void estocagem(void);
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