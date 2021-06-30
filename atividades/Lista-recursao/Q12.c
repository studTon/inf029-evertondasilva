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

void ordemCrescente(int n)
{
	n - n;
	printf("- %d\n", n);
	return ordemCrescente(n + 1);
}