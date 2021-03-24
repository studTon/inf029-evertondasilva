#include <stdio.h>
#define TAM_NOME 21
#define TAM_DATA 11//Corresponde a : "01/01/0001\0"
#define TAM_CPF 15//Corresponde a : "123.456.789-00\0"
#define NUM_BARRAS 30//Somente para finalidade decorativa
void cadastrarCliente(void);
/*Struct dos dados do cliente*/
typedef struct
{
    char nome[TAM_NOME];
    char cpf[TAM_CPF];
    char sexo;
    char dataNasc[TAM_DATA];
}cliente;

cliente perfilCliente;
/*Principal*/
int main(void)
{
    cadastrarCliente();
    /*Retorno dos dados cadastrados*/
    printf("\n===Dados cadastrados===\n\n");
    printf("Nome: %s\n", perfilCliente.nome);
    printf("CPF: %s\n", perfilCliente.cpf);
    printf("Sexo: %c\n", perfilCliente.sexo);
    printf("Data de nasc.: %s\n", perfilCliente.dataNasc);
    //Linha que determina fim do programa
    for (int contador = 0; contador < NUM_BARRAS; contador++)
        printf("=");
    printf("\n");
    return 0;
}
/*Cadastro do cliente*/
void cadastrarCliente(void)
{
    printf("Cadastro de cliente\n");
    //Nome
    printf("Nome: ");
    scanf("%[^\n]%*c", perfilCliente.nome);
    //CPF
    printf("CPF(XXX.XXX.XXX-XX): ");
    scanf("%[^\n]%*c", perfilCliente.cpf);
    //Sexo
    printf("Sexo: ");
    scanf("%c", &perfilCliente.sexo);
    //Data de nascimento
    while(getchar() != '\n' );/*Pular uma linha*/
    printf("Data de nascimento(dia/mes/ano): ");
    scanf("%[^\n]%*c", perfilCliente.dataNasc);
}