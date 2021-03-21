#include <stdio.h>
#define TAM_NOME 21
#define TAM_DATA 11 //Corresponde a : "01/01/0001\0"
#define TAM_CPF 15 //Corresponde a : "123.456.789-00\0"
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
    fflush(stdout);
    printf("CPF: %s\n", perfilCliente.cpf);
    printf("Sexo: %c\n", perfilCliente.sexo);
    printf("Data de nasc.: %s\n", perfilCliente.dataNasc);

    return 0;
}
/*Cadastro do cliente*/
void cadastrarCliente(void)
{
    printf("Cadastro de cliente\n");
    //Nome
    printf("Nome: ");
    gets(perfilCliente.nome);
    //CPF
    printf("CPF(XXX.XXX.XXX-XX): ");
    gets(perfilCliente.cpf);
    //Sexo
    printf("Sexo: ");
    scanf("%c", &perfilCliente.sexo);
    //Data de nascimento
    while(getchar() != '\n' );/*Pular uma linha*/
    printf("Data de nascimento(dia/mes/ano): ");
    gets(perfilCliente.dataNasc);
    fflush(stdout);
}
