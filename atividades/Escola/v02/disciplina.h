#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include "utilitarios.h"
/*Registro*/
typedef struct{
    char nomeDisciplina[TAM_NOME_DISC];
    char Codigo[TAM_CODIGO_DISC];
    char semestre;
    char professorDisciplina[TAM_NOME_PROF_DISC];
}cadastroDisc;

/*Funções principais*/
void menuDisc();
void inserirDisc();
void excluirDisc();
int excluirDiscNaLista(int indiceDisc);
void listarDisciplinas();
/*Funções de validação*/
void gerarCodigoDaDisc(int inputIndiceDisc);
void validarNomeDisc(char inputDisciplina[]);
void validarSemestre(char inputSemestre);
void validarProfNaDisc(char nomeProfessor[]);
/***********************/
#endif