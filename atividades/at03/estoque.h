void estocagem(void);

/*Struct dos produtos*/
typedef struct
{
    int codigo;
    char *nome;
    int qtde;//Quantidade do produto
    float preco;
}Produto;

Produto estoqueproduto[10];
/*Fim do struct*/