#include <stdio.h>
#include "aluno.h"

int chaveDeValidarAluno;
int cadastrosComSucessoAluno;
int cadastrosAlunoExcluidos;
cadastroAluno aluno[QTD_DE_ALUNOS];

void menuAluno()
{
    /**********************************************/
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
        printf("3 - Listar alunos\n");
        printf("4 - Atualizar dados de aluno\n::");

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
            case '4':
            {
                procurarAtualizarAluno();
            }break;
            default:
            {
                printf("INPUT INVALIDO\n");
            }break;
        }
    
    }
    
}
/*Geração de matrícula*/
void gerarMatriculaAluno(int inputIndiceAluno)
{   
    inputIndiceAluno++;//+1 para inicializar a numeração do cadastro
    if(inputIndiceAluno <= QTD_DE_ALUNOS)
    {
        if(cadastrosAlunoExcluidos > 0)
        inputIndiceAluno += cadastrosAlunoExcluidos;
        /*É necessário somar o char '0' a todos os valores inteiros na 
         *conversão de inteiro para char, pois o valor inteiro do char
         *'0' somado ao número inteiro equivale ao seu char correspon-
         *dente.
         */
        //Decomposição do índice do aluno
        char centenaAluno = (inputIndiceAluno / 100) + '0';
        char dezenaAluno = ((inputIndiceAluno % 100) / 10) + '0';
        char unidadeAluno = (inputIndiceAluno % 10) + '0';
        inputIndiceAluno--;//-1 para armazenar na variável correta
        //Ano e semestre
        char ano[TAM_CARACTER_ANO] = "2021\0";
        char semestre = '1';
        //Criação da string que representa a matrícula
        int contador = 0;
        while(contador < TAM_MATRICULA_ALUNO - 1)
        {
            if(contador >= 0 && contador <= 3)
            {
                aluno[inputIndiceAluno].matricula[contador] = ano[contador];
            }
            if(contador == 4||contador == 6)
            {
                aluno[inputIndiceAluno].matricula[contador] = '.';
            }
            if(contador == 5)
            {
                aluno[inputIndiceAluno].matricula[contador] = semestre;
            }
            if(contador == 7)
            {
                aluno[inputIndiceAluno].matricula[contador] = centenaAluno;
            }
            if(contador == 8)
            {
                aluno[inputIndiceAluno].matricula[contador] = dezenaAluno;
            }
            if(contador == 9)
            {
                aluno[inputIndiceAluno].matricula[contador] = unidadeAluno;
            }
            
        	contador++;
        }
        if(contador == TAM_MATRICULA_ALUNO - 1)
            aluno[inputIndiceAluno].matricula[contador] = '\0';

        printf("MATRICULA GERADA: %s\n", aluno[inputIndiceAluno].matricula);
    }
    else
    {
        printf("SEM VAGAS PARA CADASTRO DE MAIS ALUNOS\n");
    }

}
/*Verificações da entrada de dados do cadastro*/
int validarNomeAluno(char inputNome[])
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
        chaveDeValidarAluno++;
        return 1;
    }
    else
    {
        printf("ERRO: Nome invalido\n");
        return 0;
    }
        
}
int validarCPFAluno(char cpf[])
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
        chaveDeValidarAluno++;
        return 1;
    }
    else
    {
        printf("ERRO: CPF invalido\n");
        return 0;
    }
    
}
int validarSexoAluno(char sexo)
{
    if(sexo == 'M'||sexo == 'F'||sexo == 'O')
    {
        chaveDeValidarAluno++;
        return 1;
    }
    else
    {
        printf("ERRO: Sexo invalido\n");
        return 0;
    }
}
int validarNascAluno(char data[])
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
        chaveDeValidarAluno++;
        return 1;
    }
    else
    {
        printf("ERRO: Data invalida\n");
        return 0;
    }
}
/*********************************************************/
//Inserir aluno
void inserirAluno()
{
    chaveDeValidarAluno = 0;
    printf("***Cadastrar aluno***\n");
    //Matrícula    
    gerarMatriculaAluno(cadastrosComSucessoAluno);
    //Nome
    inserirNomeAluno();
    //Sexo
    inserirSexoAluno();
    //Data de nascimento
    inserirDataAluno();
    //CPF
    inserirCpfAluno();
    /*Validações*/
    validarNomeAluno(aluno[cadastrosComSucessoAluno].nome);
    validarSexoAluno(aluno[cadastrosComSucessoAluno].sexo);
    validarNascAluno(aluno[cadastrosComSucessoAluno].dataNasc);
    validarCPFAluno(aluno[cadastrosComSucessoAluno].cpf);
    if(chaveDeValidarAluno == 4)
    {
        cadastrosComSucessoAluno++;
        printf("\n***ALUNO CADASTRADO COM SUCESSO***\n");
    }    
}
/*######Funções para inserir os dados do aluno######*/
void inserirNomeAluno()
{
    printf("Digite o nome do(a) estudante: ");
    fgets(aluno[cadastrosComSucessoAluno].nome, sizeof(aluno[cadastrosComSucessoAluno].nome), stdin);
    int contaCaracter = 0;
    while(aluno[cadastrosComSucessoAluno].nome[contaCaracter] != '\n')contaCaracter++;
    aluno[cadastrosComSucessoAluno].nome[contaCaracter] = '\0';
    setbuf(stdin, NULL);
}
void inserirSexoAluno()
{
    printf("Digite o sexo do(a) estudante(F - Feminino|M - Masculino|O - Outro): ");
    scanf("%c", &aluno[cadastrosComSucessoAluno].sexo);
    /* Pula o restante da linha */
    while(getchar() != '\n');
    if(aluno[cadastrosComSucessoAluno].sexo >= 'a' && aluno[cadastrosComSucessoAluno].sexo <= 'z')
        aluno[cadastrosComSucessoAluno].sexo -= 32; //Tornar o input com letras maiúsculas
}
void inserirDataAluno()
{
    printf("Digite a data de nascimento(dd/mm/aaaa): ");
    /*fgets(aluno[cadastrosComSucessoAluno].dataNasc, sizeof(aluno[cadastrosComSucessoAluno].dataNasc), stdin);
    int contaCaracter = 0;
    while(aluno[cadastrosComSucessoAluno].dataNasc[contaCaracter] != '\n')contaCaracter++;
    aluno[cadastrosComSucessoAluno].dataNasc[contaCaracter] = '\0';*/
    scanf("%[^\n]%*c", aluno[cadastrosComSucessoAluno].dataNasc);
    setbuf(stdin, NULL);
}
void inserirCpfAluno()
{
    printf("Digite o CPF do(a) estudante(XXX.XXX.XXX-XX): ");
    /*fgets(aluno[cadastrosComSucessoAluno].cpf, sizeof(aluno[cadastrosComSucessoAluno].cpf), stdin);
    int contaCaracter = 0;
    while(aluno[cadastrosComSucessoAluno].cpf[contaCaracter] != '\n')contaCaracter++;
    aluno[cadastrosComSucessoAluno].cpf[contaCaracter] = '\0';*/
    scanf("%[^\n]%*c", aluno[cadastrosComSucessoAluno].cpf);
    setbuf(stdin, NULL);
}
/*##################################################*/
//Excluir aluno
void excluirAluno()
{
    printf("****************************\n");
    char matriculaExcluir[TAM_MATRICULA_ALUNO];
    printf("Digite a matricula do aluno: ");
    scanf("%13[^\n]%*c", matriculaExcluir);
    int jContador;
    int numeroDoAlunoEmLista = 0;
    int caracteresIguais;
    int achou = 0;//0 - Não achou|1 - Achou
    while(numeroDoAlunoEmLista < cadastrosComSucessoAluno)
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
            cadastrosComSucessoAluno += excluirAlunoNaLista(numeroDoAlunoEmLista);
            cadastrosAlunoExcluidos += achou;
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
    /*Aplicação simples de shift*/
    while(indiceAluno <= cadastrosComSucessoAluno)
    {
        for(int iContador = 0; aluno[indiceAluno].matricula[iContador] != '\0'; iContador++)
        {
            //Apagar a matrícula cadastrada
            aluno[indiceAluno].matricula[iContador] = aluno[indiceAluno + 1].matricula[iContador];
        }
    
        for(int iContador = 0; aluno[indiceAluno].nome[iContador] != '\0' && aluno[indiceAluno + 1].nome[iContador] != '\0'; iContador++)
        {
            //Apagar o nome cadastrado
            aluno[indiceAluno].nome[iContador] = aluno[indiceAluno + 1].nome[iContador];
        }
    
        aluno[indiceAluno].sexo = aluno[indiceAluno + 1].sexo; //Apagar o sexo cadastrado
    
        for(int iContador = 0; aluno[indiceAluno].cpf[iContador] != '\0'; iContador++)
        {
            //Apagar o CPF cadastrado
            aluno[indiceAluno].cpf[iContador] = aluno[indiceAluno + 1].cpf[iContador];
        }
        indiceAluno++;
    }
    
    printf("**OS DADOS DO ALUNO FORAM EXCLUIDOS**\n\n");
    return -1;
}

//Listar alunos
void listarAlunos()
{   
    /*BUG: Quando lista alunos, com pelo menos um excluído*
    *, o programa exibe um cadastro com dados vazios.     *
    */
    printf("\nLista de alunos cadastrados\n*******************************\n\n");
    int iContador = 0;
    while(iContador < cadastrosComSucessoAluno)
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

//Atualizar dados
void procurarAtualizarAluno()
{
    char inputNomeAluno[TAM_NOME];
    printf("Digite o nome do aluno que voce deseja atualizar algum dado?:: ");
    scanf("%51[^\n]%*c", inputNomeAluno);
    int indiceAluno = 0;
    while(indiceAluno <= cadastrosComSucessoAluno)
    {
        int iContador = 0;
        int contadorCaracteresReais = 0;
        while(inputNomeAluno[iContador] != '\0')
        {
	    	if(inputNomeAluno[iContador] == aluno[indiceAluno].nome[iContador])
            {
                contadorCaracteresReais++;
            }
            iContador++;
	    }
        if(contadorCaracteresReais == iContador - 1)
        {
            alterarDadosAluno(indiceAluno);
        }
        else
        {
            printf("NAO FOI POSSIVEL ENCONTRAR O ALUNO\n");
            break;
        }
        indiceAluno++;
    }
}

void alterarDadosAluno(int indiceAluno)
{
    char opcao = '1';
    while(opcao != '0')
    {  
        printf("\nDigite qual dos dados do aluno deseja alterar:\n");
        printf("0 - Voltar\n");
        printf("1 - Alterar nome\n");
        printf("2 - Alterar sexo\n");
        printf("3 - Alterar CPF\n");
        printf("4 - Alterar data de nascimento\n");

        scanf("%1c", &opcao);
        while(getchar() != '\n');/*Pular o char new line no input*/
        switch(opcao)
        {
            case '0':
            {
                printf("Voltar...");    
            }break;
            case '1':
            {   
                char nomeSubst[TAM_NOME];
                printf("Digite nome que deseja colocar: ");
                scanf("%50[^\n]%*c", nomeSubst);
    
                if(validarNomeAluno(nomeSubst) == 1)
                {
                    int iContador = 0;
                    while(nomeSubst[iContador] != '\0')
                    {
                        aluno[indiceAluno].nome[iContador] = nomeSubst[iContador];
                        iContador++;
                    }
                    aluno[indiceAluno].nome[iContador] = '\0';   
                }    
            }break;
            case '2':
            {
                char sexoSubst;
                printf("Digite o sexo que deseja colocar: ");
                scanf("%1c", &sexoSubst);
                /* Pula o restante da linha */
                while(getchar() != '\n');
                if(sexoSubst >= 'a' && sexoSubst <= 'z')
                    sexoSubst -= 32; //Tornar o input com letras maiúsculas
                if(validarSexoAluno(sexoSubst) == 1)
                {
                    aluno[indiceAluno].sexo = sexoSubst;
                }
            }break;
            case '3':
            {
                char cpfSubst[TAM_NOME];
                printf("Digite o CPF que deseja colocar: ");
                scanf("%14[^\n]%*c", cpfSubst);
                if(validarCPFAluno(cpfSubst) == 1)
                {
                    int iContador = 0;
                    while(cpfSubst[iContador] != '\0')
                    {
                        aluno[indiceAluno].cpf[iContador] = cpfSubst[iContador];
                        iContador++;
                    }
                    aluno[indiceAluno].cpf[iContador] = '\0';   
                }
            }break;
            case '4':
            {
                char dataNascSubst[TAM_NOME];
                aluno[indiceAluno].dataNasc;
                printf("Digite a data de nascimento que deseja colocar: ");
                scanf("%10[^\n]%*c", dataNascSubst);
                if(validarNascAluno(dataNascSubst) == 1)
                {
                    int iContador = 0;
                    while(dataNascSubst[iContador] != '\0')
                    {
                        aluno[indiceAluno].dataNasc[iContador] = dataNascSubst[iContador];
                        iContador++;
                    }
                    aluno[indiceAluno].dataNasc[iContador] = '\0';   
                }
            }break;
            default:
            {
                printf("INPUT INVALIDO\n");
            }break;
        }
    }
    
}