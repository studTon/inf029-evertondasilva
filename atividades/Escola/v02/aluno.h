#ifndef ALUNO_H
#define ALUNO_H
#include "utilitarios.h"
/*Registro*/
typedef struct
{
    char matricula[TAM_MATRICULA_ALUNO];
    char nome[TAM_NOME];
    char sexo;
    char dataNasc[DATA_NASC];
    char cpf[CPF];
}cadastroAluno;

/*Funções principais*/
void menuAluno();
void inserirAluno();
void excluirAluno();
int excluirAlunoNaLista(int indiceAluno);
void listarAlunos();
/*Funções de Validação*/
void gerarMatricula(int inputIndiceAluno);
void validarNome(char inputNome[]);
void validarCPF(char cpf[]);
void validarSexo(char sexo);
void validarNasc(char data[]);
/**********************/
#endif