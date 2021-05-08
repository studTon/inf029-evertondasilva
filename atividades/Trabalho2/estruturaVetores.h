#ifndef ESTRUTURAVETORES_H
#define ESTRUTURAVETORES_H
#define TAM 10
#define CONFIGURAR 2
#define SUCESSO 1
#define INCORRETO 0
int estrutura[TAM];
void limparVetor(int *vetor);
int inserirElemento(void);
int checarEstruturaAux(int posicao);
#endif