#include <stdio.h>
#include "avl.h" 

void testarVisualizacao() {
    pont raiz = criaArvore();
    int valores[] = {30, 20, 60, 40, 70, 10, 50};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++)
        raiz = inserir(raiz, valores[i]);

    printf("\nVisualização da Árvore AVL (pré-ordem - estrutura da árvore):\n");
    preOrdem(raiz);
    printf("\n");

    printf("\nEm ordem (valores ordenados):\n");
    emOrdem(raiz);
    printf("\n");

    printf("\nVisualização da Árvore AVL (em linha):\n");
    imprimirEmLinha(raiz);
    printf("\n");
}

int main() {
    testarVisualizacao();
    return 0;
}
