#include <stdio.h>
#include "disciplina.h"
#include "aluNo.h"
#include "professor.h"
#include "relatorios.h"
#include "utilitarios.h"

int cadastrosComSucessoAluNo;
int cadastrosComSucessoProf;
int disciplinasCadastradas;

cadastroAluNo aluNo[QTD_DE_ALUNoS];
cadastroDisc disciplina[QTD_DE_DISC];
aluNoIrregular aluNosIrregulares[QTD_DE_ALUNoS];

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
        printf("1 - AluNos ordenados por sexo\n");
        printf("2 - AluNos ordenados por Nome\n");
        printf("3 - AluNos ordenados por data de nascimento\n");
        printf("4 - Professores ordenados por sexo\n");
        printf("5 - Professores ordenados por Nome\n");
        printf("6 - Professores ordenados por data de nascimento\n");
        printf("7 - Aniversariantes do mes\n");
        printf("8 - Busca de pessoas\n");
        printf("9 - AluNos matriculados em meNos de 3 disciplinas\n");
        printf("A - Disciplinas, por professor, com mais de 40 aluNos\n::");
        
        scanf("%1c", &opcao);
        while(getchar() != '\n');/*Pular o char new line No input*/
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
                listarAluNosPorSexo();      
            }break;
            case '2':
            {
                listarAluNosPorNome();
            }break;
            case '3':
            {
                listarAluNosPorData();
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
                aluNosComPoucaDisciplina();     
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

void listarAluNosPorSexo()
{
    printf("***ALUNoS POR SEXO***\n");
    int iContador = 0;
    printf("FEMININo\n");
    while(iContador < cadastrosComSucessoAluNo)
    {
        if(aluNo[iContador].sexo == 'F')
            printf("%s\n", aluNo[iContador].Nome);
        iContador++;
    }
    iContador = 0;
    printf("MASCULINo\n");
    while(iContador < cadastrosComSucessoAluNo)
    {
        if(aluNo[iContador].sexo == 'M')
            printf("%s\n", aluNo[iContador].Nome);
        iContador++;
    }
    iContador = 0;
    printf("OUTRO\n");
    while(iContador < cadastrosComSucessoAluNo)
    {
        if(aluNo[iContador].sexo == 'O')
            printf("%s\n", aluNo[iContador].Nome);
        iContador++;
    }
    printf("==============\nFim da lista...\n\n");
}

void listarAluNosPorNome()
{
    printf("***ALUNoS POR NoME***\n");
    //Ordenar das strings
    int iContador = 0;
    int jContador;
    int achou = 0;
    //char listaTemporaria[QTD_DE_ALUNoS][TAM_NoME];
    char letra = 'A';

    while(letra < 'Z' + 1)
    {
        iContador = 0;
        printf("[%c]\n", letra);
        while(iContador < cadastrosComSucessoAluNo)
        {
            if(aluNo[iContador].Nome[0] == letra)
                printf("- %s\n", aluNo[iContador].Nome);
            iContador++;
        }
        letra++;
    }
    
    printf("==============\nFim da lista...\n\n");
}

void listarAluNosPorData()
{
    printf("***ALUNoS POR DATA DE NASCIMENTO***\n");
    typedef struct
    {
        char Nome[TAM_NoME];
        int listarData[3];//|dia|mês|aNo|
    }fichaTemp;
    
    fichaTemp aluNoListado[QTD_DE_ALUNoS];
    int casaAlgarismo;
    int indiceCaracter;
    int compararANo;
    int compararMes;
    int compararDia;
    int iContador = 0;
    while(iContador < cadastrosComSucessoAluNo)
    {
        //Copiar o Nome
        indiceCaracter = 0;
        while(aluNo[iContador].Nome[indiceCaracter] != '\0')
        {
            aluNoListado[iContador].Nome[indiceCaracter] = aluNo[iContador].Nome[indiceCaracter];
            indiceCaracter++;
        }
        aluNoListado[iContador].Nome[indiceCaracter] = '\0';
        //Decompor e listar data
        indiceCaracter = 6;
        casaAlgarismo = 1000;
        compararANo = 0;
        while(aluNo[iContador].dataNasc[indiceCaracter] != '\0')
        {
            compararANo += (aluNo[iContador].dataNasc[indiceCaracter] - '0') * casaAlgarismo;
            casaAlgarismo /= 10;
            indiceCaracter++;
        }
        aluNoListado[iContador].listarData[2] = compararANo;
        //*****************
        indiceCaracter = 3;
        casaAlgarismo = 10;
        compararMes = 0;
        while(aluNo[iContador].dataNasc[indiceCaracter] != '/')
        {
            compararMes += (aluNo[iContador].dataNasc[indiceCaracter] - '0') * casaAlgarismo;
            casaAlgarismo /= 10;
            indiceCaracter++;
        }
        aluNoListado[iContador].listarData[1] = compararMes;
        //****************
        indiceCaracter = 0;
        casaAlgarismo = 10;
        compararDia = 0;
        while(aluNo[iContador].dataNasc[indiceCaracter] != '/')
        {
            compararDia += (aluNo[iContador].dataNasc[indiceCaracter] - '0') * casaAlgarismo;
            casaAlgarismo /= 10;
            indiceCaracter++;
        }
        aluNoListado[iContador].listarData[0] = compararDia;
        
        iContador++;
    }
    /*Comparar data*/
    //Por dia
    int auxiliar;
    iContador = 0;
    int jContador;
    while(iContador < cadastrosComSucessoAluNo)
    {
        jContador = iContador + 1;
        while(jContador < cadastrosComSucessoAluNo)
        {
            if(aluNoListado[iContador].listarData[0] < aluNoListado[jContador].listarData[0])
            {
                //Copiar o Nome******************************************************
                char copiaNomeTemp[TAM_NoME];
                indiceCaracter = 0;
                while(aluNoListado[jContador].Nome[indiceCaracter] != '\0')
                {
                    copiaNomeTemp[indiceCaracter] = aluNoListado[jContador].Nome[indiceCaracter];
                    indiceCaracter++;
                }
                copiaNomeTemp[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(aluNoListado[iContador].Nome[indiceCaracter] != '\0')
                {
                    aluNoListado[jContador].Nome[indiceCaracter] = aluNoListado[iContador].Nome[indiceCaracter];
                    indiceCaracter++;
                }
                aluNoListado[jContador].Nome[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(copiaNomeTemp[indiceCaracter] != '\0')
                {
                    aluNoListado[iContador].Nome[indiceCaracter] = copiaNomeTemp[indiceCaracter];
                    indiceCaracter++;
                }
                aluNoListado[iContador].Nome[indiceCaracter] = '\0';
                /****************************************************************************/
                auxiliar = aluNoListado[iContador].listarData[0];
                aluNoListado[iContador].listarData[0] = aluNoListado[jContador].listarData[0];
                aluNoListado[jContador].listarData[0] = auxiliar;
                auxiliar = aluNoListado[iContador].listarData[1];
                aluNoListado[iContador].listarData[1] = aluNoListado[jContador].listarData[1];
                aluNoListado[jContador].listarData[1] = auxiliar;
                auxiliar = aluNoListado[iContador].listarData[2];
                aluNoListado[iContador].listarData[2] = aluNoListado[jContador].listarData[2];
                aluNoListado[jContador].listarData[2] = auxiliar;
            }
            jContador++;
        }
        iContador++;
    }
    //Por mês
    iContador = 0;
    while(iContador < cadastrosComSucessoAluNo)
    {
        jContador = iContador + 1;
        while(jContador < cadastrosComSucessoAluNo)
        {
            if(aluNoListado[iContador].listarData[1] < aluNoListado[jContador].listarData[1])
            {
                //Copiar o Nome******************************************************
                char copiaNomeTemp[TAM_NoME];
                indiceCaracter = 0;
                while(aluNoListado[jContador].Nome[indiceCaracter] != '\0')
                {
                    copiaNomeTemp[indiceCaracter] = aluNoListado[jContador].Nome[indiceCaracter];
                    indiceCaracter++;
                }
                copiaNomeTemp[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(aluNoListado[iContador].Nome[indiceCaracter] != '\0')
                {
                    aluNoListado[jContador].Nome[indiceCaracter] = aluNoListado[iContador].Nome[indiceCaracter];
                    indiceCaracter++;
                }
                aluNoListado[jContador].Nome[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(copiaNomeTemp[indiceCaracter] != '\0')
                {
                    aluNoListado[iContador].Nome[indiceCaracter] = copiaNomeTemp[indiceCaracter];
                    indiceCaracter++;
                }
                aluNoListado[iContador].Nome[indiceCaracter] = '\0';
                /****************************************************************************/
                auxiliar = aluNoListado[iContador].listarData[0];
                aluNoListado[iContador].listarData[0] = aluNoListado[jContador].listarData[0];
                aluNoListado[jContador].listarData[0] = auxiliar;
                auxiliar = aluNoListado[iContador].listarData[1];
                aluNoListado[iContador].listarData[1] = aluNoListado[jContador].listarData[1];
                aluNoListado[jContador].listarData[1] = auxiliar;
                auxiliar = aluNoListado[iContador].listarData[2];
                aluNoListado[iContador].listarData[2] = aluNoListado[jContador].listarData[2];
                aluNoListado[jContador].listarData[2] = auxiliar;
            }
            jContador++;
        }
        iContador++;
    }
    //Por aNo
    iContador = 0;
    while(iContador < cadastrosComSucessoAluNo)
    {
        jContador = iContador + 1;
        while(jContador < cadastrosComSucessoAluNo)
        {
            if(aluNoListado[iContador].listarData[2] < aluNoListado[jContador].listarData[2])
            {
                //Copiar o Nome******************************************************
                char copiaNomeTemp[TAM_NoME];
                indiceCaracter = 0;
                while(aluNoListado[jContador].Nome[indiceCaracter] != '\0')
                {
                    copiaNomeTemp[indiceCaracter] = aluNoListado[jContador].Nome[indiceCaracter];
                    indiceCaracter++;
                }
                copiaNomeTemp[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(aluNoListado[iContador].Nome[indiceCaracter] != '\0')
                {
                    aluNoListado[jContador].Nome[indiceCaracter] = aluNoListado[iContador].Nome[indiceCaracter];
                    indiceCaracter++;
                }
                aluNoListado[jContador].Nome[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(copiaNomeTemp[indiceCaracter] != '\0')
                {
                    aluNoListado[iContador].Nome[indiceCaracter] = copiaNomeTemp[indiceCaracter];
                    indiceCaracter++;
                }
                aluNoListado[iContador].Nome[indiceCaracter] = '\0';
                /****************************************************************************/
                auxiliar = aluNoListado[iContador].listarData[0];
                aluNoListado[iContador].listarData[0] = aluNoListado[jContador].listarData[0];
                aluNoListado[jContador].listarData[0] = auxiliar;
                auxiliar = aluNoListado[iContador].listarData[1];
                aluNoListado[iContador].listarData[1] = aluNoListado[jContador].listarData[1];
                aluNoListado[jContador].listarData[1] = auxiliar;
                auxiliar = aluNoListado[iContador].listarData[2];
                aluNoListado[iContador].listarData[2] = aluNoListado[jContador].listarData[2];
                aluNoListado[jContador].listarData[2] = auxiliar;
            }
            jContador++;
        }
        iContador++;
    }
    
    for(iContador = 0; iContador < cadastrosComSucessoAluNo; iContador++)
    {
        printf("- %s : %d/%d/%d\n", aluNoListado[iContador].Nome, aluNoListado[iContador].listarData[0], aluNoListado[iContador].listarData[1], aluNoListado[iContador].listarData[2]);
    }
    printf("==============\nFim da lista...\n\n");
}
void listarProfessorPorSexo()
{
   printf("***PROFESSORES POR SEXO***\n");
    int iContador = 0;
    printf("FEMININo\n");
    while(iContador < cadastrosComSucessoProf)
    {
        if(professor[iContador].sexo == 'F')
            printf("%s\n", professor[iContador].Nome);
        iContador++;
    }
    iContador = 0;
    printf("MASCULINo\n");
    while(iContador < cadastrosComSucessoProf)
    {
        if(professor[iContador].sexo == 'M')
            printf("%s\n", professor[iContador].Nome);
        iContador++;
    }
    iContador = 0;
    printf("OUTRO\n");
    while(iContador < cadastrosComSucessoProf)
    {
        if(professor[iContador].sexo == 'O')
            printf("%s\n", professor[iContador].Nome);
        iContador++;
    }
    printf("==============\nFim da lista...\n\n"); 
}
void listarProfessorPorNome()
{
    printf("***PROFESSORES POR NoME***\n");
    //Ordenar das strings
    int iContador = 0;
    int jContador;
    int achou = 0;
    //char listaTemporaria[QTD_DE_PROFS][TAM_NoME];
    char letra = 'A';

    while(letra < 'Z' + 1)
    {
        iContador = 0;
        printf("[%c]\n", letra);
        while(iContador < cadastrosComSucessoProf)
        {
            if(professor[iContador].Nome[0] == letra)
                printf("- %s\n", professor[iContador].Nome);
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
    int compararANo;
    int compararMes;
    int compararDia;
    
    int iContador = 0;
    typedef struct
    {
        char Nome[TAM_NoME];
        int listarData[3];//|dia|mês|aNo|
    }fichaTemp;
    
    fichaTemp professorListado[QTD_DE_PROFS];
    while(iContador < cadastrosComSucessoProf)
    {
        //Copiar o Nome
        indiceCaracter = 0;
        while(professor[iContador].Nome[indiceCaracter] != '\0')
        {
            professorListado[iContador].Nome[indiceCaracter] = professor[iContador].Nome[indiceCaracter];
            indiceCaracter++;
        }
        professorListado[iContador].Nome[indiceCaracter] = '\0';
        //Decompor e listar data
        indiceCaracter = 6;
        casaAlgarismo = 1000;
        compararANo = 0;
        while(professor[iContador].dataNasc[indiceCaracter] != '\0')
        {
            compararANo += (professor[iContador].dataNasc[indiceCaracter] - '0') * casaAlgarismo;
            casaAlgarismo /= 10;
            indiceCaracter++;
        }
        professorListado[iContador].listarData[2] = compararANo;
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
                //Copiar o Nome******************************************************
                char copiaNomeTemp[TAM_NoME];
                indiceCaracter = 0;
                while(professorListado[jContador].Nome[indiceCaracter] != '\0')
                {
                    copiaNomeTemp[indiceCaracter] = professorListado[jContador].Nome[indiceCaracter];
                    indiceCaracter++;
                }
                copiaNomeTemp[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(professorListado[iContador].Nome[indiceCaracter] != '\0')
                {
                    professorListado[jContador].Nome[indiceCaracter] = professorListado[iContador].Nome[indiceCaracter];
                    indiceCaracter++;
                }
                professorListado[jContador].Nome[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(copiaNomeTemp[indiceCaracter] != '\0')
                {
                    professorListado[iContador].Nome[indiceCaracter] = copiaNomeTemp[indiceCaracter];
                    indiceCaracter++;
                }
                professorListado[iContador].Nome[indiceCaracter] = '\0';
                /****************************************************************************/
                professorListado[iContador].Nome[indiceCaracter] = '\0';
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
                //Copiar o Nome******************************************************
                char copiaNomeTemp[TAM_NoME];
                indiceCaracter = 0;
                while(professorListado[jContador].Nome[indiceCaracter] != '\0')
                {
                    copiaNomeTemp[indiceCaracter] = professorListado[jContador].Nome[indiceCaracter];
                    indiceCaracter++;
                }
                copiaNomeTemp[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(professorListado[iContador].Nome[indiceCaracter] != '\0')
                {
                    professorListado[jContador].Nome[indiceCaracter] = professorListado[iContador].Nome[indiceCaracter];
                    indiceCaracter++;
                }
                professorListado[jContador].Nome[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(copiaNomeTemp[indiceCaracter] != '\0')
                {
                    professorListado[iContador].Nome[indiceCaracter] = copiaNomeTemp[indiceCaracter];
                    indiceCaracter++;
                }
                professorListado[iContador].Nome[indiceCaracter] = '\0';
                /****************************************************************************/
                professorListado[iContador].Nome[indiceCaracter] = '\0';
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
    //Por aNo
    iContador = 0;
    while(iContador < cadastrosComSucessoProf)
    {
        jContador = iContador + 1;
        while(jContador < cadastrosComSucessoProf)
        {
            if(professorListado[iContador].listarData[2] < professorListado[jContador].listarData[2])
            {
                //Copiar o Nome******************************************************
                char copiaNomeTemp[TAM_NoME];
                indiceCaracter = 0;
                while(professorListado[jContador].Nome[indiceCaracter] != '\0')
                {
                    copiaNomeTemp[indiceCaracter] = professorListado[jContador].Nome[indiceCaracter];
                    indiceCaracter++;
                }
                copiaNomeTemp[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(professorListado[iContador].Nome[indiceCaracter] != '\0')
                {
                    professorListado[jContador].Nome[indiceCaracter] = professorListado[iContador].Nome[indiceCaracter];
                    indiceCaracter++;
                }
                professorListado[jContador].Nome[indiceCaracter] = '\0';
                indiceCaracter = 0;
                while(copiaNomeTemp[indiceCaracter] != '\0')
                {
                    professorListado[iContador].Nome[indiceCaracter] = copiaNomeTemp[indiceCaracter];
                    indiceCaracter++;
                }
                professorListado[iContador].Nome[indiceCaracter] = '\0';
                /****************************************************************************/
                professorListado[iContador].Nome[indiceCaracter] = '\0';
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
        printf("- %s : %d / %d / %d\n", professorListado[iContador].Nome, professorListado[iContador].listarData[0], professorListado[iContador].listarData[1], professorListado[iContador].listarData[2]);
    }
    printf("==============\nFim da lista...\n\n");
}
void aniversariantesMes()
{
    typedef struct
    {
        char Nome[TAM_NoME];
        int data[2];
        int tipoMatricula;
    }fichaTemporaria;
    
    fichaTemporaria pessoa[QTD_DE_ALUNoS + QTD_DE_PROFS];
    /*Input*/
    printf("***ANIVERSARIANTES DO MES***\n");
    int mesProcurado = 0;
    printf("Digite o numero do mes em que procura aniversariantes: ");
    scanf("%d", &mesProcurado);
    printf("::\n");
    if(mesProcurado >= 1 && mesProcurado <= 12)
    {
        //decompor cadastro de data dos aluNos
        int iContador = 0;
        int kContador = 0;
        while(iContador < cadastrosComSucessoAluNo)
        {
            int mesComparar = 0;
            mesComparar += (aluNo[iContador].dataNasc[3] - '0') * 10;
            mesComparar += aluNo[iContador].dataNasc[4] - '0';
            if(mesComparar == mesProcurado)
            {
                //Tipo
                pessoa[kContador].tipoMatricula = 0;
                //O Nome
                int letra = 0;
                while(aluNo[iContador].Nome[letra] != '\0')
                {
                    pessoa[kContador].Nome[letra] = aluNo[iContador].Nome[letra];
                    letra++;
                }
                pessoa[kContador].Nome[letra] = '\0';
                //A data
                pessoa[kContador].data[1] = mesComparar;
                pessoa[kContador].data[0] = (aluNo[iContador].dataNasc[0] - '0') * 10;
                pessoa[kContador].data[0] += aluNo[iContador].dataNasc[1] - '0';
                
                kContador++;
            }
            iContador++;
        }
        //decompor cadastro de data dos aluNos
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
                //O Nome
                int letra = 0;
                while(professor[iContador].Nome[letra] != '\0')
                {
                    pessoa[kContador].Nome[letra] = professor[iContador].Nome[letra];
                    letra++;
                }
                pessoa[kContador].Nome[letra] = '\0';
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
                    char NomeTemp[TAM_NoME];
                    int letra = 0;
                    while(pessoa[kContador].Nome[letra] != '\0')
                    {
                        NomeTemp[letra] = pessoa[kContador].Nome[letra];
                        letra++;
                    }
                    NomeTemp[letra] = '\0';
                    letra = 0;
                    while(pessoa[iContador].Nome[letra] != '\0')
                    {
                        pessoa[kContador].Nome[letra] = pessoa[iContador].Nome[letra];
                        letra++;
                    }
                    pessoa[kContador].Nome[letra] = '\0';
                    letra = 0;
                    while(NomeTemp[letra] != '\0')
                    {
                        pessoa[iContador].Nome[letra] = NomeTemp[letra];
                        letra++;
                    }
                    pessoa[iContador].Nome[letra] = '\0';
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
                    char NomeTemp[TAM_NoME];
                    int letra = 0;
                    while(pessoa[kContador].Nome[letra] != '\0')
                    {
                        NomeTemp[letra] = pessoa[kContador].Nome[letra];
                        letra++;
                    }
                    NomeTemp[letra] = '\0';
                    letra = 0;
                    while(pessoa[iContador].Nome[letra] != '\0')
                    {
                        pessoa[kContador].Nome[letra] = pessoa[iContador].Nome[letra];
                        letra++;
                    }
                    pessoa[kContador].Nome[letra] = '\0';
                    letra = 0;
                    while(NomeTemp[letra] != '\0')
                    {
                        pessoa[iContador].Nome[letra] = NomeTemp[letra];
                        letra++;
                    }
                    pessoa[iContador].Nome[letra] = '\0';
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
                printf("- %s - ALUNo - DATA: %d / %d \n", pessoa[kContador].Nome, pessoa[kContador].data[0], pessoa[kContador].data[1]);
            }
            else
            {
                printf("- %s - PROFESSOR - DATA: %d / %d \n", pessoa[kContador].Nome, pessoa[kContador].data[0], pessoa[kContador].data[1]);
            }
        }
    }
    else
        printf("INPUT INVALIDO\n");
}
void buscarPessoas()
{
    printf("***BUSCAR PESSOAS***\n");
    char inputNome[TAM_NoME];
    printf("Digite o Nome da pessoa procurada\n::");
    scanf("%50[^\n]%*c", inputNome);
    int iContador = 0;
    int jContador;
    int achouSemelhante;
    int tamNome;
    while(iContador < cadastrosComSucessoAluNo)
    {
        achouSemelhante = 0;
        for(tamNome = 0; inputNome[tamNome] != '\0'; tamNome++);
        jContador = 0;
        while(jContador <= tamNome - 2)
        {
            if(inputNome[0] == aluNo[iContador].Nome[jContador] &&
               inputNome[1] == aluNo[iContador].Nome[jContador + 1] &&
               inputNome[2] == aluNo[iContador].Nome[jContador + 2])
            {
                achouSemelhante = 1;
                break;
            }
            jContador++;
        }
        if(achouSemelhante == 1)
        {
            printf("- %s\n", aluNo[iContador].Nome);
        }
        iContador++;
    }
}
void aluNosComPoucaDisciplina()
{
    printf("***LISTA DE ALUNoS COM POUCAS DISCIPLINAS***\n");
    int somaDisciplinas;
    int NomeConfere;
    int contaAluNosIrregulares = 0;
    int completou = 0;
    for(int iContador = 0; iContador < cadastrosComSucessoAluNo; iContador++)
    {
        somaDisciplinas = 0;
        int jContador = 0;
        for(; jContador < disciplinasCadastradas; jContador++)
        {
            NomeConfere = 0;
            for(int kContador = 0; disciplina[jContador].aluNosEmDisciplina[kContador][0] != 0 && NomeConfere != 1; kContador++)
            {
                int letrasIguais = 0;
                int tamNome;
                for(tamNome = 0; disciplina[jContador].aluNosEmDisciplina[kContador][tamNome] != '\0'; tamNome++)
                {
                    if(disciplina[jContador].aluNosEmDisciplina[kContador][tamNome] == aluNo[iContador].Nome[tamNome])
                    {
                        letrasIguais++;
                    }
                }
                if(letrasIguais == tamNome)
                {
                    NomeConfere = 1;  
                }
            }
            if(NomeConfere == 1)
                somaDisciplinas++;
        }
        if(jContador == disciplinasCadastradas)
            completou = 1;
        if(somaDisciplinas < 3 && completou == 1)
        {
            aluNosIrregulares[contaAluNosIrregulares] = passarDadosAluNo(aluNo[iContador].Nome, somaDisciplinas);
            contaAluNosIrregulares++;
        }
    }
    
    listarAluNosIrregulares(contaAluNosIrregulares);
}
aluNoIrregular passarDadosAluNo(char Nome[], int somaDisciplinas)
{
    aluNoIrregular dadosAluNo;
    for(int iContador = 0; Nome[iContador] != '\0'; iContador++)
    {
        dadosAluNo.Nome[iContador] = Nome[iContador];
    }
    dadosAluNo.quantDisciplinas = somaDisciplinas;
    
    return dadosAluNo;
}
void listarAluNosIrregulares(int qtdAluNos)
{
    for(int iContador = 0; iContador < qtdAluNos; iContador++)
    {
        printf("- %s == %d disciplinas\n", aluNosIrregulares[iContador].Nome, aluNosIrregulares[iContador].quantDisciplinas);
    }
}
void turmasGrandes()
{
    printf("***TURMAS COM MAIS DE 40 ALUNoS***\n");
    for(int iContador = 0; iContador < disciplinasCadastradas; iContador++)
    {
        if(verificarDisciplina(iContador) == 1)
        {
            printf("- %s\n", disciplina[iContador].NomeDisciplina);
        }
    }
}

int verificarDisciplina(int indice)
{
    int jContador;
    for(jContador = 0; disciplina[indice].aluNosEmDisciplina[jContador][0] != 0; jContador++);
    
    if(jContador > LIMITE_DE_VAGAS)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}