#include <stdio.h>

int tamanho (FILE* f);

int main (void)
{
  // Usando o arquivo do exercício passado como exemplo.
  
  FILE* f = fopen("a.txt", "r");
  printf("%d\n", tamanho(f));

  return 0;
}


int tamanho (FILE * f)
{
  int c = 0; char tmp;
  while (fgetc(f) != EOF)
  {
    c++;
  }
  return c;
}