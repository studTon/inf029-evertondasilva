#ifndef ALUNo_H
#define ALUNo_H
/*Macros de tamanho de arranjos*/
#define QTD_DE_ALUNoS 100
#define CARACTER_DIA 3
#define CARACTER_MES 3
#define CARACTER_ANo 5

/*Registro*/
typedef struct
{
    char matricula[11];
    char Nome[51];
    char sexo;
    char dataNasc[11];
    char cpf[15];
}cadastroAluNo;

/*Funções principais*/
void menuAluNo();
void inserirAluNo();
void listarAluNos();
/*Funções de Validação*/
void gerarMatricula(int inputIndiceAluNo);
void validarNome(char inputNome[]);
void validarCPF(char cpf[]);
void validarSexo(char sexo);
void validarNasc(char data[]);
/**********************/

#endif
