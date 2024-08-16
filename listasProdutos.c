#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

Desenvolver um algoritmo de busca e ordenação :
 - Lista de produtos
 - Nome
 - ID

*/
typedef struct produto {
  char nome[50];
  int id;
  float preco;
} PRODUTO;

void imprime(PRODUTO *p) {
  printf("\n\nNome do produto: %s\n", p->nome);
  printf("id do produto: %d\n", p->id);
  printf("preco do produto: %.2f", p->preco);
}

void imprime_vetor(PRODUTO *p, int n) {
  int i;
  for (i = 0; i < n; i++) {
    imprime(&p[i]);
  }
}

void ordena_por_nome(PRODUTO *p, int n) {
  int i, j;
  PRODUTO aux;
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (strcmp(p[i].nome, p[j].nome) > 0) {
        aux = p[i];
        p[i] = p[j];
        p[j] = aux;
      }
    }
  }
}

int busca_binaria(PRODUTO *p, int n, int id) {
  int ini = 0;
  int fim = n - 1;
  int meio;

  while (ini <= fim) {
    meio = (ini + fim) / 2;
    if (p[meio].id == id) {
      return meio;
    } else if (p[meio].id < id) {
      ini = meio + 1;
    } else {
      fim = meio - 1;
    }
  }
  return -1;
}

// Função para inserir um novo produto no vetor
void insere_produto(PRODUTO *p, int *n) {
  printf("\n\nDigite o id do produto: ");
  scanf("%d", &p[*n].id);

  printf("Digite o nome do produto: ");
  scanf("%s", p[*n].nome);

  printf("Digite o preco do produto: ");
  scanf("%f", &p[*n].preco);

  (*n)++;
}

// Função para remover um produto do vetor
void remove_produto(PRODUTO *p, int *n, int id) {
  int i, j;
  for (i = 0; i < *n; i++) {
    if (p[i].id == id) {
      for (j = i; j < *n - 1; j++) {
        p[j] = p[j + 1];
      }
      (*n)--;
      printf("Produto removido com sucesso!\n");
      return;
    }
  }
  printf("Produto não encontrado.\n");
}

int main(void) {
  PRODUTO p[10];
  int n = 0;
  int opcao;

  do {
    printf("\n\nMenu:\n");
    printf("1 - Inserir produto\n");
    printf("2 - Remover produto\n");
    printf("3 - Buscar produto\n");
    printf("4 - Ordenar produtos\n");
    printf("5 - Imprimir produtos\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      insere_produto(p, &n);
      break;
    case 2: {
      char nome;
      printf("\nDigite o nome do produto a ser removido: ");
      scanf("%s", &nome);
      ordena_por_nome(p, n);
      remove_produto(p, &n, nome);
      break;
    }
    case 3: {
      char nome;
      printf("\nDigite o nome do produto a ser buscado: ");
      scanf("%s", &nome);
      ordena_por_nome(p, n);
      int posicao = busca_binaria(p, n, nome);
      if (posicao != -1) {
        printf("\n\nProduto encontrado na posicao %d: \n", posicao);
        imprime(&p[posicao]);
      } else {
        printf("\n\nProduto nao encontrado!");
      }
      break;
    }
    case 4:
      ordena_por_nome(p, n);
      printf("\nProdutos ordenados com sucesso!\n");
      break;
    case 5:
      imprime_vetor(p, n);
      break;
    case 0:
      printf("\nSaindo do programa...\n");
      break;
    default:
      printf("\nOpcao invalida!");
    }

  } while (opcao != 0);
  return 0;
}
