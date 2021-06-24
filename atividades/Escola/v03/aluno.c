#include <stdio.h>
#include "aluNo.h"

int chaveDeValidarAluNo;
int cadastrosComSucessoAluNo;
int cadastrosAluNoExcluidos;
cadastroAluNo aluNo[QTD_DE_ALUNoS];

void menuAluNo()
{
    /**********************************************/
    char escolha = '1';
    while(escolha != '0')
    {
        printf("******************************\n");
        printf("*         INFO ALUNo         *\n");
        printf("******************************\n");
        /*menu AluNo*/
        printf("\nEscolha uma opcao a seguir:\n");
        printf("0 - Voltar\n");
        printf("1 - Inserir aluNo\n");
        printf("2 - Excluir aluNo\n");
        printf("3 - Listar aluNos\n");
        printf("4 - Atualizar dados de aluNo\n::");

        scanf("%c", &escolha);
        while(getchar() != '\n');/*Pular o char new line No input*/
        switch(escolha)
        {
            case '0':
            {
                printf("Voltar...\n");
            }break;
            case '1':
            {
                inserirAluNo();
            }break;
            case '2':
            {
                excluirAluNo();
            }break;
            case '3':
            {
                listarAluNos();
            }break;
            case '4':
            {
                procurarAtualizarAluNo();
            }break;
            default:
            {
                printf("INPUT INVALIDO\n");
            }break;
        }
    
    }
    
}
/*Geração de matrícula*/
void gerarMatriculaAluNo(int inputIndiceAluNo)
{   
    inputIndiceAluNo++;//+1 para inicializar a numeração do cadastro
    if(inputIndiceAluNo <= QTD_DE_ALUNoS)
    {
        if(cadastrosAluNoExcluidos > 0)
        inputIndiceAluNo += cadastrosAluNoExcluidos;
        /*É necessário somar o char '0' a todos os valores inteiros na 
         *conversão de inteiro para char, pois o valor inteiro do char
         *'0' somado ao número inteiro equivale ao seu char correspon-
         *dente.
         */
        //Decomposição do índice do aluNo
        char centenaAluNo = (inputIndiceAluNo / 100) + '0';
        char dezenaAluNo = ((inputIndiceAluNo % 100) / 10) + '0';
        char unidadeAluNo = (inputIndiceAluNo % 10) + '0';
        inputIndiceAluNo--;//-1 para armazenar na variável correta
        //ANo e semestre
        char aNo[TAM_CARACTER_ANo] = "2021\0";
        char semestre = '1';
        //Criação da string que representa a matrícula
        int contador = 0;
        while(contador < TAM_MATRICULA_ALUNo - 1)
        {
            if(contador >= 0 && contador <= 3)
            {
                aluNo[inputIndiceAluNo].matricula[contador] = aNo[contador];
            }
            if(contador == 4||contador == 6)
            {
                aluNo[inputIndiceAluNo].matricula[contador] = '.';
            }
            if(contador == 5)
            {
                aluNo[inputIndiceAluNo].matricula[contador] = semestre;
            }
            if(contador == 7)
            {
                aluNo[inputIndiceAluNo].matricula[contador] = centenaAluNo;
            }
            if(contador == 8)
            {
                aluNo[inputIndiceAluNo].matricula[contador] = dezenaAluNo;
            }
            if(contador == 9)
            {
                aluNo[inputIndiceAluNo].matricula[contador] = unidadeAluNo;
            }
            
        	contador++;
        }
        if(contador == TAM_MATRICULA_ALUNo - 1)
            aluNo[inputIndiceAluNo].matricula[contador] = '\0';

        printf("MATRICULA GERADA: %s\n", aluNo[inputIndiceAluNo].matricula);
    }
    else
    {
        printf("SEM VAGAS PARA CADASTRO DE MAIS ALUNoS\n");
    }

}
/*Verificações da entrada de dados do cadastro*/
int validarNomeAluNo(char inputNome[])
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
        chaveDeValidarAluNo++;
        return 1;
    }
    else
    {
        printf("ERRO: Nome invalido\n");
        return 0;
    }
        
}
int validarCPFAluNo(char cpf[])
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
        chaveDeValidarAluNo++;
        return 1;
    }
    else
    {
        printf("ERRO: CPF invalido\n");
        return 0;
    }
    
}
int validarSexoAluNo(char sexo)
{
    if(sexo == 'M'||sexo == 'F'||sexo == 'O')
    {
        chaveDeValidarAluNo++;
        return 1;
    }
    else
    {
        printf("ERRO: Sexo invalido\n");
        return 0;
    }
}
int validarNascAluNo(char data[])
{
    int errosData = 0;
    /*Decomposição da data*/
    int tamDoInput = 0;
    int contaCaracterBarra = 0;
    int contaDiaNumero = 0;
    int contaMesNumero = 0;
    int contaANoNumero = 0;
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
                    contaANoNumero++;
            }
        }
        if ((tamDoInput == 2 || tamDoInput == 5 )&& data[tamDoInput] == '/')
        {
            contaCaracterBarra++;
        }
        tamDoInput++;
    }

    if(contaDiaNumero != 2||contaMesNumero != 2||contaANoNumero != 4||contaCaracterBarra != 2)
        errosData++;
    else
    {
        /*Aquisição das partes da data*/
            char diaChar[TAM_CARACTER_DIA];
            char mesChar[TAM_CARACTER_MES];
            char aNoChar[TAM_CARACTER_ANo];

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
            //aNo
            jContador = 0;
            iContador++;
            while (jContador < TAM_CARACTER_ANo - 1)
            {
                aNoChar[jContador] = data[iContador];
                iContador++;
                jContador++;
            }
            aNoChar[jContador] = '\0';

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
        
        //Conversão da string aNo
        int aNoData = 0;
        indiceDoAlgarismo = 0;
        while(indiceDoAlgarismo < TAM_CARACTER_ANo - 1)
        {
            switch(indiceDoAlgarismo)
            {
                case 0:{
                    aNoData += (aNoChar[indiceDoAlgarismo] - '0') * 1000;
                }break;
                case 1:{
                    aNoData += (aNoChar[indiceDoAlgarismo] - '0') * 100;
                }break;
                case 2:{
                    aNoData += (aNoChar[indiceDoAlgarismo] - '0') * 10;
                }break;
                case 3:{
                    aNoData += (aNoChar[indiceDoAlgarismo] - '0') * 1;
                }break;
            }
            indiceDoAlgarismo++;
        }

        /*Verificação de aNo bissexto*/
        int bissexto = 0; //0 - Comum | 1 - Bissexto
        if(aNoData % 400 == 0)
            bissexto = 1;
        else
            if(aNoData % 4 == 0 && (aNoData % 100 != 0))
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
        chaveDeValidarAluNo++;
        return 1;
    }
    else
    {
        printf("ERRO: Data invalida\n");
        return 0;
    }
}
/*********************************************************/
//Inserir aluNo
void inserirAluNo()
{
    chaveDeValidarAluNo = 0;
    printf("***Cadastrar aluNo***\n");
    //Matrícula    
    gerarMatriculaAluNo(cadastrosComSucessoAluNo);
    //Nome
    inserirNomeAluNo();
    //Sexo
    inserirSexoAluNo();
    //Data de nascimento
    inserirDataAluNo();
    //CPF
    inserirCpfAluNo();
    /*Validações*/
    validarNomeAluNo(aluNo[cadastrosComSucessoAluNo].Nome);
    validarSexoAluNo(aluNo[cadastrosComSucessoAluNo].sexo);
    validarNascAluNo(aluNo[cadastrosComSucessoAluNo].dataNasc);
    validarCPFAluNo(aluNo[cadastrosComSucessoAluNo].cpf);
    if(chaveDeValidarAluNo == 4)
    {
        cadastrosComSucessoAluNo++;
        printf("\n***ALUNo CADASTRADO COM SUCESSO***\n");
    }    
}
/*######Funções para inserir os dados do aluNo######*/
void inserirNomeAluNo()
{
    printf("Digite o Nome do(a) estudante: ");
    fgets(aluNo[cadastrosComSucessoAluNo].Nome, sizeof(aluNo[cadastrosComSucessoAluNo].Nome), stdin);
    int contaCaracter = 0;
    while(aluNo[cadastrosComSucessoAluNo].Nome[contaCaracter] != '\n')contaCaracter++;
    aluNo[cadastrosComSucessoAluNo].Nome[contaCaracter] = '\0';
    setbuf(stdin, NULL);
}
void inserirSexoAluNo()
{
    printf("Digite o sexo do(a) estudante(F - FeminiNo|M - MasculiNo|O - Outro): ");
    scanf("%c", &aluNo[cadastrosComSucessoAluNo].sexo);
    /* Pula o restante da linha */
    while(getchar() != '\n');
    if(aluNo[cadastrosComSucessoAluNo].sexo >= 'a' && aluNo[cadastrosComSucessoAluNo].sexo <= 'z')
        aluNo[cadastrosComSucessoAluNo].sexo -= 32; //Tornar o input com letras maiúsculas
}
void inserirDataAluNo()
{
    printf("Digite a data de nascimento(dd/mm/aaaa): ");
    /*fgets(aluNo[cadastrosComSucessoAluNo].dataNasc, sizeof(aluNo[cadastrosComSucessoAluNo].dataNasc), stdin);
    int contaCaracter = 0;
    while(aluNo[cadastrosComSucessoAluNo].dataNasc[contaCaracter] != '\n')contaCaracter++;
    aluNo[cadastrosComSucessoAluNo].dataNasc[contaCaracter] = '\0';*/
    scanf("%[^\n]%*c", aluNo[cadastrosComSucessoAluNo].dataNasc);
    setbuf(stdin, NULL);
}
void inserirCpfAluNo()
{
    printf("Digite o CPF do(a) estudante(XXX.XXX.XXX-XX): ");
    /*fgets(aluNo[cadastrosComSucessoAluNo].cpf, sizeof(aluNo[cadastrosComSucessoAluNo].cpf), stdin);
    int contaCaracter = 0;
    while(aluNo[cadastrosComSucessoAluNo].cpf[contaCaracter] != '\n')contaCaracter++;
    aluNo[cadastrosComSucessoAluNo].cpf[contaCaracter] = '\0';*/
    scanf("%[^\n]%*c", aluNo[cadastrosComSucessoAluNo].cpf);
    setbuf(stdin, NULL);
}
/*##################################################*/
//Excluir aluNo
void excluirAluNo()
{
    printf("****************************\n");
    char matriculaExcluir[TAM_MATRICULA_ALUNo];
    printf("Digite a matricula do aluNo: ");
    scanf("%13[^\n]%*c", matriculaExcluir);
    int jContador;
    int numeroDoAluNoEmLista = 0;
    int caracteresIguais;
    int achou = 0;//0 - Não achou|1 - Achou
    while(numeroDoAluNoEmLista < cadastrosComSucessoAluNo)
    {
        caracteresIguais = 0;
        jContador = 0;
        while(matriculaExcluir[jContador] == aluNo[numeroDoAluNoEmLista].matricula[jContador])
        {
            jContador++;
            caracteresIguais++;
        }
        if(caracteresIguais == jContador)
        {
            achou = 1;
            printf("ALUNo ENCONTRADO\n");
            cadastrosComSucessoAluNo += excluirAluNoNaLista(numeroDoAluNoEmLista);
            cadastrosAluNoExcluidos += achou;
            break;
        }
        numeroDoAluNoEmLista++;
    }
    if(achou == 0)
    {
        printf("ALUNo NAO ENCONTRADO: Certifique-se do numero da matricula\n");
    }
}

//Excluir os dados do aluNo na lista
int excluirAluNoNaLista(int indiceAluNo)
{
    /*Aplicação simples de shift*/
    while(indiceAluNo <= cadastrosComSucessoAluNo)
    {
        for(int iContador = 0; aluNo[indiceAluNo].matricula[iContador] != '\0'; iContador++)
        {
            //Apagar a matrícula cadastrada
            aluNo[indiceAluNo].matricula[iContador] = aluNo[indiceAluNo + 1].matricula[iContador];
        }
    
        for(int iContador = 0; aluNo[indiceAluNo].Nome[iContador] != '\0' && aluNo[indiceAluNo + 1].Nome[iContador] != '\0'; iContador++)
        {
            //Apagar o Nome cadastrado
            aluNo[indiceAluNo].Nome[iContador] = aluNo[indiceAluNo + 1].Nome[iContador];
        }
    
        aluNo[indiceAluNo].sexo = aluNo[indiceAluNo + 1].sexo; //Apagar o sexo cadastrado
    
        for(int iContador = 0; aluNo[indiceAluNo].cpf[iContador] != '\0'; iContador++)
        {
            //Apagar o CPF cadastrado
            aluNo[indiceAluNo].cpf[iContador] = aluNo[indiceAluNo + 1].cpf[iContador];
        }
        indiceAluNo++;
    }
    
    printf("**OS DADOS DO ALUNo FORAM EXCLUIDOS**\n\n");
    return -1;
}

//Listar aluNos
void listarAluNos()
{   
    /*BUG: Quando lista aluNos, com pelo meNos um excluído*
    *, o programa exibe um cadastro com dados vazios.     *
    */
    printf("\nLista de aluNos cadastrados\n*******************************\n\n");
    int iContador = 0;
    while(iContador < cadastrosComSucessoAluNo)
    {
        printf("MATRICULA: %s\n", aluNo[iContador].matricula);
        printf("NoME: %s\n", aluNo[iContador].Nome);
        printf("SEXO: %c\n", aluNo[iContador].sexo);
        printf("DATA DE NASC.: %s\n", aluNo[iContador].dataNasc);
        printf("CPF: %s\n", aluNo[iContador].cpf);
        printf("*******************************\n");
        iContador++;
    }
    printf("Listagem completa...\n\n");
}

//Atualizar dados
void procurarAtualizarAluNo()
{
    char inputNomeAluNo[TAM_NoME];
    printf("Digite o Nome do aluNo que voce deseja atualizar algum dado?:: ");
    scanf("%51[^\n]%*c", inputNomeAluNo);
    int indiceAluNo = 0;
    while(indiceAluNo <= cadastrosComSucessoAluNo)
    {
        int iContador = 0;
        int contadorCaracteresReais = 0;
        while(inputNomeAluNo[iContador] != '\0')
        {
	    	if(inputNomeAluNo[iContador] == aluNo[indiceAluNo].Nome[iContador])
            {
                contadorCaracteresReais++;
            }
            iContador++;
	    }
        if(contadorCaracteresReais == iContador - 1)
        {
            alterarDadosAluNo(indiceAluNo);
        }
        else
        {
            printf("NAO FOI POSSIVEL ENCONTRAR O ALUNo\n");
            break;
        }
        indiceAluNo++;
    }
}

void alterarDadosAluNo(int indiceAluNo)
{
    char opcao = '1';
    while(opcao != '0')
    {  
        printf("\nDigite qual dos dados do aluNo deseja alterar:\n");
        printf("0 - Voltar\n");
        printf("1 - Alterar Nome\n");
        printf("2 - Alterar sexo\n");
        printf("3 - Alterar CPF\n");
        printf("4 - Alterar data de nascimento\n");

        scanf("%1c", &opcao);
        while(getchar() != '\n');/*Pular o char new line No input*/
        switch(opcao)
        {
            case '0':
            {
                printf("Voltar...");    
            }break;
            case '1':
            {   
                char NomeSubst[TAM_NoME];
                printf("Digite Nome que deseja colocar: ");
                scanf("%50[^\n]%*c", NomeSubst);
    
                if(validarNomeAluNo(NomeSubst) == 1)
                {
                    int iContador = 0;
                    while(NomeSubst[iContador] != '\0')
                    {
                        aluNo[indiceAluNo].Nome[iContador] = NomeSubst[iContador];
                        iContador++;
                    }
                    aluNo[indiceAluNo].Nome[iContador] = '\0';   
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
                if(validarSexoAluNo(sexoSubst) == 1)
                {
                    aluNo[indiceAluNo].sexo = sexoSubst;
                }
            }break;
            case '3':
            {
                char cpfSubst[TAM_NoME];
                printf("Digite o CPF que deseja colocar: ");
                scanf("%14[^\n]%*c", cpfSubst);
                if(validarCPFAluNo(cpfSubst) == 1)
                {
                    int iContador = 0;
                    while(cpfSubst[iContador] != '\0')
                    {
                        aluNo[indiceAluNo].cpf[iContador] = cpfSubst[iContador];
                        iContador++;
                    }
                    aluNo[indiceAluNo].cpf[iContador] = '\0';   
                }
            }break;
            case '4':
            {
                char dataNascSubst[TAM_NoME];
                aluNo[indiceAluNo].dataNasc;
                printf("Digite a data de nascimento que deseja colocar: ");
                scanf("%10[^\n]%*c", dataNascSubst);
                if(validarNascAluNo(dataNascSubst) == 1)
                {
                    int iContador = 0;
                    while(dataNascSubst[iContador] != '\0')
                    {
                        aluNo[indiceAluNo].dataNasc[iContador] = dataNascSubst[iContador];
                        iContador++;
                    }
                    aluNo[indiceAluNo].dataNasc[iContador] = '\0';   
                }
            }break;
            default:
            {
                printf("INPUT INVALIDO\n");
            }break;
        }
    }
    
}