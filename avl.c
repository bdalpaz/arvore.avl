#include <stdio.h>
#include <stdlib.h>

typedef struct noAvl {
    int chave;            //valor do nó
    struct noAvl *esq;
    struct noAvl *dir;
    int altura;
} noAvl;

typedef noAvl* pont;

// Função para obter altura do nó
int altura(noAvl *no) {
    if (no == NULL) return 0;
    return no->altura;
}
// Função para calcular o fator de balanceamento
int fatorBalanceamento(noAvl *no) {
    if (no == NULL) return 0;
    return altura(no->esq) - altura(no->dir);
}

// Atualiza altura de um nó
void atualizarAltura(noAvl *no) {
    int altesq = altura(no->esq);
    int altdir = altura(no->dir);
    no->altura = (altesq > altdir ? altesq : altdir) + 1;
}

// Rotação à direita
noAvl *rotacao_direita(noAvl *noDesbalanceado) {
    noAvl *novaRaiz = noDesbalanceado->esq;
    noAvl *subarvoreTemporaria  = novaRaiz->dir;

       novaRaiz->dir = noDesbalanceado;
    noDesbalanceado->esq = subarvoreTemporaria ;

    atualizarAltura(noDesbalanceado);
    atualizarAltura(novaRaiz);

    return novaRaiz;
}

// Rotação à esquerda
noAvl *rotacao_esquerda(noAvl *noDesbalanceado) {
    noAvl *novaRaiz = noDesbalanceado->dir;
    noAvl *subarvoreTemporaria  = noDesbalanceado->esq;

    novaRaiz->esq = noDesbalanceado;
    noDesbalanceado->dir = subarvoreTemporaria ;

        atualizarAltura(noDesbalanceado);
    atualizarAltura(novaRaiz);

    return novaRaiz;
}

// Função de balanceamento
noAvl* balancear(noAvl *no) {
    int fb = fatorBalanceamento(no);

    if (fb > 1) {
        if (fatorBalanceamento(no->esq) < 0)
            no->esq = rotacao_esquerda(no->esq); 
        return rotacao_direita(no);
    }
    if (fb < -1) {
        if (fatorBalanceamento(no->dir) > 0)
            no->dir = rotacao_direita(no->dir); 
        return rotacao_esquerda(no); 
    }

      return no;
}

// Função de inserção 
noAvl* inserir(noAvl *raiz, int chave) {
    if (raiz == NULL) {
        noAvl *novoNo = (noAvl*)malloc(sizeof(noAvl));
        novoNo->chave = chave;
        novoNo->esq = novoNo->dir = NULL;
        novoNo->altura = 1;
        return novoNo;
    }

        if (chave < raiz->chave)
        raiz->esq = inserir(raiz->esq, chave);
    else if (chave > raiz->chave)
        raiz->dir = inserir(raiz->dir, chave);
    else // chaves iguais não são permitidas
        return raiz;

    atualizarAltura(raiz);
    return balancear(raiz);
}

// Função de busca
noAvl* buscar(noAvl *raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave)
        return raiz;
    if (chave < raiz->chave)
        return buscar(raiz->esq, chave);
    return buscar(raiz->dir, chave);
}

// Cria árvore vazia
pont criaArvore() {
    return NULL;
}

// Impressão em ordem
void emOrdem(noAvl *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        emOrdem(raiz->dir);
    }
}

void imprimirArvore(noAvl *raiz, int nivel) {
    if (raiz == NULL)
        return;

    imprimirArvore(raiz->dir, nivel + 1);

    for (int i = 0; i < nivel; i++)
        printf("     "); 
        

    printf("%d\n", raiz->chave);

    imprimirArvore(raiz->esq, nivel + 1);
}
