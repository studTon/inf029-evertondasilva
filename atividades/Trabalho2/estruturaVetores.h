#ifndef ESTRUTURAVETORES_H
#define ESTRUTURAVETORES_H
#define TAM 10
#define CONFIGURAR 2
#define SUCESSO 1
#define INCORRETO 0
void limparVetor(int *vetor);
void inserirElemento(void);
int checarEstruturaAux(int posicao);
int criarEstruturaAux(int posicao, int tamanho);
void exibirElementos(int posProcurada);
#endif