#include <stdio.h>
#include <string.h>
#include "aluno.h"

struct Aluno tabelaAluno[MAX_ALUNOS];

void inicializarAlunos()
{
    printf("Inicializando alunos...\n");
    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        tabelaAluno[i].usuario[0] = '\0';
        tabelaAluno[i].senha[0] = '\0'; 
    }

    strcpy(tabelaAluno[0].usuario, "ze");
    strcpy(tabelaAluno[0].senha, "001002123");
    tabelaAluno[0].idade = 20;
    tabelaAluno[0].altura = 1.75;
    tabelaAluno[0].peso = 70.0;
    tabelaAluno[0].sexo = 'M';
    strcpy(tabelaAluno[0].treino[0], "Treino A");
    strcpy(tabelaAluno[0].dieta[0], "Dieta A");
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

void exibirInformacoesPessoais(int alunoIndex)
{
    int opcaoEditar;

    printf("\n===== INFORMAÇÕES PESSOAIS =====\n");
    printf("Usuário: %s\n", tabelaAluno[alunoIndex].usuario);
    printf("Senha: %s\n", tabelaAluno[alunoIndex].senha);
    printf("Idade: %d\n", tabelaAluno[alunoIndex].idade);
    printf("Altura: %.2f\n", tabelaAluno[alunoIndex].altura);
    printf("Peso: %.2f\n", tabelaAluno[alunoIndex].peso);
    printf("Sexo: %c\n", tabelaAluno[alunoIndex].sexo);
    printf("================================\n");

    printf("1. Editar Informações\n");
    printf("2. Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcaoEditar);

    if (opcaoEditar == 1)
    {
        editarInformacoesPessoais(alunoIndex);
    }
}

void editarInformacoesPessoais(int alunoIndex)
{
    printf("\n===== EDITAR INFORMAÇÕES =====\n");

    printf("Novo Usuário: ");
    scanf("%s", tabelaAluno[alunoIndex].usuario);

    printf("Nova Senha: ");
    scanf("%s", tabelaAluno[alunoIndex].senha);

    printf("Nova Idade: ");
    scanf("%d", &tabelaAluno[alunoIndex].idade);

    printf("Nova Altura: ");
    scanf("%f", &tabelaAluno[alunoIndex].altura);

    printf("Novo Peso: ");
    scanf("%f", &tabelaAluno[alunoIndex].peso);

    printf("Novo Sexo (M/F): ");
    scanf(" %c", &tabelaAluno[alunoIndex].sexo); 

    printf("Informações atualizadas com sucesso!\n");
}

void exibirTreino(int alunoIndex)
{
    printf("\n--- Treino ---\n");
    for (int dia = 0; dia < MAX_DIAS; dia++)
    {
        printf("Dia %d: %s\n", dia + 1, tabelaAluno[alunoIndex].treino[dia]);
    }
    printf("\nPressione qualquer tecla para voltar ao menu aluno...");
    getchar(); // limpa a peste do buffer pra n da erro nesse carai
    getchar(); // quando apertar qualquer coisa volta
}

void exibirDieta(int alunoIndex)
{
    printf("\n--- Dieta ---\n");
    for (int dia = 0; dia < MAX_DIAS; dia++)
    {
        printf("Dia %d: %s\n", dia + 1, tabelaAluno[alunoIndex].dieta[dia]);
    }
    printf("\nPressione qualquer tecla para voltar ao menu aluno...");
    getchar();
    getchar(); 
}

void menuAluno(int alunoIndex)
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
            exibirInformacoesPessoais(alunoIndex);
            break;
        case 2:
            exibirTreino(alunoIndex);
            break;
        case 3:
            exibirDieta(alunoIndex);
            break;
        case 4:
            printf("Logoff\n");
            break;
        default:
            printf("Opção inexistente.\n");
        }
    } while (opcaoAluno != 4);
}
