#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "personal.h"
#include "aluno.h"

struct Personal tabelaPersonal[MAX_PERSONAIS];
struct Aluno tabelaAluno[MAX_ALUNOS];

// Raiz da árvore de personais
struct Node *raizPersonal = NULL;

// ceindo os nós da arvore binaria
struct Node *novoNo(char usuario[], int indice)
{
    struct Node *novo = (struct Node *)malloc(sizeof(struct Node));
    strcpy(novo->usuario, usuario);
    novo->indice = indice;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// Finserindo os nós
struct Node *inserir(struct Node *raiz, char usuario[], int indice)
{
    if (raiz == NULL)
    {
        return novoNo(usuario, indice);
    }

    if (strcmp(usuario, raiz->usuario) < 0)
    {
        raiz->esquerda = inserir(raiz->esquerda, usuario, indice);
    }
    else if (strcmp(usuario, raiz->usuario) > 0)
    {
        raiz->direita = inserir(raiz->direita, usuario, indice);
    }

    return raiz;
}

// buscando os nós
struct Node *buscar(struct Node *raiz, char usuario[])
{
    if (raiz == NULL || strcmp(raiz->usuario, usuario) == 0)
    {
        return raiz;
    }

    if (strcmp(usuario, raiz->usuario) < 0)
    {
        return buscar(raiz->esquerda, usuario);
    }

    return buscar(raiz->direita, usuario);
}

// iniciando ryam pressao pra teste
void inicializarPersonais()
{
    printf("Inicializando personais...\n");
    strcpy(tabelaPersonal[0].usuario, "ryam");
    strcpy(tabelaPersonal[0].senha, "123456");
    raizPersonal = inserir(raizPersonal, tabelaPersonal[0].usuario, 0);
}

// aqui mudou pra se adaptar na arvore
int validarLoginPersonal(char usuario[], char senha[])
{
    struct Node *personalNode = buscar(raizPersonal, usuario);
    if (personalNode != NULL)
    {
        int indice = personalNode->indice;
        if (strcmp(tabelaPersonal[indice].senha, senha) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void editarTreino()
{
    char senha[50];
    printf("Digite a senha do aluno para editar o treino: ");
    scanf("%s", senha);
    getchar();

    int indice = buscarAlunoPorSenha(senha);
    if (indice != -1)
    {
        printf("Aluno encontrado: %s\n", tabelaAluno[indice].usuario);

        char treinoDia[100];
        const char *diasSemana[7] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado", "Domingo"};

        for (int j = 0; j < MAX_DIAS; j++)
        {
            printf("Digite o treino para %s: ", diasSemana[j]);
            fgets(treinoDia, sizeof(treinoDia), stdin);
            treinoDia[strcspn(treinoDia, "\n")] = 0;
            strcpy(tabelaAluno[indice].treino[j], treinoDia);
        }
        printf("Treinos atualizados com sucesso para o aluno %s!\n", tabelaAluno[indice].usuario);
    }
    else
    {
        printf("Aluno não encontrado!\n");
    }
}

void editarDieta()
{
    char senha[50];
    printf("Digite a senha do aluno para editar a dieta: ");
    scanf("%s", senha);
    getchar();

    int indice = buscarAlunoPorSenha(senha);
    if (indice != -1)
    {
        printf("Aluno encontrado: %s\n", tabelaAluno[indice].usuario);
        char dietaDia[100];
        const char *diasSemana[7] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado", "Domingo"};

        for (int j = 0; j < MAX_DIAS; j++)
        {
            printf("Digite a dieta para %s: ", diasSemana[j]);
            fgets(dietaDia, sizeof(dietaDia), stdin);
            dietaDia[strcspn(dietaDia, "\n")] = 0;
            strcpy(tabelaAluno[indice].dieta[j], dietaDia);
        }
        printf("Dietas atualizadas com sucesso para o aluno %s!\n", tabelaAluno[indice].usuario);
    }
    else
    {
        printf("Aluno não encontrado!\n");
    }
}

int buscarAlunoPorSenha(char senha[])
{
    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        if (strcmp(tabelaAluno[i].senha, senha) == 0)
        {
            return i;
        }
    }
    return -1;
}

void excluirAluno(int indice)
{
    tabelaAluno[indice].usuario[0] = '\0';
    tabelaAluno[indice].senha[0] = '\0';
    printf("Aluno excluído com sucesso.\n");
}

void exibirInformacoesAluno()
{
    char senha[50];
    printf("Digite a senha do aluno: ");
    scanf("%s", senha);

    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        if (strcmp(tabelaAluno[i].senha, senha) == 0)
        {
            printf("Usuario: %s\n", tabelaAluno[i].usuario);
            printf("Idade: %d\n", tabelaAluno[i].idade);
            printf("Altura: %.2f\n", tabelaAluno[i].altura);
            printf("Peso: %.2f\n", tabelaAluno[i].peso);
            printf("Sexo: %c\n", tabelaAluno[i].sexo);

            printf("\n===== Treinos =====\n");
            const char *diasSemana[7] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado", "Domingo"};
            for (int j = 0; j < MAX_DIAS; j++)
            {
                printf("Treino para %s: %s\n", diasSemana[j], tabelaAluno[i].treino[j]);
            }

            printf("\n===== Dietas =====\n");
            for (int j = 0; j < MAX_DIAS; j++)
            {
                printf("%s: %s\n", diasSemana[j], tabelaAluno[i].dieta[j]);
            }

            int opcao;
            printf("Escolha uma opção:\n");
            printf("1. Excluir Aluno\n");
            printf("2. Sair\n");
            scanf("%d", &opcao);

            switch (opcao)
            {
            case 1:
                excluirAluno(i);
                return;
            case 2:
                printf("Retornando ao menu Personal...\n");
                return;
            default:
                printf("Opção inexistente.\n");
            }
            return;
        }
    }
    printf("Aluno não encontrado!\n");
}

void cadastrarPersonal()
{
    int indice = -1;
    for (int i = 0; i < MAX_PERSONAIS; i++)
    {
        if (tabelaPersonal[i].usuario[0] == '\0')
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        printf("Número máximo de personais atingido!\n");
        return;
    }

    printf("Digite o nome de usuário para o novo personal: ");
    scanf("%s", tabelaPersonal[indice].usuario);
    printf("Digite a senha para o novo personal: ");
    scanf("%s", tabelaPersonal[indice].senha);

    printf("Personal %s cadastrado com sucesso!\n", tabelaPersonal[indice].usuario);
}

void exibirPersonais()
{
    int opcao;
    do
    {
        printf("\n===== LISTA DE PERSONAIS =====\n");
        for (int i = 0; i < MAX_PERSONAIS; i++)
        {
            if (tabelaPersonal[i].usuario[0] != '\0')
            {
                printf("%d. Usuario: %s, Senha: %s\n", i + 1, tabelaPersonal[i].usuario, tabelaPersonal[i].senha);
            }
        }
        printf("==============================\n");
        printf("1. Excluir personal\n");
        printf("2. Cadastrar novo personal\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            excluirPersonal();
            break;
        case 2:
            cadastrarPersonal();
            break;
        case 3:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 3);
}

int buscarPersonalPorSenha(char senha[])
{
    for (int i = 0; i < MAX_PERSONAIS; i++)
    {
        if (strcmp(tabelaPersonal[i].senha, senha) == 0)
        {
            return i;
        }
    }
    return -1;
}

void excluirPersonal()
{
    char senha[50];
    printf("Digite a senha do personal para excluir: ");
    scanf("%s", senha);

    for (int i = 0; i < MAX_PERSONAIS; i++)
    {
        if (strcmp(tabelaPersonal[i].senha, senha) == 0)
        {
            printf("Excluindo personal: %s\n", tabelaPersonal[i].usuario);
            tabelaPersonal[i].usuario[0] = '\0'; // personal foi pra a casa do chapeu
            tabelaPersonal[i].senha[0] = '\0';   // F pra a senha do personal
            printf("Personal excluído com sucesso!\n");
            return;
        }
    }
    printf("Personal não encontrado!\n");
}

// esuqleto pro menu personal
void menuPersonal()
{
    int opcaoPersonal;
    do
    {
        printf("\n===== MENU PERSONAL =====\n");
        printf("1. Exibir Alunos\n");
        printf("2. Cadastrar Aluno\n");
        printf("3. Treino\n");
        printf("4. Dieta\n");
        printf("5. Exibir Personais\n");
        printf("6. Sair\n");
        printf("===========================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoPersonal);

        switch (opcaoPersonal)
        {
        case 1:
            exibirInformacoesAluno();
            break;
        case 2:
        {
            char usuario[50], senha[50], sexo;
            int idade;
            float altura, peso;
            char treino[MAX_DIAS][100], dieta[MAX_DIAS][100];

            printf("Digite o usuario: ");
            scanf("%s", usuario);
            printf("Digite a senha: ");
            scanf("%s", senha);
            printf("Digite a idade: ");
            scanf("%d", &idade);
            printf("Digite a altura (em metros): ");
            scanf("%f", &altura);
            printf("Digite o peso (em kg): ");
            scanf("%f", &peso);
            printf("Digite o sexo (M/F): ");
            scanf(" %c", &sexo);

            for (int i = 0; i < MAX_DIAS; i++)
            {
                printf("Digite o treino para o dia %d: ", i + 1);
                scanf(" %[^\n]", treino[i]);
                printf("Digite a dieta para o dia %d: ", i + 1);
                scanf(" %[^\n]", dieta[i]);
            }

            cadastrarAluno(usuario, senha, idade, altura, peso, sexo, treino, dieta);
            break;
        }
        case 3:
            editarTreino();
            break;
        case 4:
            editarDieta();
            break;
        case 5:
            exibirPersonais();
            break;
        case 6:
            printf("Saindo do menu...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (opcaoPersonal != 6);
}
