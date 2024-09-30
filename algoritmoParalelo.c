#include <stdio.h>
#include <stdlib.h>

// Função para dividir o array e encontrar o pivô
int partition(int *arr, int low, int high) {
    int pivot = arr[high]; // Pivô
    int i = low - 1; // Índice menor que o pivô

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // Troca arr[i] e arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Troca o pivô para a posição correta
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

// Função recursiva do Quick Sort (divisão e conquista)
void quickSort(int *arr, int low, int high) {
    if (low < high) {
        // Encontra o índice do pivô
        int pi = partition(arr, low, high);

        // Ordena recursivamente as duas metades
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("\n\nDigite o numero de elementos do array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    // Preenche o array com valores aleatórios
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Valores entre 0 e 99
    }

    // Exibe o array original
    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Executa o Quick Sort
    quickSort(arr, 0, n - 1);

    // Exibe o array ordenado
    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
