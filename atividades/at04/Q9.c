#include <stdio.h>
#include <stdlib.h>
#define TAM_NOME 21
#define TAM_DATA 11 //Corresponde a : "01/01/0001\0"
#define TAM_CPF 15 //Corresponde a : "123.456.789-00\0"
#define CARACTER_DIA 3
#define CARACTER_MES 3
#define CARACTER_ANO 5
/*Protótipo das funções utilizadas*/
void cadastrarCliente(void);
void validarNome(char inputNome[]);
void validarCPF(char cpf[]);
void validarSexo(char sexo);
void validarNasc(char data[]);
/*Struct dos dados do cliente*/
typedef struct
{
    char nome[TAM_NOME];
    char cpf[TAM_CPF];
    char sexo;
    char dataNasc[TAM_DATA];
}cliente;

cliente perfilCliente;

/*Chave de validação de erros*/
int contaErros = 0;//0 = Sem erros

/*Principal*/
int main(int argc, char *argv[])
{
    cadastrarCliente();
    /*Validação dos dados*/
    printf("\n\n===Validacao dos dados===\n\n");
    validarNome(perfilCliente.nome);
    validarCPF(perfilCliente.cpf);
    validarSexo(perfilCliente.sexo);
    validarNasc(perfilCliente.dataNasc);
    /*Retorno dos dados cadastrados*/
    if(contaErros == 0)
    {
        printf("\n\n===Dados cadastrados===\n\n");
        printf("Nome: %s\n", perfilCliente.nome);
        fflush(stdout);
        printf("CPF: %s\n", perfilCliente.cpf);
        printf("Sexo: %c\n", perfilCliente.sexo);
        printf("Data de nasc.: %s\n", perfilCliente.dataNasc);    
    }

    return 0;
}

void cadastrarCliente(void)
{
    printf("===Cadastro de cliente===\n\n");
    //Nome
    printf("Primeiro nome: ");
    gets(perfilCliente.nome);
    //CPF
    printf("CPF(Formato: XXX.XXX.XXX-XX): ");
    gets(perfilCliente.cpf);
    //Sexo
    printf("Sexo(M - Masculino|F - Feminino|O - Outro): ");
    scanf("%c", &perfilCliente.sexo);
    /*Capitalização do caractere que define sexo*/
    if(perfilCliente.sexo >= 'a' && perfilCliente.sexo <= 'z')
        perfilCliente.sexo -= 32; 
    //Data de nascimento
    while(getchar() != '\n' );/*Pular uma linha*/
    printf("Data de nascimento(Formato: dia/mes/ano): ");
    gets(perfilCliente.dataNasc);
    fflush(stdout);
}

/*Validar nome*/
void validarNome(char inputNome[])
{
    int tamDoInput = 0;
    int caracteresValidos = 0;
    while(inputNome[tamDoInput] != '\0')
    {
        if(
        (inputNome[tamDoInput] >= 'A' && inputNome[tamDoInput] <= 'Z')||
        (inputNome[tamDoInput] >= 'a' && inputNome[tamDoInput] <= 'z')||
        (inputNome[tamDoInput] == ' ')
          )
        {
            caracteresValidos++;
        }
        tamDoInput++;
    }
    /*Conclusão*/
    if(tamDoInput > TAM_NOME || caracteresValidos < tamDoInput)
    {
        printf("ERRO: Nome invalido\n");
        contaErros++;
    }
    else
    {
        printf("Nome VALIDO\n");
    }
}

/*Validar CPF*/
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
    }
    else
    {
        printf("ERRO: CPF invalido\n");
        contaErros++;
    }
    
}

/*Validar o sexo*/
void validarSexo(char sexo)
{
    if (sexo == 'M'|sexo == 'm'|sexo == 'F'|sexo == 'f'|sexo == 'O'|sexo == 'o')
    {
        printf("Sexo VALIDO\n");
    }
    else
    {
        printf("ERRO: Sexo invalido\n");
        contaErros++;
    }
}

/*Validar data de nascimento*/
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
        if (tamDoInput == 2 || tamDoInput == 5 && data[tamDoInput] == '/')
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
            char diaChar[CARACTER_DIA];
            char mesChar[CARACTER_MES];
            char anoChar[CARACTER_ANO];

            //dia
            int iContador = 0;
            int jContador = 0;
            while (jContador < CARACTER_DIA - 1)
            {
                diaChar[jContador] = data[iContador];
                iContador++;
                jContador++;
            }
            diaChar[jContador] = '\0';
            //mês
            jContador = 0;
            iContador++;
            while (jContador < CARACTER_MES - 1)
            {
                mesChar[jContador] = data[iContador];
                iContador++;
                jContador++;
            }
            mesChar[jContador] = '\0';
            //ano
            jContador = 0;
            iContador++;
            while (jContador < CARACTER_ANO - 1)
            {
                anoChar[jContador] = data[iContador];
                iContador++;
                jContador++;
            }
            anoChar[jContador] = '\0';

        /*Conversão para inteiros*/
        int diaData = atoi(diaChar);
        int mesData = atoi(mesChar);
        int anoData = atoi(anoChar);

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
        printf("Data VALIDA\n");
    }
    else
    {
        printf("ERRO: Data invalida\n");
        contaErros++;
    }
    
}