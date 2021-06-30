#include <stdio.h>
void ordemCrescente(int n);

int main(void)
{
	int num;
	printf("Digite um número positivo qualquer: ");
	scanf("%d", &num);
	ordemCrescente(num);
	
	return 0;
}

static int aux = 0;
/*Algum erro de lógica não está me permitindo imprimir mais valores na tela*/
void ordemCrescente(int n)
{
	if(aux < n)
	{
		printf("-- %d\n", aux);
		aux++;
	}	
	else
		return;
	
	ordemCrescente(aux);
}