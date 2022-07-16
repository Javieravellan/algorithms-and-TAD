#include <stdio.h>

#define M 3
void mezcla(double a[], int izq, int medio, int dere);
void mergesort(double a[], int primero, int ultimo)
{
    if (primero < ultimo) {
        int central = (primero + ultimo) / 2;
        mergesort(a, primero, central);
        mergesort(a, central+1, ultimo);
        mezcla(a, primero, central, ultimo);
    }
}

void mezcla(double a[], int pri, int medio, int ult)
{
<<<<<<< HEAD
    double tmp[M];
    int x, y, z;
    x = z = pri;
    y = medio+1;

    // bucle de mezcla usa tmp[] como auxiliar. Z es el indice de tmpA[]
    while (x<=medio && y<=ult) {
        double cx = a[x]; // a[x] actual
        double cy = a[y]; // a[y] actual
        // si a[x] es menor que a[y]
        if (cx<=cy) {
            tmp[z++] = a[x++]; // ponemos a[x] (a[x] sería el menor) al principio del arreglo.
        } else
            tmp[z++] = a[y++]; // si no, ponemos a[y] (a[y] sería el menor) al principio del arreglo.
    }

    // bucle para mover elementos que quedan de la sublista izquierda.
    while(x<=medio) {
        double cx = a[x++];
        tmp[z++] = cx;
    }
    
    // bucle para mover elementos que quedan de la sublista derecha.
    while(y<=ult) {
        double cy = a[y++];
        tmp[z++] = cy;
    }

    // copia los elementos de tmp a a[]
    for (z = pri; z <= ult; z++) {
        a[z] = tmp[z];
=======
    int i, j, k;
    int n1 = medio - izq + 1;
    int n2 = dere - medio;
  
    /* create temp arrays */
    int L[n1], R[n2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = a[izq + i];
    for (j = 0; j < n2; j++)
        R[j] = a[medio + 1 + j];
  
    /* Merge the temp aays back into a[l..r]*/
    i = 0; // Initial index of first subaay
    j = 0; // Initial index of second subaay
    k = izq; // Initial index of merged subaay
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
  
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
  
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
>>>>>>> 475325e2664663ead3cd5e2fd67563357ad63d5f
    }
}

// Function Main
int main() 
{
<<<<<<< HEAD
    double a[M] = {5, 2, 1};
    mergesort(a, 0, sizeof(a)/sizeof(a[0]) - 1);
    for (int i = 0; i < M; i++)
        printf("Valor %f\n", a[i]);
=======
    double a[] = {5, 2, 1, 4};
    mergesort(a, 0, sizeof(a)/sizeof(a[0]));
    printf("Indice %f", a[0]);
>>>>>>> 475325e2664663ead3cd5e2fd67563357ad63d5f

    return 0;
}

