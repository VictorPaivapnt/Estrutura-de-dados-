#include <stdlib.h>
#include <stdio.h>
#ifndef  LISTADUPLADINAM_H
#define LISTADUPLADINAM_H

//Lista duplamente escadeada
//sem restrições de acesso

typedef struct no{
    int dado;
    struct no*ant;
    struct no* prox;
}No;

typedef struct lista{
    struct no* ini;
    struct no* fim;
}Lst;


Lst* cria_lista(){
    Lst * ll = (Lst*)malloc(sizeof(Lst));
    if(ll = NULL){
        printf("erro ao alocar/n");
    }
    ll->ini = 0;
    ll->fim = 0;
}
No* cria_no(Lst* ll, int valor){
    No* novo = (No*)malloc(sizeof(No));
    if(novo){
        novo->ant = 0;
        novo->prox =  0;
        return novo;
    }
    else{return;}
}

No* adiciona_inicio(Lst* ll, No* no){
    if(ll->ini == 0){
        ll->ini = no;
        ll->fim = no;
    }
    else{
        no->prox = ll->ini;
        ll->ini->ant =no;
        ll->ini = no;
    }

}

No* adiciona_fim(Lst* ll, No* no){
    if(ll->ini == 0){
        ll->ini = no;
        ll->fim = no;
    }
    else{
    no->ant = ll->fim;
    no->ant->prox = no;
    ll->fim = no;
    }
}

void adiciona_meio(Lst* ll, No* no, int chave){
    No* aux;
    //insercao do elemento antes da chave
    for(aux = ll->ini; aux->dado != chave; aux = aux->prox){    
        no->prox = aux;
        no->ant = aux->ant;
        no->prox->ant = no;
        no->ant->prox = no;
    }

}

int comprimento( Lst* l){
    No* aux = l->ini;
    int c = 0;
    if(l == NULL){
            return c;
        }
        while(aux != NULL){
            c++;
            aux = aux->prox;
        }
        return c;

}

int maiores(Lst* l, int n){
    No* aux = l->ini;
    int maioresQn = 0;
    while(aux != NULL){
        if(aux->dado > n){
            maioresQn++;
        }
        aux = aux->prox;
    }
    return maioresQn;
}
//funcao para encontrar o ultimo elemento supondo uma implementacao
// de lista simples encadeada.
Lst* ultimo(Lst* l){
    Lst*aux = l;
    while(aux->ini != NULL){
        aux->ini = aux->ini->prox;
    }
    return aux;
}

Lst* concatena(Lst* l1, Lst* l2){
    Lst*l3;
    l3 = cria_lista(l3)
}





#endif