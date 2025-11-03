#include <stdio.h>

// Estruturas
struct Pessoa {
  int idade;
  char nome[64];
  int peso;
};

// Assinatura das funções
void preenchePessoa(struct Pessoa *p);
void escrevePessoa(struct Pessoa *p, FILE *f);
void lePessoa(struct Pessoa *p, FILE *f);
void exibePessoa(struct Pessoa * p);


int main (void)
{
  struct Pessoa pessoas[10];
  for (int i = 0; i < 10; i++)
  {
    printf("Preencha as informações da %dª pessoa\n", i+1);
    preenchePessoa(&pessoas[i]);
    puts(" ");
  }
  
  FILE *f = fopen("pessoas.bin", "wb"); 
  for (int i = 0; i < 10; i++)
  {
    escrevePessoa(&pessoas[i], f);
  }
  fclose(f);

  f = fopen("pessoas.bin", "rb"); // f já foi declarada antes como um ponteiro para arquivo, então agora basta apenas atibuir um novo valor à ela
  struct Pessoa pessoasLidas[10];
  for (int i = 0; i < 10; i++)
  {
    lePessoa(&pessoasLidas[i], f);
  }
  fclose(f);

  for (int i = 0; i < 10; i++)
  {
    printf("Informações da %dª pessoa\n", i+1);
    exibePessoa(&pessoasLidas[i]);
    puts(" ");
  }

  return 0;
}

// Funções completas

void preenchePessoa(struct Pessoa *p)
{
  printf("Digite a idade da pessoa: ");
  scanf("%d", &p->idade);

  printf("Digite o nome da pessoa: ");
  scanf("%63s", p->nome);

  printf("Digite o peso da pessoa: ");
  scanf("%d", &p->peso);
}

void escrevePessoa(struct Pessoa *p, FILE *f)
{
  fwrite(p, sizeof(struct Pessoa), 1, f); // Leia 1 bloco de 72 bytes que escontra-se a partir do local na memória apontado pela variável p e escreva-o para o arquivo binário f
}

void lePessoa(struct Pessoa *p, FILE *f)
{
  fread(p, sizeof(struct Pessoa), 1, f); // Leia 1 bloco de 72 bytes que escontra-se no arquivo binário f (aonde quer que esteja o cursor do arquivo no momento) e escreva-o para o local na memória apontado pela variável p
}

void exibePessoa(struct Pessoa *p)
{
  printf("Idade: %d\n", p->idade);
  printf("Nome: %s\n", p->nome);
  printf("Peso: %d\n", p->peso);
}