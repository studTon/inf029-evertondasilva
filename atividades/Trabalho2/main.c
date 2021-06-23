#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "NoVetores.h"

int menu();

void dobrar(int *x);

int menu()
{
    int op;
    printf("Digite as opção desejada\n");
    printf("0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Excluir\n");
    printf("3 - Listar uma No\n");
    printf("4 - Dobrar Numero\n");
    printf("5 - \n::");
    scanf("%d", &op);
    return op;
}

int main()
{
	setlocale(LC_ALL, "");
    inicializar();
    int op;
    int sair = 0;
    int ret;
    while (!sair)
    {
        op = menu();
        switch (op)
        {
        case 0:
        {
            sair = 1;
            finalizar();
            break;
        }
        case 1:
        { //inserir
            //TODO
			int posicao;
			int tamanho;
			printf("Digite a posicao que deseja criar No auxiliar: ");
			scanf("%d", &posicao);
			printf("Digite o tamanho da No que deseja criar: ");
			scanf("%d", &tamanho);
            ret = inserirNumeroNo(posicao, tamanho);
            if (ret == SUCESSO)
            {
                printf("Inserido com sucesso\n");
            }
            else if (ret == SEM_ESPACO)
            {
                printf("Sem Espaço\n");
            }
            else if (ret == SEM_No_AUXILIAR)
            {
                printf("Sem No Auxiliar\n");
            }
            break;
        }

        case 2:
        { //excluir
            int op;
			printf("Digite o que deseja fazer: \n");
			printf("0 - Voltar\n");
			printf("1 - Excluir no final da No\n");
			printf("2 - Excluir numero especifico da No\n");
			scanf("%d", &op);
			if( op == 0 )
				break;
			else
			if (op == 1)
			{
				int pos;
				printf("Digite a posição: ");
				scanf("%d", &pos);
				excluirNumeroDoFinaldaNo(pos);
			}
			else
			if (op == 2)
			{
				int num;
				int pos;
				printf("Digite a posição: ");
				scanf("%d", &pos);
				printf("Digite o número que está na No: ");
				scanf("%d", &num);
				excluirNumeroEspecificoDeNo(pos, num);
			}
            break;
        }

        case 3:
        { //recuperar dados No auxiliar
            int posicao, retorno;
            printf("Qual a No a ser listada (1..10)?");
            scanf("%d", &posicao);

            int qtd = getQuantidadeElementosNoAuxiliar(posicao);

            if (qtd == POSICAO_INVALIDA)
            {
                printf("Posição inválida\n");
            }
            else
            { // existe elemento
                int vetorAux[qtd];

                retorno = getDadosNoAuxiliar(posicao, vetorAux);

                if (retorno == SUCESSO)
                {
                    //imprimir para os dados para o usuÃ¡rio
                    int i;
                    for (i = 0; i < qtd; i++)
                    {
                        printf("%d", vetorAux[i]);
                    }
                }
            }
            break;
        }

        case 10:
        { //dobrar
            //ler um numero
            int valor;
            scanf("%i", &valor);

            //dobrar(&valor);

            //passar para um funcao (void dobrar(...)) que recebe o numero e dobra (NoVetores.c)

            printf("%i", valor);

            break;
        }

        default:
        {
            printf("opcao inválida\n");
        }
        }
    }

    return 0;
}
