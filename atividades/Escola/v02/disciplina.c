#include <stdio.h>
#include "disciplina.h"
/*Variáveis para auxiliar a contagem de disciplinas*/
int chaveValidarDisciplina;
int DisciplinasCadastradas = 0;
/*Registro das disciplinas*/
cadastroDisc disciplina[QTD_DE_DISC];

void menuDisc()
{
    char escolha = '1';
    while(escolha != '0')
    {
        printf("******************************\n");
        printf("*       INFO DISCIPLINA      *\n");
        printf("******************************\n");
        /*menu disciplina*/
        printf("\nEscolha uma opcao a seguir:\n");
        printf("0 - Voltar\n");
        printf("1 - Inserir disciplina\n");
        printf("2 - Excluir disciplina\n");
        printf("3 - Listar disciplinas\n::");

        scanf("%1c%*c", &escolha);
        while(getchar() != '\n');/*Pular o char new line no input*/
        switch(escolha)
        {
            case '0':
            {
                printf("Voltar...\n");
            }break;
            case '1':
            {
                inserirDisc();
            }break;
            case '2':
            {
                excluirDisc();
            }break;
            case '3':
            {
                listarDisciplinas();
            }break;
            default:
            {
                printf("INPUT INVALIDO\n");
            }break;
        }
    
    }
}

void inserirDisc()
{
    chaveValidarDisciplina = 0;
    printf("***Inserir disciplina***\n");
    //Gerar código
    gerarCodigoDaDisc(DisciplinasCadastradas + 1);
    //Nome da disciplina
    printf("Digite o nome da disciplina: ");
    scanf("%33[^\n]%*c", disciplina[DisciplinasCadastradas + 1].nomeDisciplina);
    //Semestre da disciplina
    printf("Digite o semestre da disciplina: ");
    scanf("%1%*c", &disciplina[DisciplinasCadastradas + 1].semestre);
    //Nome do professor na disciplinar
    printf("Digite o nome do professor que ensina a disciplina: ");
    scanf("%51%[^\n]%*c", &disciplina[DisciplinasCadastradas + 1].professorDisciplina);
    /*Validações dos campos inseridos*/
    validarNomeDisc(disciplina[DisciplinasCadastradas + 1].nomeDisciplina);
    validarSemestre(disciplina[DisciplinasCadastradas + 1].semestre);
    validarProfNaDisc(disciplina[DisciplinasCadastradas + 1].professorDisciplina);
    if(chaveValidarDisciplina == 4)
        DisciplinasCadastradas++;
}

void gerarCodigoDaDisc(int inputIndiceDisc)
{
    
}
void validarNomeDisc(char inputDisciplina[])
{
    
}
void validarSemestre(char inputSemestre)
{
    
}
void validarProfNaDisc(char nomeProfessor[])
{
    
}
void excluirDisc()
{
    
}
int excluirDiscNaLista(int indiceDisc)
{
    
}
void listarDisciplinas()
{
    
}