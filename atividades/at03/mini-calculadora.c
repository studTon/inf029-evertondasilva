#include <stdio.h>
/*Protótipos das funções das operações*/
float somar(float numA, float numB);
float subtrair(float numA, float numB);
float multiplicar(float numA, float numB);
float dividir(float numA, float numB);

/*Função da calculadora*/
void calcular(void)
{
    int a;
    int b;
    int operacao = 1;
    while(operacao != 0)
    {
        printf("==========================\n\tMini calculadora\n==========================\n");
        printf("Qual operacao deseja realizar:\n");
        printf("1 - Somar\n2 - Subtrair\n3 - Multiplicar\n4 - Dividir\n::");
        scanf("%d", &operacao);
        printf("Digite o primeiro valor: ");
        scanf("%d", &a);
        printf("Digite o segundo valor: ");
        scanf("%d", &b);
        
        printf("Resultado:");
        switch (operacao)
        {
            case 1:{
                printf("%.2f\n",somar(a, b));
            }break;
            case 2:{
                printf("%.2f\n",subtrair(a, b));
            }break;
            case 3:{
                printf("%.2f\n",multiplicar(a, b));
            }break;
            case 4:{
                printf("%.2f\n",dividir(a, b));
            }break;
            default: break;
        }

        printf("Deseja realizar outra operacao?\n0 - NAO\n1 - SIM\n::");
        scanf("%d", &operacao);
        if (operacao == 0)
        {
            break;
        }
    }
    
    
}
/*Funções das operações*/
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