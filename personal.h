#ifndef PERSONAL_H
#define PERSONAL_H

// Definição do número máximo de usuários
#define MAX_PERSONAIS 10

// Estrutura para armazenar dados do Personal
struct Personal {
    char usuario[50];
    char senha[50];
};
// array global de personais
extern struct Personal tabelaPersonal[MAX_PERSONAIS];

// Estrutura de um nó da árvore binária de busca
struct Node {
    char usuario[50];
    int indice;  // Índice na tabela hash
    struct Node* esquerda;
    struct Node* direita;
};

// Funções para manipulação da árvore binária de busca
struct Node* inserir(struct Node* root, char usuario[], int indice);
struct Node* buscar(struct Node* root, char usuario[]);

// Prototipação das funções
void inicializarPersonais();
int validarLoginPersonal(char usuario[], char senha[]);

void menuPersonal();
void exibirPersonais(); // Nova função para exibir e excluir personal
void cadastrarPersonal(); // Nova função para cadastrar um novo personal
void excluirPersonal();   // Função para excluir personal

void cadastrarAluno(char usuario[], char senha[], int idade, float altura, float peso, char sexo, char treino[][100], char dieta[][100]);

int buscarAlunoPorSenha(char senha[]);
void excluirAluno(int indice);

void editarTreino();
void editarDieta();



#endif