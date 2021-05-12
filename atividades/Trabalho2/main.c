#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "estruturaVetores.h"

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
	int *estrutura = malloc(TAM * sizeof(int));
	int op;
	do{
		system("cls");
		printf("Escolha uma das opções:\n");
		printf("0 - Sair\n");
		printf("1 - Inserir elemento em estrutura auxiliar\n::");
		scanf("%d", &op);
		while(getchar() != '\n');
		
		limparVetor(estrutura);
		switch(op)
		{
			case 0: printf("Saindo...\n");break;
			case 1: {
				inserirElemento();
			}break;
			default: printf("INPUT INVÁLIDO\n");break;
		}
	}while(op != 0);
	
	free(estrutura);
	return 0;
}