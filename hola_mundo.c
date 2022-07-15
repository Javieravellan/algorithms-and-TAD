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
    }
}

// function Main
int main() 
{
    double a[] = {5, 2, 1, 4};
    mergesort(a, 0, sizeof(a)/sizeof(a[0]));
    printf("Indice %f", a[0]);

    return 0;
}

