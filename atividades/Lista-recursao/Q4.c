#include <stdio.h>
#define TAM_VETOR 10
int somarVetor(int V[], int N);

int main(void)
{
    int V[] = { 1, 2, 3, 4, 5 };
    int N = sizeof(V) / sizeof(V[0]);
    printf("%d\n", somarVetor(V, N));
    return 0;
}

int somarVetor(int V[], int N)
{
    if (N <= 0)
        return 0;
    return (somarVetor(V, N - 1) + V[N - 1]);
}		
