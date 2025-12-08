#include <stdio.h>

int tamanho (FILE * f);

int main (void)
{
  // Usando o arquivo do exercício 1 como exemplo

  FILE* f = fopen("a.txt", "r+");
  int total = tamanho(f);
  int meio = total / 2;
  int resto = total - meio;

  fseek(f, meio, SEEK_SET);
  char buffer[resto]; // Construindo uma variável para armazenar tudo que está escrito do meio até o final do arquivo
  fread(buffer, sizeof(char), resto, f);
  
  fseek(f, meio, SEEK_SET);
  fwrite("|meio|", sizeof(char), 6, f);
  fwrite(buffer, sizeof(char), resto, f);

  fclose(f);

  return 0;
}

int tamanho (FILE * f)
{
  fseek(f, 0, SEEK_END);
  int tamanho = (int) ftell(f);
  return tamanho;
}