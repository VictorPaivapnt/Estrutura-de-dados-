#include<stdlib.h>




struct pilha{
    struct no* top;

};

struct no{
    int info;
    struct no* prox;

};
struct pilha* push(struct pilha* p, int v){
    struct no* no = cria_no();
    no->prox = p->top;
    p->top = no;

    return p;
}


struct pilha* pop(struct pilha* p){
    if(p== NULL){
        printf("pilha ja está vazia/n");
        exit(1);
    }
    struct pilha* aux = p->top;
}

struct calc_pos{
    char f[21];
    struct pilha* p;
};