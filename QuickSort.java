import java.util.Arrays;
import java.util.Scanner;

public class QuickSort {
    
    // Função para particionar o array
    private static int partition(int[] array, int low, int high) {
        int pivot = array[high]; // Pivô
        int i = (low - 1); // Índice do menor elemento

        for (int j = low; j < high; j++) {
            // Se o elemento atual é menor ou igual ao pivô
            if (array[j] <= pivot) {
                i++;
                // Troca array[i] e array[j]
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        // Troca array[i + 1] e array[high] (ou pivô)
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        return i + 1;
    }

    // Função principal do Quick Sort
    private static void quickSort(int[] array, int low, int high) {
        if (low < high) {
            // Índice de particionamento
            int pi = partition(array, low, high);

            // Ordena as partes separadamente
            quickSort(array, low, pi - 1);
            quickSort(array, pi + 1, high);
        }
    }

    // Função de wrapper para facilitar a chamada
    public static void quickSortWrapper(int[] array) {
        quickSort(array, 0, array.length - 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Informe o tamanho do array: ");
        int n = scanner.nextInt(); // Lê o tamanho do array
        int[] array = new int[n];

        // Lê os elementos do array
        System.out.println("Informe os elementos do array:");
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        System.out.println("Array original: " + Arrays.toString(array));

        quickSortWrapper(array);

        System.out.println("Array ordenado: " + Arrays.toString(array));
        
        scanner.close(); // Fecha o scanner
    }
}
