#include <stdio.h>
#include "avl.h"

void testarVisualizacao() {
    pont raiz = criaArvore();
    int valores[] = {10, 20, 30, 25, 5, 15};
    int n = sizeof(valores)/sizeof(valores[0]);

    for (int i = 0; i < n; i++)
        raiz = inserir(raiz, valores[i]);

    printf("\nVisualização da Árvore AVL:\n\n");
    imprimirArvore(raiz, 0);
}

int main() {
    testarVisualizacao();
    return 0;
}
