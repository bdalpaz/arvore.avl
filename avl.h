#ifndef AVL_H
#define AVL_H

typedef struct noAvl {
    int chave;
    struct noAvl *esq;
    struct noAvl *dir;
    int altura;
} noAvl;

typedef noAvl* pont;

pont criaArvore();
pont inserir(pont raiz, int chave);
pont buscar(pont raiz, int chave);

void emOrdem(pont raiz);
void preOrdem(pont raiz);
void imprimirEmLinha(pont raiz); 

#endif
