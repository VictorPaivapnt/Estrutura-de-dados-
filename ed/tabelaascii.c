#include <stdio.h>
#include <stdlib.h>

int main() {
    int chave;

    printf("Digite um codigo entre 0 e 127 para mostrar o caractere equivalente na tabela ASCII:\n");

    // Leitura inicial
    scanf("%d", &chave);

    while (chave >= 0 && chave <= 127) {
        printf("O caractere equivalente eh: '%c'\n", chave);
        printf("Digite outro codigo entre 0 e 127 (ou fora do intervalo para sair):\n");
        scanf("%d", &chave);
    }

    printf("Codigo fora do intervalo. Programa encerrado.\n");

    return 0;
}

