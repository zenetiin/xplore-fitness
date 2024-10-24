#include <stdio.h>
#include <string.h>
#include "personal.h"

struct Personal tabelaPersonal[MAX_USERS];

void inicializarUsuarios()
{
    strcpy(tabelaPersonal[0].usuario, "ryam");
    strcpy(tabelaPersonal[0].senha, "123456");
}

int validarLogin(char usuario[], char senha[])
{
    printf("Validando login...\n"); //debug
    for (int i = 0; i < MAX_USERS; i++)
    {
        printf("Comparando com o usuário: %s\n", tabelaPersonal[i].usuario); //debug
        if (strcmp(tabelaPersonal[i].usuario, usuario) == 0 && strcmp(tabelaPersonal[i].senha, senha) == 0)
        {
            printf("Login bem-sucedido!\n"); //Debug
            return 1;                        
        }
    }
    printf("Falha no login\n"); //Debug
    return 0;                   
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
        printf("5. Sair\n");
        printf("===========================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoPersonal);

        switch (opcaoPersonal)
        {
        case 1:
            printf("Aqui exibirá a lista de alunos criados e suas informações pessoais \n");
            break;
        case 2:
            printf("Aqui será criado o cadastro de um novo aluno, cadastrando suas informações pessoais\n");
            break;
        case 3:
            printf("Aqui será editada a seção de treino de cada aluno (área sujeita a alteração)\n");
            break;
        case 4:
            printf("Aqui será editada a dieta de cada aluno (área sujeita a alteração também)\n");
            break;
        case 5:
            printf("Logoff\n");
            break;
        default:
            printf("Opção inexistente\n");
        }
    } while (opcaoPersonal != 5);
}
