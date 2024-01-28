#include <stdio.h>

// declarar funciones
void selectionSort(int a[], int size);
void escribirArray(int a[], int size);

int main() {
    // Declarar array de enteros desordenados.
    int array[] = {10, 25, 12, 8, 30, 21};
    int lengthArray = sizeof(array)/sizeof(array[0]);
    selectionSort(array, lengthArray);

    // mostrar array
    escribirArray(array, lengthArray);
    return 0;
}

void selectionSort(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // obtener el indice mìnimo
        int minimo = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[minimo]) {
                minimo = j;
            }
        }
        // intercambiar elementos
        int aux = a[i];
        a[i] = a[minimo];
        a[minimo] = aux;
    }
}

void escribirArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}