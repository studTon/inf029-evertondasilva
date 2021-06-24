#ifndef ALUNo_H
#define ALUNo_H
#include "utilitarios.h"
/*Registro*/
typedef struct
{
    char matricula[TAM_MATRICULA_ALUNo];
    char Nome[TAM_NoME];
    char sexo;
    char dataNasc[TAM_DATA_NASC];
    char cpf[TAM_CPF];
}cadastroAluNo;
/*Variáveis para auxiliar a contagem dos aluNos*/
extern int chaveDeValidarAluNo;
extern int cadastrosComSucessoAluNo;
extern int cadastrosAluNoExcluidos;
/*Registro*/
extern cadastroAluNo aluNo[QTD_DE_ALUNoS];
/*Funções principais*/
void menuAluNo(void);
void inserirAluNo(void);
void excluirAluNo(void);
int excluirAluNoNaLista(int indiceAluNo);
void listarAluNos(void);
void procurarAtualizarAluNo(void);
/*Funções para inserir os dados do aluNo*/
void inserirNomeAluNo(void);
void inserirSexoAluNo(void);
void inserirDataAluNo(void);
void inserirCpfAluNo(void);
//Alterar dados do aluNo
void alterarDadosAluNo(int indiceAluNo);
/*######################################*/
/*Funções de Validação*/
void gerarMatriculaAluNo(int inputIndiceAluNo);
int validarNomeAluNo(char inputNome[]);
int validarCPFAluNo(char cpf[]);
int validarSexoAluNo(char sexo);
int validarNascAluNo(char data[]);
/**********************/
#endif