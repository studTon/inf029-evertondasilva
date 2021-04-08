#include <stdio.h>
#include "relatorios.h"
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "utilitarios.h"

void menuRelatorios()
{   
    char opcao = '1';
    while(opcao != '0')
    {
        printf("******************************\n");
        printf("*         RELATORIOS         *\n");
        printf("******************************\n");
        /*menu Relatórios*/
        printf("\nEscolha uma opcao a seguir:\n");
        printf("0 - Voltar\n");
        printf("1 - Alunos ordenados por sexo\n");
        printf("2 - Alunos ordenados por nome\n");
        printf("3 - Alunos ordenados por data de nascimento\n");
        printf("4 - Professores ordenados por sexo\n");
        printf("5 - Professores ordenados por nome\n");
        printf("6 - Professores ordenados por data de nascimento\n");
        printf("7 - Aniversariantes do mes\n");
        printf("8 - Busca de pessoas\n");
        printf("9 - Alunos matriculados em menos de 3 disciplinas\n");
        printf("A - Disciplinas, por professor, com mais de 40 alunos\n::");
        
        scanf("%1c", &opcao);
        while(getchar() != '\n');/*Pular o char new line no input*/
        switch(opcao)
        {
            case '0':
            {
                printf("Voltar...");
            }break;
            case '1':
            {
                listarAlunosPorSexo();      
            }break;
            case '2':
            {
                listarAlunosPorNome();
            }break;
            case '3':
            {
                printf("%s\n", aluno[0].nome);    
            }break;
            case '4':
            {
                        
            }break;
            case '5':
            {
                       
            }break;
            case '6':
            {
                       
            }break;
            case '7':
            {
                        
            }break;
            case '8':
            {
                      
            }break;
            case '9':
            {
                       
            }break;
            case 'A':
            {
                       
            }break;
            default:
            {
                printf("INPUT INVALIDO\n");        
            }break;
                
        }
        
    }
}

void listarAlunosPorSexo()
{
    printf("***ALUNOS POR SEXO***\n");
    int iContador = 0;
    printf("FEMININO\n");
    while(iContador <= cadastrosComSucessoAluno)
    {
        if(aluno[iContador].sexo == 'F')
            printf("%s\n", aluno[iContador].nome);
        iContador++;
    }
    iContador = 0;
    printf("MASCULINO\n");
    while(iContador <= cadastrosComSucessoAluno)
    {
        if(aluno[iContador].sexo == 'M')
            printf("%s\n", aluno[iContador].nome);
        iContador++;
    }
    iContador = 0;
    printf("OUTRO\n");
    while(iContador <= cadastrosComSucessoAluno)
    {
        if(aluno[iContador].sexo == 'O')
            printf("%s\n", aluno[iContador].nome);
        iContador++;
    }
    printf("==============\nFim da lista...\n\n");
}

void listarAlunosPorNome()
{
    printf("***ALUNOS POR NOME***\n");
    //Ordenar das strings
    int iContador = 0;
    char letra = 'A';
    while(iContador <= cadastrosComSucessoAluno && letra < 'Z' + 1)
    {
        printf("***%c***\n", letra);
        while(aluno[iContador].nome[0] == letra)
        {
            printf("%s\n", aluno[iContador].nome);
            iContador++;
        }
        letra++;
        /*Caso passe para próxima letra, volta a contar do zero.
        */
        if(letra > aluno[iContador - 1].nome[0])
            iContador = 0;
    }
    printf("==============\nFim da lista...\n\n");
}