#include <stdio.h>
#include <stdlib.h>
#define CARACTER_DIA 3
#define CARACTER_MES 3
#define CARACTER_ANO 5

int contaErros = 0;
int main(int argc, char *argv[])
{
    char data[11] = "30/02/2016";
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
    {
        errosData++;
        printf("Erros data1: %d\n===============\n", errosData);
    }
    else
    {
        printf("DATA: %s\n================\n", data);
        /*Aquisição das partes da data*/
        char diaChar[CARACTER_DIA] = "00";
        char mesChar[CARACTER_MES] = "00";
        char anoChar[CARACTER_ANO] = "0000";

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

        printf("dia: %s\nmes: %s\nano: %s\n==============", diaChar, mesChar, anoChar);
        /*Conversão para inteiros*/
        int diaData = atoi(diaChar);
        int mesData = atoi(mesChar);
        int anoData = atoi(anoChar);
        printf("\ndia: %d\nmes: %d\nano: %d\n=============\n", diaData, mesData, anoData);
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
        printf("ERRO: Data inserida invalida\n");
        contaErros++;
    }
    
}