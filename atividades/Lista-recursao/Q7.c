#include <stdio.h>
#define TAM 100
void inverter(float *vetor);

int main(void)
{
	float vetor[TAM];
	for(int iCont = 0; iCont < TAM; iCont++)
	{
		vetor[iCont] = (float)(8 + iCont)/2.0;//0 = 2.48...
	}
	
	inverter(vetor);
	
	for(int jCont = 0; jCont < TAM; jCont++)
	{
		printf("- %f\n", vetor[jCont]);
	}
	
	
	return 0;
}

void inverter(float vetor[])
{
	int aux;
	int kCont = 0;
	while(kCont < TAM - 1)
	{
		aux = vetor[kCont];
		vetor[kCont] = vetor[kCont + 1];
		vetor[kCont + 1] = aux;
		kCont++;
	}
	
}