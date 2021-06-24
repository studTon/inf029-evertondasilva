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

/*Registro*/
cadastroAluNo aluNo[QTD_DE_ALUNoS];

/*Funções principais*/
void menuAluNo(void);
void inserirAluNo(void);
void excluirAluNo(void);
int excluirAluNoNaLista(int indiceAluNo);
void listarAluNos(void);
/*Funções para inserir os dados do aluNo*/
void inserirNomeAluNo(void);
void inserirSexoAluNo(void);
void inserirDataAluNo(void);
void inserirCpfAluNo(void);
/*######################################*/
/*Funções de Validação*/
void gerarMatriculaAluNo(int inputIndiceAluNo);
void validarNomeAluNo(char inputNome[]);
void validarCPFAluNo(char cpf[]);
void validarSexoAluNo(char sexo);
void validarNascAluNo(char data[]);
/**********************/
#endif