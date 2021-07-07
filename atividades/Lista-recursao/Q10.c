#include <stdio.h>
int encontrarDigito(int num, int digito);

int main(void)
{
	int numero;
	printf("Digite um numero: ");
	scanf("%d", &numero);
	
	int valor;
	printf("Digite o digito que procura: ");
	scanf("%d", &valor);
	
	printf("O digito ocorre %d vezes\n", encontrarDigito(numero, valor));
	return 0;
}

int encontrarDigito(int num, int digito)
{
	if(num == 0)
		return num;
	int procura = num % 10;
	if(procura == digito)
		return 1 + encontrarDigito(num / 10, digito);
	return encontrarDigito(num / 10, digito);
	
}