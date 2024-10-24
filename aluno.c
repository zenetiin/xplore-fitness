#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct Aluno tabelaAluno[MAX_ALUNOS];
int numAlunos = 0;
struct TernaryNode *root = NULL;

// Iniciar teste com ze
void inicializarAlunos()
{
    printf("Inicializando alunos...\n");
    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        tabelaAluno[i].usuario[0] = '\0';
        tabelaAluno[i].senha[0] = '\0';
    }

    strcpy(tabelaAluno[0].usuario, "ze");
    strcpy(tabelaAluno[0].senha, "001002123");
    tabelaAluno[0].idade = 20;
    tabelaAluno[0].altura = 1.75;
    tabelaAluno[0].peso = 70.0;
    tabelaAluno[0].sexo = 'M';
    strcpy(tabelaAluno[0].treino[0], "Treino A");
    strcpy(tabelaAluno[0].dieta[0], "Dieta A");
}

// deus abencoe que essa arvore preste
struct TernaryNode *inserirTernario(struct TernaryNode *root, char usuario[], int indice)
{
    if (root == NULL)
    {
        root = (struct TernaryNode *)malloc(sizeof(struct TernaryNode));
        strcpy(root->usuario, usuario);
        root->indice = indice;
        root->esquerda = root->meio = root->direita = NULL;
    }
    else if (strcmp(usuario, root->usuario) < 0)
    {
        root->esquerda = inserirTernario(root->esquerda, usuario, indice);
    }
    else if (strcmp(usuario, root->usuario) == 0)
    {
        root->meio = inserirTernario(root->meio, usuario, indice);
    }
    else
    {
        root->direita = inserirTernario(root->direita, usuario, indice);
    }
    return root;
}

// caçar o aluno
struct TernaryNode *buscarTernario(struct TernaryNode *root, char usuario[])
{
    if (root == NULL)
        return NULL;

    if (strcmp(usuario, root->usuario) < 0)
    {
        return buscarTernario(root->esquerda, usuario);
    }
    else if (strcmp(usuario, root->usuario) == 0)
    {
        return root; // Retorna o nó correspondente
    }
    else
    {
        return buscarTernario(root->direita, usuario);
    }
}

// validação usando a busca com arvore
int validarLoginAluno(char usuario[], char senha[])
{
    struct TernaryNode *node = buscarTernario(root, usuario);
    if (node != NULL)
    {
        if (strcmp(tabelaAluno[node->indice].senha, senha) == 0)
        {
            return 1;
        }
    }
    return 0;
}

// pega ai esse prototipo de busca em banco de daods heheheheheheheehe
void cadastrarAluno(char usuario[], char senha[], int idade, float altura, float peso, char sexo, char treino[][100], char dieta[][100])
{
    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        if (tabelaAluno[i].usuario[0] == '\0')
        {
            strcpy(tabelaAluno[i].usuario, usuario);
            strcpy(tabelaAluno[i].senha, senha);
            tabelaAluno[i].idade = idade;
            tabelaAluno[i].altura = altura;
            tabelaAluno[i].peso = peso;
            tabelaAluno[i].sexo = sexo;

            for (int j = 0; j < MAX_DIAS; j++)
            {
                strcpy(tabelaAluno[i].treino[j], treino[j]);
                strcpy(tabelaAluno[i].dieta[j], dieta[j]);
            }

            printf("Aluno %s cadastrado com sucesso!\n", usuario); // debug pra ver se deu certo
            root = inserirTernario(root, usuario, i);
            break;
        }
    }
}

void exibirInformacoesPessoais(int alunoIndex)
{
    int opcaoEditar;

    printf("\n===== INFORMAÇÕES PESSOAIS =====\n");
    printf("Usuário: %s\n", tabelaAluno[alunoIndex].usuario);
    printf("Senha: %s\n", tabelaAluno[alunoIndex].senha);
    printf("Idade: %d\n", tabelaAluno[alunoIndex].idade);
    printf("Altura: %.2f\n", tabelaAluno[alunoIndex].altura);
    printf("Peso: %.2f\n", tabelaAluno[alunoIndex].peso);
    printf("Sexo: %c\n", tabelaAluno[alunoIndex].sexo);
    printf("================================\n");

    printf("1. Editar Informações\n");
    printf("2. Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcaoEditar);

    if (opcaoEditar == 1)
    {
        editarInformacoesPessoais(alunoIndex);
    }
}

// repetição ainda mata o caba
void editarInformacoesPessoais(int alunoIndex)
{
    printf("\n===== EDITAR INFORMAÇÕES =====\n");

    // Usuário pode modificar cada campo
    printf("Novo Usuário: ");
    scanf("%s", tabelaAluno[alunoIndex].usuario);

    printf("Nova Senha: ");
    scanf("%s", tabelaAluno[alunoIndex].senha);

    printf("Nova Idade: ");
    scanf("%d", &tabelaAluno[alunoIndex].idade);

    printf("Nova Altura: ");
    scanf("%f", &tabelaAluno[alunoIndex].altura);

    printf("Novo Peso: ");
    scanf("%f", &tabelaAluno[alunoIndex].peso);

    printf("Novo Sexo (M/F): ");
    scanf(" %c", &tabelaAluno[alunoIndex].sexo);

    printf("Informações atualizadas com sucesso!\n");
}

void exibirTreino(int alunoIndex)
{
    printf("\n--- Treino ---\n");
    for (int dia = 0; dia < MAX_DIAS; dia++)
    {
        printf("Dia %d: %s\n", dia + 1, tabelaAluno[alunoIndex].treino[dia]);
    }
    printf("\nPressione qualquer tecla para voltar ao menu aluno...");
    getchar();
    getchar();
}

void exibirDieta(int alunoIndex)
{
    printf("\n--- Dieta ---\n");
    for (int dia = 0; dia < MAX_DIAS; dia++)
    {
        printf("Dia %d: %s\n", dia + 1, tabelaAluno[alunoIndex].dieta[dia]);
    }
    printf("\nPressione qualquer tecla para voltar ao menu aluno...");
    getchar();
    getchar();
}

// menuzin pro aluno
void menuAluno(int alunoIndex)
{
    int opcaoAluno;
    do
    {
        printf("\n===== MENU ALUNO =====\n");
        printf("1. Informações Pessoais\n");
        printf("2. Treino\n");
        printf("3. Dieta\n");
        printf("4. Sair\n");
        printf("========================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoAluno);

        switch (opcaoAluno)
        {
        case 1:
            exibirInformacoesPessoais(alunoIndex);
            break;
        case 2:
            exibirTreino(alunoIndex);
            break;
        case 3:
            exibirDieta(alunoIndex);
            break;
        case 4:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcaoAluno != 4);
}
