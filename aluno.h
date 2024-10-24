#ifndef ALUNO_H
#define ALUNO_H

#define MAX_ALUNOS 10

struct Aluno
{
    char usuario[50];
    char senha[50];
    int idade;
    float altura;
    float peso;
    char sexo;
    char treino[100];
    char dieta[100];
};

void inicializarAlunos();
int validarLoginAluno(char usuario[], char senha[]);
void cadastrarAluno(char usuario[], char senha[], int idade, float altura, float peso, char sexo, char treino[], char dieta[]);
void menuAluno();

#endif
