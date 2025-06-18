//Imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definindo tipos
struct no{
    struct no* esq;
    int valor;
    struct no* dir;
    int fb;
};

typedef struct no No;

//Protótipo de Funções
int altura_arv(No* raiz);
int conta_nos(No* raiz);
No* cria_arvore();
No* insere_arv(No* raiz, int dado);
void insere_srec(No** raiz, int dado);
No* limpa_arv(No* raiz);
void mostra_arvore_pre(No* raiz);
void mostra_arvore_inf(No* raiz);
void mostra_arvore_pos(No* raiz);
No* rota_dir(No* raiz);
No* rota_esq(No* raiz);


//main
int main(){
    int i, mostra, n;
    No* arvore;
    
    do
    {
        printf("\nDigite qual opreacao deseja realizar:\n1.Criar a arvore\n2.Mostrar a arvore\n3.Inserir na arvore\n4.Insere sem recursividade\n0.Sair\n\n");
        scanf("%d", &i);

        if (i==1)
        {
            arvore = cria_arvore();
        }

        if (i==2)
        {
            printf("\nDigite qual tipo deseja mostrar:\n1.Prefix\n2.Infix\n3.Posfix\n\n");
            scanf("%d", &mostra);
            if (mostra == 1)
            {
                mostra_arvore_pre(arvore);
            }
            if (mostra == 2)
            {
                mostra_arvore_inf(arvore);
            }
            if (mostra == 3)
            {
                mostra_arvore_pos(arvore);
            }
            
        }

        if (i==3)
        {
            printf("\n\nDigite o numero que deseja inserir: ");
            scanf("%d", &n);
            arvore = insere_arv(arvore,n);
        }

        if (i==4)
        {
            printf("\n\nDigite o numero que deseja inserir: ");
            scanf("%d", &n);
            insere_srec(&arvore,n);
        }

        if (i==0)
        {
            limpa_arv(arvore);
        }
        
        
        
    } while (i!=0);
    return 0;
}

//Funções

int altura_arv(No* raiz){
    int a, b;
    if (raiz)
    {
        a = altura_arv(raiz->esq);
        b = altura_arv(raiz->dir);
        if (a>b)
        {
            return a+1;
        }
        else
        {
            return b+1;
        } 
    }
    else
    {
        return 0;
    }
}

int conta_nos(No* raiz){
    int a, b;
    if (raiz)
    {
        a = conta_nos(raiz->esq);
        b = conta_nos(raiz->dir);
        return (a+b+1);
    }
    else
    {
        return 0;
    }
}

No* cria_arvore(){
    return 0;
}

void insere_srec(No** raiz, int dado){
    No* aux;
    No* prev;
    aux = *(raiz);
    
    if(aux != 0){ 
        while (aux->dir!=0 && aux->esq!=0)
        {
            if(dado > aux->valor)
            {
                aux = aux->dir;
            }
            else
            {
                aux = aux->esq;
            }
        }
    }
   
    
    No* novo;
    novo = (No*)malloc(sizeof(No));
    if (novo)
    {
        novo->valor = dado;
        novo->esq = 0;
        novo->dir = 0;
        novo->fb = 0;

        if(aux == 0)
        {
            *(raiz) = novo;
        }
        else if(dado > aux->valor)
        {
            aux->dir = novo;
        }
        else
        {
            aux->esq = novo;
        }
    }
    
}

No* insere_arv(No* raiz, int dado){
    if(raiz == 0)
    {
        No* novo;
        novo = (No*)malloc(sizeof(No));
        if(novo)
        {
            novo->valor = dado;
            novo->esq = 0;
            novo->dir = 0;
            novo->fb = 0;
        }
        return novo;
    }
    else
    {
        if (dado>raiz->valor)
        {
            raiz->dir = insere_arv(raiz->dir, dado);
        }
        else
        {
            raiz->esq = insere_arv(raiz->esq, dado);
        }

        raiz->fb = altura_arv(raiz->esq) - altura_arv(raiz->dir);

        if (raiz->fb == 2)
        {
            printf("Arvore desbalanceada");
            if (raiz->esq->fb == -1)
            {
                raiz->esq = rota_esq(raiz->esq);
            }
            raiz = rota_dir(raiz);
        }
        if (raiz->fb == -2) 
        {
            printf("Arvore desbalanceada");
            if (raiz->dir->fb == 1)
            {
                raiz->dir = rota_dir(raiz->dir);
            }
            raiz = rota_esq(raiz);
        }


        return raiz;
    }

}

No* limpa_arv(No* raiz){ //Usa conceitos de PosFix
    if(raiz)
    {
        raiz->esq = limpa_arv(raiz->esq);
        raiz->dir = limpa_arv(raiz->dir);
        free(raiz);
        return 0;
    }
    else
    {
        return 0;
    }
}

    //Existem 3 caminhos de se mostrar a arvore (Prefix, Infix, Posfix)
    //Prefix - info, esq, dir -- 
    //Infix - esq, info, dir -- Ordenação
    //Posfix - esq, dir, info -- Profundidade
    //Todas as 3 sendo uma leve alteração no código. Exemplo a seguir

void mostra_arvore_pre(No* raiz){
    if(raiz)
    {
        printf("%d ", raiz->valor);
        mostra_arvore_pre(raiz->esq);
        mostra_arvore_pre(raiz->dir);
    }
    else
    {
        return;
    }
}

void mostra_arvore_inf(No* raiz){
    if(raiz)
    {
        mostra_arvore_inf(raiz->esq);
        printf("%d ", raiz->valor);
        mostra_arvore_inf(raiz->dir);
    }
    else
    {
        return;
    }
}

void mostra_arvore_pos(No* raiz){
    if(raiz)
    {
        mostra_arvore_pos(raiz->esq);
        mostra_arvore_pos(raiz->dir);
        printf("%d ", raiz->valor);
    }
    else
    {
        return;
    }
}

No* rota_dir(No* raiz){  //rotacao esquerda esqeurda
    No* aux;

    aux = raiz->esq;
    raiz->esq = aux->dir;
    aux->dir = raiz;
    raiz = aux;
    return(raiz);
}

No* rota_esq(No* raiz){ //rotacao direita direita
    No* aux;

    aux = raiz->dir;
    raiz->dir = aux->esq;
    aux->esq = raiz;
    raiz = aux;
    return(raiz);
}