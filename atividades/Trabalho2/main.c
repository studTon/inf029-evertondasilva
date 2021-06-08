#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "estruturaVetores.h"

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
	//menu
	int op = 1;
	
	while( op > 0 )
	{
		printf("0 - Sair\n");
		printf("1 - Inserir estrutura auxiliar\n");
		printf("Digite um valor de 0 a 1\n::");
		scanf("%d*%c", &op);
		
		switch(op)
		{
			case 0: printf("Saindo...\n"); break;
			case 1: {
				printf("Inserir estrutura auxiliar\n");
				
			}
				break;
			default: printf("Entrada inválida\n"); break;		
		}
		
	}
	return 0;
}