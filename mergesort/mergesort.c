#include <stdio.h>

#define M 7
void mezcla(int a[], int izq, int medio, int dere);
void mergesort(int a[], int primero, int ultimo)
{
    if (primero < ultimo) {
        int central = (primero + ultimo) / 2;
        mergesort(a, primero, central);
        mergesort(a, central+1, ultimo);
        mezcla(a, primero, central, ultimo);
    }
}

void mezcla(int a[], int pri, int medio, int ult)
{
    int tmp[M];
    int x, y, z;
    x = z = pri;
    y = medio+1;

    // bucle de mezcla usa tmp[] como auxiliar. Z es el indice de tmpA[]
    while (x<=medio && y<=ult) {
        int cx = a[x]; // a[x] actual
        int cy = a[y]; // a[y] actual
        // si a[x] es menor que a[y]
        if (cx<=cy) {
            tmp[z++] = a[x++]; // ponemos a[x] (a[x] sería el menor) al principio del arreglo.
        } else
            tmp[z++] = a[y++]; // si no, ponemos a[y] (a[y] sería el menor) al principio del arreglo.
    }

    // bucle para mover elementos que quedan de la sublista izquierda.
    while(x<=medio) {
        int cx = a[x++];
        tmp[z++] = cx;
    }
    
    // bucle para mover elementos que quedan de la sublista derecha.
    while(y<=ult) {
        int cy = a[y++];
        tmp[z++] = cy;
    }

    // copia los elementos de tmp a a[]
    for (z = pri; z <= ult; z++) {
        a[z] = tmp[z];
    }
}

// Function Main
int main() 
{
    int a[M] = {5, 2, 1, 7, 5, 2, 18};
    mergesort(a, 0, sizeof(a)/sizeof(a[0]) - 1);
    for (int i = 0; i < M; i++)
        printf("%i|", a[i]);

    printf("\n");
    return 0;
}

