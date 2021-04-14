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
                       
            }break;
            case 'A':
            {
                       
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
    /*Input*/
    printf("***ANIVERSARIANTES DO MES***\n");
    int mesProcurado = 0;
    printf("Digite o numero do mes em que procura aniversariantes: ");
    scanf("%d", &mesProcurado);
    if(mesProcurado >= 1 && mesProcurado <= 12)
    {
        typedef struct
        {
            char nome[TAM_NOME];
            int tipoMatricula;//0 - Aluno|1 - Professor
            int listarData[2];
        }fichaTemp;

        fichaTemp pessoaListada[QTD_DE_PROFS + QTD_DE_ALUNOS];

        
        //Decompor a data de nascimento
        int casaAlgarismo;
        int indiceCaracter;
        int compararMes;
        int compararDia;
        /*Captura da base dados do aluno*/
        int iContador = 0;
        while(iContador < cadastrosComSucessoAluno)
        {
            //Tipo de pessoa cadastrada
            pessoaListada[iContador].tipoMatricula = 0;
            //Copiar o nome
            indiceCaracter = 0;
            while(aluno[iContador].nome[indiceCaracter] != '\0')
            {
                pessoaListada[iContador].nome[indiceCaracter] = aluno[iContador].nome[indiceCaracter];
                indiceCaracter++;
            }
            pessoaListada[iContador].nome[indiceCaracter] = '\0';
            //Decompor e listar a data
            indiceCaracter = 3;
            casaAlgarismo = 10;
            compararMes = 0;
            while(aluno[iContador].dataNasc[indiceCaracter] != '/')
            {
                compararMes += (aluno[iContador].dataNasc[indiceCaracter] - '0') * casaAlgarismo;
                casaAlgarismo /= 10;
                indiceCaracter++;
            }
            pessoaListada[iContador].listarData[1] = compararMes;
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
            pessoaListada[iContador].listarData[0] = compararDia;
            iContador++; 
        }
        /*Captura da base dados do professor*/
        iContador = 0;
        while(iContador < cadastrosComSucessoProf)
        {
            //Tipo de pessoa cadastrada
            pessoaListada[iContador + cadastrosComSucessoAluno].tipoMatricula = 1;
            //Copiar o nome
            indiceCaracter = 0;
            while(professor[iContador].nome[indiceCaracter] != '\0')
            {
                pessoaListada[iContador + cadastrosComSucessoAluno].nome[indiceCaracter] = professor[iContador].nome[indiceCaracter];
                indiceCaracter++;
            }
            pessoaListada[iContador + cadastrosComSucessoAluno].nome[indiceCaracter] = '\0';
            //Decompor e listar a data
            indiceCaracter = 3;
            casaAlgarismo = 10;
            compararMes = 0;
            while(professor[iContador].dataNasc[indiceCaracter] != '/')
            {
                compararMes += (professor[iContador].dataNasc[indiceCaracter] - '0') * casaAlgarismo;
                casaAlgarismo /= 10;
                indiceCaracter++;
            }
            pessoaListada[iContador + cadastrosComSucessoAluno].listarData[1] = compararMes;
            //****************
            indiceCaracter = 0;
            casaAlgarismo = 10;
            compararDia = 0;
            while(professor[iContador].dataNasc[indiceCaracter] != '/')
            {
                compararDia += (professor[iContador].dataNasc[indiceCaracter] - '0') * casaAlgarismo;
                casaAlgarismo /= 10;
                indiceCaracter++;
            }
            pessoaListada[iContador + cadastrosComSucessoAluno].listarData[0] = compararDia;
            
            iContador++; 
        }
        
        /*Listar por dia mês*/
        iContador = 0;
        int jContador;
        int auxiliar;
        int totalDeCadastros = cadastrosComSucessoAluno + cadastrosComSucessoProf;
        char nomeTemp[TAM_NOME];
        while(iContador < totalDeCadastros)
        {
            jContador = iContador + 1;
            while(jContador < totalDeCadastros)
            {
                if(pessoaListada[iContador].listarData[0] < pessoaListada[jContador].listarData[0])
                {
                    //Trocar tipo
                    auxiliar = pessoaListada[iContador].tipoMatricula;
                    pessoaListada[iContador].tipoMatricula = pessoaListada[jContador].tipoMatricula;
                    pessoaListada[jContador].tipoMatricula = auxiliar;
                    //Trocar nome
                    indiceCaracter = 0;
                    while(pessoaListada[iContador].nome[indiceCaracter] != '\0')
                    {
                        nomeTemp[indiceCaracter] = pessoaListada[iContador].nome[indiceCaracter];
                        indiceCaracter++;
                    }
                    nomeTemp[indiceCaracter - 1] = '\0';
                    indiceCaracter = 0;
                    while(pessoaListada[jContador].nome[indiceCaracter] != '\0')
                    {
                        pessoaListada[iContador].nome[indiceCaracter] = pessoaListada[jContador].nome[indiceCaracter];
                        indiceCaracter++;
                    }
                    pessoaListada[iContador].nome[indiceCaracter - 1] = '\0';
                    indiceCaracter = 0;
                    while(nomeTemp[indiceCaracter] != '\0')
                    {
                        pessoaListada[jContador].nome[indiceCaracter] = nomeTemp[indiceCaracter];
                        indiceCaracter++;
                    }
                    pessoaListada[jContador].nome[indiceCaracter - 1] = '\0';
                    //Trocar datas
                    auxiliar = pessoaListada[iContador].listarData[0];
                    pessoaListada[iContador].listarData[0] = pessoaListada[jContador].listarData[0];
                    pessoaListada[jContador].listarData[0] = auxiliar;
                    auxiliar = pessoaListada[iContador].listarData[1];
                    pessoaListada[iContador].listarData[1] = pessoaListada[jContador].listarData[1];
                    pessoaListada[jContador].listarData[1] = auxiliar;
                }
                if(pessoaListada[iContador].listarData[1] < pessoaListada[jContador].listarData[1])
                {
                    //Trocar tipo
                    auxiliar = pessoaListada[iContador].tipoMatricula;
                    pessoaListada[iContador].tipoMatricula = pessoaListada[jContador].tipoMatricula;
                    pessoaListada[jContador].tipoMatricula = auxiliar;
                    //Trocar nome
                    indiceCaracter = 0;
                    while(pessoaListada[iContador].nome[indiceCaracter] != '\0')
                    {
                        nomeTemp[indiceCaracter] = pessoaListada[iContador].nome[indiceCaracter];
                        indiceCaracter++;
                    }
                    nomeTemp[indiceCaracter - 1] = '\0';
                    indiceCaracter = 0;
                    while(pessoaListada[jContador].nome[indiceCaracter] != '\0')
                    {
                        pessoaListada[iContador].nome[indiceCaracter] = pessoaListada[jContador].nome[indiceCaracter];
                        indiceCaracter++;
                    }
                    pessoaListada[iContador].nome[indiceCaracter - 1] = '\0';
                    indiceCaracter = 0;
                    while(nomeTemp[indiceCaracter] != '\0')
                    {
                        pessoaListada[jContador].nome[indiceCaracter] = nomeTemp[indiceCaracter];
                        indiceCaracter++;
                    }
                    pessoaListada[jContador].nome[indiceCaracter - 1] = '\0';
                    //Trocar datas
                    auxiliar = pessoaListada[iContador].listarData[0];
                    pessoaListada[iContador].listarData[0] = pessoaListada[jContador].listarData[0];
                    pessoaListada[jContador].listarData[0] = auxiliar;
                    auxiliar = pessoaListada[iContador].listarData[1];
                    pessoaListada[iContador].listarData[1] = pessoaListada[jContador].listarData[1];
                    pessoaListada[jContador].listarData[1] = auxiliar;
                }
                jContador++;
            }
            iContador++;
        }

        
        /*Busca pela lista do mês*/
        
        iContador = 0;
        int achou = 0;
        while(pessoaListada[iContador].listarData[1] != mesProcurado || iContador < totalDeCadastros)
        {
            iContador++;
        }
        if(pessoaListada[iContador].listarData[1] == mesProcurado)
            achou = 1;
        
        if(achou == 1)
        {
            //Listagem do mês
            switch(mesProcurado)
            {
                case 1: printf("JANEIRO:\n"); break;
                case 2: printf("FEVEREIRO:\n"); break;
                case 3: printf("MARCO:\n"); break;
                case 4: printf("ABRIL:\n"); break;
                case 5: printf("MAIO:\n"); break;
                case 6: printf("JUNHO:\n"); break;
                case 7: printf("JULHO:\n"); break;
                case 8: printf("AGOSTO:\n"); break;
                case 9: printf("SETEMBRO:\n"); break;
                case 10: printf("OUTUBRO:\n"); break;
                case 11: printf("NOVEMBRO:\n"); break;
                case 12: printf("DEZEMBRO:\n"); break;
            }
            while(pessoaListada[iContador].listarData[1] == mesProcurado)
            {
                if(pessoaListada[iContador].tipoMatricula == 0)
                {
                    printf("- %s - ALUNO - %d / %d\n", pessoaListada[iContador].nome, pessoaListada[iContador].listarData[0], pessoaListada[iContador].listarData[1]);
                }
                    
                else
                {
                    printf("- %s - PROFESSOR - %d / %d\n", pessoaListada[iContador].nome, pessoaListada[iContador].listarData[0], pessoaListada[iContador].listarData[1]);
                }
                iContador++;
            }
        }
        else
            printf("NAO EXISTEM ANIVERSARIANTES NO MES PROCURADO\n");
    }
    else
        printf("INPUT INVALIDO\n");
}
void buscarPessoas()
{
    char inputNome[TAM_NOME];
    printf("Digite o nome da pessoa procurada\n");
    scanf("%50[^\n]%*c", inputNome);
    //int totalDeCadastros = cadastrosComSucessoProf + cadastrosComSucessoAluno;
    int iContador = 0;
    int jContador;
    int kContador;
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