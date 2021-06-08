#include <stdio.h>
#include <stdlib.h>
#include "estruturaVetores.h"

int principal[TAM];


void limparVetor(int *vetor)
{
	for(int iCont = 0; iCont < TAM; iCont++)
		vetor[iCont] = 0;
}

void inserirElemento(void) 
{
	int op = 1;
	int posicao;
}

int criarEstruturaAux(void)
{
	limparVetor(principal);
	int posicao;
	
	printf("Digite em qual posição deseja inserir uma estrutura auxiliar:");
	scanf("%d*%c", &posicao);
	
	int tamanho;
	printf("Digite o tamanho da estrutura:");
	scanf("%d*%c", &tamanho);
	
	int auxiliar[tamanho];
	
	//principal[posicao] = auxiliar;
	
	return SUCESSO;
}