#include <stdio.h>
#include <stdlib.h>
/*Bibliotecas dos módulos*/
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "relatorios.h"
/*************************/

int main(int argc, char *argv[])
{

    char escolhaMenu = '1';
    while(escolhaMenu != '0')
    {
        printf("******************************\n");
        printf("*            ESCOLA          *\n");
        printf("******************************\n");

        //Menu
        printf("\nEscolha uma opcao a seguir:\n");
        printf("0 - Sair\n");
        printf("1 - Gerenciar alunos\n");
        printf("2 - Gerenciar professores\n");
        printf("3 - Gerenciar disciplina\n");
        printf("4 - Relatorios\n::");

        scanf("%1c", &escolhaMenu);
        while(getchar() != '\n');/*Pular o char new line no input*/
        switch(escolhaMenu)
        {
            case '0':
            {
                printf("Sair...\n");
            }break;
            case '1':
            {
                //Informações sobre aluno
                menuAluno();
            }break;
            case '2':
            {
                //Informações sobre professor
                menuProf();
                
            }break;
            case '3':
            {
                //Informações sobre disciplina
                menuDisc();
                
            }break;
            case '4':
            {
                //Informações sobre disciplina
                menuRelatorios();
                
            }break;
            default:
            {
                printf("INPUT INVALIDO\n");
            }break;
        }

    }
    
    return 0;
}