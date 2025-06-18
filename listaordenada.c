#include <stdio.h>
#include <stdlib.h>
#include "listavet.h"

void insere_18(Lista* l){
    int j = l->indice;
    for(int i = 0; i < l->indice; i++){
        if(l->dados[i] > 18){
            for(j; j > i; j--){
                l->dados[j+1] = l->dados[j];
            }
        }   
    }
    l->dados[j] = 18;
    l->indice +=1;
}

int main(){

    return 0;
}