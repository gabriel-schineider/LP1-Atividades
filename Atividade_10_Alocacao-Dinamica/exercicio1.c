#include <stdlib.h>

// Estruturas
struct Caixa {
    int valor;
    struct Caixa* prox;
};

int main (void) {

  struct Caixa * c5 = malloc(sizeof(struct Caixa)); c5->valor = 5; c5->prox = NULL;
  struct Caixa * c4 = malloc(sizeof(struct Caixa)); c4->valor = 7; c4->prox = c5;
  struct Caixa * c3 = malloc(sizeof(struct Caixa)); c3->valor = 9; c3->prox = c4;
  struct Caixa * c2 = malloc(sizeof(struct Caixa)); c2->valor = 3; c2->prox = c3;
  struct Caixa * c1 = malloc(sizeof(struct Caixa)); c1->valor = 1; c1->prox = c2;
 
  return 0;
}