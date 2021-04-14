#ifndef RELATORIOS_H
#define RELATORIOS_H
/*Registro*/
typedef struct
{
    char nome[TAM_NOME];
    int quantDisciplinas;
}alunoIrregular;

alunoIrregular alunosIrregulares[QTD_DE_ALUNOS];
/*Principais funções*/
void menuRelatorios(void);
void listarAlunosPorSexo(void);
void listarAlunosPorNome(void);
void listarAlunosPorData(void);
void listarProfessorPorSexo(void);
void listarProfessorPorNome(void);
void listarProfessorPorData(void);
void aniversariantesMes(void);
void buscarPessoas(void);
void alunosComPoucaDisciplina(void);//Alunos matriculados em menos de 3 disciplinas
void turmasGrandes(void);//Disciplina ultrapassa 40 vagas

/*Funções auxiliares*/
alunoIrregular passarDadosAluno(char nome[], int somaDisciplinas);
void listarAlunosIrregulares(int qtdAlunos);
int verificarDisciplina(int indice);

#endif