#include <stdio.h>
#include <stdlib.h>
/*Bibliotecas dos módulos*/
#include "aluno.h"
/*************************/

int main(int argc, char *argv[])
{
    //Menu
    char escolhaMenu = '1';
    while(escolhaMenu != '0')
    {
        printf("******************************\n");
        printf("*            ESCOLA          *\n");
        printf("******************************\n");
        printf("\nEscolha uma opcao a seguir:\n0 - Sair\n1 - Gerenciar alunos\n::");
        scanf("%1c%*c", &escolhaMenu);
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
            default:
            {
                printf("INPUT INVALIDO\n");
            }break;
        }

    }
    
    return 0;
}