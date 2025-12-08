#include <stdlib.h>
#include <stdio.h>

// Estruturas
struct Caixa {
    int valor;
    struct Caixa* prox;
};

// Assinaturas das funções
void Exibir (struct Caixa * caixa);



int main (void) {

  struct Caixa * c5 = malloc(sizeof(struct Caixa)); c5->valor = 5; c5->prox = NULL;
  struct Caixa * c4 = malloc(sizeof(struct Caixa)); c4->valor = 7; c4->prox = c5;
  struct Caixa * c3 = malloc(sizeof(struct Caixa)); c3->valor = 9; c3->prox = c4;
  struct Caixa * c2 = malloc(sizeof(struct Caixa)); c2->valor = 3; c2->prox = c3;
  struct Caixa * c1 = malloc(sizeof(struct Caixa)); c1->valor = 1; c1->prox = c2;

  Exibir(c1);

  return 0;
}



// Funções completas
void Exibir (struct Caixa * caixa) {
  // exibe uma lista encadeada

  for (struct Caixa * p = caixa; p != NULL; p = p->prox) {
    printf("%d", p->valor);
    if (p->prox != NULL) printf(" -> ");
    else printf(" -> NULL\n");
  }
}