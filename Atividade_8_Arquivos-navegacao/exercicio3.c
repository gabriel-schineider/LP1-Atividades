#include <stdio.h>


int tamanho (FILE * f);

int main (void)
{
  // Usando o arquivo do exercício 1 como exemplo

  FILE* f = fopen("a.txt", "r+");
  int meio = tamanho(f) / 2;

  fseek(f, meio, SEEK_SET);

  fwrite("|meio|", sizeof(char), 6, f);

  return 0;
}

int tamanho (FILE * f)
{
  fseek(f, 0, SEEK_END);
  int tamanho = (int) ftell(f);
  return tamanho;
}