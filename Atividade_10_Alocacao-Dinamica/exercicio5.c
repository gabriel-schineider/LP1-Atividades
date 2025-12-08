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
struct Caixa * Remover (struct Caixa * caixa, int x);

int main (void) {

  struct Caixa * c5 = malloc(sizeof(struct Caixa)); c5->valor = 5; c5->prox = NULL;
  struct Caixa * c4 = malloc(sizeof(struct Caixa)); c4->valor = 7; c4->prox = c5;
  struct Caixa * c3 = malloc(sizeof(struct Caixa)); c3->valor = 9; c3->prox = c4;
  struct Caixa * c2 = malloc(sizeof(struct Caixa)); c2->valor = 3; c2->prox = c3;
  struct Caixa * c1 = malloc(sizeof(struct Caixa)); c1->valor = 1; c1->prox = c2;
  struct Caixa * cabeca = c1;

  Exibir(cabeca);

  Contem(cabeca, 9);

  puts("");

  cabeca = Remover(cabeca, 9);

  puts("");

  Contem(cabeca, 9);

  Exibir(cabeca);

  return 0;
}



// Funções completas

void Exibir (struct Caixa * caixa) {
  // Assume caixa uma lista encadeada
  // Exibe uma lista encadeada

  for (struct Caixa * p = caixa; p != NULL; p=p->prox) {
    printf("%d", p->valor);
    if (p->prox != NULL) printf(" -> ");
    else printf(" -> NULL\n");
  }
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

struct Caixa * Remover (struct Caixa * lista, int valor) {
  // Assume lista uma lista encadeada não ordenada
  // Remove todas as ocorrências do valor na lista

  int r = contem(lista, valor);
  if(!r) {
    printf("O valor %d não encontra-se na lista passada.\n", valor);
    return lista;
  }

  struct Caixa * p, * pAnt;
  p = lista; pAnt = NULL;

  while (p != NULL) {
    if (p->valor == valor) {
      if (pAnt == NULL) { // primeira caixa a ser removida
        lista = p->prox; free(p); p = lista;
      }
      else {
        pAnt->prox = p->prox; free(p); p = pAnt->prox;
      }
    }

    pAnt = p; p = p->prox;
  }

  printf("Remoção do elemento %d realizada com sucesso!\n", valor);
  return lista;
}