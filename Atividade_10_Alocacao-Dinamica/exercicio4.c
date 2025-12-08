#include <stdlib.h>
#include <stdio.h>

// Estruturas
struct Caixa {
    int valor;
    struct Caixa* prox;
};

// Assinaturas das funções
void Exibir (struct Caixa * caixa);
int contem (struct Caixa * lista, int valor);
void Contem (struct Caixa * lista, int valor);
void Remover (struct Caixa ** caixa, int x);
void Inserir (struct Caixa ** caixa, int x);

int main (void) {

  struct Caixa * c5 = malloc(sizeof(struct Caixa)); c5->valor = 5; c5->prox = NULL;
  struct Caixa * c4 = malloc(sizeof(struct Caixa)); c4->valor = 7; c4->prox = c5;
  struct Caixa * c3 = malloc(sizeof(struct Caixa)); c3->valor = 9; c3->prox = c4;
  struct Caixa * c2 = malloc(sizeof(struct Caixa)); c2->valor = 3; c2->prox = c3;
  struct Caixa * c1 = malloc(sizeof(struct Caixa)); c1->valor = 1; c1->prox = c2;
  struct Caixa * c0 = c1;

  Exibir(c0);

  Contem(c0, 9);

  Remover(&c0, 9);

  Contem(c0, 9);

  Exibir(c0);

  Inserir(&c0,9);

  Contem(c0, 9);

  Exibir(c0);

  return 0;
}



// Funções completas

void Exibir (struct Caixa * caixa) {
  // Assume caixa uma lista encadeada
  // Exibe uma lista encadeada

  for (struct Caixa * p = caixa; p != NULL; p = p->prox) {
    printf("%d", p->valor);
    if (p->prox != NULL) printf(" -> ");
    else printf(" -> NULL\n");
  }
}

void Remover (struct Caixa ** caixa, int x) {
  // Assume caixa uma lista encadeada não ordenada
  // Remove todas as ocorrencias de x na lista caixa

  int r = contem(*caixa, x);
  if (!r) {
    printf("O elemento %d não encontra-se na lista passada.\n", x);
    return;
  }

  struct Caixa * p, * pAnt;
  p = *caixa; pAnt = NULL;

  while (p != NULL) {
    if (p->valor == x) {
      if (pAnt == NULL) {
        *caixa = p->prox; free(p); p = *caixa;
      }
      else {
        pAnt->prox = p->prox; free(p); p = pAnt->prox;
      }
    }
    pAnt = p; p = p->prox;
  }

  printf("Remoção do elemento %d realizada com sucesso!\n", x);
}

void Inserir (struct Caixa ** caixa, int x) {
  // Assume caixa uma lista encadeada não ordenada
  // Insere o elemento x na primeira posição da lista caixa

  struct Caixa * novaCaixa = malloc(sizeof(struct Caixa));
  novaCaixa->valor = x; novaCaixa->prox = * caixa;
  *caixa = novaCaixa;

  printf("Inserção do elemento %d realizada com sucesso!\n", x);
}

int contem (struct Caixa * lista, int valor) {
  if (lista == NULL) return 0;
  else {
    if (lista->valor == valor) return 1;
    else return contem(lista->prox, valor);
  }
}

void Contem (struct Caixa * lista, int valor) {
  int r = contem(lista, valor);
  printf("O elemento %d está na lista passada? %d\n", valor, r);
}