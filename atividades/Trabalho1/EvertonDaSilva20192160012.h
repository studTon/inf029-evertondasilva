// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questõeses do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Everton Souza da Silva
//  email: 20192160012@ifba.edu.br
//  Matrícula: 20192160012
//  Semestre: 2021.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 12/12/2017

// #################################################

int somar(int x, int y); //função utilizada para testes
int fatorial(int x); //função utilizada para testes
int q1(char *data);
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos);
int q3(char *texto, char c, int isCaseSensitive);
int q4(char *strTexto, char *strBusca, int posicoes[30]);
int q5(int num);
int q6(int numerobase, int numerobusca);

/*Funções extras*/
//Q1 e Q2
int verificarData(int arranjoData[]);
int decomporDataDia(char data[]);
int decomporDataMes(char data[]);
int decomporDataAno(char data[]);
int anoBissexto(int arranjoData[]);
//Q2
int calcularDias(char *datainicial, char *datafinal);
int calcularMaiorData(char *datainicial, char *datafinal);