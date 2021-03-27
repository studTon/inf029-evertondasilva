#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "aluno.h"
cadastroAluno aluno[200];
//menu Aluno
void menuAluno()
{
    /*Detecção de SO para SO a tela*/
    #if defined(WIN32)
        #define SO 1
    #endif
    if(SO == 1)
        system("cls");//Windows
    /**********************/

    char escolha = '1';
    while(escolha != '0')
    {
        printf("******************************\n");
        printf("*         INFO ALUNO         *\n");
        printf("******************************\n");
        printf("\nEscolha uma opção a seguir:\n0 - Voltar\n1 - Cadastrar\n2 - Listar\n::");
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
                cadastrarAluno();
            }break;
            case '2':
            {
                //Listar alunos cadastrados
            }break;
        }
        /*Detecção de SO para SO limpar a tela*/
        if(SO == 1)
            system("cls");//Windows
        /**********************/
    }
    
}

//Verificações da entrada de dados do cadastro
void validarMatricula(char inputMatricula[])
{
    /*Análise dos campos da matrícula*/
    int tamDoInput = 0;
    int contadorCaracterPonto = 0;
    int contadorNumeros = 0;
    while(inputMatricula[tamDoInput] != '\0')
    {
        if(inputMatricula[tamDoInput] >= '0' && inputMatricula[tamDoInput] <= '9' &&
        (tamDoInput != 4 && tamDoInput != 8))
        {
            contadorNumeros++;
        }
        else
        if(inputMatricula[tamDoInput] == '.' && (tamDoInput == 4 || tamDoInput == 8))
        {
            contadorCaracterPonto++;
        }
        tamDoInput++;
    }
    int somaContadores = contadorCaracterPonto + contadorNumeros;
    /*Conclusão*/
    if(somaContadores == 12)
    {
        printf("MATRÍCULA VALIDA\n");
    }
    else
    {
        printf("ERRO: Matrícula invalida\n");
        //contaErros++;
    }
    
}
void validarNome(char inputNome[])
{

}
void validarCPF(char cpf[])
{

}
void validarSexo(char sexo)
{

}
void validarNasc(char data[])
{

}
//Cadastrar aluno
void cadastrarAluno()
{
    setlocale(LC_ALL, "Portuguese");
    printf("***Cadastrar aluno***\n");
    int iContador = 0;
    /*while(aluno[iContador].sexo != '\0')
    {
        iContador++;
    }*/
    //Matrícula        
    printf("Digite a matrícula do(a) estudante(XXXX.XXX.XXX): ");//Ano.Turma.NúmeroDoEstudante
    fgets(aluno[iContador].matricula, 13, stdin);
    int tamanhoDoInput = 0;
    while(aluno[iContador].matricula[tamanhoDoInput] != '\0') tamanhoDoInput++;
    size_t novaLinha = tamanhoDoInput - 1;
    if (aluno[iContador].matricula[novaLinha] == '\n')
	    aluno[iContador].matricula[novaLinha] = '\0';
    //Nome
    printf("Digite o nome do(a) estudante: ");
    fgets(aluno[iContador].nome, 51, stdin);
    tamanhoDoInput = 0;
    while(aluno[iContador].nome[tamanhoDoInput] != '\0') tamanhoDoInput++;
    novaLinha = tamanhoDoInput - 1;
    if(aluno[iContador].matricula[novaLinha] == '\n')
        aluno[iContador].matricula[novaLinha] = '\0';
    //Sexo
    printf("Digite o sexo do(a) estudante(F - Feminino|M - Masculino|O - Outro): ");
    scanf("%1c", &aluno[iContador].sexo);
    while(getchar() != '\n');/*Pular o char new line no input*/
    //Data de nascimento
    printf("Digite a data de nascimento(dd/mm/aaaa): ");
    scanf("%[^\n]%*c", aluno[iContador].dataNasc);
    while(getchar() != '\n');/*Pular o char new line no input*/
    //CPF
    printf("Digite o CPF do(a) estudante(XXX.XXX.XXX-XX): ");
    scanf("%[^\n]%*c", aluno[iContador].cpf);
    while(getchar() != '\n');/*Pular o char new line no input*/
    /*Validações*/
    validarMatricula(aluno[iContador].matricula);

    /*Detecção de SO para pausar*/
    if(SO == 1)
        system("pause");//Windows
    /**********************/
}