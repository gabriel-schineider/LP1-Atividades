#include<stdio.h>
#include<string.h>

int main (void)
{
	char Palavra[26];
	FILE* fR = fopen("t.txt", "rb");
	int tmp = fgetc(fR);
	int i = 0;
	while ( (i < 25) && (tmp != EOF) )
	{
		Palavra[i] = (char)tmp;
		i++;
		tmp = fgetc(fR);
	}
	Palavra[i] = '\0'; // Adicionando o Terminador Nulo após o último caracter
	
	printf("%s\n", Palavra);
	
	return 0;
}