#include <stdio.h>
#include <stdlib.h>
/*Bibliotecas dos módulos*/
#include "aluNo.h"
#include "professor.h"
#include "disciplina.h"
/*************************/

int main(int argc, char *argv[])
{

    char escolhaMenu = '1';
    while(escolhaMenu != '0')
    {
        printf("******************************\n");
        printf("*            ESCOLA          *\n");
        printf("******************************\n");

        //Menu de escolhas
        printf("\nEscolha uma opcao a seguir:\n");
        printf("0 - Sair\n");
        printf("1 - Gerenciar aluNos\n");
        printf("2 - Gerenciar professores\n");
        printf("3 - Gerenciar disciplina\n::");

        scanf("%c", &escolhaMenu);
        while(getchar() != '\n');/*Pular o char new line No input*/
        switch(escolhaMenu)
        {
            case '0':
            {
                printf("Sair...\n");
            }break;
            case '1':
            {
                //Informações sobre aluNo
                menuAluNo();
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
            default:
            {
                printf("INPUT INVALIDO\n");
            }break;
        }

    }
    
    return 0;
}