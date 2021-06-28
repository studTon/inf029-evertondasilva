#ifndef RELATORIOS_H
#define RELATORIOS_H
/*Registro*/
typedef struct
{
    char Nome[TAM_NoME];
    int quantDisciplinas;
}aluNoIrregular;

aluNoIrregular aluNosIrregulares[QTD_DE_ALUNoS];
/*Principais funções*/
void menuRelatorios(void);
void listarAluNosPorSexo(void);
void listarAluNosPorNome(void);
void listarAluNosPorData(void);
void listarProfessorPorSexo(void);
void listarProfessorPorNome(void);
void listarProfessorPorData(void);
void aniversariantesMes(void);
void buscarPessoas(void);
void aluNosComPoucaDisciplina(void);//AluNos matriculados em meNos de 3 disciplinas
void turmasGrandes(void);//Disciplina ultrapassa 40 vagas

/*Funções auxiliares*/
aluNoIrregular passarDadosAluNo(char Nome[], int somaDisciplinas);
void listarAluNosIrregulares(int qtdAluNos);
int verificarDisciplina(int indice);

#endif