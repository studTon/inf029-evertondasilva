#include <stdio.h>
int convBin(int numero);
int main(void)
{
	int num;
	printf("Digite um valor: ");
	scanf("%d", &num);
	printf("Binario: %d\n", convBin(num));
	
	
	return 0;
}

int convBin(int numero)
{
	if(numero <= 1)
		return numero;
	else
		return 10 * convBin(numero / 2) + ( numero % 2);
}