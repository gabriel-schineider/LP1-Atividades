#include <stdio.h>
#include <string.h>

int main (void)
{
	char strings[10][26]; // array de 10 elementos onde cada elemento é um array de 26 elementos do tipo char. Ou seja, 10 strings de até 25 caracteres + 1 terminador nulo
	

	for (int i = 0; i < 10; i++)
	{
		printf("Digite a %dª palavra: ", i+1);
		scanf("%25s", strings[i]); // scanf adiciona automaticamente o '\0'
		// strings[i], nesse caso, é um ponteiro para um array de 26 chars "char (*)[26]" o que é exatamente o que queremos, pois pretendemos reservar 26 espaços na memória para cada palavra
	}

	FILE *fW = fopen("arq.txt", "wb");

	for (int i = 0; i < 10; i++)
	{
		int j = 0;
		while ( (strings[i][j] != '\0') && (j < 26))
		{
			fputc(strings[i][j], fW);
			j++;
		}
		fputc('\n', fW);
	}
	fclose(fW);


	return 0;
}

// char *p = &strings[0][0]; // Criaria um ponteiro para o primeiro elemento do banco de palavras de modo que seja possível percorrer a memória de forma estritamente linear.

// strings[i], também percorre a memória de forma "linear" mas a diferença é que "pula" o total de elementos de cada "sub-array" para ir ao próximo "array"