#include <stdio.h>
int inverterNum(int numero);

int main(void)
{
	printf("Digite um número inteiro positivo: ");
	int num;
	scanf("%d", &num);
	num = inverterNum(num);
	printf("Numero invertido: %d\n", num);
	
	return 0;
}

int soma;
int resto;
int inverterNum(int numero)
{
	if(numero){
		resto = numero % 10;
		soma = soma * 10 + resto;
		inverterNum(numero/10);	
	}
else
	return soma;
return soma;
}