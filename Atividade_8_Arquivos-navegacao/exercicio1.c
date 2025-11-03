#include <stdio.h>
#include <string.h>

void leInfo (void);

int main (void)
{

  leInfo();

  return 0;
}

void leInfo (void)
{
  int linha;
  printf("Digite uma linha para obter a idade e o estado correspondentes: ");
  scanf(" %d", &linha);

  if ( (linha < 1) || (linha >= 4) )
  {
    printf("registro não encontrado.\n");
    return;
  }

  FILE* f = fopen("a.txt", "r");
  if (f == NULL)
  {
    perror("não foi possível abrir o arquivo.");
  }

  char conteudo[23]; // 21 do conteúudo +1 do "\n" +1 do '\0' do fgets
  char idade[4];
  char estado[3];

  // Posicionando o cursor no começo da linha escolhida
  fseek(f, (linha - 1) * 22, SEEK_SET);
  
  // linha - 1, pois a linha 1 no arquivo, para o usuário, é lida como linha 0 + coluna x no programa.
  // 22 é o número de "colunas" de cada linha contando com a quebra de linha "\n"

  
  fgets(conteudo, 23, f); // Copiando toda linha para um buffer que será utilizado como auxiliar

  strncpy(idade, &conteudo[9], 3); idade[3] = '\0';
  strncpy(estado, &conteudo[19], 2); estado[2] = '\0';

  printf("\nLinha %d\n Idade: %s\n Estado: %s\n", linha, idade, estado);
// printf("Conteúdo da linha: %s\n", conteudo);
}