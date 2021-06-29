#include <stdio.h>
int fibonnaci(int nElementos);

int main(void)
{
	int num;
	printf("Digite quantos números deseja exibir na lista: ");
	scanf("%d", &num);
	printf("Fibonacci = %d\n", fibonnaci(num));
	return 0;
}

int fibonnaci(int nElementos)
{
	if(nElementos <= 1)
		return nElementos;
	return fibonnaci(nElementos - 1) + fibonnaci(nElementos - 2);
}