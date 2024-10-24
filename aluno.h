#ifndef ALUNO_H
#define ALUNO_H
#define MAX_ALUNOS 10
#define MAX_DIAS 7

extern struct Aluno
{ // extren pra todo mundo usar
    char usuario[50];
    char senha[50];
    int idade;
    float altura;
    float peso;
    char sexo;
    char treino[MAX_DIAS][100];
    char dieta[MAX_DIAS][100];
};

// Eestrutura da ternaria
struct TernaryNode
{
    char usuario[50];
    int indice;                   // Índice na tabela hash
    struct TernaryNode *esquerda; // Menor
    struct TernaryNode *meio;     // Igual
    struct TernaryNode *direita;  // Maior
};

// adição e busca na ternaria
struct TernaryNode *inserirTernario(struct TernaryNode *root, char usuario[], int indice);
struct TernaryNode *buscarTernario(struct TernaryNode *root, char usuario[]);

extern struct Aluno tabelaAluno[MAX_ALUNOS];
void inicializarAlunos();
int validarLoginAluno(char usuario[], char senha[]);

void menuAluno(int alunoIndex);
void exibirInformacoesPessoais(int alunoIndex);
void editarInformacoesPessoais(int alunoIndex);

extern int buscarAlunoPorSenha(char senha[]);

#endif
