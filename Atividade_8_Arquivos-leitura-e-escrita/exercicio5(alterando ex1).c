#include <stdio.h>
#include <string.h>

void escreveString(FILE* f, char* str);

int main (void)
{
	char Palavra[26];
	printf("Digite uma palavra: ");
	scanf("%25s", Palavra); // Adicionando uma camada de segurança que evita um buffer overflow por limitar o número de caracteres
	
	FILE* fW = fopen("t.txt", "wb");
  escreveString(fW, Palavra);
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