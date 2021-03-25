#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(int argc, char *argv[])
{
    /*Detecção de SO*/
    #ifdef WIN32
        system("cls");//Windows
    #endif
    #ifdef _linux_
        system("clear");//Linux
    #endif
    /**********************/
    setlocale(LC_ALL, "Portuguese"); //Idioma para exibição
    
    //Menu
    char escolhaMenu = '1';
    while(escolhaMenu != '0')
    {
        printf("******************************\n");
        printf("*            ESCOLA          *\n");
        printf("******************************\n");
        printf("\nDigite uma das seguintes opções:\n0 - Sair\n1 - Cadastrar aluno\n2 - Listar alunos\n::");
        scanf("%c", &escolhaMenu);
        while(getchar() != '\n');/*Pular o char new line no input*/
        switch(escolhaMenu)
        {
            case '0':
            {
                printf("Sair...\n");
            }break;
            case '1':
            {
                //Cadastrar aluno
            }break;
            case '2':
            {
                //Listar alunos
            }break;
            default:
            {
                printf("INPUT INVÁLIDO\n");
            }break;
        }
        /*Detecção de SO*/
        #ifdef WIN32
            system("cls");//Windows
        #endif
        #ifdef _linux_
            system("clear");//Linux
        #endif
        /**********************/
    }
    
    return 0;
}