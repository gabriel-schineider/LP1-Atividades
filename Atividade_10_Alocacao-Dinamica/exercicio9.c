#include <stdlib.h>
#include <stdio.h>

// Estruturas
struct Caixa {
    int valor;
    struct Caixa* prox;
};


// Assinatura das funções
void Inserir (struct Caixa ** lista, int x);
void Exibir (struct Caixa * lista);



int main (void) {

  struct Caixa * lista = NULL;

  int x;
  scanf(" %d", &x);
  while (x != -1) {
    Inserir(&lista, x);
    scanf(" %d", &x);
  }

  Exibir(lista);

  return 0;
}


// Funções completas

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

void Exibir (struct Caixa * lista) {
  for (struct Caixa * p = lista; p != NULL; p = p->prox) {
    printf("%d", p->valor);
    if (p->prox != NULL) printf(" -> ");
    else printf (" -> NULL\n");
  }
}