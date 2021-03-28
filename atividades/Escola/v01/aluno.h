/*Registro*/
typedef struct
{
    char matricula[13];
    char nome[51];
    char sexo;
    char dataNasc[11];
    char cpf[15];
}cadastroAluno;
/*Funções*/
void menuAluno();
/*Validações*/
void gerarMatricula(int inputIndiceAluno);
void validarNome(char inputNome[]);
void validarCPF(char cpf[]);
void validarSexo(char sexo);
void validarNasc(char data[]);
/**********************/
void cadastrarAluno();