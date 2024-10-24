#ifndef PERSONAL_H
#define PERSONAL_H

#define MAX_USERS 10

struct Personal
{
    char usuario[50];
    char senha[50];
};

void menuPersonal();
int validarLogin(char usuario[], char senha[]);
void inicializarUsuarios();

#endif
