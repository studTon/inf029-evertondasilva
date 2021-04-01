#include <stdio.h>
#include "disciplina.h"

void menuDisc()
{
    char escolha = '1';
    while(escolha != '0')
    {
        printf("******************************\n");
        printf("*       INFO DISCIPLINA      *\n");
        printf("******************************\n");
        /*menu disciplina*/
        printf("\nEscolha uma opcao a seguir:\n");
        printf("0 - Voltar\n");
        printf("1 - Inserir disciplina\n");
        printf("2 - Excluir disciplina\n");
        printf("3 - Listar disciplinas\n::");

        scanf("%1c%*c", &escolha);
        while(getchar() != '\n');/*Pular o char new line no input*/
        switch(escolha)
        {
            case '0':
            {
                printf("Voltar...\n");
            }break;
            case '1':
            {
                inserirDisc();
            }break;
            case '2':
            {
                excluirDisc();
            }break;
            case '3':
            {
                listarDisciplinas();
            }break;
            default:
            {
                printf("INPUT INVALIDO\n");
            }break;
        }
    
    }
}