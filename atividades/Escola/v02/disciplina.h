#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include "utilitarios.h"
/*Registro*/
typedef struct{
    char nomeDisciplina[TAM_NOME_DISC];
    char codigo[TAM_CODIGO_DISC];
    char semestre;
    char professorDisciplina[TAM_NOME_PROF_DISC];
}cadastroDisc;

/*Funções principais*/
void menuDisc(void);
void inserirDisc(void);
void excluirDisc(void);
int excluirDiscNaLista(int indiceDisc);
void listarDisciplinas(void);
/*Funções de preenchimento dos dados da disciplina*/
void nomeDaDisciplina(void);
void semestreDaDisciplina(void);
void professorDaDisciplina(void);
/*Funções de validação*/
void gerarCodigoDaDisc(int inputIndiceDisc);
void validarNomeDisc(char inputDisciplina[]);
void validarSemestre(char inputSemestre);
void validarProfNaDisc(char nomeProfessor[]);
/***********************/
#endif