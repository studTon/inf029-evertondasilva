#include <stdio.h>
void ler3letras(char *letra1, char *letra2, char *letra3);
int main(void)
{
    char input[3];
    ler3letras(&input[0], &input[1], &input[2]);
    printf("Letras:\n%c | %c | %c\n", input[0], input[1], input[2]);

    return 0;
}

void ler3letras(char *letra1, char *letra2, char *letra3)
{
    printf("Digite 3 letras:\n");
    scanf("%c %c %c", &*letra1, &*letra2, &*letra3);
}