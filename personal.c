#include <stdio.h>
#include "personal.h"

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
            printf("Aqui exibira a lista de alunos criados e, suas informações pessoais \n");
            break;
        case 2:
            printf("Aqui sera criado o cadastro de um novo aluno, cadastrando suas informações pessoais\n");
            break;
        case 3:
            printf("Aqui sera editado a seção de treino de cada aluno (area sujeita a alteração)/n");
            break;
        case 4:
            printf("Aqui sera editada a dieta de cada aluno (area sujeita a alteração tambem)/n");
            break;
        case 5:
            printf("Logoff\n");
            break;
        default:
            printf("Opção inexistente\n");
        }
    } while (opcaoPersonal != 5);
}
