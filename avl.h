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
noAvl* inserir(noAvl *raiz, int chave);
noAvl* buscar(noAvl *raiz, int chave);
void emOrdem(noAvl *raiz);
void imprimirArvore(noAvl *raiz, int nivel);


#endif
