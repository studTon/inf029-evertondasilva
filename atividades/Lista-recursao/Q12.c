#include <stdio.h>
void ordemCrescente(int limite, int inicio);

int main(void)
{
	int num;
	int comeco;
	printf("Digite um número positivo qualquer: ");
	scanf("%d", &num);
	printf("A partir de qual número a função deve começar?::");
	scanf("%d", &comeco);
	ordemCrescente(num, comeco);
	
	return 0;
}

static int aux = 0;
/*Algum erro de lógica não está me permitindo imprimir mais valores na tela*/
void ordemCrescente(int limite, int inicio)
{
	if(inicio <= limite)
	{
		printf("-- %d\n", inicio);
		ordemCrescente(limite, inicio + 1);
	}
		
}