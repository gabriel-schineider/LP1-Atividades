# include <stdio.h>

// Estrutura do Nó

typedef struct Caixa
{
  int valor;
  struct Caixa* prox;
} Caixa;


// Assinatura das funções
struct Caixa * Remove (Caixa * lista, int valor);
void exibeEncadeada (Caixa * c0);
void Remove2 (Caixa ** lista, int valor);


int main (void)
{
  Caixa * c0;
	Caixa c1, c2, c3, c4, c5;

  c0 = &c1;
  c1.valor = 1; c1.prox = &c2;
	c2.valor = 3; c2.prox = &c3;
	c3.valor = 9; c3.prox = &c4;
	c4.valor = 7; c4.prox = &c5;
	c5.valor = 5; c5.prox = NULL;

  // Testando com uma caixa do meio da lista
  exibeEncadeada(c0);
  Remove(c0, 9);

  // Testando com a última caixa
  exibeEncadeada(c0);
  Remove(c0, 5);

  // Testando com a primeira caixa
  exibeEncadeada(c0); 
  c0 = Remove(c0, 1);


  exibeEncadeada(c0);


  // Testando com uma lista vazia
  Caixa * listaNula = NULL;
  Remove(listaNula, 4);
  exibeEncadeada(listaNula);



  // NOVOS TESTES, AGORA USANDO A FUNÇÃO REMOVE2

  c0 = &c1;
  c1.valor = 10; c1.prox = &c2;
	c2.valor = 30; c2.prox = &c3;
	c3.valor = 90; c3.prox = &c4;
	c4.valor = 70; c4.prox = &c5;
	c5.valor = 50; c5.prox = NULL;

  // Testando com uma caixa do meio da lista
  exibeEncadeada(c0);
  Remove2(&c0, 90);

  // Testando com a última caixa
  exibeEncadeada(c0);
  Remove2(&c0, 50);

  // Testando com a primeira caixa
  exibeEncadeada(c0); 
  Remove2(&c0, 10);


  exibeEncadeada(c0);


  // Testando com uma lista vazia
  listaNula = NULL;
  Remove2(&listaNula, 4);
  exibeEncadeada(listaNula);

  return 0;
}


struct Caixa * Remove (Caixa * lista, int valor)
{
  // Recebe um ponteiro para o primeiro elemento da lista encadeada
  // Remove todas as ocorrências do valor na lista

  Caixa * p, * pAnt, * tmp; 
  p = lista; pAnt = NULL;

  while (p != NULL) // Verifica a lista inteira até o final
  {
    if (p->valor == valor)
    {
      if (pAnt == NULL) // Primeiro elemento da lista a ser removido
      {
        tmp = p;
        lista = p->prox; // Agora a lista aponta para o segundo elemento
        p = lista; // O ponteiro que percorre a lista agora aponta para a nova primeira caixa da lista
        tmp->prox = NULL; // A caixa removida não aponta para mais nenhuma outra, assim como nenhuma aponta para ela
      }
      else // Elementos do meio ou do final
      {
        tmp = p;
        pAnt->prox = p->prox; // A caixa anterior à que está sendo removida aponta para a próxima à ela
        p = pAnt->prox; // o ponteiro da frente que percorre a lista aponta para a caixa que a caixa que foi removida apontava
        tmp->prox = NULL; // A caixa removida não aponta para mais nenhuma outra, assim como nenhuma aponta para ela
      }
    }
    else
    {
      pAnt = p; p = p->prox;
    }
  }

  return lista;
}

void exibeEncadeada (Caixa * c0)
{
	Caixa* p = c0;
	while (p != 0) // Usando 0 apenas para mostrar que NULL = 0
	{
		printf("%d ", p->valor);
		p = p->prox;
	}
	puts("");
}


void Remove2 (Caixa ** lista, int valor)
{
  // Recebe um ponteiro para uma lista encadeada. Ou seja, recebe um ponteiro para uma variável que, por sua vez já é um ponteiro. (Fazendo isso para não ter que atribuir à lista o resultado dessa função, mais simples...)
  // Remove todas as ocorrências do valor na lista

  Caixa * p, * pAnt, * tmp; 
  p = *lista; pAnt = NULL;

  while (p != NULL) // Verifica a lista inteira até o final
  {
    if (p->valor == valor)
    {
      if (pAnt == NULL) // Primeiro elemento da lista a ser removido
      {
        tmp = p;
        *lista = p->prox; // Agora a lista aponta para o segundo elemento
        p = *lista; // O ponteiro que percorre a lista agora aponta para a nova primeira caixa da lista
        tmp->prox = NULL; // A caixa removida não aponta para mais nenhuma outra, assim como nenhuma aponta para ela
      }
      else // Elementos do meio ou do final
      {
        tmp = p;
        pAnt->prox = p->prox; // A caixa anterior à que está sendo removida aponta para a próxima à ela
        p = pAnt->prox; // o ponteiro da frente que percorre a lista aponta para a caixa que a caixa que foi removida apontava
        tmp->prox = NULL; // A caixa removida não aponta para mais nenhuma outra, assim como nenhuma aponta para ela
      }
    }
    else
    {
      pAnt = p; p = p->prox;
    }
  }
}