#include <stdio.h>
#include <string.h>
#include "personal.h"
#include "aluno.h"

struct Personal tabelaPersonal[MAX_USERS];

// usuario inicial ryam para teste
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

void cadastrarAluno(char usuario[], char senha[], int idade, float altura, float peso, char sexo, char treino[], char dieta[])
{
    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        if ((tabelaAluno[i].usuario[0]) == '\0')
        {
            strcpy(tabelaAluno[i].usuario, usuario);
            strcpy(tabelaAluno[i].senha, senha);
            tabelaAluno[i].idade = idade;
            tabelaAluno[i].altura = altura;
            tabelaAluno[i].peso = peso;
            tabelaAluno[i].sexo = sexo;
            strcpy(tabelaAluno[i].treino, treino);
            strcpy(tabelaAluno[i].dieta, dieta);
            printf("Aluno %s cadastrado com sucesso!\n", usuario);
            break;
        }
    }
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
            printf("Aqui exibirá a lista de alunos criados e suas informações pessoais \n");
            break;
        case 2:
        {
            // dados para cadastrar aluno
            char usuario[50], senha[50], treino[100], dieta[100], sexo;
            int idade;
            float altura, peso;
            getchar(); // retira o \n que sobrar pra nao prejudicar as entradas

            printf("Cadastrar novo aluno:\n");
            printf("Usuario: ");
            scanf("%s", usuario);

            printf("Senha: ");
            scanf("%s", senha);

            printf("Idade: ");
            scanf("%d", &idade);

            printf("Altura: ");
            scanf("%f", &altura);

            printf("Peso: ");
            scanf("%f", &peso);

            getchar(); // retira o \n

            printf("Sexo (M/F): ");
            scanf("%c", &sexo);

            getchar(); // retira o \n

            printf("Treino: ");
            fgets(treino, 100, stdin);         // fgets le a string que tem espaços
            treino[strcspn(treino, "\n")] = 0; // Remove o '\n' que o fgets faz

            printf("Dieta: ");
            fgets(dieta, 100, stdin);
            dieta[strcspn(dieta, "\n")] = 0;

            cadastrarAluno(usuario, senha, idade, altura, peso, sexo, treino, dieta);
            break;
        }
        case 3:
            printf("Aqui será editada a seção de treino de cada aluno (área sujeita a alteração)\n");
            break;

        case 4:
            printf("Aqui será editada a dieta de cada aluno (área sujeita a alteração também)\n");
            break;

        case 5:
            printf("Aqui serao exibidos os outros personais\n");
            break;

        case 6:
            printf("Voltando ao menu inicial...\n");
            break;

        default:
            printf("Opção inexistente\n");
        }
    } while (opcaoPersonal != 6);
}
