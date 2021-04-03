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
    nomeDaDisciplina();
    //Semestre da disciplina
    semestreDaDisciplina();
    //Nome do professor na disciplinar
    professorDaDisciplina();
    /*Validações dos campos inseridos*/
    validarNomeDisc(disciplina[DisciplinasCadastradas + 1].nomeDisciplina);
    validarSemestre(disciplina[DisciplinasCadastradas + 1].semestre);
    validarProfNaDisc(disciplina[DisciplinasCadastradas + 1].professorDisciplina);
    
    /*Contar os cadastros com sucesso*/
    if(chaveValidarDisciplina == 4)
        DisciplinasCadastradas++;
}

void nomeDaDisciplina()
{
    printf("Digite o nome da disciplina: ");
    fgets(disciplina[DisciplinasCadastradas + 1].nomeDisciplina, TAM_NOME_DISC, stdin);
}

void semestreDaDisciplina()
{
    printf("Digite o semestre da disciplina: ");
    scanf("%c", &disciplina[DisciplinasCadastradas + 1].semestre);
}

void professorDaDisciplina()
{
    printf("Digite o nome do professor que ensina a disciplina: ");
    fgets(disciplina[DisciplinasCadastradas + 1].professorDisciplina, TAM_NOME_PROF_DISC, stdin);
}
void gerarCodigoDaDisc(int inputIndiceDisc)
{
    //Decomposição do inteiro para char
    char caracterCentena = (inputIndiceDisc / 100) + '0';
    char caracterDezena = ((inputIndiceDisc % 100) / 10) + '0';
    char caracterUnidade = (inputIndiceDisc % 10) + '0';
    
    //Formar a string do código
    int iContador = 0;
    while(iContador < TAM_CODIGO_DISC)
    {
        if(iContador == 0)
        {
            disciplina[DisciplinasCadastradas + 1].codigo[iContador] = caracterCentena;
        }
        if(iContador == 1)
        {
            disciplina[DisciplinasCadastradas + 1].codigo[iContador] = caracterDezena;
        }
        if(iContador == 2)
        {
            disciplina[DisciplinasCadastradas + 1].codigo[iContador] = caracterUnidade;
        }
        iContador++;
    }
    if(iContador == 3)
        disciplina[DisciplinasCadastradas + 1].codigo[iContador] = '\0';
    
    //Conclusão
    printf("***Codigo da disciplina: %s***\n", disciplina[DisciplinasCadastradas + 1].codigo);
}
void validarNomeDisc(char inputDisciplina[])
{
    int iContador = 0;
    int contadorCaracteresReais = 0;
    while(inputDisciplina[iContador] != '\0')
    {
		if((inputDisciplina[iContador] >= 'a'&&inputDisciplina[iContador] <= 'z')||(inputDisciplina[iContador] >= 'A'&&inputDisciplina[iContador] <= 'Z')||inputDisciplina[iContador] == ' ')
        {
            contadorCaracteresReais++;
        }
        iContador++;
	}
    if(contadorCaracteresReais == iContador)
    {
        printf("NOME DA DISCIPLINA VALIDO\n");
        chaveValidarDisciplina++;
    }   
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
