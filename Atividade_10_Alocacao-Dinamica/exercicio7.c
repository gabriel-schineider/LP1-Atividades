#include <stdlib.h>
#include <stdio.h>

// Estruturas
struct Caixa {
    int valor;
    struct Caixa* prox;
};

// Assinatura das funções
void Exibir (struct Caixa * lista);
void Inserir (struct Caixa ** lista, int x);
struct Caixa * Concatenar (struct Caixa * l1, struct Caixa * l2);


int main (void) {

  // Primeira lista
  struct Caixa * c5 = malloc(sizeof(struct Caixa));
  c5->valor = 5; c5->prox = NULL;
  
  struct Caixa * c4 = malloc(sizeof(struct Caixa));
  c4->valor = 4; c4->prox = c5;

  struct Caixa * c3 = malloc(sizeof(struct Caixa));
  c3->valor = 3; c3->prox = c4;

  struct Caixa * c2 = malloc(sizeof(struct Caixa));
  c2->valor = 2; c2->prox = c3;

  struct Caixa * c1 = malloc(sizeof(struct Caixa));
  c1->valor = 1; c1->prox = c2;

  struct Caixa * l1 = c1;


  // Segunda lista
  struct Caixa * c8 = malloc(sizeof(struct Caixa));
  c8->valor = -3; c8->prox = NULL;
  
  struct Caixa * c7 = malloc(sizeof(struct Caixa));
  c7->valor = -4; c7->prox = c8;

  struct Caixa * c6 = malloc(sizeof(struct Caixa));
  c6->valor = -5; c6->prox = c7;

  struct Caixa * l2 = c6;


  struct Caixa * lista = Concatenar(l1, l2);
  Exibir(lista);


  return 0;
}

void Exibir (struct Caixa * lista) {
  struct Caixa * p = lista;

  while (p != NULL) {
    printf ("%d", p->valor);
    if (p->prox != NULL) {
      printf(" -> ");
    }
    else {
      printf(" -> NULL\n");
    }

    p = p->prox;
  }
}

void Inserir (struct Caixa ** lista, int x) {
  // Assume caixa uma lista encadeada ordenada
  // Insere o elemento x na primeira posição da lista caixa

  struct Caixa * p = *lista;
  struct Caixa * pAnt = NULL;

  while ( (p != NULL) && (p->valor < x) ) {
    pAnt = p; p = p->prox;
  }

  struct Caixa * novaCaixa = malloc(sizeof(struct Caixa));
  novaCaixa->valor = x;

  if (pAnt == NULL) {
    novaCaixa->prox = *lista; *lista = novaCaixa;
  }
  else {
    pAnt->prox = novaCaixa; novaCaixa->prox = p;
  }
}

struct Caixa * Concatenar (struct Caixa * l1, struct Caixa * l2) {
  // Concatena as listas incluindo repetições

  struct Caixa * p1 = l1;
  struct Caixa * p2 = l2;

  struct Caixa * lista = NULL;

  while (p1 != NULL) {
    Inserir(&lista, p1->valor);
    p1 = p1->prox;
  }
  while (p2 != NULL) {
    Inserir(&lista, p2->valor);
    p2 = p2->prox;
  }

  return lista;
}