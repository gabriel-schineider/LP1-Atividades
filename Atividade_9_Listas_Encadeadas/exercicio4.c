# include <stdio.h>

// Estrutura do Nó

typedef struct Caixa
{
  int valor;
  struct Caixa* prox;
} Caixa;


// Assinatura das funções
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

  printf("A lista encadeada contém o elemento 9? %d\n", contem(c0, 9) );
  printf("A lista encadeada contém o elemento 0? %d\n", contem(c0, 0) );


  Caixa * listaNula = NULL;
  printf("A lista encadeada contém o elemento -1000? %d\n", contem(listaNula, -1000) ); // Qualquer elemento aqui retornaria 0

  return 0;
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