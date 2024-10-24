#include <stdio.h>
#include <string.h>
#include "personal.h"
#include "aluno.h"

struct Personal tabelaPersonal[MAX_USERS];
struct Aluno tabelaAluno[MAX_ALUNOS];

// startando ryamzin do grau
void inicializarUsuarios()
{
    strcpy(tabelaPersonal[0].usuario, "ryam");
    strcpy(tabelaPersonal[0].senha, "123456");
}

int validarLogin(char usuario[], char senha[])
{
    printf("Validando login...\n"); // debug
    for (int i = 0; i < MAX_USERS; i++)
    {
        printf("Comparando com o usuário: %s\n", tabelaPersonal[i].usuario); // debug
        if (strcmp(tabelaPersonal[i].usuario, usuario) == 0 && strcmp(tabelaPersonal[i].senha, senha) == 0)
        {
            printf("Login bem-sucedido!\n"); // debug
            return 1;
        }
    }
    printf("Falha no login\n"); // debug
    return 0;
}

void cadastrarAluno(char usuario[], char senha[], int idade, float altura, float peso, char sexo, char treino[][100], char dieta[][100])
{
    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        if (tabelaAluno[i].usuario[0] == '\0')
        { // Encontrar posição vazia
            strcpy(tabelaAluno[i].usuario, usuario);
            strcpy(tabelaAluno[i].senha, senha);
            tabelaAluno[i].idade = idade;
            tabelaAluno[i].altura = altura;
            tabelaAluno[i].peso = peso;
            tabelaAluno[i].sexo = sexo;

            for (int j = 0; j < MAX_DIAS; j++)
            {
                strcpy(tabelaAluno[i].treino[j], treino[j]); // pega os treinos do aluno
                strcpy(tabelaAluno[i].dieta[j], dieta[j]);   // pega as dietas do aluno
            }
            printf("Aluno %s cadastrado com sucesso!\n", usuario);
            break;
        }
    }
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
            fgets(treinoDia, sizeof(treinoDia), stdin);       // le a entrada do treino
            treinoDia[strcspn(treinoDia, "\n")] = 0;          // remove o \n do fgets
            strcpy(tabelaAluno[indice].treino[j], treinoDia); // bota o treino por cima do antigo
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
            fgets(dietaDia, sizeof(dietaDia), stdin);       // Le a entrada da dieta todinha
            dietaDia[strcspn(dietaDia, "\n")] = 0;          // remove o \n do fgets
            strcpy(tabelaAluno[indice].dieta[j], dietaDia); // joga essa dieta por cima da que tiver la
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
    tabelaAluno[indice].usuario[0] = '\0'; // F usuário
    tabelaAluno[indice].senha[0] = '\0';   // F senha
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
                excluirAluno(i); // o i é onde o aluno ta na hash
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
            scanf(" %c", &sexo); // o c ta afastado pra nao pegar o espaço

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
            printf("Aqui serao exibidos os outros personais\n");
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
