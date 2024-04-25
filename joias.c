#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "joias.h"

#define MAX_EMAIL_LENGTH 80
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 50
#define MAX_FILE_NAME_LENGTH 50

struct Usuario{
    char email[MAX_EMAIL_LENGTH];
    char senha[20];
};

struct Produto{
    char nome[MAX_NAME_LENGTH];
    char categoria[MAX_CATEGORY_LENGTH];
    float preco;
    int emPromocao; // 1 se estiver em promoção, 0 caso contrário
};

struct no_usuario {
    Usuario dados;
    struct no_usuario* prox;
};