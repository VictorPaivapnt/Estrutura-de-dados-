#include<stdlib.h>


struct no{
    int info;
    struct no* prox;
};

struct fila{
    struct no* inicio;
    struct no* fim;
};


