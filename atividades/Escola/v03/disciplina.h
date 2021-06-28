#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include "utilitarios.h"
/*Registro*/
typedef struct{
    char NomeDisciplina[TAM_NoME_DISC];
    char codigo[TAM_CODIGO_DISC];
    char semestre;
    char professorDisciplina[TAM_NoME_PROF_DISC];
    char aluNosEmDisciplina[QTD_DE_ALUNoS][TAM_NoME];
}cadastroDisc;
/*Registro das disciplinas*/
cadastroDisc disciplina[QTD_DE_DISC];

/*Variáveis para auxiliar a contagem de disciplinas*/
extern int chaveValidarDisciplina;
extern int disciplinasCadastradas;
extern int disciplinasExcluidas;
//Verificar limite de disciplinas
extern int naoPossivelDisc;
/*Funções principais*/
void menuDisc(void);
void inserirDisc(void);
void excluirDisc(void);
int excluirDiscNaLista(int indiceDisc);
void listarDisciplinas(void);
void matricularAluNoEmDisc(void);
void listarUmaDisciplina(void);
/*Funções de preenchimento dos dados da disciplina*/
void NomeDaDisciplina(void);
void semestreDaDisciplina(void);
void professorDaDisciplina(void);
/*Funções de validação*/
void gerarCodigoDaDisc(int inputIndiceDisc);
void validarNomeDisc(char inputDisciplina[]);
void validarSemestre(char inputSemestre);
void validarProfNaDisc(char NomeProfessor[]);
/***********************/
#endif
