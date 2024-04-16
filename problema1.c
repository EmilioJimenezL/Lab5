#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int size) {
    printf("Array generado: ");
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

int compare(const void *a, const void *b) {
    return ((int)a - (int)b);
}

int main() {
    int N, choice, target, result;
    clock_t start, end;
    double cpu_time_used;

    printf("Ingrese el tamaño del arreglo N: ");
    scanf("%d", &N);
    int arr[N];
    srand(time(0));
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % N;  // números aleatorios entre 0 y N-1
    }
    printArray(arr, N);

    printf("Ingrese el número a buscar: ");
    scanf("%d", &target);
    printf("Elija el método de búsqueda:\n1. Búsqueda Secuencial\n2. Búsqueda Binaria\n");
    scanf("%d", &choice);

    start = clock();  // Inicio del cronómetro

    switch (choice) {
        case 1:
            result = sequentialSearch(arr, N, target);
            break;
        case 2:
            qsort(arr, N, sizeof(int), compare);
            printArray(arr, N);  // imprimir el arreglo ordenado
            result = binarySearch(arr, 0, N-1, target);
            break;
        default:
            printf("Opción inválida.\n");
            return 0;
    }

    end = clock();  // Fin del cronómetro
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    if (result != -1) {
        printf("Resultado: Método de búsqueda %d, número encontrado en la posición %d.\n", choice, result);
    } else {
        printf("Resultado: Método de búsqueda %d, número no encontrado.\n", choice);
    }

    printf("Tiempo de ejecución: %f segundos.\n", cpu_time_used);

    return 0;
}