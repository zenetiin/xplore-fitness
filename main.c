#include <stdio.h>
#include <string.h>
#include "personal.h"
#include "aluno.h"

void loginPersonal()
{
    printf("Entrando como Personal.\n");
    menuPersonal();
}

void loginAluno()
{
    printf("Entrando como Aluno.\n");
    menuAluno();
}

int main()
{
    int opcao;
    char usuario[50], senha[50];

    inicializarUsuarios();
    inicializarAlunos();

    do
    {
        printf("\n===== MENUZIN INICIAL =====\n");
        printf("1. Login como Personal\n");
        printf("2. Login como Aluno\n");
        printf("3. Sair\n");
        printf("=============================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Usuario: ");
            scanf("%s", usuario); 
            printf("Senha: ");
            scanf("%s", senha);

            if (validarLogin(usuario, senha))
            {
                printf("Login com sucesso\n");
                menuPersonal();
            }
            else
            {
                printf("Usuario ou senha incorretos, tente novamente\n");
            }
            break;

        case 2:
            printf("Usuario: ");
            scanf("%s", usuario);
            printf("Senha: ");
            scanf("%s", senha);
            
            if (validarLoginAluno(usuario, senha))
            {
                printf("Login bem sucedido\n");
                loginAluno();
            }
            else
            {
                printf("Usuario ou senha incorretos\n");
            }
            break;

        case 3:
            printf("Até a próxima\n");
            break;

        default:
            printf("Opção inexistente\n");
        }
    } while (opcao != 3);

    return 0;
}
