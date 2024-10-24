#ifndef PERSONAL_H
#define PERSONAL_H
#define MAX_USERS 10
#define MAX_DIAS 7

struct Personal
{
    char usuario[50];
    char senha[50];
};

void inicializarUsuarios();
int validarLogin(char usuario[], char senha[]);
void menuPersonal();
void cadastrarAluno(char usuario[], char senha[], int idade, float altura, float peso, char sexo, char treino[][100], char dieta[][100]);
int buscarAlunoPorSenha(char senha[]);
void excluirAluno(int indice);
void editarTreino();
void editarDieta();

#endif