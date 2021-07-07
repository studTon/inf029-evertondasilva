#include <stdio.h>
int mdc(int x, int y);

int main(void)
{
	int numX, numY;
	
	printf("Digite um número qualquer: ");
	scanf("%d", &numX);
	printf("Digite outro número qualquer: ");
	scanf("%d", &numY);
	
	int resultado = mdc(numX, numY);
	printf("MDC: %d\n", resultado);
	
	return 0;
}

int mdc(int x, int y)
{
	if(y == 0)
		return x;
	else
		return mdc(y, x%y);
}