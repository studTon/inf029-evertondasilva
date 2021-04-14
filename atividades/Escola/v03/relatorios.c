#include <stdio.h>
#include "disciplina.h"
#include "aluno.h"
#include "professor.h"
#include "relatorios.h"
#include "utilitarios.h"

int cadastrosComSucessoAluno;
int cadastrosComSucessoProf;
int disciplinasCadastradas;

cadastroAluno aluno[QTD_DE_ALUNOS];
cadastroDisc disciplina[QTD_DE_DISC];
alunoIrregular alunosIrregulares[QTD_DE_ALUNOS];

void menuRelatorios()
{    
    char opcao = '1';
    
    while(opcao != '0')
    {
        printf("******************************\n");
        printf("*         RELATORIOS         *\n");
        printf("******************************\n");
        /*menu Relatórios*/
        printf("\nEscolha uma opcao a seguir:\n");
        printf("0 - Voltar\n");
        printf("1 - Alunos ordenados por sexo\n");
        printf("2 - Alunos ordenados por nome\n");
        printf("3 - Alunos ordenados por data de nascimento\n");
        printf("4 - Professores ordenados por sexo\n");
        printf("5 - Professores ordenados por nome\n");
        printf("6 - Professores ordenados por data de nascimento\n");
        printf("7 - Aniversariantes do mes\n");
        printf("8 - Busca de pessoas\n");
        printf("9 - Alunos matriculados em menos de 3 disciplinas\n");
        printf("A - Disciplinas, por professor, com mais de 40 alunos\n::");
        
        scanf("%1c", &opcao);
        while(getchar() != '\n');/*Pular o char new line no input*/
        if(opcao == 'a')
            opcao = 'A';
        switch(opcao)
        {
            case '0':
            {
                printf("Voltar...\n");
            }break;
            case '1':
            {
                listarAlunosPorSexo();      
            }break;
            case '2':
            {
                listarAlunosPorNome();
            }break;
            case '3':
            {
                listarAlunosPorData();
            }break;
            case '4':
            {
                listarProfessorPorSexo();           
            }break;
            case '5':
            {
                listarProfessorPorNome();      
            }break;
            case '6':
            {
                listarProfessorPorData();           
            }break;
            case '7':
            {
                aniversariantesMes();        
            }break;
            case '8':
            {
                buscarPessoas();
            }break;
            case '9':
            {
                alunosComPoucaDisciplina();     
            }break;
            case 'A':
            {
                turmasGrandes();        
            }break;
            default:
            {
                printf("INPUT INVALIDO\n");        
            }break;
                
        }
        
    }
}

void listarAlunosPorSexo()
{
    printf("***ALUNOS POR SEXO***\n");
    int iContador = 0;
    printf("FEMININO\n");
    while(iContador < cadastrosComSucessoAluno)
    {
        if(aluno[iContador].sexo == 'F')
            printf("%s\n", aluno[iContador].nome);
        iContador++;
    }
    iContador = 0;
    printf("MASCULINO\n");
    while(iContador < cadastrosComSucessoAluno)
    {
        if(aluno[iContador].sexo == 'M')
            printf("%s\n", aluno[iContador].nome);
        iContador++;
    }
    iContador = 0;
    printf("OUTRO\n");
    while(iContador < cadastrosComSucessoAluno)
    {
        if(aluno[iContador].sexo == 'O')
            printf("%s\n", aluno[iContador].nome);
        iContador++;
    }
    printf("==============\nFim da lista...\n\n");
}

void listarAlunosPorNome()
{
    printf("***ALUNOS POR NOME***\n");
    //Ordenar das strings
    int iContador = 0;
    int jContador;
    int achou = 0;
    //char listaTemporaria[QTD_DE_ALUNOS][TAM_NOME];
    char letra = 'A';

    while(letra < 'Z' + 1)
    {
        iContador = 0;
        printf("[%c]\n", letra);
        while(iContador < cadastrosComSucessoAluno)
        {
            if(aluno[iContador].nome[0] == letra)
                printf("- %s\n", aluno[iContador].nome);
            iContador++;
        }
        letra++;
    }
    
    printf("==============\nFim da lista...\n\n");
}

void listarAlunosPorData()
{
    printf("***ALUNOS POR DATA DE NASCIMENTO***\n");
    typedef struct
    {
        char nome[TAM_NOME];
        int listarData[3];//|dia|mês|ano|
    }fichaTemp;
    
    fichaTemp alunoListado[QTD_DE_ALUNOS];
    int casaAlgarismo;
    int indiceCaracter;
    int compararAno;
    int compararMes;
    int compararDia;
    int iContador = 0;
    while(iContador < cadastrosComSucessoAluno)
    {
        //Copiar o nome
        indiceCaracter = 0;
        while(aluno[iContador].nome[indiceCaracter] != '\0')
        {
            alunoListado[iContador].nome[indiceCaracter] = aluno[iContador].nome[indiceCaracter];
            indiceCaracter++;
        }
        alunoListado[iContador].nome[indiceCaracter] = '\0';
        //Decompor e listar data
        indiceCaracter = 6;
        casaAlgarismo = 1000;
        compararAno = 0;
        while(aluno[iContador].dataNasc[indiceCaracter] != '\0')
        {
            compararAno += (aluno[iContador].dataNasc[indiceCaracter] - '0') * casaAlgarismo;
            casaAlgarismo /= 10;
            indiceCaracter++;
        }
        alunoListado[iContador].listarData[2] = compararAno;
        //*****************
        indiceCaracter = 3;
        casaAlgarismo = 10;
        compararMes = 0;
        while(aluno[iContador].dataNasc[indiceCaracter] != '/')
        {
            compararMes += (aluno[iContador].dataNasc[indiceCaracter] - '0') * casaAlgarismo;
            casaAlgarismo /= 10;
            indiceCaracter++;
        }
        alunoListado[iContador].listarData[1] = compararMes;
        //****************
        indiceCaracter = 0;
        casaAlgarismo = 10;
        compararDia = 0;
        while(aluno[iContador].dataNasc[indiceCaracter] != '/')
        {
            compararDia += (aluno[iContador].dataNasc[indiceCaracter] - '0') * casaAlgarismo;
            casaAlgarismo /= 10;
            indiceCaracter++;
        }
        alunoListado[iContador].listarData[0] = compararDia;
        
        iContador++;
    }
    /*Comparar data*/
    //Por dia
    int auxiliar;
    iContador = 0;
    int jContador;
    while(iContador < cadastrosComSucessoAluno)
    {
        jContador = iContador + 1;
        while(jContador < cadastrosComSucessoAluno)
        {
            if(alunoListado[iContador].listarData[0] < alunoListado[jContador].listarData[0])
            {
                //Copiar o nome******************************************************
                char copiaNomeTemp[TAM_NOME];
                indiceCaracter = 0;
                while(alunoListado[jContador].nome[indiceCaracter] != '\0')
                {
                    copiaNomeTemp[indiceCaracter] = alunoListado[jContador].nome[indiceCaracter];
                    indiceCaracter++;
                }
                copiaNomeTemp[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(alunoListado[iContador].nome[indiceCaracter] != '\0')
                {
                    alunoListado[jContador].nome[indiceCaracter] = alunoListado[iContador].nome[indiceCaracter];
                    indiceCaracter++;
                }
                alunoListado[jContador].nome[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(copiaNomeTemp[indiceCaracter] != '\0')
                {
                    alunoListado[iContador].nome[indiceCaracter] = copiaNomeTemp[indiceCaracter];
                    indiceCaracter++;
                }
                alunoListado[iContador].nome[indiceCaracter] = '\0';
                /****************************************************************************/
                auxiliar = alunoListado[iContador].listarData[0];
                alunoListado[iContador].listarData[0] = alunoListado[jContador].listarData[0];
                alunoListado[jContador].listarData[0] = auxiliar;
                auxiliar = alunoListado[iContador].listarData[1];
                alunoListado[iContador].listarData[1] = alunoListado[jContador].listarData[1];
                alunoListado[jContador].listarData[1] = auxiliar;
                auxiliar = alunoListado[iContador].listarData[2];
                alunoListado[iContador].listarData[2] = alunoListado[jContador].listarData[2];
                alunoListado[jContador].listarData[2] = auxiliar;
            }
            jContador++;
        }
        iContador++;
    }
    //Por mês
    iContador = 0;
    while(iContador < cadastrosComSucessoAluno)
    {
        jContador = iContador + 1;
        while(jContador < cadastrosComSucessoAluno)
        {
            if(alunoListado[iContador].listarData[1] < alunoListado[jContador].listarData[1])
            {
                //Copiar o nome******************************************************
                char copiaNomeTemp[TAM_NOME];
                indiceCaracter = 0;
                while(alunoListado[jContador].nome[indiceCaracter] != '\0')
                {
                    copiaNomeTemp[indiceCaracter] = alunoListado[jContador].nome[indiceCaracter];
                    indiceCaracter++;
                }
                copiaNomeTemp[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(alunoListado[iContador].nome[indiceCaracter] != '\0')
                {
                    alunoListado[jContador].nome[indiceCaracter] = alunoListado[iContador].nome[indiceCaracter];
                    indiceCaracter++;
                }
                alunoListado[jContador].nome[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(copiaNomeTemp[indiceCaracter] != '\0')
                {
                    alunoListado[iContador].nome[indiceCaracter] = copiaNomeTemp[indiceCaracter];
                    indiceCaracter++;
                }
                alunoListado[iContador].nome[indiceCaracter] = '\0';
                /****************************************************************************/
                auxiliar = alunoListado[iContador].listarData[0];
                alunoListado[iContador].listarData[0] = alunoListado[jContador].listarData[0];
                alunoListado[jContador].listarData[0] = auxiliar;
                auxiliar = alunoListado[iContador].listarData[1];
                alunoListado[iContador].listarData[1] = alunoListado[jContador].listarData[1];
                alunoListado[jContador].listarData[1] = auxiliar;
                auxiliar = alunoListado[iContador].listarData[2];
                alunoListado[iContador].listarData[2] = alunoListado[jContador].listarData[2];
                alunoListado[jContador].listarData[2] = auxiliar;
            }
            jContador++;
        }
        iContador++;
    }
    //Por ano
    iContador = 0;
    while(iContador < cadastrosComSucessoAluno)
    {
        jContador = iContador + 1;
        while(jContador < cadastrosComSucessoAluno)
        {
            if(alunoListado[iContador].listarData[2] < alunoListado[jContador].listarData[2])
            {
                //Copiar o nome******************************************************
                char copiaNomeTemp[TAM_NOME];
                indiceCaracter = 0;
                while(alunoListado[jContador].nome[indiceCaracter] != '\0')
                {
                    copiaNomeTemp[indiceCaracter] = alunoListado[jContador].nome[indiceCaracter];
                    indiceCaracter++;
                }
                copiaNomeTemp[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(alunoListado[iContador].nome[indiceCaracter] != '\0')
                {
                    alunoListado[jContador].nome[indiceCaracter] = alunoListado[iContador].nome[indiceCaracter];
                    indiceCaracter++;
                }
                alunoListado[jContador].nome[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(copiaNomeTemp[indiceCaracter] != '\0')
                {
                    alunoListado[iContador].nome[indiceCaracter] = copiaNomeTemp[indiceCaracter];
                    indiceCaracter++;
                }
                alunoListado[iContador].nome[indiceCaracter] = '\0';
                /****************************************************************************/
                auxiliar = alunoListado[iContador].listarData[0];
                alunoListado[iContador].listarData[0] = alunoListado[jContador].listarData[0];
                alunoListado[jContador].listarData[0] = auxiliar;
                auxiliar = alunoListado[iContador].listarData[1];
                alunoListado[iContador].listarData[1] = alunoListado[jContador].listarData[1];
                alunoListado[jContador].listarData[1] = auxiliar;
                auxiliar = alunoListado[iContador].listarData[2];
                alunoListado[iContador].listarData[2] = alunoListado[jContador].listarData[2];
                alunoListado[jContador].listarData[2] = auxiliar;
            }
            jContador++;
        }
        iContador++;
    }
    
    for(iContador = 0; iContador < cadastrosComSucessoAluno; iContador++)
    {
        printf("- %s : %d/%d/%d\n", alunoListado[iContador].nome, alunoListado[iContador].listarData[0], alunoListado[iContador].listarData[1], alunoListado[iContador].listarData[2]);
    }
    printf("==============\nFim da lista...\n\n");
}
void listarProfessorPorSexo()
{
   printf("***PROFESSORES POR SEXO***\n");
    int iContador = 0;
    printf("FEMININO\n");
    while(iContador < cadastrosComSucessoProf)
    {
        if(professor[iContador].sexo == 'F')
            printf("%s\n", professor[iContador].nome);
        iContador++;
    }
    iContador = 0;
    printf("MASCULINO\n");
    while(iContador < cadastrosComSucessoProf)
    {
        if(professor[iContador].sexo == 'M')
            printf("%s\n", professor[iContador].nome);
        iContador++;
    }
    iContador = 0;
    printf("OUTRO\n");
    while(iContador < cadastrosComSucessoProf)
    {
        if(professor[iContador].sexo == 'O')
            printf("%s\n", professor[iContador].nome);
        iContador++;
    }
    printf("==============\nFim da lista...\n\n"); 
}
void listarProfessorPorNome()
{
    printf("***PROFESSORES POR NOME***\n");
    //Ordenar das strings
    int iContador = 0;
    int jContador;
    int achou = 0;
    //char listaTemporaria[QTD_DE_PROFS][TAM_NOME];
    char letra = 'A';

    while(letra < 'Z' + 1)
    {
        iContador = 0;
        printf("[%c]\n", letra);
        while(iContador < cadastrosComSucessoProf)
        {
            if(professor[iContador].nome[0] == letra)
                printf("- %s\n", professor[iContador].nome);
            iContador++;
        }
        letra++;
    }
    
    printf("==============\nFim da lista...\n\n");
}
void listarProfessorPorData()
{
    printf("***PROFESSORES POR DATA DE NASCIMENTO***\n");
    int casaAlgarismo;
    int indiceCaracter;
    int compararAno;
    int compararMes;
    int compararDia;
    
    int iContador = 0;
    typedef struct
    {
        char nome[TAM_NOME];
        int listarData[3];//|dia|mês|ano|
    }fichaTemp;
    
    fichaTemp professorListado[QTD_DE_PROFS];
    while(iContador < cadastrosComSucessoProf)
    {
        //Copiar o nome
        indiceCaracter = 0;
        while(professor[iContador].nome[indiceCaracter] != '\0')
        {
            professorListado[iContador].nome[indiceCaracter] = professor[iContador].nome[indiceCaracter];
            indiceCaracter++;
        }
        professorListado[iContador].nome[indiceCaracter] = '\0';
        //Decompor e listar data
        indiceCaracter = 6;
        casaAlgarismo = 1000;
        compararAno = 0;
        while(professor[iContador].dataNasc[indiceCaracter] != '\0')
        {
            compararAno += (professor[iContador].dataNasc[indiceCaracter] - '0') * casaAlgarismo;
            casaAlgarismo /= 10;
            indiceCaracter++;
        }
        professorListado[iContador].listarData[2] = compararAno;
        //*****************
        indiceCaracter = 3;
        casaAlgarismo = 10;
        compararMes = 0;
        while(professor[iContador].dataNasc[indiceCaracter] != '/')
        {
            compararMes += (professor[iContador].dataNasc[indiceCaracter] - '0') * casaAlgarismo;
            compararMes /= 10;
            indiceCaracter++;
        }
        professorListado[iContador].listarData[1] = compararMes;
        //****************
        indiceCaracter = 0;
        casaAlgarismo = 10;
        compararDia = 0;
        while(professor[iContador].dataNasc[indiceCaracter] != '/')
        {
            compararDia += (professor[iContador].dataNasc[indiceCaracter] - '0') * casaAlgarismo;
            compararDia /= 10;
            indiceCaracter++;
        }
        professorListado[iContador].listarData[0] = compararDia;
        
        iContador++;
    }
    /*Comparar data*/
    //Por dia
    int auxiliar;
    iContador = 0;
    int jContador;
    while(iContador < cadastrosComSucessoProf)
    {
        jContador = iContador + 1;
        while(jContador < cadastrosComSucessoProf)
        {
            if(professorListado[iContador].listarData[0] < professorListado[jContador].listarData[0])
            {
                //Copiar o nome******************************************************
                char copiaNomeTemp[TAM_NOME];
                indiceCaracter = 0;
                while(professorListado[jContador].nome[indiceCaracter] != '\0')
                {
                    copiaNomeTemp[indiceCaracter] = professorListado[jContador].nome[indiceCaracter];
                    indiceCaracter++;
                }
                copiaNomeTemp[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(professorListado[iContador].nome[indiceCaracter] != '\0')
                {
                    professorListado[jContador].nome[indiceCaracter] = professorListado[iContador].nome[indiceCaracter];
                    indiceCaracter++;
                }
                professorListado[jContador].nome[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(copiaNomeTemp[indiceCaracter] != '\0')
                {
                    professorListado[iContador].nome[indiceCaracter] = copiaNomeTemp[indiceCaracter];
                    indiceCaracter++;
                }
                professorListado[iContador].nome[indiceCaracter] = '\0';
                /****************************************************************************/
                professorListado[iContador].nome[indiceCaracter] = '\0';
                auxiliar = professorListado[iContador].listarData[0];
                professorListado[iContador].listarData[0] = professorListado[jContador].listarData[0];
                professorListado[jContador].listarData[0] = auxiliar;
                auxiliar = professorListado[iContador].listarData[1];
                professorListado[iContador].listarData[1] = professorListado[jContador].listarData[1];
                professorListado[jContador].listarData[1] = auxiliar;
                auxiliar = professorListado[iContador].listarData[2];
                professorListado[iContador].listarData[2] = professorListado[jContador].listarData[2];
                professorListado[jContador].listarData[2] = auxiliar;
            }
            jContador++;
        }
        iContador++;
    }
    //Por mês
    iContador = 0;
    while(iContador < cadastrosComSucessoProf)
    {
        jContador = iContador + 1;
        while(jContador < cadastrosComSucessoProf)
        {
            if(professorListado[iContador].listarData[1] < professorListado[jContador].listarData[1])
            {
                //Copiar o nome******************************************************
                char copiaNomeTemp[TAM_NOME];
                indiceCaracter = 0;
                while(professorListado[jContador].nome[indiceCaracter] != '\0')
                {
                    copiaNomeTemp[indiceCaracter] = professorListado[jContador].nome[indiceCaracter];
                    indiceCaracter++;
                }
                copiaNomeTemp[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(professorListado[iContador].nome[indiceCaracter] != '\0')
                {
                    professorListado[jContador].nome[indiceCaracter] = professorListado[iContador].nome[indiceCaracter];
                    indiceCaracter++;
                }
                professorListado[jContador].nome[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(copiaNomeTemp[indiceCaracter] != '\0')
                {
                    professorListado[iContador].nome[indiceCaracter] = copiaNomeTemp[indiceCaracter];
                    indiceCaracter++;
                }
                professorListado[iContador].nome[indiceCaracter] = '\0';
                /****************************************************************************/
                professorListado[iContador].nome[indiceCaracter] = '\0';
                auxiliar = professorListado[iContador].listarData[0];
                professorListado[iContador].listarData[0] = professorListado[jContador].listarData[0];
                professorListado[jContador].listarData[0] = auxiliar;
                auxiliar = professorListado[iContador].listarData[1];
                professorListado[iContador].listarData[1] = professorListado[jContador].listarData[1];
                professorListado[jContador].listarData[1] = auxiliar;
                auxiliar = professorListado[iContador].listarData[2];
                professorListado[iContador].listarData[2] = professorListado[jContador].listarData[2];
                professorListado[jContador].listarData[2] = auxiliar;
            }
            jContador++;
        }
        iContador++;
    }
    //Por ano
    iContador = 0;
    while(iContador < cadastrosComSucessoProf)
    {
        jContador = iContador + 1;
        while(jContador < cadastrosComSucessoProf)
        {
            if(professorListado[iContador].listarData[2] < professorListado[jContador].listarData[2])
            {
                //Copiar o nome******************************************************
                char copiaNomeTemp[TAM_NOME];
                indiceCaracter = 0;
                while(professorListado[jContador].nome[indiceCaracter] != '\0')
                {
                    copiaNomeTemp[indiceCaracter] = professorListado[jContador].nome[indiceCaracter];
                    indiceCaracter++;
                }
                copiaNomeTemp[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(professorListado[iContador].nome[indiceCaracter] != '\0')
                {
                    professorListado[jContador].nome[indiceCaracter] = professorListado[iContador].nome[indiceCaracter];
                    indiceCaracter++;
                }
                professorListado[jContador].nome[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(copiaNomeTemp[indiceCaracter] != '\0')
                {
                    professorListado[iContador].nome[indiceCaracter] = copiaNomeTemp[indiceCaracter];
                    indiceCaracter++;
                }
                professorListado[iContador].nome[indiceCaracter] = '\0';
                /****************************************************************************/
                professorListado[iContador].nome[indiceCaracter] = '\0';
                auxiliar = professorListado[iContador].listarData[0];
                professorListado[iContador].listarData[0] = professorListado[jContador].listarData[0];
                professorListado[jContador].listarData[0] = auxiliar;
                auxiliar = professorListado[iContador].listarData[1];
                professorListado[iContador].listarData[1] = professorListado[jContador].listarData[1];
                professorListado[jContador].listarData[1] = auxiliar;
                auxiliar = professorListado[iContador].listarData[2];
                professorListado[iContador].listarData[2] = professorListado[jContador].listarData[2];
                professorListado[jContador].listarData[2] = auxiliar;
            }
            jContador++;
        }
        iContador++;
    }
    
    for(iContador = 0; iContador < cadastrosComSucessoProf; iContador++)
    {
        printf("- %s : %d / %d / %d\n", professorListado[iContador].nome, professorListado[iContador].listarData[0], professorListado[iContador].listarData[1], professorListado[iContador].listarData[2]);
    }
    printf("==============\nFim da lista...\n\n");
}
void aniversariantesMes()
{
    typedef struct
    {
        char nome[TAM_NOME];
        int data[2];
        int tipoMatricula;
    }fichaTemporaria;
    
    fichaTemporaria pessoa[QTD_DE_ALUNOS + QTD_DE_PROFS];
    /*Input*/
    printf("***ANIVERSARIANTES DO MES***\n");
    int mesProcurado = 0;
    printf("Digite o numero do mes em que procura aniversariantes: ");
    scanf("%d", &mesProcurado);
    printf("::\n");
    if(mesProcurado >= 1 && mesProcurado <= 12)
    {
        //decompor cadastro de data dos alunos
        int iContador = 0;
        int kContador = 0;
        while(iContador < cadastrosComSucessoAluno)
        {
            int mesComparar = 0;
            mesComparar += (aluno[iContador].dataNasc[3] - '0') * 10;
            mesComparar += aluno[iContador].dataNasc[4] - '0';
            if(mesComparar == mesProcurado)
            {
                //Tipo
                pessoa[kContador].tipoMatricula = 0;
                //O nome
                int letra = 0;
                while(aluno[iContador].nome[letra] != '\0')
                {
                    pessoa[kContador].nome[letra] = aluno[iContador].nome[letra];
                    letra++;
                }
                pessoa[kContador].nome[letra] = '\0';
                //A data
                pessoa[kContador].data[1] = mesComparar;
                pessoa[kContador].data[0] = (aluno[iContador].dataNasc[0] - '0') * 10;
                pessoa[kContador].data[0] += aluno[iContador].dataNasc[1] - '0';
                
                kContador++;
            }
            iContador++;
        }
        //decompor cadastro de data dos alunos
        iContador = 0;
        while(iContador < cadastrosComSucessoProf)
        {
            int mesComparar = 0;
            mesComparar += (professor[iContador].dataNasc[3] - '0') * 10;
            mesComparar += professor[iContador].dataNasc[4] - '0';
            if(mesComparar == mesProcurado)
            {
                //Tipo
                pessoa[kContador].tipoMatricula = 1;
                //O nome
                int letra = 0;
                while(professor[iContador].nome[letra] != '\0')
                {
                    pessoa[kContador].nome[letra] = professor[iContador].nome[letra];
                    letra++;
                }
                pessoa[kContador].nome[letra] = '\0';
                //A data
                pessoa[kContador].data[1] = mesComparar;
                pessoa[kContador].data[0] = (professor[iContador].dataNasc[0] - '0') * 10;
                pessoa[kContador].data[0] += professor[iContador].dataNasc[1] - '0';
                kContador++;
            }
            iContador++;   
        }
        int totalAchado = kContador;
        //Ordenar por dia
        for(kContador = 0; kContador < totalAchado; kContador++)
        {
            for(iContador = kContador + 1; iContador < totalAchado; iContador++)
            {
                if(pessoa[kContador].data[0] > pessoa[iContador].data[0])
                {
                    int auxiliar;
                    //Tipo
                    auxiliar = pessoa[kContador].tipoMatricula;
                    pessoa[kContador].tipoMatricula = pessoa[iContador].tipoMatricula;
                    pessoa[iContador].tipoMatricula = auxiliar;
                    //Nome
                    char nomeTemp[TAM_NOME];
                    int letra = 0;
                    while(pessoa[kContador].nome[letra] != '\0')
                    {
                        nomeTemp[letra] = pessoa[kContador].nome[letra];
                        letra++;
                    }
                    nomeTemp[letra] = '\0';
                    letra = 0;
                    while(pessoa[iContador].nome[letra] != '\0')
                    {
                        pessoa[kContador].nome[letra] = pessoa[iContador].nome[letra];
                        letra++;
                    }
                    pessoa[kContador].nome[letra] = '\0';
                    letra = 0;
                    while(nomeTemp[letra] != '\0')
                    {
                        pessoa[iContador].nome[letra] = nomeTemp[letra];
                        letra++;
                    }
                    pessoa[iContador].nome[letra] = '\0';
                    //Data
                    auxiliar = pessoa[kContador].data[0];
                    pessoa[kContador].data[0] = pessoa[iContador].data[0];
                    pessoa[iContador].data[0] = auxiliar;
                    auxiliar = pessoa[kContador].data[1];
                    pessoa[kContador].data[1] = pessoa[iContador].data[1];
                    pessoa[iContador].data[1] = auxiliar;
                }
            }
        }
        //Ordenar por mês
        for(kContador = 0; kContador < totalAchado; kContador++)
        {
            for(iContador = kContador + 1; iContador < totalAchado; iContador++)
            {
                if(pessoa[kContador].data[1] > pessoa[iContador].data[1])
                {
                    int auxiliar;
                    //Tipo
                    auxiliar = pessoa[kContador].tipoMatricula;
                    pessoa[kContador].tipoMatricula = pessoa[iContador].tipoMatricula;
                    pessoa[iContador].tipoMatricula = auxiliar;
                    //Nome
                    char nomeTemp[TAM_NOME];
                    int letra = 0;
                    while(pessoa[kContador].nome[letra] != '\0')
                    {
                        nomeTemp[letra] = pessoa[kContador].nome[letra];
                        letra++;
                    }
                    nomeTemp[letra] = '\0';
                    letra = 0;
                    while(pessoa[iContador].nome[letra] != '\0')
                    {
                        pessoa[kContador].nome[letra] = pessoa[iContador].nome[letra];
                        letra++;
                    }
                    pessoa[kContador].nome[letra] = '\0';
                    letra = 0;
                    while(nomeTemp[letra] != '\0')
                    {
                        pessoa[iContador].nome[letra] = nomeTemp[letra];
                        letra++;
                    }
                    pessoa[iContador].nome[letra] = '\0';
                    //Data
                    auxiliar = pessoa[kContador].data[0];
                    pessoa[kContador].data[0] = pessoa[iContador].data[0];
                    pessoa[iContador].data[0] = auxiliar;
                    auxiliar = pessoa[kContador].data[1];
                    pessoa[kContador].data[1] = pessoa[iContador].data[1];
                    pessoa[iContador].data[1] = auxiliar;
                }
            }
        }
        //Exibir lista
        for(kContador = 0; kContador < totalAchado; kContador++)
        {
            if(pessoa[kContador].tipoMatricula == 0)
            {
                printf("- %s - ALUNO - DATA: %d / %d \n", pessoa[kContador].nome, pessoa[kContador].data[0], pessoa[kContador].data[1]);
            }
            else
            {
                printf("- %s - PROFESSOR - DATA: %d / %d \n", pessoa[kContador].nome, pessoa[kContador].data[0], pessoa[kContador].data[1]);
            }
        }
    }
    else
        printf("INPUT INVALIDO\n");
}
void buscarPessoas()
{
    printf("***BUSCAR PESSOAS***\n");
    char inputNome[TAM_NOME];
    printf("Digite o nome da pessoa procurada\n::");
    scanf("%50[^\n]%*c", inputNome);
    int iContador = 0;
    int jContador;
    int achouSemelhante;
    int tamNome;
    while(iContador < cadastrosComSucessoAluno)
    {
        achouSemelhante = 0;
        for(tamNome = 0; inputNome[tamNome] != '\0'; tamNome++);
        jContador = 0;
        while(jContador <= tamNome - 2)
        {
            if(inputNome[0] == aluno[iContador].nome[jContador] &&
               inputNome[1] == aluno[iContador].nome[jContador + 1] &&
               inputNome[2] == aluno[iContador].nome[jContador + 2])
            {
                achouSemelhante = 1;
                break;
            }
            jContador++;
        }
        if(achouSemelhante == 1)
        {
            printf("- %s\n", aluno[iContador].nome);
        }
        iContador++;
    }
}
void alunosComPoucaDisciplina()
{
    printf("***LISTA DE ALUNOS COM POUCAS DISCIPLINAS***\n");
    int somaDisciplinas;
    int nomeConfere;
    int contaAlunosIrregulares = 0;
    int completou = 0;
    for(int iContador = 0; iContador < cadastrosComSucessoAluno; iContador++)
    {
        somaDisciplinas = 0;
        int jContador = 0;
        for(; jContador < disciplinasCadastradas; jContador++)
        {
            nomeConfere = 0;
            for(int kContador = 0; disciplina[jContador].alunosEmDisciplina[kContador][0] != 0 && nomeConfere != 1; kContador++)
            {
                int letrasIguais = 0;
                int tamNome;
                for(tamNome = 0; disciplina[jContador].alunosEmDisciplina[kContador][tamNome] != '\0'; tamNome++)
                {
                    if(disciplina[jContador].alunosEmDisciplina[kContador][tamNome] == aluno[iContador].nome[tamNome])
                    {
                        letrasIguais++;
                    }
                }
                if(letrasIguais == tamNome)
                {
                    nomeConfere = 1;  
                }
            }
            if(nomeConfere == 1)
                somaDisciplinas++;
        }
        if(jContador == disciplinasCadastradas)
            completou = 1;
        if(somaDisciplinas < 3 && completou == 1)
        {
            alunosIrregulares[contaAlunosIrregulares] = passarDadosAluno(aluno[iContador].nome, somaDisciplinas);
            contaAlunosIrregulares++;
        }
    }
    
    listarAlunosIrregulares(contaAlunosIrregulares);
}
alunoIrregular passarDadosAluno(char nome[], int somaDisciplinas)
{
    alunoIrregular dadosAluno;
    for(int iContador = 0; nome[iContador] != '\0'; iContador++)
    {
        dadosAluno.nome[iContador] = nome[iContador];
    }
    dadosAluno.quantDisciplinas = somaDisciplinas;
    
    return dadosAluno;
}
void listarAlunosIrregulares(int qtdAlunos)
{
    for(int iContador = 0; iContador < qtdAlunos; iContador++)
    {
        printf("- %s == %d disciplinas\n", alunosIrregulares[iContador].nome, alunosIrregulares[iContador].quantDisciplinas);
    }
}
void turmasGrandes()
{
    printf("***TURMAS COM MAIS DE 40 ALUNOS***\n");
    for(int iContador = 0; iContador < disciplinasCadastradas; iContador++)
    {
        if(verificarDisciplina(iContador) == 1)
        {
            printf("- %s\n", disciplina[iContador].nomeDisciplina);
        }
    }
}

int verificarDisciplina(int indice)
{
    int jContador;
    for(jContador = 0; disciplina[indice].alunosEmDisciplina[jContador][0] != 0; jContador++);
    
    if(jContador > LIMITE_DE_VAGAS)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}