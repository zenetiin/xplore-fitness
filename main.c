#include <stdio.h>
#include <string.h>
#include "personal.h"
#include "aluno.h"

int main() {
    inicializarAlunos();
    inicializarUsuarios();

    int opcaoLogin;
    
    do {
        printf("===== MENU DE LOGIN =====\n");
        printf("1. Login como Aluno\n");
        printf("2. Login como Personal\n");
        printf("3. Sair\n");
        printf("=========================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoLogin);

        if (opcaoLogin == 1) {
            char usuario[50], senha[50];
            printf("Digite seu usuário: ");
            scanf("%s", usuario);
            printf("Digite sua senha: ");
            scanf("%s", senha);

            int alunoIndex = buscarAlunoPorSenha(senha); 
            if (alunoIndex != -1) { 
                menuAluno(alunoIndex); 
            } else {
                printf("Login de aluno falhou!\n");
            }
        } else if (opcaoLogin == 2) {
            char usuario[50], senha[50];
            printf("Digite seu usuário: ");
            scanf("%s", usuario);
            printf("Digite sua senha: ");
            scanf("%s", senha);

            if (validarLogin(usuario, senha)) {
                menuPersonal(); 
            } else {
                printf("Login de personal falhou!\n");
            }
        } else if (opcaoLogin == 3) {
            printf("Saindo...\n");
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcaoLogin != 3);

    return 0;
}