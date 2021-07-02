#include <stdio.h>

int potencia(int k, int n);

int main(void)
{
	int num;
	int exp;
	printf("Digite um número::");
	scanf("%d", &num);
	printf("Digite um expoente::");
	scanf("%d", &exp);
	
	printf("Retorna: %d\n", potencia(num, exp));
	
	return 0;
}

int potencia(int k, int n)
{
	if(n < 1)
		return 1;
	else
		return n * potencia(k, n - 1);
	
}