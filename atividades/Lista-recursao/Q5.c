/*
Crie uma função recursiva que receba um número inteiro positivo N e calcule o somatório dos números de 1 a N.
*/
#include <stdio.h>
int somaRecursiva(int num);
int main(void)
{
	int N;
	
	printf("Digite um número qualquer positivo maior que 1\n");
	scanf("%d", &N);
	
	printf("Resultado: %d\n", somaRecursiva(N));
	
}

int somaRecursiva(int num)
{
	if(num <= 1)
		return 1;
	return num + somaRecursiva(num - 1);
}