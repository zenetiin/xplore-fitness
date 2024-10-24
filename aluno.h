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

extern struct Aluno tabelaAluno[MAX_ALUNOS];
void inicializarAlunos();
int validarLoginAluno(char usuario[], char senha[]);
void menuAluno();

#endif
