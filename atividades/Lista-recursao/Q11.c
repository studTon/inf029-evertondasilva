#include <stdio.h>
int multip_rec(int num1, int num2);
int main(void)
{
	int n1;
	printf("Digite um numero: ");
	scanf("%d", &n1);
	int n2;
	printf("Digite outro numero: ");
	scanf("%d", &n2);
	printf("Resultado: %d\n", multip_rec(n1, n2));
	return 0;
}

int multip_rec(int num1, int num2)
{
	if(num1 == 0 || num2 == 0)
		return 0;
	if(num1 == 1)
		return num2;
	return num2 + multip_rec(num1 - 1, num2);
}