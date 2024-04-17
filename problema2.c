#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 9

int hashTable[TABLE_SIZE];

int h1(int k) {
    return k % 9;
}

int h2(int k) {
    return k % 6;
}

void insert(int key) {
    int index = h1(key);
    int step = h2(key);
    int i = 0;
    while (hashTable[(index + i * step) % TABLE_SIZE] != 0 && i < TABLE_SIZE) {
        i++;
    }
    if (i < TABLE_SIZE) {
        hashTable[(index + i * step) % TABLE_SIZE] = key;
    } else {
        printf("Tabla Hash llena.\n");
    }
}

bool search(int key) {
    int index = h1(key);
    int step = h2(key);
    int i = 0;
    while (hashTable[(index + i * step) % TABLE_SIZE] != key && hashTable[(index + i * step) % TABLE_SIZE] != 0 && i < TABLE_SIZE) {
        i++;
    }
    return (hashTable[(index + i * step) % TABLE_SIZE] == key);
}

void delete(int key){
    int index = h1(key);
    int step = h2(key);
    int i = 0;
    while (hashTable[(index + i * step) % TABLE_SIZE] != key && hashTable[(index + i * step) % TABLE_SIZE] != 0 && i < TABLE_SIZE) {
        i++;
    }
    hashTable[(index + i * step) % TABLE_SIZE] = 0;
}

void printHashTable() {
    printf("Tabla Hash: ");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d ", hashTable[i]);
    }
    printf("\n");
}

int main() {
    int choice, key;
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = 0;
    }
    insert(4);
    insert(17);
    insert(30);
    insert(55);
    insert(90);
    insert(11);
    insert(56);
    insert(77);
    do {
        printHashTable();
        printf("1: Insertar un dato\n2: Buscar un dato\n3: Eliminar un dato\n0: Salir\n");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Saliendo...");
                break;
            case 1:
                printf("Ingrese el dato a insertar:\n");
                scanf("%d", &key);
                insert(key);
                printHashTable();
                break;
            case 2:
                printf("Ingrese el dato a buscar:\n");
                scanf("%d", &key);
                if (search(key)) {
                    printf("Dato %d encontrado.\n", key);
                } else {
                    printf("Dato %d no encontrado.\n", key);
                }
                break;
            case 3:
                printf("Ingrese el dato a eliminar:\n");
                scanf("%d", &key);
                delete(key);
                printf("Dato eliminado\n");
                break;
            default:
                printf("Opcion invalida.\n");
                break;
        }
    } while (choice != 0);


    return 0;
}