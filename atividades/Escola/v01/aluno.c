#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "aluno.h"
cadastroAluno aluno[200];
//menu Aluno
void menuAluno()
{
    /*Detecção de SO para SO a tela*/
    #if defined(WIN32)
        #define SO 1
    #endif
    if(SO == 1)
        system("cls");//Windows
    /**********************/

    char escolha = '1';
    while(escolha != '0')
    {
        printf("******************************\n");
        printf("*         INFO ALUNO         *\n");
        printf("******************************\n");
        printf("\nEscolha uma opção a seguir:\n0 - Voltar\n1 - Cadastrar\n2 - Listar\n::");
        scanf("%c", &escolha);
        while(getchar() != '\n');/*Pular o char new line no input*/
        switch(escolha)
        {
            case '0':
            {
                printf("Voltar...\n");
            }break;
            case '1':
            {
                cadastrarAluno();
            }break;
            case '2':
            {
                //Listar alunos cadastrados
            }break;
        }
        /*Detecção de SO para SO limpar a tela*/
        if(SO == 1)
            system("cls");//Windows
        /**********************/
    }
    
}

int turma = 1;//De 1 a 9
void gerarMatricula(int inputIndiceAluno)
{
    /*Geração da matrícula*/
    int ano = 2021;
    inputIndiceAluno++;
    if(inputIndiceAluno > 50) turma++;
    int numeroDoEstudante = inputIndiceAluno++;
    aluno[numeroDoEstudante].matricula = 2021 * 1000000 + turma * 1000 + numeroDoEstudante;    
    
    /*Conclusão*/
    printf("MATRÍCULA GERADA\n::%d\n", aluno[numeroDoEstudante].matricula);

}
//Verificações da entrada de dados do cadastro
void validarNome(char inputNome[])
{
    int tamanhoInputNome = 0;
    while(inputNome[tamanhoInputNome] != '\0') tamanhoInputNome++;
    int tamanhoNomeReal = 0;
    while(inputNome[tamanhoNomeReal] != '\0')
    {
        if(
        (inputNome[tamanhoNomeReal] >= 'a' && inputNome[tamanhoNomeReal] <= 'z')||
        (inputNome[tamanhoNomeReal] >= 'A' && inputNome[tamanhoNomeReal] <= 'Z')||
        (inputNome[tamanhoNomeReal] == ' '))
            tamanhoNomeReal++;
    } 
    if(tamanhoInputNome == tamanhoNomeReal)
        printf("NOME VÁLIDO\n");
    else
        printf("ERRO: Nome inválido\n");
}
void validarCPF(char cpf[])
{

}
void validarSexo(char sexo)
{

}
void validarNasc(char data[])
{

}
//Cadastrar aluno
int iContador = 0;
void cadastrarAluno()
{
    setlocale(LC_ALL, "Portuguese");
    printf("***Cadastrar aluno***\n");
    if(iContador > 50)
        iContador = 0;
    //Matrícula
    /*Gerar matrícula*/        
    gerarMatricula(iContador);
    //Nome
    printf("Digite o nome do(a) estudante: ");
    fgets(aluno[iContador].nome, sizeof(aluno[iContador].nome), stdin);
    /****Remover o new line*/
    int tamanhoDoInput = 0;
    while(aluno[iContador].nome[tamanhoDoInput] != '\0') tamanhoDoInput++;
    if(aluno[iContador].nome[tamanhoDoInput] == '\n')
        aluno[iContador].nome[tamanhoDoInput] = '\0';
    //Sexo
    printf("Digite o sexo do(a) estudante(F - Feminino|M - Masculino|O - Outro): ");
    scanf("%c%*c", &aluno[iContador].sexo);
    
    //Data de nascimento
    printf("Digite a data de nascimento(dd/mm/aaaa): ");
    fgets(aluno[iContador].dataNasc, 11, stdin);
    /****Remover o new line*/
    tamanhoDoInput = 0;
    while(aluno[iContador].nome[tamanhoDoInput] != '\0') tamanhoDoInput++;
    if(aluno[iContador].nome[tamanhoDoInput] == '\n')
        aluno[iContador].nome[tamanhoDoInput] = '\0';
    //CPF
    printf("Digite o CPF do(a) estudante(XXX.XXX.XXX-XX): ");
    fgets(aluno[iContador].cpf, 15, stdin);
    /****Remover o new line*/
    tamanhoDoInput = 0;
    while(aluno[iContador].nome[tamanhoDoInput] != '\0') tamanhoDoInput++;
    if(aluno[iContador].nome[tamanhoDoInput] == '\n')
        aluno[iContador].nome[tamanhoDoInput] = '\0';
    /*Validações*/
    validarNome(aluno[iContador].nome);
    /*Detecção de SO para pausar*/
    if(SO == 1)
        system("pause");//Windows
    /**********************/
}