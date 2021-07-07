#include <stdio.h>
int somatorio(int num);

int main(void)
{
	int numero;
	printf("Digite um numero qualquer: ");
	scanf("%d", &numero);
	
	printf("Somatorio: %d\n", somatorio(numero));
	
	return 0;
}

int somatorio(int num)
{
	if(num <= 1)
		return num;
	else
		return num + (somatorio(num - 1));
}