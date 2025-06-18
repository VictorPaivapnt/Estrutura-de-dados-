#include <stdio.h>
#include <stdlib.h>
#include "listavet.h"


int main() {
    Lista minhaLista;
    criar_lista(&minhaLista);

    inserir_fim(10, &minhaLista);
    inserir_fim(20, &minhaLista);
    inserir_fim(30, &minhaLista);

    printf("Elementos da lista: ");
    mostrar_lista(&minhaLista);

    printf("Tamanho da lista: %d\n", tamanho(minhaLista));

    remover_fim(&minhaLista);
    printf("Apos remover o ultimo elemento: ");
    mostrar_lista(&minhaLista);

    return 0;
}
