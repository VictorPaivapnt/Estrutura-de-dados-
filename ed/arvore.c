#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int chave;
    int altura;
    struct no* fd; 
    struct no* fe; 
} No;

// Protótipos das funções
No* CriaArv(); // Inicializa uma árvore vazia
No* CriaNo(int v);
int AlturaNo (No* no); // Descobre a altura do no
No* AdicionaNO (No* raiz, int v); // Adiciona um nó na árvore
No* RotacaoEsquerda(No* raiz); // Rotação a esquerda LL
No* RotacaoDireita(No* raiz); //Rotação a direita RR
void MostraPrefixo(No* raiz); // Percurso pré-ordem
void MostraInfixo(No* raiz); // Percurso in-ordem
void MostraInfixo(No* raiz); // Percurso pós-ordem
No* LimpaArvore(No* raiz); // Libera a memória da árvore
int Maior(int a, int b); // Retorna maior entre dois valores(utilizado para comparar altura dos nós)
int FatorBalanceamento(No* no); // calcula o fator de balanceamento dos nós
No* Balancear(No* raiz); // Balanceia a arvore






int main() {
    No* raiz = CriaArv(); 



    raiz = AdicionaN(raiz, 5);
    raiz = AdicionaN(raiz, 9);
    raiz = AdicionaN(raiz, 3);
    raiz = AdicionaN(raiz, 11);
    raiz = AdicionaN(raiz, 7);
    raiz = AdicionaN(raiz, 4);
    raiz = AdicionaN(raiz, 1);
    raiz = AdicionaN(raiz, 8);
     
     
    printf("Pré-ordem: ");
    mostra_1(raiz);
         printf("\n");

    printf("In-ordem: ");
    mostra_2(raiz);
    printf("\n");

    printf("Pós-ordem: ");
    mostra_3(raiz);
    printf("\n");

 
    raiz = limpa_arv(raiz);

    return 0;

}


No* Balancear( No* raiz){
    int fb = FatorBalanceamento(raiz);
    if(fb < -1 && FatorBalanceamento(raiz->fd) <= 0){
        RotacaoEsquerda(raiz);
    }    
    
    }


int AlturaNo(No* no){
    if(no == NULL){
        return -1;
    }
    else{
        return no->altura;
    }
}

int Maior(int a, int b){
    return(a >b)? a:b;
}

int FatorBalanceamento(No* no){
    if(no){
        return AlturaNo(no->fe) - AlturaNo(no->fd);
    }
    else{ return 0;}
}

No* CriaArv() {
    return NULL;
}

No* CriaNo(int v){
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocação de memória.\n");
        exit(1); 
    }
    novo->fd = NULL;
    novo->fe = NULL;
    novo->altura = 0;
    novo->chave = v;
    return novo;
    
}

No* AdicionaNO(No* raiz, int v) {
    if (!raiz) { 
        No* no = CriaNo(v);
        raiz = no;
    }

    if (raiz->chave == v) {
        printf("Chave já existe, insira outra.\n");
        return raiz;
    }

    if (raiz->chave > v) {
        raiz->fe = AdicionaNO(raiz->fe, v);
    } else {
        raiz->fd = AdicionaNO(raiz->fd, v);
    }
     
    raiz->altura = Maior(AlturaNo(raiz->fe), AlturaNo(raiz->fd));

    Balancear(raiz);

    return raiz;
}
    
No* RotacaoDireita(No* raiz){
    No* y, *f;

    y = raiz->fe;
    f = y->fd;

    y->fd = raiz;
    raiz->fe = f;

    raiz->altura = Maior(AlturaNo(raiz->fe), AlturaNo(raiz->fd)) + 1;
    y->altura = Maior(AlturaNo(y->fd), AlturaNo(y->fe)) +1;

    return y;
}
No* RotacaoEsquerda(No* raiz){
    No* y, *f;

    y = raiz->fd;
    f = y->fe;


    y->fe = raiz;
    raiz->fd = f;

    raiz->altura = Maior(AlturaNo(raiz->fd), AlturaNo(raiz->fe)) +1;
    y->altura = Maior(AlturaNo(y->fd), AlturaNo(y->fe)) +1;
    
    return y;
}


void MostraPrefixo(No* raiz) {
    if (!raiz) return;
    printf("%d ", raiz->chave);
    MostraPrefixo(raiz->fe);
    MostraPrefixo(raiz->fd);
}


void MostraInfixo(No* raiz) {
    if (!raiz) return;
    MostraInfixo(raiz->fe);
    printf("%d ", raiz->chave);
    MostraInfixo(raiz->fd);
}


void MostraPosfixo(No* raiz) {
    if (!raiz) return;
    MostraPosfixo(raiz->fe);
    MostraPosfixo(raiz->fd);
    printf("%d ", raiz->chave);
}


No* LimpaArvore(No* raiz) {
    if (!raiz) return NULL;
    raiz->fe = LimpaArvore(raiz->fe);
    raiz->fd = LimpaArvore(raiz->fd);
    free(raiz);
    return NULL;
}
