#include <stdio.h>
#include "aluno.h"

void menuAluno()
{

    int opcaoAluno;

    do
    {
        printf("\n===== MENU ALUNO =====\n");
        printf("1. Informações Pessoais\n");
        printf("2. Treino\n");
        printf("3. Dieta\n");
        printf("4. Sair\n");
        printf("======================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoAluno);

        switch (opcaoAluno)
        {
        case 1:
            printf("Aqui sera exibido as propiras informações do aluno logado\n");
            break;
        case 2:
            printf("Aqui sera exibido o treino do aluno logado\n");
            break;
        case 3:
            printf("Aqui sera exibido a dieta do aluno logado\n");
            break;
        case 4:
            printf("Logoff\n");
            break;
        default:
            printf("Opção inexistente.\n");
        }
    } while (opcaoAluno != 4);
}
