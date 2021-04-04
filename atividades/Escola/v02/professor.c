#include <stdio.h>
#include "professor.h"
/*Variáveis para auxiliar a contagem dos alunos*/
int chaveDeValidarProf;
int cadastrosComSucessoProf = 0;
int cadastrosProfExcluidos = 0;

void menuProf()
{
    char escolha = '1';
    while(escolha != '0')
    {
        printf("******************************\n");
        printf("*       INFO PROFESSOR       *\n");
        printf("******************************\n");
        /*menu Aluno*/
        printf("\nEscolha uma opcao a seguir:\n");
        printf("0 - Voltar\n");
        printf("1 - Inserir professor\n");
        printf("2 - Excluir professor\n");
        printf("3 - Listar professor\n::");

        scanf("%c", &escolha);
        while(getchar() != '\n');/*Pular o char new line no input*/
        switch(escolha)
        {
            case '0':
            {
                printf("Voltar...\n");
            }break;
            case '1':
            {
                inserirProf();
            }break;
            case '2':
            {
                excluirProf();
            }break;
            case '3':
            {
                listarProf();
            }break;
            default:
            {
                printf("INPUT INVALIDO\n");
            }break;
        }
    
    }
    
}
/*Geração de matrícula*/
void gerarMatriculaProf(int inputIndiceProf)
{   
    
    inputIndiceProf++;//+1 para inicializar a numeração do cadastro
    if(inputIndiceProf <= QTD_DE_ALUNOS)
    {
        if(cadastrosProfExcluidos > 0)
        inputIndiceProf += cadastrosProfExcluidos;
        /*É necessário somar o char '0' a todos os valores inteiros na 
         *conversão de inteiro para char, pois o valor inteiro do char
         *'0' somado ao número inteiro equivale ao seu char correspon-
         *dente.
         */
        //Decomposição do índice do professor
        char centenaProf = (inputIndiceProf / 100) + '0';
        char dezenaProf = ((inputIndiceProf % 100) / 10) + '0';
        char unidadeProf = (inputIndiceProf % 10) + '0';
        inputIndiceProf--;//-1 para armazenar na variável correta
        //Ano
        char ano[TAM_CARACTER_ANO] = "2021\0";
        //Criação da string que representa a matrícula
        int contador = 0;
        while(contador < TAM_MATRICULA_PROF - 1)
        {
            if(contador >= 0 && contador <= 3)
            {
                professor[inputIndiceProf].matricula[contador] = ano[contador];
            }
            if(contador == 4)
            {
                professor[inputIndiceProf].matricula[contador] = '.';
            }
            if(contador == 5)
            {
                professor[inputIndiceProf].matricula[contador] = centenaProf;
            }
            if(contador == 6)
            {
                professor[inputIndiceProf].matricula[contador] = dezenaProf;
            }
            if(contador == 7)
            {
                professor[inputIndiceProf].matricula[contador] = unidadeProf;
            }
            
        	contador++;
        }
        if(contador == TAM_MATRICULA_PROF - 1)
        {
            professor[inputIndiceProf].matricula[contador] = '\0';
        }
            

        printf("MATRICULA GERADA: %s\n", professor[inputIndiceProf].matricula);
        /*Matrícula do tipo: XXXX.XXX -> Ano.Número Do Professor*/
    }
    else
    {
        printf("SEM VAGAS PARA CADASTRO DE MAIS PROFESSORES\n");
    }

}
/*Verificações da entrada de dados do cadastro*/
void validarNomeProf(char inputNome[])
{   
    
    int tamanhoInputNome = 0;
    while(inputNome[tamanhoInputNome] != '\0') tamanhoInputNome++;
    tamanhoInputNome--;
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
        chaveDeValidarProf++;
    }
    else
        printf("ERRO: Nome invalido\n");
}
void validarCPFProf(char cpf[])
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
    if(somaContadores == TAM_CPF - 1)
    {
        printf("CPF VALIDO\n");
        chaveDeValidarProf++;
    }
    else
    {
        printf("ERRO: CPF invalido\n");
        //contaErros++;
    }
    
}
void validarSexoProf(char sexo)
{
    if(sexo == 'M'||sexo == 'F'||sexo == 'O')
    {
        printf("SEXO VALIDO\n");
        chaveDeValidarProf++;
    }
    else
    {
        printf("ERRO: Sexo invalido\n");
    }
}
void validarNascProf(char data[])
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
        chaveDeValidarProf++;
    }
    else
    {
        printf("ERRO: Data invalida\n");
    }
}
/*********************************************************/
//Inserir professor
void inserirProf()
{
    chaveDeValidarProf = 0;
    printf("***Cadastrar professor***\n");
    //Matrícula       
    gerarMatriculaProf(cadastrosComSucessoProf);
    //Nome
    inserirNomeProf();
    //Sexo
    inserirSexoProf();
    //Data de nascimento
    inserirDataProf();
    //CPF
    inserirCpfProf();
    /*Validações*/
    validarNomeProf(professor[cadastrosComSucessoProf].nome);
    validarSexoProf(professor[cadastrosComSucessoProf].sexo);
    validarNascProf(professor[cadastrosComSucessoProf].dataNasc);
    validarCPFProf(professor[cadastrosComSucessoProf].cpf);
    if(chaveDeValidarProf == 4)
        cadastrosComSucessoProf++;
}
/*######Funções de preenchimento dos campos######*/
void inserirNomeProf()
{
    printf("Digite o nome do(a) professor(a): ");
    fgets(professor[cadastrosComSucessoProf].nome, TAM_NOME, stdin);
    int contaCaracter = 0;
    while(professor[cadastrosComSucessoProf].nome[contaCaracter] != '\n')contaCaracter++;
    professor[cadastrosComSucessoProf].nome[contaCaracter] = '\n';
    setbuf(stdin, NULL);
}
void inserirSexoProf()
{
    printf("Digite o sexo do(a) professor(a)(F - Feminino|M - Masculino|O - Outro): ");
    scanf("%c", &professor[cadastrosComSucessoProf].sexo);
    /* Pula o restante da linha */
    while( getchar() != '\n' );
    if(professor[cadastrosComSucessoProf].sexo >= 'a' && professor[cadastrosComSucessoProf].sexo <= 'z')
        professor[cadastrosComSucessoProf].sexo -= 32; //Tornar o input com letras maiúsculas
    setbuf(stdin, NULL);
}
void inserirDataProf()
{
    printf("Digite a data de nascimento(dd/mm/aaaa): ");
    scanf("%[^\n]%*c", professor[cadastrosComSucessoProf].dataNasc);
    setbuf(stdin, NULL);
}
void inserirCpfProf()
{
    printf("Digite o CPF do(a) professor(a)(XXX.XXX.XXX-XX): ");
    scanf("%[^\n]%*c", professor[cadastrosComSucessoProf].cpf);
    setbuf(stdin, NULL);
}
/*###############################################*/
//Excluir professor
void excluirProf()
{
    printf("****************************\n");
    char matriculaExcluir[TAM_MATRICULA_PROF];
    printf("Digite a matricula do(a) professor(a): ");
    scanf("%13[^\n]%*c", matriculaExcluir);
    int jContador;
    int numeroDoProfEmLista = 0;
    int caracteresIguais;
    int achou = 0;//0 - Não achou|1 - Achou
    while(numeroDoProfEmLista < cadastrosComSucessoProf)
    {
        caracteresIguais = 0;
        jContador = 0;
        while(matriculaExcluir[jContador] == professor[numeroDoProfEmLista].matricula[jContador])
        {
            jContador++;
            caracteresIguais++;
        }
        if(caracteresIguais == jContador)
        {
            achou = 1;
            printf("PROFESSOR ENCONTRADO\n");
            cadastrosComSucessoProf += excluirProfNaLista(numeroDoProfEmLista);
            cadastrosProfExcluidos += achou;
            break;
        }
        numeroDoProfEmLista++;
    }
    if(achou == 0)
    {
        printf("PROFESSOR NAO ENCONTRADO: Certifique-se do numero da matricula\n");
    }
}

//Excluir os dados do professor na lista
int excluirProfNaLista(int indiceProf)
{
    /*Shift para excluir os dados*/
    while(indiceProf <= cadastrosComSucessoProf)
    {
        for(int iContador = 0; professor[indiceProf].matricula[iContador] != '\0'; iContador++)
        {
            //Apagar a matrícula cadastrada
            professor[indiceProf].matricula[iContador] = 0;
        }

        for(int iContador = 0; professor[indiceProf].nome[iContador] != '\0' && professor[indiceProf + 1].nome[iContador] != '\0'; iContador++)
        {
            //Apagar o nome cadastrado
            professor[indiceProf].nome[iContador] = 0;
        }

        professor[indiceProf].sexo = 0; //Apagar o sexo cadastrado

        for(int iContador = 0; professor[indiceProf].cpf[iContador] != '\0'; iContador++)
        {
            //Apagar o CPF cadastrado
            professor[indiceProf].cpf[iContador] = 0;
        }
        indiceProf++;
    }
    printf("**OS DADOS DO(A) PROFESSOR(A) FORAM EXCLUIDOS**\n\n");
    return -1;
}

//Listar professores
void listarProf()
{   
    /*BUG: Quando lista professores, com pelo menos um excluído*
    *, o programa exibe um cadastro com dados vazios.          *
    */
    printf("\nLista de professores cadastrados(as)\n*******************************\n\n");
    int iContador = 0;
    while(iContador <= cadastrosComSucessoProf)
    {
        printf("MATRICULA: %s\n", professor[iContador].matricula);
        printf("NOME: %s\n", professor[iContador].nome);
        printf("SEXO: %c\n", professor[iContador].sexo);
        printf("DATA DE NASC.: %s\n", professor[iContador].dataNasc);
        printf("CPF: %s\n", professor[iContador].cpf);
        printf("*******************************\n");
        iContador++;
    }
    printf("Listagem completa...\n\n");
}