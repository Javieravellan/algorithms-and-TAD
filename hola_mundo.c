#include <stdio.h>

#define M 4
void mezcla(double a[], int izq, int medio, int dere);
void mergesort(double a[], int primero, int ultimo)
{
    int central;
    if (primero < ultimo) {
        central = (primero + ultimo) / 2;
        mergesort(a, primero, central);
        mergesort(a, central+1, ultimo);
        mezcla(a, primero, central, ultimo);
    }
}

void mezcla(double a[], int izq, int medio, int dere)
{
    double tmp[M];
    int x, y, z;
    x = z = izq;
    y = medio++;

    // bucle de mezcla usa tmp[] como auxiliar. Z es el indice de tmpA[]
    while (x<=medio && y<=dere) {
        if (a[x]<=a[y]) {
            tmp[z++] = a[x++];
        } else
            tmp[z++] = a[y++];
    }

    // bucles para mover elementos que quedan de sublistas
    while(x<=medio)
        tmp[z++] = a[x++];
    
    while(y<=dere)
        tmp[z++] = a[y++];

    // copia los elementos de tmp a a[]
    for (z =izq; z <= dere; z++) {
        a[z] = tmp[z];
    }
}

// function Main
int main() 
{
    double a[M] = {5, 2, 1, 4};
    mergesort(a, 0, sizeof(a)/sizeof(a[0]));
    printf("Indice %f", a[0]);

    return 0;
}

