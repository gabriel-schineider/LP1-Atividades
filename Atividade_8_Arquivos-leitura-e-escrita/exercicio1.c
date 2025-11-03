#include <stdio.h>
#include <string.h>

int main (void)
{
	char Palavra[26];
	printf("Digite uma palavra: ");
	scanf("%25s", Palavra); // Limitando o número de caracteres
	
	FILE* fW = fopen("t.txt", "wb"); // Escrevendo no diretório que estiver no momento
	
	int i = 0;
	while ( (i < 26) && (Palavra[i] != '\0') )
	{
		fputc(Palavra[i], fW);
		i++;
	}

	return 0;
}