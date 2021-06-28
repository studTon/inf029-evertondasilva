void estocagem(void);

/*Struct dos produtos*/
typedef struct
{
    int codigo;
    char *Nome;
    int qtde;//Quantidade do produto
    float preco;
}Produto;

Produto estoqueproduto[10];
/*Fim do struct*/