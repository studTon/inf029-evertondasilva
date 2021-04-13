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
/*Variáveis para auxiliar a contagem dos alunos*/
extern int chaveDeValidarAluno;
extern int cadastrosComSucessoAluno;
extern int cadastrosAlunoExcluidos;
/*Registro*/
extern cadastroAluno aluno[QTD_DE_ALUNOS];
/*Funções principais*/
void menuAluno(void);
void inserirAluno(void);
void excluirAluno(void);
int excluirAlunoNaLista(int indiceAluno);
void listarAlunos(void);
void procurarAtualizarAluno(void);
/*Funções para inserir os dados do aluno*/
void inserirNomeAluno(void);
void inserirSexoAluno(void);
void inserirDataAluno(void);
void inserirCpfAluno(void);
//Alterar dados do aluno
void alterarDadosAluno(int indiceAluno);
/*######################################*/
/*Funções de Validação*/
void gerarMatriculaAluno(int inputIndiceAluno);
int validarNomeAluno(char inputNome[]);
int validarCPFAluno(char cpf[]);
int validarSexoAluno(char sexo);
int validarNascAluno(char data[]);
/**********************/
/*Retornar cadastros realizados com sucesso*/
int retornarCadastrosAluno(int valor);
#endif