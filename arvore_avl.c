typedef struct noAvl {
  int info;             
  struct noAvl *esq;         // Ponteiro para o filho da esquerda
  struct noAvl *dir;         // Ponteiro para o filho da direita
  int alt;                     // Altura do nó
} noAvl;

noAvl *rotacao_esquerda(noAvl *no);
noAvl *rotacao_direita(noAvl *no);


int altura(struct noAvl *subarvore) {
  if (subarvore == NULL)
      return -1; // A altura de uma subárvore inexistente é -1
  else
      return subarvore->alt;
}
