#include <stdio.h>
#include <locale.h>
#include "estruturaVetores.h"

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	//int *estrutura[QTD_POSICOES];
	
	int opcao = 0;
	do
	{
		printf("Digite a opção que deseja escolher: ");
		printf("0 - Sair\n");
		printf("1 - Inserir elemento\n");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 0: printf("Sair\n");break;
			case 1:{
				//Inserir elemento
			}break;
			case 2:{

			}break;
			case 3:{

			}break;
			case 4:{
					
			}break;
			default: printf("Inválido\n");
		}
	}while(opcao != 0);
	
	
	return 0;
}