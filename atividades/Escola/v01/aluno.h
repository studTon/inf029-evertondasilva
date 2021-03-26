/*Registro*/
typedef struct
{
    char matricula[12];
    char nome[51];
    char sexo;
    char dataNasc[11];
    char cpf[15];
}cadastroAluno;

cadastroAluno aluno[200];
/*Funções*/
void menuAluno();
void validarCadastroAluno(int indiceAluno);
void cadastrarAluno();