#include <stdlib.h>


typedef struct lista{
    struct no* ini;
}Lst;

typedef struct no{
    int info;
    struct no* prox;
}No;