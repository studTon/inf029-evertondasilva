#include <stdio.h>
#include "disciplina.h"
#include "aluno.h"
#include "professor.h"

int chaveValidarDisciplina;
int cadastrosComSucessoAluno;
int cadastrosComSucessoProf;
int disciplinasCadastradas;
int disciplinasExcluidas;
int naoPossivelDisc;

void menuDisc()
{
    disciplinasCadastradas = 0;
    disciplinasExcluidas = 0;
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
        printf("3 - Listar disciplinas\n");
        printf("4 - Matricular aluno em disciplina\n");
        printf("5 - Listar alunos em disciplina\n::");

        scanf("%1c", &escolha);
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
            case '4':
            {
                matricularAlunoEmDisc();           
            }break;
            case '5':
            {
                listarUmaDisciplina();
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
    gerarCodigoDaDisc(disciplinasCadastradas);
    if(!naoPossivelDisc)
    {
        //Nome da disciplina
        nomeDaDisciplina();
        //Semestre da disciplina
        semestreDaDisciplina();
        //Nome do professor na disciplinar
        professorDaDisciplina();
        /*Validações dos campos inseridos*/
        validarNomeDisc(disciplina[disciplinasCadastradas].nomeDisciplina);
        validarSemestre(disciplina[disciplinasCadastradas].semestre);
        validarProfNaDisc(disciplina[disciplinasCadastradas].professorDisciplina);

        /*Contar os cadastros com sucesso*/
        if(chaveValidarDisciplina == 3)
        {
            disciplinasCadastradas++;
            printf("\n***DISCIPLINA CADASTRADA COM SUCESSO***\n");
        }
    }     
}
/*######Funções para inserir os campos do cadastro da disciplina######*/
void nomeDaDisciplina()
{
    printf("Digite o nome da disciplina: ");
    fgets(disciplina[disciplinasCadastradas].nomeDisciplina, TAM_NOME_DISC, stdin);
    int iContador = 0;
    while(disciplina[disciplinasCadastradas].nomeDisciplina[iContador] != '\n')iContador++;
    disciplina[disciplinasCadastradas].nomeDisciplina[iContador] = '\0';
}

void semestreDaDisciplina()
{
    printf("Digite o semestre da disciplina: ");
    scanf("%c", &disciplina[disciplinasCadastradas].semestre);
    while(getchar() != '\n');
}

void professorDaDisciplina()
{
    printf("Digite o nome do professor que ensina a disciplina: ");
    scanf("%51[^\n]%*c", disciplina[disciplinasCadastradas].professorDisciplina);
}
/*###################################################################*/
void gerarCodigoDaDisc(int inputIndiceDisc)
{
    inputIndiceDisc++;//+1 para inicializar a numeração do cadastro
    if(inputIndiceDisc <= QTD_DE_DISC)
    {
        if(disciplinasExcluidas > 0)
            inputIndiceDisc += disciplinasExcluidas;
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
                disciplina[disciplinasCadastradas].codigo[iContador] = caracterCentena;
            }
            if(iContador == 1)
            {
                disciplina[disciplinasCadastradas].codigo[iContador] = caracterDezena;
            }
            if(iContador == 2)
            {
                disciplina[disciplinasCadastradas].codigo[iContador] = caracterUnidade;
            }
            iContador++;
        }
        if(iContador == 3)
            disciplina[disciplinasCadastradas].codigo[iContador] = '\0';

        //Conclusão
        printf("***Codigo da disciplina: %s***\n", disciplina[disciplinasCadastradas].codigo);   
    }
    else
    {
        printf("IMPOSSIVEL CADASTRAR MAIS DISCIPLINAS\n");
        naoPossivelDisc = 1;
    }
    
}
/*###Validações dos dados inseridos###*/
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
        chaveValidarDisciplina++;
    }
    else
    {
        printf("NOME INVALIDO PARA A DISCIPLINA\n");
    }
}
void validarSemestre(char inputSemestre)
{
    if(inputSemestre >= '1' && inputSemestre <= '8')
    {
        chaveValidarDisciplina++;
    }
    else
    {
        printf("SEMESTRE INVALIDO\n");
    }
}
void validarProfNaDisc(char nomeProfessor[])
{   
    int professorEscolhido;
    int indiceProfessor = 0;
    int achou = 0;//0 - Não achou professor| 1 - Achou professor
    while(indiceProfessor <= cadastrosComSucessoProf)
    {
        int iContador = 0;
        int caracteresIguais = 0;
        while(nomeProfessor[iContador] != '\0')
        {
            if(nomeProfessor[iContador] == professor[indiceProfessor].nome[iContador])
            {
                caracteresIguais++;
            }
            iContador++;
        }
        if(caracteresIguais == iContador - 1)
        {   
            achou = 1;
            professorEscolhido = indiceProfessor;
            break;
        }
        indiceProfessor++;
    }
    if(!achou)
    {
        chaveValidarDisciplina++;
    }
    else
    {
        printf("NOME DE PROFESSOR INVALIDO\n");
    }
}
//#######################################
void excluirDisc()
{
    printf("****************************\n");
    char nomeDisciplinaExcluir[TAM_NOME_DISC];
    printf("Digite o nome da disciplina que deseja excluir: ");
    fgets(nomeDisciplinaExcluir, TAM_NOME_DISC, stdin);
    int jContador;
    int indiceDaDisciplina = 0;
    int caracteresIguais;
    int achou = 0;//0 - Não achou|1 - Achou
    while(indiceDaDisciplina < disciplinasCadastradas)
    {
        caracteresIguais = 0;
        jContador = 0;
        while(nomeDisciplinaExcluir[jContador] == disciplina[indiceDaDisciplina].nomeDisciplina[jContador])
        {
            jContador++;
            caracteresIguais++;
        }
        if(caracteresIguais == jContador)
        {
            achou = 1;
            printf("DISCIPLINA ENCONTRADA\n");
            disciplinasCadastradas += excluirDiscNaLista(indiceDaDisciplina);
            disciplinasExcluidas += achou;
            break;
        }
        indiceDaDisciplina++;
    }
    if(achou == 0)
    {
        printf("DISCIPLINA NAO ENCONTRADA: Certifique-se do numero da disciplina\n");
    }

}
int excluirDiscNaLista(int indiceDisc)
{
    while(indiceDisc <= disciplinasCadastradas)
    {
        //Nome disciplina
        int iContador = 0;
        while(disciplina[indiceDisc].nomeDisciplina[iContador] != '\0')
        {
            disciplina[indiceDisc].nomeDisciplina[iContador] = 0;
            iContador++;
        }
        //Código da disciplina
        iContador = 0;
        while(disciplina[indiceDisc].codigo[iContador] != '\0')
        {
            disciplina[indiceDisc].codigo[iContador] = 0;
            iContador++;
        }
        disciplina[indiceDisc].semestre = 0;//Semestre
        iContador = 0;
        //Nome de professor associado
        while(disciplina[indiceDisc].professorDisciplina[iContador] != '\0')
        {
            disciplina[indiceDisc].professorDisciplina[iContador] = 0;
            iContador++;
        } 
        indiceDisc++;
    }
    
    return -1;
}
void listarDisciplinas()
{
    printf("\nLista de disciplinas cadastradas\n*******************************\n\n");
    int indiceDisciplina = 0;
    while(indiceDisciplina < disciplinasCadastradas)
    {
        printf("CODIGO: %s\n", disciplina[indiceDisciplina].codigo);
        printf("NOME DA DISCIPLINA: %s\n", disciplina[indiceDisciplina].nomeDisciplina);
        printf("SEMESTRE: %c\n", disciplina[indiceDisciplina].semestre);
        printf("PROFESSOR DA DISCIPLINA: %s\n", disciplina[indiceDisciplina].professorDisciplina);
        printf("*******************************\n");
        indiceDisciplina++;
    }
    printf("Listagem completa...\n\n");
}

void matricularAlunoEmDisc()
{
    printf("****************************\n***Matricular aluno em disciplina***\n");
    char alunoProcurado[TAM_NOME];
    char discProcurada[TAM_NOME_DISC];
    int encontrouALuno = 0;//0 - Não encontrou|1 - Encontrou
    int encontrouDisciplina = 0;//0 - Não encontrou|1 - Encontrou
    int indiceAlunoEncontrado;
    int indiceDiscEncontrada;
    int alunoAdicionado = 0;
    char escolha = '1';
    while(escolha != '0')
    {
        printf("Digite o nome do aluno procurado: ");
        scanf("%[^\n]%*c", alunoProcurado);
        int indiceAluno = 0;
        while(indiceAluno <= cadastrosComSucessoAluno)
        {
            int contadorLetra = 0;
            int contaIguais = 0;
            while(alunoProcurado[contadorLetra] == aluno[indiceAluno].nome[contadorLetra] || contaIguais != contadorLetra)
            {
                if(aluno[indiceAluno].nome[contadorLetra] == alunoProcurado[contadorLetra])
                {
                    contaIguais++;
                }
                    
                contadorLetra++;
            }
            if(contaIguais == contadorLetra)
            {
                encontrouALuno = 1;//Achou o aluno
                indiceAlunoEncontrado = indiceAluno;
                break;
            }
            indiceAluno++;
        }
        printf("Digite o nome da disciplina: ");
        scanf("%[^\n]%*c", discProcurada);
        int indiceDisc = 0;
        while(indiceDisc <= disciplinasCadastradas)
        {
            int contadorLetra = 0;
            int contaIguais = 0;
            while(discProcurada[contadorLetra] == disciplina[indiceDisc].nomeDisciplina[contadorLetra] || contaIguais != contadorLetra)
            {
                if(discProcurada[contadorLetra] == disciplina[indiceDisc].nomeDisciplina[contadorLetra])
                {
                    contaIguais++;
                }
                contadorLetra++;
            }
            if(contaIguais == contadorLetra)
            {
                encontrouDisciplina = 1;//Encontrou a disciplina
                indiceDiscEncontrada = indiceDisc;
                break;
            }
            indiceDisc++;
        }
        if(encontrouDisciplina == 1 && encontrouALuno == 1)
        {
            alunoAdicionado++;
            int iContador = 0;
            int posicaoAdicionar = alunoAdicionado - 1;
            while(aluno[indiceAlunoEncontrado].nome[iContador] != '\0')
            {
                disciplina[indiceDiscEncontrada].alunosEmDisciplina[posicaoAdicionar][iContador] = aluno[indiceAlunoEncontrado].nome[iContador];
                iContador++;
            }
            disciplina[indiceDiscEncontrada].alunosEmDisciplina[posicaoAdicionar][iContador] = '\0';
            iContador = 0;
            while(iContador < TAM_NOME)
            {
                disciplina[indiceDiscEncontrada].alunosEmDisciplina[posicaoAdicionar + 1][iContador] = 0;
                iContador++;
            }
            disciplina[indiceDiscEncontrada].alunosEmDisciplina[posicaoAdicionar + 1][iContador] = '\0';
            printf("***ALUNO CADASTRADO COM SUCESSO***\n");
        }
        else
        {
            printf("NAO FOI POSSIVEL CADASTRAR: Verifique os dados e tente novamente\n");
        }
        printf("Deseja continuar adicionando aluno em disciplina?\n0 - Voltar\nQualquer tecla - continuar\n::");
        scanf("%c", &escolha);
        while(getchar() != '\n');/*Pular o char new line no input*/
        switch(escolha)
        {
            case '0':
            {
                printf("Voltar...\n");
            }break;
            default:
            {
                printf("Continuar...\n");
            }break; 
            
        }
    }
}

void listarUmaDisciplina()
{
    char inputDisciplina[TAM_NOME_DISC];
    printf("Digite o nome da disciplina que deseja listar os dados: ");
    scanf("%[^\n]%*c", inputDisciplina);
    int indiceDisciplina = 0;
    int indiceDiscDesejada;
    int achou = 0;
    while(indiceDisciplina <= disciplinasCadastradas)
    {
        int contaIguais = 0;
        int iContador = 0;
        while(inputDisciplina[iContador] != '\0')
        {
            if(inputDisciplina[iContador] == disciplina[indiceDisciplina].nomeDisciplina[iContador])
            {
                contaIguais++;
            }
            iContador++;
        }
        if(iContador == contaIguais)
        {
            indiceDiscDesejada = indiceDisciplina;
            achou = 1;
            break;
        }
        indiceDisciplina++;
    }
    if(achou == 1)
    {
        printf("==========================\n");
        printf("NOME DA DISCIPLINA: %s\n", disciplina[indiceDiscDesejada].nomeDisciplina);
        printf("CODIGO: %s\n", disciplina[indiceDiscDesejada].codigo);
        printf("SEMESTRE: %c\n", disciplina[indiceDiscDesejada].semestre);
        printf("PROFESSOR: %s\n", disciplina[indiceDiscDesejada].professorDisciplina);
        printf("===ALUNOS NA DISCIPLINA===\n");
        int indiceAluno = 0;
        while(disciplina[indiceDiscDesejada].alunosEmDisciplina[indiceAluno][0] != 0)
        {
            printf("%d -> %s\n", indiceAluno + 1, disciplina[indiceDiscDesejada].alunosEmDisciplina[indiceAluno]);
            indiceAluno++;
        }
        printf("==========================\nFim da lista\n\n");  
    }
    else
        printf("DISCIPLINA NAO ENCONTRADA\n");
}