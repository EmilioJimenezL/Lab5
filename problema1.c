#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    int temp;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sequentialSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int N, choice, target, result;
    clock_t start, end;
    double cpu_time_used;

    printf("Ingrese el largo del arreglo N:\n");
    scanf("%d", &N);
    int arr[N];
    srand(time(0));
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % N;  // números aleatorios entre 0 y N-1
    }
    quickSort(arr, 0, N-1);
    printArray(arr, N);

    do {
        printf("Ingrese el numero a buscar:\n");
        scanf("%d", &target);
        printf("Elija el metodo de busqueda:\n1. Busqueda Secuencial\n2. Busqueda Binaria\n0. Salir\n");
        scanf("%d", &choice);
        if(choice != 0) {
            start = clock();  // Inicio del cronómetro

            switch (choice) {
                case 1:
                    result = sequentialSearch(arr, N, target);
                    break;
                case 2:
                    result = binarySearch(arr, 0, N - 1, target);
                    break;
                default:
                    printf("Opcion invalida.\n");
                    return 0;
            }

            end = clock();  // Fin del cronómetro
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

            if (result != -1) {
                printf("Resultado: Metodo de busqueda %d, numero encontrado en la posicion %d.\n", choice, result);
            } else {
                printf("Resultado: Metodo de busqueda %d, numero no encontrado.\n", choice);
            }

            printf("Tiempo de ejecucion: %f segundos.\n", cpu_time_used);
        }
    } while (choice != 0);

    return 0;
}