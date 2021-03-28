#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "aluno.h"
cadastroAluno aluno[100];
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
//Geração de matrícula

int turma = 1;
void gerarMatricula(int inputIndiceAluno)
{
    int iContador = inputIndiceAluno;
    inputIndiceAluno++;
    if(inputIndiceAluno > 50)
    {
        turma++;
        inputIndiceAluno - 50;
    }
    //Decomposição do índice do aluno
    char centenaAluno = inputIndiceAluno / 100;
    char dezenaAluno = (inputIndiceAluno % 100) / 10;
    char unidadeAluno = inputIndiceAluno % 10;
    //Ano e semestre
    char ano[5] = "2021\0";
    char semestre = '1';
    //Decomposição da turma
    char dezenaTurma = turma / 10;
    char unidadeTurma = turma % 10;
    //Criação da string que representa a matrícula
    int contador = 0;
    while(aluno[iContador].matricula[contador] != '\0')
    {
        if(contador >= 0 && contador <= 3)
        {
            aluno[iContador].matricula[contador] = ano[contador];
        }
        if(contador == 4 || contador == 6 ||contador == 9)
        {
            aluno[iContador].matricula[contador] = '.';
        }
        if(contador == 5)
        {
            aluno[iContador].matricula[contador] = semestre;
        }
        if(contador == 7)
        {
            aluno[iContador].matricula[contador] = dezenaTurma;
        }
        else
            if(contador == 8)
            {
                aluno[iContador].matricula[contador] = unidadeTurma;
            }
        if(contador == 10)
        {
            aluno[iContador].matricula[contador] = centenaAluno;
        }
        else
            if(contador == 11)
            {
                aluno[iContador].matricula[contador] = dezenaAluno;
            }
            else
                if(contador == 12)
                {
                    aluno[iContador].matricula[contador] = unidadeAluno;
                }
    
    contador++;
    }
    printf("\n**CONTADOR**::%d\n", contador);
    if(contador == 13)
        aluno[iContador].matricula[contador] = '\0';

    printf("MATRÍCULA GERADA: %s", aluno[iContador].matricula);

}
//Verificações da entrada de dados do cadastro
void validarNome(char inputNome[])
{   
    
    int tamanhoInputNome = 0;
    while(inputNome[tamanhoInputNome] != '\0') tamanhoInputNome++;
    int tamanhoNomeReal = 0;
    int contador = 0;
    while(inputNome[contador] != '\0')
    {
        if(
        (inputNome[contador] >= 'a' && inputNome[contador] <= 'z')||
        (inputNome[contador] >= 'A' && inputNome[contador] <= 'Z')||
        (inputNome[contador] == ' '))
            tamanhoNomeReal++;
        contador++;
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
void cadastrarAluno()
{
    int iContador = 0;
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
    scanf("%11[^\n]%*c", &aluno[iContador].dataNasc);
    //CPF
    printf("Digite o CPF do(a) estudante(XXX.XXX.XXX-XX): ");
    scanf("%15[^\n]%*c", &aluno[iContador].cpf);
    /*Validações*/
    validarNome(aluno[iContador].nome);
    /*Detecção de SO para pausar*/
    if(SO == 1)
        system("pause");//Windows
    /**********************/
}