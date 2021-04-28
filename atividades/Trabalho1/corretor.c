// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Anßlise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo contém exemplos de testes das questões do trabalho.
//  o aluno pode incrementar os testes

//  Copyright © 2016 Renato Novais. All rights reserved.
// Útima atualização: 19/08/2016 - 12/12/2018

// #################################################

#include <stdio.h>
#include <string.h>
#include <locale.h>
//renomeie o arquivo do include abaixo para PrimeiroUltimoNomeMATRICULA.c
#include "EvertonDaSilva20192160012.h"

void testSomar();    //fun??o utilizada para testes
void testFatorial(); //fun??o utilizada para testes
void testQ1();
void testQ2();
void testQ3();
void testQ4();
void testQ5();
void testQ6();

int main()
{
    //testSomar();
    //testFatorial();
    testQ1();
    testQ2();
    testQ3();
    testQ4();
    testQ5();
    testQ6();
}

int mainData()
{
    //digita a data
    //char data[11];
    //ler a data em "data"
    //validarData(data);
}

void testSomar()
{
    printf("%d\n", somar(3, 4) == 7);
    printf("%d\n", somar(-1, -3) == 2);
    printf("%d\n", somar(-6, 6) == 0);
    printf("%d\n", somar(74, 9) == 83);
    printf("%d\n", somar(30, -9) == 21);
}

void testFatorial()
{
    printf("%d\n", fatorial(3) == 6);
    printf("%d\n", fatorial(1) == 1);
    printf("%d\n", fatorial(5) == 120);
}

void testQ1()
{
    char str[11];
    strcpy(str, "29/02/2015");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "18/03/2020");
    printf("%d\n", q1(str) == 1);
    strcpy(str, "29/02/2012");
    printf("%d\n", q1(str) == 1);
    strcpy(str, "9/13/2014");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "45/4/2014");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "/9/2014");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "//");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "1/1/01");
    printf("%d\n", q1(str) == 1);
}

void testQ2()
{
    char datainicial[11], datafinal[11];
    int qtdDias, qtdMeses, qtdAnos;
    int retorno;

    //teste 1
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "01/06/2015");
    strcpy(datafinal, "15/07/2015");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 14);
    printf("%d\n", qtdMeses == 1);
    printf("%d\n", qtdAnos == 0);

    //teste 2 - retornos
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "01/30/2015");
    strcpy(datafinal, "01/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 2);

    strcpy(datainicial, "01/3/2015");
    strcpy(datafinal, "40/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 3);

    strcpy(datainicial, "01/06/2016");
    strcpy(datafinal, "01/06/2015");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 4);

    //teste 3
    
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "06/06/2017");
    strcpy(datafinal, "07/07/2017");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 1);
    printf("%d\n", qtdMeses == 1);
    printf("%d\n", qtdAnos == 0);
    
    //teste 4
    
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;
    
    strcpy(datainicial, "01/06/2015");
    strcpy(datafinal, "04/06/2015");
    
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 3);
    printf("%d\n", qtdMeses == 0);
    printf("%d\n", qtdAnos == 0);
}

void testQ3()
{
    setlocale(LC_ALL, "Portuguese");
    setlocale(LC_CTYPE, "Portuguese");
    setlocale(LC_NUMERIC, "Portuguese");
    char str[250];
    strcpy(str, "Glória Limá Gôuveá");
    printf("%d\n", q3(str, 'a', 0) == 3);
    printf("%d\n", q3(str, 'b', 0) == 0);
    printf("%d\n", q3(str, 'l', 1) == 1);
    printf("%d\n", q3(str, 'l', 0) == 2);
    printf("%d\n", q3(str, 'L', 0) == 2);
}

void testQ4()
{
    setlocale(LC_ALL, "");
    
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;
    
    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    strcpy(strTexto, "A casa do casamento");
    strcpy(strBusca, "casa");
    printf("%d\n", q4(strTexto, strBusca, posicoes) == 2);
    printf("%d\n", posicoes[0] == 2);
    printf("%d\n", posicoes[1] == 10);
    
    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    strcpy(strTexto, "Olá, o mundo é muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca, "mui");
    printf("%d\n", q4(strTexto, strBusca, posicoes) == 3);
    printf("%d\n", posicoes[0] == 15);
    printf("%d\n", posicoes[1] == 33);
    printf("%d\n", posicoes[2] == 51);
    
    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    strcpy(strTexto, "Sra. Pêra é muito inteligente. Cozêramos uma feijoada para ela");
    strcpy(strBusca, "êra");
    printf("%d\n", q4(strTexto, strBusca, posicoes) == 2);
    printf("%d\n", posicoes[0] == 6);
    printf("%d\n", posicoes[1] == 34);
}

void testQ5()
{
    printf("%d\n", q5(345) == 543);
    printf("%d\n", q5(78) == 87);
    printf("%d\n", q5(3) == 3);
    printf("%d\n", q5(5430) == 345);
    printf("%d\n", q5(54952302) == 20325945);
}

void testQ6()
{
    printf("%d\n", q6(3452, 3) == 1);
    printf("%d\n", q6(34567368, 4576) == 0);
    printf("%d\n", q6(3533343, 33) == 1);
    printf("%d\n", q6(1222022, 222) == 1);
    printf("%d\n", q6(54444, 44) == 2);
    printf("%d\n", q6(4576368, 4576) == 0);
}