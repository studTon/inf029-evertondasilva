#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "utilitarios.h"
/*Registro*/
typedef struct
{
    char matricula[TAM_MATRICULA_PROF];
    char nome[TAM_NOME];
    char sexo;
    char dataNasc[DATA_NASC];
    char cpf[CPF];
}cadastroProfessor;

/*Funções principais*/
void menuProf();
void inserirProf();
void excluirProf();
int excluirProfNaLista(int indiceProf);
void listarProf();
/*Funções de Validação*/
void gerarMatricula(int inputIndiceProf);
void validarNome(char inputNome[]);
void validarCPF(char cpf[]);
void validarSexo(char sexo);
void validarNasc(char data[]);
/**********************/
#endif