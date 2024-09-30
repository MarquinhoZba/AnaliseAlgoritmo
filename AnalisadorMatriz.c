#include <stdio.h>
#include <time.h>

/*
  Desenvolvendo um analisador para analisar a matriz
*/

void multiplicarMatrizes(int n){
    int A[n][n], B[n][n], C[n][n];
    int i, j, k;

    // Inicializando as matrizes com valores arbitrários
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            A[i][j] = i + j;
            B[i][j] = i - j;
            C[i][j] = 0;
        }
    }

    // Medida empírica: Começar a contagem de tempo
    clock_t start = clock();

    // Multiplicação das matrizes (Complexidade O(n³))
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            for(k = 0; k < n; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Medida empírica: Parar a contagem de tempo
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    // Exibindo tempo de execução
    printf("Tempo gasto: %f segundos\n", time_spent);

    // Análise de complexidade assintótica
    printf("Complexidade do algoritmo: O(n^3)\n");

    // Analisando os casos
    printf("Melhor caso: O(n^3)\n");
    printf("Pior caso: O(n^3)\n");
    printf("Caso medio: O(n^3)\n\n");
}

// Função principal para testar o algoritmo
int main(){
    int n;

    printf("\n\nInforme o tamanho da matriz: ");
    scanf("%d", &n);

    multiplicarMatrizes(n);

    return 0;
}
