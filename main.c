#include <stdio.h>
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
            loginPersonal();
            break;
        case 2:
            loginAluno();
            break;
        case 3:
            printf("Logoff\n");
            break;
        default:
            printf("Opção inexistente\n");
        }
    } while (opcao != 3);

    return 0;
}
