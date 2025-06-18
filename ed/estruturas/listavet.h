#ifndef LISTAVET_H
#define LISTAVET_H
#define T 30


typedef struct lista{
    int indice;
    int dados[T];

}Lista;

void criar_lista( Lista*);
int consulta(int num,  Lista*);
char esta_cheia( Lista*);
char esta_vazia(Lista*);
char inserir_fim(int, Lista*);
void remover_fim(Lista*);
void mostrar_lista(Lista*);
int tamanho(Lista);






#endif