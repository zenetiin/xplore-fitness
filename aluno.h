#ifndef ALUNO_H
#define ALUNO_H
#define MAX_ALUNOS 10
#define MAX_DIAS 7

extern struct Aluno
{
    char usuario[50];
    char senha[50];
    int idade;
    float altura;
    float peso;
    char sexo;
    char treino[MAX_DIAS][100];
    char dieta[MAX_DIAS][100];
};

extern struct Aluno tabelaAluno[MAX_ALUNOS];
void inicializarAlunos();
int validarLoginAluno(char usuario[], char senha[]);
void menuAluno(int alunoIndex);
void exibirInformacoesPessoais(int alunoIndex);
void editarInformacoesPessoais(int alunoIndex);
extern int buscarAlunoPorSenha(char senha[]); 

#endif
