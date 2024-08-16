#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMES 10
#define TAM_NOME 50

// Função para comparar dois nomes para a ordenação
int comparar_nomes(const void *a, const void *b) {
  strcmp(*(const char **)a, *(const char **)b);

  retun comparar_nomes;
}

int main() {
  char nomes[MAX_NOMES][TAM_NOME];
  char nome_busca[TAM_NOME];
  int i, encontrado = 0;

  // Geração de nomes aleatórios
  strcpy(nomes[0], "Maria");
  strcpy(nomes[1], "Joao");
  strcpy(nomes[2], "Ana");
  strcpy(nomes[3], "Pedro");
  strcpy(nomes[4], "Mariana");
  strcpy(nomes[5], "Jose");
  strcpy(nomes[6], "Carla");
  strcpy(nomes[7], "Paulo");
  strcpy(nomes[8], "Beatriz");
  strcpy(nomes[9], "Felipe");

  // Ordenação dos nomes
  qsort(nomes, MAX_NOMES, sizeof(nomes[0]), comparar_nomes);

  // Impressão dos nomes ordenados
  printf("Nomes em ordem alfabetica:\n");
  for (i = 0; i < MAX_NOMES; i++) {
    printf("%s\n", nomes[i]);
  }

  // Busca por um nome específico
  printf("\nDigite um nome para buscar: ");
  scanf("%s", nome_busca);
  for (i = 0; i < MAX_NOMES; i++) {
    if (strcmp(nomes[i], nome_busca) == 0) {
      encontrado = 1;
      break;
    }
  }

  if(encontrado){
    printf("O nome %s foi encontrado na lista. \n", nome_busca);
  }
  else{
    printf("O nome %s nao foi encontrado na lista. \n", nome_busca);
  }
}