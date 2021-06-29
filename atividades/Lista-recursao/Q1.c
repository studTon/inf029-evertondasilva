#include <stdio.h>
int fatorial(int n);

int main(void)
{
	int num;
	printf("Digite um valor inteiro positivo: ");
	scanf("%d", &num);
	printf("Fat: %d\n", fatorial(num));
	return 0;
}

int fatorial(int n)
{
	if(n == 0)
		return n + 1;
	else
		if(n == 1)
			return 1;
	else
		return n * (fatorial(n - 1));
}