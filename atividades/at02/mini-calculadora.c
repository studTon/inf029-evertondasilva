#include <stdio.h>

//Funções para as operações da calculadora

float somar(float numA, float numB)
{
    return numA + numB;
}

float subtrair(float numA, float numB)
{
    return numA - numB;
}

float multiplicar(float numA, float numB)
{
    return numA * numB;
}

float dividir(float numA, float numB)
{
    return numA / numB;
}

//Corpo principal do programa

int main()
{
    int escolha;
    float numeroA, numeroB, resultado;

    while(escolha >= 0 && escolha <= 4)
    {
        printf("\nEscolha uma das operacoes:");
        printf("\n0 - Sair\n1 - Somar\n2 - Subtrair\n3 - Multiplicar\n4 - Dividir\n");
        printf("Sua escolha: ");
        scanf("%d", &escolha);
        if(escolha == 0)
        {
            printf("\nSair\n");
            break;
        }    

        printf("Digite o primeiro numero: ");
        scanf("%f", &numeroA);
        printf("Digite o segundo numero: ");
        scanf("%f", &numeroB);

        switch(escolha)
        {
            case 0: printf("\nSair\n"); break;
            case 1: {
                resultado = somar(numeroA, numeroB);
                printf("\nResultado: %.3f", resultado);
            }break;
            case 2: {
                resultado = subtrair(numeroA, numeroB);
                printf("\nResultado: %.3f", resultado);
            }break;
            case 3: {
                resultado = multiplicar(numeroA, numeroB);
                printf("\nResultado: %.3f", resultado);
            }break;
            case 4: {
                if(numeroB != 0)
                {
                    resultado = dividir(numeroA, numeroB);
                    printf("\nResultado: %.3f", resultado);
                }
                else
                {
                    printf("\nNao pode dividir por zero!");
                }
            }break;
            default: {
                printf("Digite uma das 5 alternativas");
                break;
            }

        }
        printf("\n\n");
    }
    

    return 0;
}