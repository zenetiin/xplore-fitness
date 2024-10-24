#ifndef PERSONAL_H
#define PERSONAL_H
#define MAX_USERS 10

struct Personal
{
    char usuario[50];
    char senha[50];
};

void menuPersonal();
int validarLogin(char usuario[], char senha[]);
void inicializarUsuarios();
void cadastrarAluno(char usuario[], char senha[], int idade, float altura, float peso, char sexo, char treino[], char dieta[]);
int buscarAlunoPorSenha(char senha[]);
void excluirAluno(int indice);

#endif
