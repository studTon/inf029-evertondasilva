// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Everton Souza da Silva
//  email: 20192160012@ifba.edu.br
//  Matrícula: 20192160012
//  Semestre: 2021.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include "EvertonDaSilva20192160012.h"
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
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char *data)
{
    int datavalida = 0;
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
    
    //printf("Input %d\n", bomInput);
    
    if(bomInput == 4)
    {
        char dataDia[3];
        char dataMes[3];
        char dataAno[5];
        int dataInt[3];
        
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
            dataInt[0] = (dataDia[0] - '0') * 10;
            dataInt[0] += dataDia[1] - '0';    
        }
        else
            dataInt[0] = dataDia[0] - '0';
        //printf("jD %d\n", jContador);
        
        iContador++;
        jContador = 0;
        while( data[iContador] != '/')
        {
            dataMes[jContador] = data[iContador];
            iContador++;
            jContador++;
        }
        dataMes[jContador] = '\0';
        if( jContador == 2 )
        {
            dataInt[1] = (dataMes[0] - '0') * 10;
            dataInt[1] += dataMes[1] - '0';    
        }
        else
            dataInt[1] = dataMes[0] - '0';
        //printf("jM %d\n", jContador);
        
        iContador++;
        jContador = 0;
        while( jContador < 4 || data[iContador] != '\0' )
        {
            dataAno[jContador] = data[iContador];
            iContador++;
            jContador++;
        }
        dataAno[jContador] = '\0';
        if( jContador == 4 )
        {
            dataInt[2] = (dataAno[0] - '0') * 1000;
            dataInt[2] += (dataAno[1] - '0') * 100;
            dataInt[2] += (dataAno[2] - '0') * 10;
            dataInt[2] += (dataAno[3] - '0');    
        }
        else if( jContador == 3 )
                {
                    dataInt[2] = (dataAno[0] - '0') * 100;
                    dataInt[2] += (dataAno[1] - '0') * 10;
                    dataInt[2] += (dataAno[2] - '0');
                }
                else if( jContador == 2 )
                        {
                            dataInt[2] = (dataAno[0] - '0') * 10;
                            dataInt[2] += (dataAno[1] - '0');
                        }
        //printf("jA %d\n", jContador);
        
        //printf("Data %d / %d / %d\n", dataInt[0], dataInt[1], dataInt[2]);
        
        datavalida = verificarData(dataInt);
    }    
    else
    {
        datavalida = 0; 
    }

    if (datavalida == 1)
        return 1;
    else
        return 0;
}

int verificarData(int arranjoData[]) /*Formato [0] == dia| [1] == mês| [2] == ano*/
{
    int bissexto = 0;
    if((arranjoData[2] % 400 == 0) || ((arranjoData[2] % 4 == 0) && (arranjoData[2] % 100 != 0)))
    {
        bissexto = 1;
    }
    
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
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{

    //calcule os dados e armazene nas três variáveis a seguir
    int nDias, nMeses, nAnos;

    if (q1(datainicial) == 0)
        return 2;

    nDias = 4;
    nMeses = 10;
    nAnos = 2;

    /*mantenha o código abaixo, para salvar os dados em 
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;
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
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = -1;

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

    return num;
}

/*
 Q5 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
    return qtdOcorrencias;
}
