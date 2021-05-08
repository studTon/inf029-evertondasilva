#include <stdio.h>
#include "estruturaVetores.h"

int estrutura[TAM];

void limparVetor(int *vetor)
{
	for(int iCont = 0; iCont < TAM; iCont++)
		vetor[iCont] = 0;
}

int inserirElemento(void) 
{
	int posicao;
	printf("Digite o número da posição em que deseja colocar o elemento (Entre 1 e 10): ");
	scanf("%d", &posicao);
	while(getchar() != '\n');
	
	if(checarEstruturaAux(posicao) == SUCESSO)
	{
		return SUCESSO;
	}

	return posicao;	
}

int checarEstruturaAux(int posicao)
{
	if (posicao == 0)
	{
		return CONFIGURAR; 
	}
	else
	{
		return SUCESSO;
	}
}