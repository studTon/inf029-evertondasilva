#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "aluno.h"

//menu Aluno
void menuAluno()
{
    /*Detecção de SO*/
    #if defined(WIN32)
        system("cls");//Windows
    #endif
    #if defined(_linux_)
        system("clear");//Linux
    #endif
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
        /*Detecção de SO*/
        #if defined(WIN32)
            system("cls");//Windows
        #endif
        #if defined(_linux_)
            system("clear");//Linux
        #endif
        /**********************/
    }
    
}

//Verificar entrada de dados do cadastro
void validarCadastroAluno(int indiceAluno)
{
    
}
//Cadastrar aluno
void cadastrarAluno()
{
    setlocale(LC_ALL, "Portuguese");
    printf("***Cadastrar aluno***\n");
    int iContador = 0;
    while(aluno[iContador].sexo != '\0')
    {
        iContador++;
    }
    //Matrícula        
    printf("Digite a matrícula do(a) estudante(XXXX.XXX.XXX): ");//Ano.Turma.NúmeroDoEstudante
    scanf("[%^\n]%*c", aluno[iContador].matricula);
    while(getchar() != '\n');/*Pular o char new line no input*/
    //Nome
    printf("Digite o nome do(a) estudante: ");
    scanf("[%^\n]%*c", aluno[iContador].nome);
    while(getchar() != '\n');/*Pular o char new line no input*/
    //Sexo
    printf("Digite o sexo do(a) estudante(F - Feminino|M - Masculino|O - Outro): ");
    scanf("%c", &aluno[iContador].sexo);
    while(getchar() != '\n');/*Pular o char new line no input*/
    //Data de nascimento
    printf("Digite a data de nascimento(dd/mm/aaaa): ");
    scanf("[%^\n]%*c", aluno[iContador].dataNasc);
    while(getchar() != '\n');/*Pular o char new line no input*/
    //CPF
    printf("Digite o CPF do(a) estudante(XXX.XXX.XXX-XX): ");
    scanf("[%^\n]%*c", aluno[iContador].cpf);
    while(getchar() != '\n');/*Pular o char new line no input*/
    validarCadastroAluno(iContador);
}