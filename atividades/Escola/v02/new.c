#include <stdio.h>
#define QTD_DE_ALUNOS 100
#define TAM_CARACTER_ANO 5
typedef struct
{
    char matricula[11];
}dadosAluno;

dadosAluno aluno[QTD_DE_ALUNOS];

void gerarMatricula(int inputIndiceAluno)
{    
    if(inputIndiceAluno < QTD_DE_ALUNOS)
    {
        inputIndiceAluno += 1;
       
        /*É necessário somar o char '0' a todos os valores inteiros na 
         *conversão de inteiro para char, pois o valor inteiro do char
         *'0' somado ao número inteiro equivale ao seu char correspon-
         *dente.
         */
        //Decomposição do índice do aluno
        char centenaAluno = (inputIndiceAluno / 100) + '0';
        char dezenaAluno = ((inputIndiceAluno % 100) / 10) + '0';
        char unidadeAluno = (inputIndiceAluno % 10) + '0';
        //Ano e semestre
        char ano[TAM_CARACTER_ANO] = "2021\0";
        char semestre = '1';
        //Criação da string que representa a matrícula
        int contador = 0;
        while(contador < 11)
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
        if(contador == 10)
            aluno[inputIndiceAluno].matricula[contador] = '\0';

        printf("MATRICULA GERADA: %s\n", aluno[inputIndiceAluno].matricula);
    }
    else
    {
        printf("SEM VAGAS PARA CADASTRO DE MAIS ALUNOS\n");
    }
        
}

int main(int argc, char *argv[])
{
    int numeroDeMatriculas;
    
    printf("Digite quantas matriculas deseja gerar(max. %d): ", QTD_DE_ALUNOS);
    scanf("%d", &numeroDeMatriculas);
    int iContador = 0;
    while(iContador < numeroDeMatriculas)
    {
        gerarMatricula(iContador);
        iContador++;
    }
    
    return 0;
}