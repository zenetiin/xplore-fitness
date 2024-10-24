#include <stdio.h>
#include <string.h>
#include "aluno.h"

struct Aluno tabelaAluno[MAX_ALUNOS];

void inicializarAlunos()
{
    printf("Inicializando aluno\n");
    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        tabelaAluno[i].usuario[0] = '\0'; // Inicializando com string vazia
        tabelaAluno[i].senha[0] = '\0';   // Inicializando a senha como vazia também
    }

    // Adicionando um aluno de teste (ze)
    strcpy(tabelaAluno[0].usuario, "ze");
    strcpy(tabelaAluno[0].senha, "001002123");
    tabelaAluno[0].idade = 20;
    tabelaAluno[0].altura = 1.75;
    tabelaAluno[0].peso = 70.0;
    tabelaAluno[0].sexo = 'M';
    strcpy(tabelaAluno[0].treino, "Treino A");
    strcpy(tabelaAluno[0].dieta, "Dieta A");
}

int validarLoginAluno(char usuario[], char senha[])
{
    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        printf("Comparando com: %s, %s\n", tabelaAluno[i].usuario, tabelaAluno[i].senha);
        if (strcmp(tabelaAluno[i].usuario, usuario) == 0 && strcmp(tabelaAluno[i].senha, senha) == 0)
        {
            return 1;
        }
    }
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
            printf("Aqui exibe o treino do aluno logado\n");
            break;
        case 3:
            printf("Aqui exibe a dieta do aluno logado\n");
            break;
        case 4:
            printf("Logoff\n");
            break;
        default:
            printf("Opção inexistente.\n");
        }
    } while (opcaoAluno != 4);
}
