#include <stdio.h>
#include <string.h>
#include "personal.h"
#include "aluno.h"

struct Personal tabelaPersonal[MAX_USERS];

// inicializando ryam
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
    tabelaAluno[indice].usuario[0] = '\0'; // apaga usuario
    tabelaAluno[indice].senha[0] = '\0';   // apaga senha
    printf("Aluno excluído com sucesso.\n");
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
        {
            char senha[50];
            printf("Insira a senha do aluno para exibir as informações: ");
            scanf("%s", senha);

            int indice = buscarAlunoPorSenha(senha);
            if (indice != -1)
            {
                printf("\n===== INFORMAÇÕES DO ALUNO =====\n");
                printf("Usuario: %s\n", tabelaAluno[indice].usuario);
                printf("Idade: %d\n", tabelaAluno[indice].idade);
                printf("Altura: %.2f\n", tabelaAluno[indice].altura);
                printf("Peso: %.2f\n", tabelaAluno[indice].peso);
                printf("Sexo: %c\n", tabelaAluno[indice].sexo);
                printf("Treino: %s\n", tabelaAluno[indice].treino);
                printf("Dieta: %s\n", tabelaAluno[indice].dieta);

                int opcaoAluno;
                do
                {
                    printf("\n1. Excluir Aluno\n");
                    printf("2. Sair\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &opcaoAluno);

                    if (opcaoAluno == 1)
                    {
                        excluirAluno(indice);
                        break;
                    }
                    else if (opcaoAluno != 2)
                    {
                        printf("Opção inválida, tente novamente.\n");
                    }
                } while (opcaoAluno != 2);
            }
            else
            {
                printf("Aluno não encontrado.\n");
            }
            break;
        }
        case 2:
        {
            char usuario[50], senha[50], treino[100], dieta[100], sexo;
            int idade;
            float altura, peso;

            getchar();

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

            getchar();

            printf("Sexo (M/F): ");
            scanf("%c", &sexo);

            getchar();

            printf("Treino: ");
            fgets(treino, 100, stdin);         // fgets le as entradas com espaço
            treino[strcspn(treino, "\n")] = 0; // remove o \n do fgets

            printf("Dieta: ");
            fgets(dieta, 100, stdin);        // fgets le as entradas com espaço
            dieta[strcspn(dieta, "\n")] = 0; // remove o \n do fgets

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
