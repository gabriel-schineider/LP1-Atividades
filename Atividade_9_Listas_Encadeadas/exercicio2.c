# include <stdio.h>

typedef struct Caixa
{
  int valor;
  struct Caixa* prox;
} Caixa;


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


int main (void)
{
	Caixa c1, c2, c3, c4, c5;
	c1.valor = 1; c1.prox = &c2;
	c2.valor = 3; c2.prox = &c3;
	c3.valor = 9; c3.prox = &c4;
	c4.valor = 7; c4.prox = &c5;
	c5.valor = 5; c5.prox = NULL;

	exibeEncadeada(&c1);
	
	return 0;
}
