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
int contem (struct Caixa * lista, int valor);
int Retirar (struct Caixa ** lista, int valor);


int main (void) {

  struct Caixa * lista = NULL;

  puts("Adicione valores na lista ou digite '-1' para sair: ");
  int x;
  scanf(" %d", &x);
  while (x != -1) {
    Inserir(&lista, x);
    scanf(" %d", &x);
  }

  puts("Lista:");
  Exibir(lista);

  puts("");

  int k; printf("Escolha um valor para retirar da lista em tê-lo em mãos: "); scanf(" %d", &k);
  int y = Retirar(&lista, k);

  puts("");

  if (y == -1) {
    printf("Esse valor não encontra-se na lista. Portanto, o valor que agora tens em mãos é -1.");
  }
  else {
    printf("O valor %d foi retirado da lista e está em suas mãos!\n", y);
  }

  puts("");

  puts("Nova Lista:");
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

int contem (struct Caixa * lista, int valor) {
  if (lista == NULL) return 0;
  else {
    if (lista->valor == valor) return 1;
    else return contem(lista->prox, valor);
  }
}

void Remover (struct Caixa ** lista, int x) {
  // Assume caixa uma lista encadeada não ordenada
  // Remove a primeira ocorrência de x na lista

    struct Caixa * p = *lista;
    struct Caixa * pAnt = NULL;

    while (p != NULL) {
      if (p->valor == x) {
        if (pAnt == NULL) {
          *lista = p->prox; free(p); p = *lista;
        }
        else {
          pAnt->prox = p->prox; free(p); p = pAnt->prox;
        }

        return;
      }

      pAnt = p; p = p->prox;
    }
}

int Retirar (struct Caixa ** lista, int valor) {
  // Assume lista uma lista encadeada
  // Se o valor estiver contido na lista, remove a primeira ocorrência do valor na lista e retorna esse valor ou -1 caso contrário

  if (contem(*lista, valor)) {
    Remover(lista, valor);
    return valor;
  }
  else return -1;
}