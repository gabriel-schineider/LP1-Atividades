// # Pergunta:
// ## Qual é a relação entre o tamanho do nome de uma Pessoa e o tamanho final do arquivo gravado?

// # Resposta
// ## Nesse exercício 7, independente do tamanho do nome da pesssoa, o tamanho escrito no arquivo contará com todos os bytes do array nome. Realizando esse exercício 8 que altera as funções de escrita e leitura, o tamanho do array nome escrito no arquivo será apenas o que realmente for preenchido no array e não todos os bytes disponíveis nele.


#include <stdio.h>
#include "exercicio7.c"

void EscrevePessoa (struct Pessoa * pessoa)
{
  FILE* f = fopen("pessoas.bin", "wb");

  fwrite(&pessoa->idade, sizeof(int), 1, f); // Escrevendo a idade no arquivo
  fwrite(pessoa->nome, strlen(pessoa->nome) + 1, 1, f); // Escrevendo o nome da pessoa até aonde foi preenchido mais o terminador nulo
  fwrite(&pessoa->peso, sizeof(int), 1, f); // Escrevendo o peso no arquivo

  fclose(f);
}

void LePessoa (struct Pessoa * pessoa)
{
  FILE* f = fopen("pessoas.bin", "rb");

  fread(&pessoa->idade, sizeof(int), 1, f); // Lendo a idade do arquivo e atribuindo-a para a variável em questão

  int i = 0; char tmp;
  while ( (fread(&tmp, sizeof(char), 1, f) == 1) && (tmp != '\0') )
  {
    pessoa->nome[i++] = tmp;
  }
  pessoa->nome[i++] = '\0'; // No caso, nesse momento, tmp == '\0', mas preferi deixar essa atribuição explícita


  fread(&pessoa->peso, sizeof(int), 1, f); // Lendo o peso do arquivo e atribuindo-o para a variável em questão
}