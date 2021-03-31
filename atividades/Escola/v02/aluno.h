#ifndef ALUNO_H
#define ALUNO_H
/*Macros de tamanho de arranjos*/
#define QTD_DE_ALUNOS 100
#define TAM_CARACTER_DIA 3
#define TAM_CARACTER_MES 3
#define TAM_CARACTER_ANO 5

/*Registro*/
typedef struct
{
    char matricula[11];
    char nome[51];
    char sexo;
    char dataNasc[11];
    char cpf[15];
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