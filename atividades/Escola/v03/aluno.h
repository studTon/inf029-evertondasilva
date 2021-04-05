#ifndef ALUNO_H
#define ALUNO_H
#include "utilitarios.h"
/*Registro*/
typedef struct
{
    char matricula[TAM_MATRICULA_ALUNO];
    char nome[TAM_NOME];
    char sexo;
    char dataNasc[TAM_DATA_NASC];
    char cpf[TAM_CPF];
}cadastroAluno;

/*Registro*/
cadastroAluno aluno[QTD_DE_ALUNOS];

/*Variáveis para auxiliar a contagem dos alunos*/
static int chaveDeValidarAluno;
static int cadastrosComSucessoAluno = 0;
static int cadastrosAlunoExcluidos = 0;

/*Funções principais*/
void menuAluno(void);
void inserirAluno(void);
void excluirAluno(void);
int excluirAlunoNaLista(int indiceAluno);
void listarAlunos(void);
/*Funções para inserir os dados do aluno*/
void inserirNomeAluno(void);
void inserirSexoAluno(void);
void inserirDataAluno(void);
void inserirCpfAluno(void);
/*######################################*/
/*Funções de Validação*/
void gerarMatriculaAluno(int inputIndiceAluno);
void validarNomeAluno(char inputNome[]);
void validarCPFAluno(char cpf[]);
void validarSexoAluno(char sexo);
void validarNascAluno(char data[]);
/**********************/
#endif