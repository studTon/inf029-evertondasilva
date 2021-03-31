#include <stdio.h>
#include "aluno.h"
#define TAM_CARACTER_DIA 3
#define TAM_CARACTER_MES 3
#define TAM_CARACTER_ANO 5
#define TAM_MATRICULA 13
#define QTD_DE_ALUNOS 100
cadastroAluno aluno[QTD_DE_ALUNOS];
int chaveDeValidar = 0;
int cadastrosComSucesso = 0;

void menuAluno()
{
    char escolha = '1';
    while(escolha != '0')
    {
        printf("******************************\n");
        printf("*         INFO ALUNO         *\n");
        printf("******************************\n");
        /*menu Aluno*/
        printf("\nEscolha uma opcao a seguir:\n");
        printf("0 - Voltar\n");
        printf("1 - Inserir aluno\n");
        printf("2 - Excluir aluno\n");
        printf("3 - Listar alunos\n::");

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
                inserirAluno();
            }break;
            case '2':
            {
                excluirAluno();
            }break;
            case '3':
            {
                listarAlunos();
            }break;
            default:
            {
                printf("INPUT INVALIDO\n");
            }break;
        }
    
    }
    
}
/*Geração de matrícula*/
int turma = 1;
void gerarMatricula(int inputIndiceAluno)
{    
    if(inputIndiceAluno < QTD_DE_ALUNOS)
        if(inputIndiceAluno >= 50)
        {
            turma++;
            inputIndiceAluno -= 50;
        }
    //Decomposição do índice do aluno
    /*É necessário somar o char '0' a todos os valores inteiros na 
     *conversão de inteiro para char, pois o valor inteiro do char
     *'0' somado ao número inteiro equivale ao seu char correspon-
     *dente.
     */
    char centenaAluno = (inputIndiceAluno / 100) + '0';
    char dezenaAluno = ((inputIndiceAluno % 100) / 10) + '0';
    char unidadeAluno = (inputIndiceAluno % 10) + '0';
    //Ano e semestre
    char ano[TAM_CARACTER_ANO] = "2021\0";
    char semestre = '1';
    //Decomposição da turma
    char dezenaTurma = (turma / 10) + '0';
    char unidadeTurma = (turma % 10) + '0';
    //Criação da string que representa a matrícula
    int contador = 0;
    while(contador < 13)
    {
        if(contador >= 0 && contador <= 3)
        {
            aluno[inputIndiceAluno].matricula[contador] = ano[contador];
        }
        if(contador == 4 || contador == 6 ||contador == 9)
        {
            aluno[inputIndiceAluno].matricula[contador] = '.';
        }
        if(contador == 5)
        {
            aluno[inputIndiceAluno].matricula[contador] = semestre;
        }
        if(contador == 7)
        {
            aluno[inputIndiceAluno].matricula[contador] = dezenaTurma;
        }
        else
	    {
            if(contador == 8)
                {
                    aluno[inputIndiceAluno].matricula[contador] = unidadeTurma;
                }
	    }    
        if(contador == 10)
        {
            aluno[inputIndiceAluno].matricula[contador] = centenaAluno;
        }
        else
        {
            if(contador == 11)
            {
                aluno[inputIndiceAluno].matricula[contador] = dezenaAluno;
            }
            else
            {
                if(contador == 12)
                {
                    aluno[inputIndiceAluno].matricula[contador] = unidadeAluno;
                }
            }
        }
    	contador++;
    }
    if(contador == 13)
        aluno[inputIndiceAluno].matricula[contador] = '\0';

    printf("MATRICULA GERADA: %s\n", aluno[inputIndiceAluno].matricula);

}
/*Verificações da entrada de dados do cadastro*/
void validarNome(char inputNome[])
{   
    
    int tamanhoInputNome = 0;
    while(inputNome[tamanhoInputNome] != '\0') tamanhoInputNome++;
    int tamanhoNomeReal = 0;
    int contador = 0;
    while(inputNome[contador] != '\0')
    {
        if(
        (inputNome[contador] >= 'a' && inputNome[contador] <= 'z')||
        (inputNome[contador] >= 'A' && inputNome[contador] <= 'Z')||
        (inputNome[contador] == ' '))
            tamanhoNomeReal++;
        contador++;
    }
    if(tamanhoInputNome == tamanhoNomeReal)
    {
        printf("NOME VALIDO\n");
        chaveDeValidar++;
    }
    else
        printf("ERRO: Nome invalido\n");
}
void validarCPF(char cpf[])
{
    /*Análise dos campo CPF*/
    int tamDoInput = 0;
    int contadorCaracterPonto = 0;
    int contadorCaracterHifen = 0;
    int contadorNumeros = 0;
    while(cpf[tamDoInput] != '\0')
    {
        if(cpf[tamDoInput] >= '0' && cpf[tamDoInput] <= '9' &&
        (tamDoInput != 3 && tamDoInput != 7 && tamDoInput != 11))
        {
            contadorNumeros++;
        }
        if(cpf[tamDoInput] == '.' && (tamDoInput == 3 || tamDoInput == 7))
        {
            contadorCaracterPonto++;
        }
        if(cpf[tamDoInput] == '-' && tamDoInput == 11)
        {
            contadorCaracterHifen++;
        }
        tamDoInput++;
    }
    int somaContadores = contadorCaracterHifen + contadorCaracterPonto + contadorNumeros;
    /*Conclusão*/
    if(somaContadores == 14)
    {
        printf("CPF VALIDO\n");
        chaveDeValidar++;
    }
    else
    {
        printf("ERRO: CPF invalido\n");
        //contaErros++;
    }
    
}
void validarSexo(char sexo)
{
    if(sexo == 'M'||sexo == 'F'||sexo == 'O')
    {
        printf("SEXO VALIDO\n");
        chaveDeValidar++;
    }
    else
    {
        printf("ERRO: Sexo invalido\n");
    }
}
void validarNasc(char data[])
{
    int errosData = 0;
    /*Decomposição da data*/
    int tamDoInput = 0;
    int contaCaracterBarra = 0;
    int contaDiaNumero = 0;
    int contaMesNumero = 0;
    int contaAnoNumero = 0;
    while(data[tamDoInput] != '\0')
    {
        if(tamDoInput != 2 && tamDoInput != 5)
        {
            if(tamDoInput < 2)
            {
                if(data[tamDoInput] >= '0' && data[tamDoInput] <= '9')
                    contaDiaNumero++;
            }
            if(tamDoInput > 2 && tamDoInput < 5)
            {
                if(data[tamDoInput] >= '0' && data[tamDoInput] <= '9')
                    contaMesNumero++;
            }
            if(tamDoInput > 5 && tamDoInput < 10)
            {
                if(data[tamDoInput] >= '0' && data[tamDoInput] <= '9')
                    contaAnoNumero++;
            }
        }
        if ((tamDoInput == 2 || tamDoInput == 5 )&& data[tamDoInput] == '/')
        {
            contaCaracterBarra++;
        }
        tamDoInput++;
    }

    if(contaDiaNumero != 2||contaMesNumero != 2||contaAnoNumero != 4||contaCaracterBarra != 2)
        errosData++;
    else
    {
        /*Aquisição das partes da data*/
            char diaChar[TAM_CARACTER_DIA];
            char mesChar[TAM_CARACTER_MES];
            char anoChar[TAM_CARACTER_ANO];

            //dia
            int iContador = 0;
            int jContador = 0;
            while (jContador < TAM_CARACTER_DIA - 1)
            {
                diaChar[jContador] = data[iContador];
                iContador++;
                jContador++;
            }
            diaChar[jContador] = '\0';
            //mês
            jContador = 0;
            iContador++;
            while (jContador < TAM_CARACTER_MES - 1)
            {
                mesChar[jContador] = data[iContador];
                iContador++;
                jContador++;
            }
            mesChar[jContador] = '\0';
            //ano
            jContador = 0;
            iContador++;
            while (jContador < TAM_CARACTER_ANO - 1)
            {
                anoChar[jContador] = data[iContador];
                iContador++;
                jContador++;
            }
            anoChar[jContador] = '\0';

        /*Conversão para inteiros*/
        //Conversão da string dia
        int indiceDoAlgarismo = 0;
        int diaData = 0;
        while (indiceDoAlgarismo < TAM_CARACTER_DIA - 1)
        {   
            switch(indiceDoAlgarismo)
            {
                case 0:{
                    diaData += (diaChar[indiceDoAlgarismo] - '0') * 10;
                }break;
                case 1:{
                    diaData += (diaChar[indiceDoAlgarismo] - '0') * 1;
                }break;
            }
            indiceDoAlgarismo++;
        }
        
        //Conversão da string mês
        int mesData = 0;
        indiceDoAlgarismo = 0;
        while(indiceDoAlgarismo < TAM_CARACTER_MES - 1)
        {
            switch(indiceDoAlgarismo)
            {
                case 0:{
                    mesData += (mesChar[indiceDoAlgarismo] - '0') * 10;
                }break;
                case 1:{
                    mesData += (mesChar[indiceDoAlgarismo] - '0') * 1;
                }break;
            }
            indiceDoAlgarismo++;
        }
        
        //Conversão da string ano
        int anoData = 0;
        indiceDoAlgarismo = 0;
        while(indiceDoAlgarismo < TAM_CARACTER_ANO - 1)
        {
            switch(indiceDoAlgarismo)
            {
                case 0:{
                    anoData += (anoChar[indiceDoAlgarismo] - '0') * 1000;
                }break;
                case 1:{
                    anoData += (anoChar[indiceDoAlgarismo] - '0') * 100;
                }break;
                case 2:{
                    anoData += (anoChar[indiceDoAlgarismo] - '0') * 10;
                }break;
                case 3:{
                    anoData += (anoChar[indiceDoAlgarismo] - '0') * 1;
                }break;
            }
            indiceDoAlgarismo++;
        }

        /*Verificação de ano bissexto*/
        int bissexto = 0; //0 - Comum | 1 - Bissexto
        if(anoData % 400 == 0)
            bissexto = 1;
        else
            if(anoData % 4 == 0 && (anoData % 100 != 0))
            {
                bissexto = 1;
            }

        /*Verificação da data conforme calendário*/
        if(bissexto == 1)
        {   
            //Meses
            if(mesData < 1 || mesData > 12)
                errosData++;
            //Dias                
            if(mesData == 1||mesData == 3||mesData == 5||mesData == 7||
            mesData == 8||mesData == 10||mesData == 12)
                if(diaData < 1 || diaData > 31)
                    errosData++;
            if(mesData == 4||mesData == 6||mesData == 9||mesData == 11)
                if(diaData < 1 || diaData > 30)
                    errosData++;
            if(mesData == 2 && (diaData < 1 || diaData > 29))
                errosData++;
        }
        else
        {
            //Meses
            if(mesData < 1 || mesData > 12)
                errosData++;
            //Dias
            if(mesData == 1||mesData == 3||mesData == 5||mesData == 7||
            mesData == 8||mesData == 10||mesData == 12)
                if(diaData < 1 || diaData > 31)
                    errosData++;
            if(mesData == 4||mesData == 6||mesData == 9||mesData == 11)
                if(diaData < 1 || diaData > 30)
                    errosData++;
            if(mesData == 2 && (diaData < 1 || diaData > 28))
                errosData++;
        }
    }
    

    /*Conclusão da validação*/
    if (errosData == 0)
    {
        printf("DATA VALIDA\n");
        chaveDeValidar++;
    }
    else
    {
        printf("ERRO: Data invalida\n");
    }
}
/*********************************************************/
//Inserir aluno
void inserirAluno()
{
    printf("***Cadastrar aluno***\n");
    //Matrícula
    /*Gerar matrícula*/        
    gerarMatricula(cadastrosComSucesso + 1);
    //Nome
    printf("Digite o nome do(a) estudante: ");
    scanf("%51[^\n]%*c", aluno[cadastrosComSucesso + 1].nome);
    //Sexo
    printf("Digite o sexo do(a) estudante(F - Feminino|M - Masculino|O - Outro): ");
    scanf("%1c%*c", &aluno[cadastrosComSucesso + 1].sexo);
    if(aluno[cadastrosComSucesso + 1].sexo >= 'a' && aluno[cadastrosComSucesso + 1].sexo <= 'z')
        aluno[cadastrosComSucesso + 1].sexo -= 32; //Tornar o input com letras maiúsculas
    //Data de nascimento
    printf("Digite a data de nascimento(dd/mm/aaaa): ");
    scanf("%[^\n]%*c", &aluno[cadastrosComSucesso + 1].dataNasc);
    //CPF
    printf("Digite o CPF do(a) estudante(XXX.XXX.XXX-XX): ");
    scanf("%[^\n]%*c", &aluno[cadastrosComSucesso + 1].cpf);
    /*Validações*/
    validarNome(aluno[cadastrosComSucesso + 1].nome);
    validarSexo(aluno[cadastrosComSucesso + 1].sexo);
    validarNasc(aluno[cadastrosComSucesso + 1].dataNasc);
    validarCPF(aluno[cadastrosComSucesso + 1].cpf);
    if(chaveDeValidar == 4)
        cadastrosComSucesso++;
}

//Excluir aluno
void excluirAluno()
{
    printf("****************************\n");
    char matriculaExcluir[13];
    printf("Digite a matricula do aluno: ");
    scanf("%13[^\n]%*c", matriculaExcluir);
    int jContador;
    int numeroDoAlunoEmLista = 0;
    int caracteresIguais;
    int achou = 0;//0 - Não achou|1 - Achou
    while(numeroDoAlunoEmLista < cadastrosComSucesso)
    {
        caracteresIguais = 0;
        jContador = 0;
        while(matriculaExcluir[jContador] == aluno[numeroDoAlunoEmLista].matricula[jContador])
        {
            jContador++;
            caracteresIguais++;
        }
        if(caracteresIguais == jContador)
        {
            achou = 1;
            printf("ALUNO ENCONTRADO\n");
            excluirAlunoNaLista(numeroDoAlunoEmLista);
            cadastrosComSucesso -= achou;
            break;
        }
        numeroDoAlunoEmLista++;
    }
    if(achou == 0)
    {
        printf("ALUNO NAO ENCONTRADO: Certifique-se do numero da matricula\n");
    }
}

//Excluir os dados do aluno na lista
int excluirAlunoNaLista(int indiceAluno)
{
    for(int iContador = 0; aluno[indiceAluno].matricula[iContador] != '\0'; iContador++)
    {
        //Apagar a matrícula cadastrada
        aluno[indiceAluno].matricula[iContador] = 0;
    }
    for(int iContador = 0; aluno[indiceAluno].nome[iContador] != '\0'; iContador++)
    {
        //Apagar o nome cadastrado
        aluno[indiceAluno].nome[iContador] = 0;
    }
    aluno[indiceAluno].sexo = 0; //Apagar o sexo cadastrado
    for(int iContador = 0; aluno[indiceAluno].cpf[iContador] != '\0'; iContador++)
    {
        //Apagar o CPF cadastrado
        aluno[indiceAluno].cpf[iContador] = 0;
    }
    printf("**OS DADOS DO ALUNO FORAM EXCLUIDOS**\n\n");
}

//Listar alunos
void listarAlunos()
{
    printf("\nLista de alunos cadastrados\n*******************************\n\n");
    int iContador = 0;
    while(iContador < cadastrosComSucesso)
    {
        printf("MATRICULA: %s\n", aluno[iContador].matricula);
        printf("NOME: %s\n", aluno[iContador].nome);
        printf("SEXO: %c\n", aluno[iContador].sexo);
        printf("DATA DE NASC.: %s\n", aluno[iContador].dataNasc);
        printf("CPF: %s\n", aluno[iContador].cpf);
        printf("*******************************\n");
        iContador++;
    }
    printf("Listagem completa...\n\n");
}