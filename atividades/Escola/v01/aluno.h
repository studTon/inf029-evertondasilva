#ifndef ALUNO_H
#define ALUNO_H
/*Macros de tamanho de arranjos*/
#define QTD_DE_ALUNOS 100
#define CARACTER_DIA 3
#define CARACTER_MES 3
#define CARACTER_ANO 5

/*Registro*/
typedef struct
{
    char matricula[11];
    char nome[51];
    char sexo;
    char dataNasc[11];
    char cpf[15];
}cadastroAluno;

cadastroAluno aluno[QTD_DE_ALUNOS];

/*Funções*/
void menuAluno();
void inserirAluno();
void listarAlunos();
/*Funções de Validação*/
void gerarMatricula(int inputIndiceAluno);
void validarNome(char inputNome[]);
void validarCPF(char cpf[]);
void validarSexo(char sexo);
void validarNasc(char data[]);
/**********************/

#endif
