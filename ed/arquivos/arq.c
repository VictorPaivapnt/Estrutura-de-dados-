#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *db, *db1, *db2;
    int i, idade;
    char nome[30], cpf[16];

    db = fopen("DB.txt", "r");
    if (!db) {
        perror("Erro ao abrir DB.txt");
        return 1;
    }

    db1 = fopen("db1.txt", "w");
    if (!db1) {
        perror("Erro ao abrir db1.txt");
        fclose(db);
        return 1;
    }

    db2 = fopen("db2.txt", "w");
    if (!db2) {
        perror("Erro ao abrir db2.txt");
        fclose(db);
        fclose(db1);
        return 1;
    }

    // Corrigindo a condição do loop
    for (i = 0; i < 14; i++) {
        if (fscanf(db, "%s %s %d", nome, cpf, &idade) != 3) {
            perror("Erro ao ler os dados do arquivo");
            break;
        }

        // Escrevendo em db1 os nomes e CPFs
        fprintf(db1, "%s %s\n", nome, cpf);

        // Escrevendo em db2 as idades
        fprintf(db2, "%d\n", idade);
    }

    fclose(db);
    fclose(db1);
    fclose(db2);

    return 0;
}
