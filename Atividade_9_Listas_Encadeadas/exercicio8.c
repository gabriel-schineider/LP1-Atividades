# include <stdio.h>

// Estrutura do Nó

typedef struct Caixa
{
  int valor;
  struct Caixa* prox;
} Caixa;


// Assinatura das funções
struct Caixa * concatena (struct Caixa * l1, struct Caixa * l2);
void exibeEncadeada (Caixa * c0);
int contem (Caixa * lista, int valor);


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

  Caixa * c00;
	Caixa c10, c20, c30, c40, c50;

  c00 = &c10;
  c10.valor = 1; c10.prox = &c20;
	c20.valor = -30; c20.prox = &c30;
	c30.valor = 9; c30.prox = &c40;
	c40.valor = -70; c40.prox = &c50;
	c50.valor = 5; c50.prox = NULL;

  printf("Lista c0: "); exibeEncadeada(c0);

  printf("Lista c00: "); exibeEncadeada(c00);

  struct Caixa * c000 = NULL;
  c000 = concatena(c0, c00);

  printf("Lista c0+c00: "); exibeEncadeada(c000);

  return 0;
}




// Funções completas
struct Caixa * concatena (struct Caixa * l1, struct Caixa * l2)
{
  struct Caixa * l0 = l1; // Ponteiro da nova lista
  struct Caixa * p = l0; // Ponteiro que vai percorrer a lista até nulo
  struct Caixa * pAnt = NULL; // Ponteiro que vai percorrer a lista, atrás do outro de modo que, quando o outro ficar nulo, este esteja apontando para a última caixa

  while (p != NULL) // Percorrendo a lista l1
  {
    pAnt = p; p = p->prox;
  }
  
  p = l2;
  while (p != NULL) // Percorrendo a lista l2
  {
    if (! contem(l0, p->valor)) // Verificando se o elemento em questão, da lista l2, já entrou na lista l0 pela lista l1
    {
      pAnt->prox = p; // l0 recebe, na última posição, o elemento que ainda não está nessa lista
      pAnt = pAnt->prox; // O ponteiro que está em l0 avança para a última caixa dessa lista
      p = p->prox; // Avança com p para a próxima caixa da lista l2
      pAnt->prox = NULL; // Torna esse o ponteiro dessa caixa nulo, visto que é a última caixa da lista
    }
    else
    {
      p = p->prox;
    }
  }

  return l0;
}

void exibeEncadeada (Caixa * c0)
{
	Caixa* p = c0;

	while (p != NULL)
	{
		printf("%d ", p->valor);
		p = p->prox;
	}
	puts("");
}

int contem (Caixa * lista, int valor)
{
  Caixa * p = lista;

  while (p != NULL) // Verifica a lista inteira até o final
  {
    if (p->valor == valor)
    {
      return 1; // Se estiver contido
    }
    p = p->prox;
  }

  return 0; // Se não estiver contido
}