#include <stdio.h>
#include <string.h>

void escreveString(FILE* f, char* str);


int main (void)
{
  char strings[10][26];

	for (int i = 0; i < 10; i++)
	{
		printf("Digite a %dª palavra: ", i+1);
		scanf("%25s", strings[i]);
  }

	FILE *fW = fopen("arq.txt", "wb");

  for (int i = 0; i < 10; i++)
	{
		escreveString(fW, strings[i]);
    fputc('\n', fW);
  }
  fclose(fW);

	
	return 0;
}


void escreveString(FILE* f, char* str)
{
  int i = 0;
  while ( (i < 25) && (str[i] != '\0') )
  {
    fputc(str[i], f);
    i++;
  }
}