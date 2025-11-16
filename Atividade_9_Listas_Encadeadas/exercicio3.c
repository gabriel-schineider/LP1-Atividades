# include <stdio.h>

// Estrutura do Nó

typedef struct Caixa
{
	int valor;
	struct Caixa* prox;
} Caixa;


// Assinatura das funções

void exibeEncadeada (Caixa * c0);



int main (void)
{
	Caixa c1, c2, c3, c4, c5;
	c1.valor = 1; c1.prox = &c2;
	c2.valor = 3; c2.prox = &c3;
	c3.valor = 9; c3.prox = &c4;
	c4.valor = 7; c4.prox = &c5;
	c5.valor = 5; c5.prox = NULL;
	
	printf("%d -> %d -> %d -> %d -> %d\n", c1.valor,
																				 c1.prox->valor,
																				 c1.prox->prox->valor,
																				 c1.prox->prox->prox->valor,
																				 c1.prox->prox->prox->prox->valor);


	puts("");


	// Criando um nó cabeça
	Caixa * cabeca = &c1;
	
	// "Removendo" a caixa c2 da lista
	cabeca->prox = &c3; // c1 aponta para c3
	c2.prox = NULL; // c2 não aponta para ninguém, assim como, mais ninguém aponta para c2
	
	
	// Exibindo a lista sem a caixa c2
		printf("Lista sem c2: "); exibeEncadeada(cabeca);
	
	
	puts("");
	
	
	// Adicionando a caixa c2 no início da lista;
	c2.prox = &c1;
	cabeca = &c2;
	
	// Exibindo a lista com a caixa c2 reinserida na primeira posicao apontada pelo nó cabeça
	printf("Lista com c2 no início: "); exibeEncadeada(cabeca);
	

	return 0;
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
