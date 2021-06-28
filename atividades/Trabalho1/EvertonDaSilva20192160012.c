// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluNo.
//  Cada aluNo deve reNomear esse arquivo para AluNo<MATRICULA>.c
//  O aluNo deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do AluNo -----
//  Nome: Everton Souza da Silva
//  email: 20192160012@ifba.edu.br
//  Matrícula: 20192160012
//  Semestre: 2021.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "EvertonDaSilva20192160012.h"
tipoData dataProcessada;
/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma = 0;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
    int fat = 1;
    if(x == 0 || x == 1)
        fat = 1;
    else
    {   
        fat = x;
        while(x > 1)
        {
            x--;
            fat *= x;
        }
    }
    return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao aNo. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char *data)
{
    int datavalida;
    int bomInput = 0;
    int tamData = 0;
    
    int contaCorretos = 0;
    while(data[tamData] != '/')
    {
        if(data[tamData] >= '0' && data[tamData] <= '9')
        {
            contaCorretos++;
        }
        tamData++;
    }

    if(contaCorretos >= 1 && contaCorretos <= 2)
    {
        bomInput++;
    }
    
    tamData++;
    contaCorretos = 0;
    while(data[tamData] != '/')
    {
        if(data[tamData] >= '0' && data[tamData] <= '9')
        {
            contaCorretos++;
        }
        tamData++;
    }
    if(contaCorretos >= 1 && contaCorretos <= 2)
    {
        bomInput++;
    }

    tamData++;
    contaCorretos = 0;
    while(data[tamData] != '\0' || tamData < 10)
    {
        if(data[tamData] >= '0' && data[tamData] <= '9')
        {
            contaCorretos++;
        }
        tamData++;
    }
    if(contaCorretos >= 2 && contaCorretos <= 4)
    {
        bomInput++;
    }
    
    contaCorretos = 0;
    tamData = 0;
    while( data[tamData] != '\0' || tamData < 10)
    {
        if (data[tamData] == '/' && (tamData >= 1 && tamData <= 5))
        {
            contaCorretos++;
        }
        tamData++;
    }

    if( contaCorretos == 2 )
    {
        bomInput++;
    }
    
    
    if(bomInput == 4)
    {
        int dataInt[3];
        
        dataInt[0] = decomporDataDia(data);
        dataInt[1] = decomporDataMes(data);
        dataInt[2] = decomporDataANo(data);
        
        datavalida = verificarData(dataInt);
    }    
    else
    {
        datavalida = 0; 
    }

    return datavalida;
}

int decomporDataDia(char *data)
{
    char dataDia[3];
    int dataInt;

    int iContador = 0;
    int jContador = 0;

    while( data[iContador] != '/' )
    {
        dataDia[jContador] = data[iContador];
        iContador++;
        jContador++;
    }
    dataDia[jContador] = '\0';
    if( jContador == 2 )
    {
        dataInt = (dataDia[0] - '0') * 10;
        dataInt += dataDia[1] - '0';    
    }
    else
        dataInt = dataDia[0] - '0';

    return dataInt;
}
int decomporDataMes(char *data)
{
    int dataInt;
    char dataMes[3];
    
    int iContador = 0;
    while(data[iContador] != '/') iContador++;
    iContador++;
    int jContador = 0;
    while( data[iContador] != '/')
    {
        dataMes[jContador] = data[iContador];
        iContador++;
        jContador++;
    }
    dataMes[jContador] = '\0';
    if( jContador == 2 )
    {
        dataInt = (dataMes[0] - '0') * 10;
        dataInt += dataMes[1] - '0';    
    }
    else
        dataInt = dataMes[0] - '0';
    
    return dataInt;
}

int decomporDataANo(char *data)
{
    char dataANo[5];
    int dataInt;
    int iContador = 0;
    int contaBarras = 0;
    while(contaBarras < 2)
    {
        if(data[iContador] == '/')
            contaBarras++;
        iContador++;
    }
    int jContador = 0;
    while( jContador < 4 || dataANo[jContador] != '\0')
    {
        dataANo[jContador] = data[iContador];
        iContador++;
        jContador++;
    }
    dataANo[jContador] = '\0';

    if( jContador == 4 )
    {
        dataInt = atoi(dataANo);
    }
    else   
    {
        dataInt = atoi(dataANo) + 2000;
    }
   
    return dataInt;
}

int aNoBissexto(int aNo)
{
    return ((aNo % 400 == 0) || ((aNo % 4 == 0) && (aNo % 100 != 0)));
}

int verificarData(int arranjoData[]) /*Formato [0] == dia| [1] == mês| [2] == aNo*/
{
    
    int bissexto = aNoBissexto(arranjoData[2]);
    
    
    if
    (arranjoData[1] == 1||arranjoData[1] == 3||arranjoData[1] == 5||arranjoData[1] == 7||
     arranjoData[1] == 8||arranjoData[1] == 10||arranjoData[1] == 12)
    {
        if(arranjoData[0] >= 1 && arranjoData[0] <= 31)
            return 1;
        else
            return 0;
    }
    if
    (arranjoData[1] == 4||arranjoData[1] == 6||arranjoData[1] == 9||arranjoData[1] == 11)
    {
        if(arranjoData[0] >= 1 && arranjoData[0] <= 30)
            return 1;
        else
            return 0;
    }


    if(bissexto == 1)
    {
        if(arranjoData[1] == 2 && (arranjoData[0] >= 1 && arranjoData[0] <= 29))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    if(bissexto == 0)
    {
        if(arranjoData[1] == 2 && (arranjoData[0] >= 1 && arranjoData[0] <= 28))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em aNos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdANos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdANos)
{
    int validadeDistancia = 1;
    if ( q1(datainicial) == 0 )
    {
        validadeDistancia = 2;
        return validadeDistancia;
    }    
    else
        if( q1(datafinal) == 0 )
        {
            validadeDistancia = 3;
            return validadeDistancia;
        }
        else
            if(calcularMaiorData(datainicial, datafinal) == 0)
            {
                validadeDistancia = 4;
                return validadeDistancia;
            }
    
    //calcule os dados e armazene nas três variáveis a seguir
    int nDias, nMeses, nANos;
    
    dataProcessada = calcularDataSeparada(calcularDias(datainicial, datafinal));
    nDias = dataProcessada.dia;
    nMeses = dataProcessada.mes;
    nANos = dataProcessada.aNo;
    
    
    /*mantenha o código abaixo, para salvar os dados em 
    Nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdANos = nANos;
    *qtdMeses = nMeses;

    //coloque o retorNo correto
    return validadeDistancia;
}

int calcularMaiorData(char *datainicial, char *datafinal)
{
    int inicialDia = decomporDataDia(datainicial);
    int inicialMes = decomporDataMes(datainicial);
    int inicialANo = decomporDataANo(datainicial);
    int finalDia = decomporDataDia(datafinal);
    int finalMes = decomporDataMes(datafinal);
    int finalANo = decomporDataANo(datafinal);
    
    int dataFinalMaior = 0;
    if(finalANo < inicialANo)
        return dataFinalMaior;
    else
    {
        if(finalANo == inicialANo)
        {
            if(finalMes < inicialMes)
                return dataFinalMaior;
            else
            {
                if(finalMes == inicialMes)
                {
                    if(finalDia < inicialDia)
                        return dataFinalMaior;
                    else
                        if(finalDia == inicialDia)
                            return dataFinalMaior;
                        else
                        {
                            dataFinalMaior = 1;
                            return dataFinalMaior;
                        }
                        
                }
                if(finalMes > inicialMes)
                {
                    dataFinalMaior = 1;
                    return dataFinalMaior;
                }
            }
        }
        else
        {
            dataFinalMaior = 1;
           return dataFinalMaior; 
        }
    }
}

int calcularDias(char *datainicial, char *datafinal)
{
    int inicialDia = decomporDataDia(datainicial);
    int inicialMes = decomporDataMes(datainicial);
    int inicialANo = decomporDataANo(datainicial);
    int finalDia = decomporDataDia(datafinal);
    int finalMes = decomporDataMes(datafinal);
    int finalANo = decomporDataANo(datafinal);
    //printf("Final aNo %d\n", finalANo);
                                  /*J   F   M   A   M   J   J   A   S   O   N   D*/
    int diasDosMeses[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                               {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    
    int aNoAnalizado = inicialANo;
    /*
    Esse indice será inicializado com o indice do próximo mês ao inicial, pois em C o vetor é contador a partir de 0        */
    int indice = inicialMes;
    int dias = 0;
    int bissexto;
    while(aNoAnalizado <= finalANo)
    {
        bissexto = aNoBissexto(aNoAnalizado);
        if(bissexto == 1)
        {
            if(inicialANo == finalANo)
            {
                if(inicialMes == finalMes)
                {
                    dias += (finalDia - inicialDia);
                }
                if(inicialMes + 1 == finalMes)
                {
                    dias += (diasDosMeses[bissexto][inicialMes] - inicialDia);
                    dias += finalDia;
                }
                if(finalMes - inicialMes >= 2)
                {
                    dias += diasDosMeses[bissexto][inicialMes] - inicialDia;
                    for(int indice = inicialMes + 1; indice <= finalMes - 1; indice++)
                    {
                        dias += diasDosMeses[bissexto][indice];
                    }
                    dias += finalDia;
                }
            }
            if(aNoAnalizado == inicialANo && aNoAnalizado != finalANo)
            {
                dias += diasDosMeses[bissexto][inicialMes] - inicialDia;
                
                for(int indice = inicialMes + 1; indice <= 12; indice++)
                {
                    dias += diasDosMeses[bissexto][indice];
                }
            }
            if(aNoAnalizado != inicialANo && aNoAnalizado != finalANo)
            {
                for(int indice = 1; indice <= 12; indice++)
                {
                    dias += diasDosMeses[bissexto][indice];
                }
            }
            if(aNoAnalizado == finalANo && aNoAnalizado != inicialANo)
            {
                if(finalMes != 1)
                {
                    for(int indice = 1; indice <= finalMes - 1; indice++)
                    {
                        dias += diasDosMeses[bissexto][indice];
                    }
                    dias += finalDia;
                }   
                else
                    dias += finalDia;
            }
        }
        else
        {
            if(inicialANo == finalANo)
            {
                if(inicialMes == finalMes)
                {
                    dias += (finalDia - inicialDia);
                }
                if(inicialMes + 1 == finalMes)
                {
                    dias += (diasDosMeses[bissexto][inicialMes] - inicialDia);
                    dias += finalDia;
                }
                if(finalMes - inicialMes >= 2)
                {
                    dias += (diasDosMeses[bissexto][inicialMes] - inicialDia);
                    for(int indice = inicialMes + 1; indice <= finalMes - 1; indice++)
                    {
                        dias += diasDosMeses[bissexto][indice];
                    }
                    dias += finalDia;
                }
            }
            if(aNoAnalizado == inicialANo && aNoAnalizado != finalANo)
            {
                dias += diasDosMeses[bissexto][inicialMes] - inicialDia;
                
                for(int indice = inicialMes + 1; indice <= 12; indice++)
                {
                    dias += diasDosMeses[bissexto][indice];
                }
            }
            if(aNoAnalizado != inicialANo && aNoAnalizado != finalANo)
            {
                for(int indice = 1; indice <= 12; indice++)
                {
                    dias += diasDosMeses[bissexto][indice];
                }
            }
            if(aNoAnalizado == finalANo && aNoAnalizado != inicialANo)
            {
                if(finalMes != 1)
                {
                    for(int indice = 1; indice <= finalMes - 1; indice++)
                    {
                        dias += diasDosMeses[bissexto][indice];
                    }
                    dias += finalDia;
                }   
                else
                    dias += finalDia;
            }
        }
        aNoAnalizado++;  
    }
     
    return dias;
}

tipoData calcularDataSeparada(int dias)
{
    tipoData dataCalculada;
    
    dataCalculada.aNo = dias / 365;
    dataCalculada.mes = dias / 30;
    dataCalculada.dia = dias % 30;
    
    return dataCalculada;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    //printf("local %s\n", setlocale(LC_ALL, ""));
    setlocale(LC_ALL, "Portuguese");
    setlocale(LC_CTYPE, "Portuguese");
    setlocale(LC_NUMERIC, "Portuguese");
    //printf("%s\n", texto);
    //char l = 'á'
    //printf("%c", l);
    int qtdOcorrencias = 0;
    
    if(isCaseSensitive == 1)
    {
        int iContador = 0;
        while( texto[iContador] != '\0')
        {
            /*####################################Vogais acentuadas###################################*/
            if(texto[iContador] == 'á'||texto[iContador] == 'à'||texto[iContador] == 'â'||texto[iContador] == 'ã'||texto[iContador] == 'ä')
            {
                texto[iContador] = 'a';
            }
            if(texto[iContador] == 'Á'||texto[iContador] == 'À'||texto[iContador] == 'Â'||texto[iContador] == 'Ã'||texto[iContador] == 'Ä')
            {
                texto[iContador] = 'A';
            }
            if(texto[iContador] == 'é'||texto[iContador] == 'è'||texto[iContador] == 'ê'||texto[iContador] == 'ë')
            {
                texto[iContador] = 'e';
            }
            if(texto[iContador] == 'É'||texto[iContador] == 'È'||texto[iContador] == 'Ê'||texto[iContador] == 'Ë')
            {
                texto[iContador] = 'E';
            }
            if(texto[iContador] == 'í'||texto[iContador] == 'ì'||texto[iContador] == 'ï'||texto[iContador] == 'î')
            {
                texto[iContador] = 'i'; 
            }
            if(texto[iContador] == 'Í'||texto[iContador] == 'Ì'||texto[iContador] == 'Ï'||texto[iContador] == 'Î')
            {
                texto[iContador] = 'I'; 
            }
            if(texto[iContador] == 'ó'||texto[iContador] == 'ò'||texto[iContador] == 'ö'||texto[iContador] == 'ô'||texto[iContador] == 'õ')
            {
                texto[iContador] = 'o'; 
            }
            if(texto[iContador] == 'Ó'||texto[iContador] == 'Ò'||texto[iContador] == 'Ö'||texto[iContador] == 'Ô'||texto[iContador] == 'Õ')
            {
                texto[iContador] = 'O'; 
            }
            if(texto[iContador] == 'ú'||texto[iContador] == 'ù'||texto[iContador] == 'ü'||texto[iContador] == 'û')
            {
                texto[iContador] = 'u'; 
            }
            if(texto[iContador] == 'Ú'||texto[iContador] == 'Ù'||texto[iContador] == 'Ü'||texto[iContador] == 'Û')
            {
                texto[iContador] = 'U'; 
            }
            if(texto[iContador] == 'ç')
            {
                texto[iContador] = 'c';
            }
            if(texto[iContador] == 'Ç')
            {
                texto[iContador] = 'C';
            }
            /*###########################################################################################*/
            
            if(texto[iContador] == c)
            {
                qtdOcorrencias++;
            }
            iContador++;
        }
    }
    else
    {
        int iContador = 0;
        while( texto[iContador] != '\0')
        {
            /*####################################Vogais acentuadas###################################*/
            if(texto[iContador] == 'á'||texto[iContador] == 'à'||texto[iContador] == 'â'||texto[iContador] == 'ã'||texto[iContador] == 'ä')
            {
                texto[iContador] = 'a';
            }
            if(texto[iContador] == 'Á'||texto[iContador] == 'À'||texto[iContador] == 'Â'||texto[iContador] == 'Ã'||texto[iContador] == 'Ä')
            {
                texto[iContador] = 'A';
            }
            if(texto[iContador] == 'é'||texto[iContador] == 'è'||texto[iContador] == 'ê'||texto[iContador] == 'ë')
            {
                texto[iContador] = 'e';
            }
            if(texto[iContador] == 'É'||texto[iContador] == 'È'||texto[iContador] == 'Ê'||texto[iContador] == 'Ë')
            {
                texto[iContador] = 'E';
            }
            if(texto[iContador] == 'í'||texto[iContador] == 'ì'||texto[iContador] == 'ï'||texto[iContador] == 'î')
            {
                texto[iContador] = 'i'; 
            }
            if(texto[iContador] == 'Í'||texto[iContador] == 'Ì'||texto[iContador] == 'Ï'||texto[iContador] == 'Î')
            {
                texto[iContador] = 'I'; 
            }
            if(texto[iContador] == 'ó'||texto[iContador] == 'ò'||texto[iContador] == 'ö'||texto[iContador] == 'ô'||texto[iContador] == 'õ')
            {
                texto[iContador] = 'o'; 
            }
            if(texto[iContador] == 'Ó'||texto[iContador] == 'Ò'||texto[iContador] == 'Ö'||texto[iContador] == 'Ô'||texto[iContador] == 'Õ')
            {
                texto[iContador] = 'O'; 
            }
            if(texto[iContador] == 'ú'||texto[iContador] == 'ù'||texto[iContador] == 'ü'||texto[iContador] == 'û')
            {
                texto[iContador] = 'u'; 
            }
            if(texto[iContador] == 'Ú'||texto[iContador] == 'Ù'||texto[iContador] == 'Ü'||texto[iContador] == 'Û')
            {
                texto[iContador] = 'U'; 
            }
            if(texto[iContador] == 'ç')
            {
                texto[iContador] = 'c';
            }
            if(texto[iContador] == 'Ç')
            {
                texto[iContador] = 'C';
            }
            /*###########################################################################################*/
            
            if(c >= 'A' && c <= 'Z')
            {
                if(texto[iContador] == c || texto[iContador] == c + 32)
                {
                    qtdOcorrencias++;
                }
            }
            
            if(c >= 'a' && c <= 'z')
            {
                if(texto[iContador] == c || texto[iContador] == c - 32)
                {
                    qtdOcorrencias++;
                }
            }
            iContador++;
        }
    }
    //printf("qtd %d\n", qtdOcorrencias);
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) No texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca No texto, deve-se armazenar No vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição No texto deve começar ser contado a partir de 1.
        O retorNo da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    setlocale(LC_ALL, "");
    
    int tamSubStr;
    for(tamSubStr = 0; strBusca[tamSubStr] != '\0'; tamSubStr++);
    
    int tamStrTexto;
    for(tamStrTexto = 0; strTexto[tamStrTexto] != '\0'; tamStrTexto++);
    
    int qtdOcorrencias = 0;
    for(int indice = 0; indice <= tamStrTexto - tamSubStr; indice++)
    {
        int aux;
        int contaCorretos = 0;
        int indiceAux;
        for(int indBusca = 0, indiceAux = indice; indBusca < tamSubStr; indBusca++, indiceAux++)
        {
            if(indBusca == 0)
                aux = indice;
            /*####################################Vogais acentuadas###################################*/
            if(strTexto[indiceAux] == 'á'||strTexto[indiceAux] == 'à'||strTexto[indiceAux] == 'â'||strTexto[indiceAux] == 'ã'||strTexto[indiceAux] == 'ä')
            {
                strTexto[indiceAux] = 'a';
            }
            if(strTexto[indiceAux] == 'Á'||strTexto[indiceAux] == 'À'||strTexto[indiceAux] == 'Â'||strTexto[indiceAux] == 'Ã'||strTexto[indiceAux] == 'Ä')
            {
                strTexto[indiceAux] = 'A';
            }
            if(strTexto[indiceAux] == 'é'||strTexto[indiceAux] == 'è'||strTexto[indiceAux] == 'ê'||strTexto[indiceAux] == 'ë')
            {
                strTexto[indiceAux] = 'e';
            }
            if(strTexto[indiceAux] == 'É'||strTexto[indiceAux] == 'È'||strTexto[indiceAux] == 'Ê'||strTexto[indiceAux] == 'Ë')
            {
                strTexto[indiceAux] = 'E';
            }
            if(strTexto[indiceAux] == 'í'||strTexto[indiceAux] == 'ì'||strTexto[indiceAux] == 'ï'||strTexto[indiceAux] == 'î')
            {
                strTexto[indiceAux] = 'i';
            }
            if(strTexto[indiceAux] == 'Í'||strTexto[indiceAux] == 'Ì'||strTexto[indiceAux] == 'Ï'||strTexto[indiceAux] == 'Î')
            {
                strTexto[indiceAux] = 'I';
            }
            if(strTexto[indiceAux] == 'ó'||strTexto[indiceAux] == 'ò'||strTexto[indiceAux] == 'ö'||strTexto[indiceAux] == 'ô'||strTexto[indiceAux] == 'õ')
            {
                strTexto[indiceAux] = 'o';
            }
            if(strTexto[indiceAux] == 'Ó'||strTexto[indiceAux] == 'Ò'||strTexto[indiceAux] == 'Ö'||strTexto[indiceAux] == 'Ô'||strTexto[indiceAux] == 'Õ')
            {
                strTexto[indiceAux] = 'O';
            }
            if(strTexto[indiceAux] == 'ú'||strTexto[indiceAux] == 'ù'||strTexto[indiceAux] == 'ü'||strTexto[indiceAux] == 'û')
            {
                strTexto[indiceAux] = 'u';
            }
            if(strTexto[indiceAux] == 'Ú'||strTexto[indiceAux] == 'Ù'||strTexto[indiceAux] == 'Ü'||strTexto[indiceAux] == 'Û')
            {
                strTexto[indiceAux] = 'U';
            }
            if(strTexto[indiceAux] == 'ç')
            {
                strTexto[indiceAux] = 'c';
            }
            if(strTexto[indiceAux] == 'Ç')
            {
                strTexto[indiceAux] = 'C';
            }
            
            if(strBusca[indBusca] == 'à' || strBusca[indBusca] == 'á' || strBusca[indBusca] == 'â' || strBusca[indBusca] == 'ã'|| strBusca[indBusca] == 'ä')
            {
                strBusca[indBusca] = 'a';
            }
            if(strBusca[indBusca] == 'À' || strBusca[indBusca] == 'Á' || strBusca[indBusca] == 'Â' || strBusca[indBusca] == 'Ã'|| strBusca[indBusca] == 'Ä')
            {
                strBusca[indBusca] = 'A';
            }
            if(strBusca[indBusca] == 'è' || strBusca[indBusca] == 'é' || strBusca[indBusca] == 'ê' || strBusca[indBusca] == 'ë')
            {
                strBusca[indBusca] = 'e';
            }
            if(strBusca[indBusca] == 'È' || strBusca[indBusca] == 'É' || strBusca[indBusca] == 'Ê' || strBusca[indBusca] == 'Ë')
            {
                strBusca[indBusca] = 'E';
            }
            if(strBusca[indBusca] == 'ì' || strBusca[indBusca] == 'í' || strBusca[indBusca] == 'î' || strBusca[indBusca] == 'ï')
            {
                strBusca[indBusca] = 'i';
            }
            if(strBusca[indBusca] == 'Ì' || strBusca[indBusca] == 'Í' || strBusca[indBusca] == 'Î' || strBusca[indBusca] == 'Ï')
            {
                strBusca[indBusca] = 'I';
            }
            if(strBusca[indBusca] == 'ò' || strBusca[indBusca] == 'ó' || strBusca[indBusca] == 'ô' || strBusca[indBusca] == 'õ'|| strBusca[indBusca] == 'ö')
            {
                strBusca[indBusca] = 'o';
            }
            if(strBusca[indBusca] == 'Ò' || strBusca[indBusca] == 'Ó' || strBusca[indBusca] == 'Ô' || strBusca[indBusca] == 'Õ'|| strBusca[indBusca] == 'Ö')
            {
                strBusca[indBusca] = 'O';
            }
            if(strBusca[indBusca] == 'ù' || strBusca[indBusca] == 'ú' || strBusca[indBusca] == 'û' || strBusca[indBusca] == 'ü')
            {
                strBusca[indBusca] = 'u';
            }
            if(strBusca[indBusca] == 'Ù' || strBusca[indBusca] == 'Ú' || strBusca[indBusca] == 'Û' || strBusca[indBusca] == 'Ü')
            {
                strBusca[indBusca] = 'U';
            }
            if(strBusca[indBusca] == 'ç')
            {
                strBusca[indBusca] = 'c';
            }
            if(strBusca[indBusca] == 'Ç')
            {
                strBusca[indBusca] = 'c';
            }
            
            if(strTexto[indiceAux] == strBusca[indBusca])
                contaCorretos++;
        }
        if(contaCorretos == tamSubStr)
        {
            posicoes[qtdOcorrencias] = aux;
            qtdOcorrencias++;
        }
            
    }
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int numInvertido = 0;
    int restante;
    while(num > 0)
    {
        restante = num % 10;
        numInvertido = numInvertido * 10 + restante;
        num /= 10;
    }
    
    
    return numInvertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    
    int aux = numerobusca;
    int tamanhoNum = 0;
    
    while(aux != 0)
    {   
        if(aux % 10 > 0)
        {
            tamanhoNum++;
        }
        aux /= 10;
    }
    
    
    aux = numerobase;
    int potDez = 10;
    int contadorLimite = 0;
    while( (aux / 10) != 0 )
    {
        aux /= 10;
        potDez *= 10;
        contadorLimite++;
    }
    
    int divTam;
    int iContador;
    for(divTam = 1, iContador = 0; iContador < tamanhoNum; divTam *= 10, iContador++ );
    
    aux = numerobase;
    int divDez = divTam / divTam;
    //printf("tam %d\n", divDez);
    int dezFixo = divTam;
    //printf("dec-fixo %d\n", dezFixo);
    int comparador;
    while( divTam <= potDez )
    {
        comparador = ((aux % divTam) - (aux % divDez)) / divDez;
        //printf("- %d\n", comparador);
        if( comparador == numerobusca )
        {
            qtdOcorrencias++;
        }
            
        divTam *= dezFixo;
        divDez *= dezFixo;
    }
    
    
    
    return qtdOcorrencias;
}