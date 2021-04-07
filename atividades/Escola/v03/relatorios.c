#include <stdio.h>
#include "relatorios.h"
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"

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
        printf("7 - Aniversariantes do mês\n");
        printf("8 - Busca de pessoas\n");
        printf("9 - Alunos matriculados em menos de 3 disciplinas\n");
        printf("10 - Disciplinas, por professor, com mais de 40 alunos\n");
        
        scanf("%c", &opcao);
    }
    
    
}