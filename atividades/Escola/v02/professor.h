#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "utilitarios.h"
/*Registro*/
typedef struct
{
    char matricula[TAM_MATRICULA_PROF];
    char Nome[TAM_NoME];
    char sexo;
    char dataNasc[TAM_DATA_NASC];
    char cpf[TAM_CPF];
}cadastroProfessor;

/*Registro*/
cadastroProfessor professor[QTD_DE_PROFS];

/*Funções principais*/
void menuProf(void);
void inserirProf(void);
void excluirProf(void);
int excluirProfNaLista(int indiceProf);
void listarProf(void);
/*Funções para inserir os dados do professor*/
void inserirNomeProf(void);
void inserirSexoProf(void);
void inserirDataProf(void);
void inserirCpfProf(void);
/*Funções de Validação*/
void gerarMatriculaProf(int inputIndiceProf);
void validarNomeProf(char inputNome[]);
void validarCPFProf(char cpf[]);
void validarSexoProf(char sexo);
void validarNascProf(char data[]);
/**********************/
#endif