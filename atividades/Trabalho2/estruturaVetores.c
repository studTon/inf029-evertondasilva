#include <stdio.h>
#include <stdlib.h>
#include "estruturaVetores.h"

int *estrutura[TAM];

void limparVetor(int **vetor)
{
	for(int iCont = 0; iCont < TAM; iCont++)
		vetor[iCont] = 0;
}

void inserirElemento(void) 
{
	int op = 1;
	int posicao;
	do
	{
		printf("Digite o número da posição em que deseja colocar o elemento (Entre 1 e 10): ");
		scanf("%d", &posicao);
		while(getchar() != '\n');
		
		if(checarEstruturaAux(posicao) == SUCESSO)
		{
			int posAuxiliar;
			int elemento;
			printf("Digite a posição que deseja inserir o elemento na estrutura auxiliar\n::");
			scanf("%d", &posAuxiliar);
			while(getchar() != '\n');
			printf("Digite o valor do elemento::\n");
			scanf("%d", &elemento);
			while(getchar() != '\n');
			//resolver aqui
			//
			(estrutura)[posAuxiliar] = elemento;
			printf("SUCESSO\n");
		}
		else
		{
			printf("Você precisa configurar uma estrutura auxiliar na posição %d\n", posicao);
			
			int tamanho;
			printf("Qual o tamanho da estrutura auxiliar que você deseja criar?\n");
			scanf("%d", &tamanho);
			
			if(criarEstruturaAux(posicao, tamanho) == SUCESSO)
			{
				printf("Estrutura auxiliar criada com SUCESSO\n");
			}
			else
			{
				printf("Ocorreu algum erro\n");
			}
		}
		
		printf("Deseja continuar? (0 - Voltar|Outro número - Continuar)\n::");
		scanf("%d", &op);
		while(getchar() != '\n');
		system("pause");
		
	}while(op != 0);
	printf("Saindo...\n");
}

int checarEstruturaAux(int posicao)
{
	if (estrutura[posicao] == 0)
	{
		return CONFIGURAR; 
	}
	else
	{
		return SUCESSO;
	}
}

int criarEstruturaAux(int posicao, int tamanho)
{
	int *auxiliar = malloc(tamanho * sizeof(int));
	estrutura[posicao] = *auxiliar;
	return SUCESSO;
}

void exibirElementos(int posProcurada)
{
	if(checarEstruturaAux(posProcurada) == SUCESSO)
	{
		printf("Listar elementos da lista %d\n", posProcurada);
		for(int iCont = 0; iCont < sizeof(estrutura[posProcurada]; iCont++))
		{
			printf("-- %d\n", estrutura[posProcurada] + iCont);
		}
	}
	
}