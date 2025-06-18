#include <stdlib.h>
#include <stdio.h>

int main() {
    int fib;

    printf("Digite a quantidade de termos da sequência de Fibonacci desejada:\n");
    scanf("%d", &fib);

    // Validar a entrada.
    if (fib <= 0) {
        printf("Por favor, insira um número positivo.\n");
    } else if (fib == 1) {
        printf("0\n");
    } else {
        int a = 0, b = 1;
        printf("0, 1");

        for (int i = 2; i < fib; i++) {
            int aux = a + b;
            printf(", %d", aux);
            a = b;
            b = aux;
        }
        printf("\n"); // Finaliza com uma quebra de linha.
    }

    // Limpar o buffer para evitar problemas com entradas subsequentes
    fflush(stdin);

    return 0;
}

