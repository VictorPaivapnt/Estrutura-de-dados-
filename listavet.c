#include <stdio.h>
#include <stdlib.h>
#include "listavet.h"


void criar_lista(Lista* lst) {       
    lst->indice = -1;
}

int consulta(int num, Lista* lst) {
    if (esta_vazia(lst)) {
        return 0;
    }
    
    for (int i = 0; i <= lst->indice; i++) {
        if (lst->dados[i] == num) {
            return 1;
        }
    }
    return 0; 
}

char esta_cheia(Lista *lst) {
    return (lst->indice == T - 1) ? 1 : 0;
}

char esta_vazia(Lista *lst) {
    return (lst->indice == -1) ? 1 : 0;
}

char inserir_fim(int dado, Lista* lst) {
    if (esta_cheia(lst)) {
        printf("Lista cheia\n");
        return 0;
    }
    lst->indice++;
    lst->dados[lst->indice] = dado;
    return 1;
}

void remover_fim(Lista* lst) {
    if (esta_vazia(lst)) {
        printf("Lista já está vazia\n");
    } else {
        lst->indice--;
    }
}

void mostrar_lista(Lista* lst) {
    if (esta_vazia(lst)) {
        printf("Lista vazia\n");
        return;
    }
    
    for (int i = 0; i <= lst->indice; i++) {
        printf("%d ", lst->dados[i]);
    }
    printf("\n");
}

int tamanho(Lista lst) {
    return lst.indice + 1;
}

