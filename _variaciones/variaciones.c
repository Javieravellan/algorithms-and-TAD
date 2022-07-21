#include <stdio.h>

#define M 12
#define CLAVE -1

// m = número de subconjuntos.
int m;
// n = número de elementos para cada subconjunto.
int n;
char cnj[M] = {'a', 'b','c', 'd', 'e', 'f','g', 'h', 'h', 'j','k', 'l'};
int c[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
//variaciones
int v[M];
// declaración de funciones
void variaciones(int p, int c[]);
void escribir(int v[]);

// func main
int main() {
    do {
        printf("\n m = "); // cargar m número de subconjuntos
        scanf("%d", &m);
        printf("\n n = "); // cargar n número de elementos de cada subconjunto. 
        scanf("%d", &n);
    } while ( m > M || n > m);
    printf("\n \tVariaciones(%d, %d)\n", m, n);
    variaciones(1,c);
    return 0;
}

void variaciones(int p, int c[]) {
    int i; // declara i
    for (i = 1; i <= m; i++) {
        if (c[i-1] == i-1) { // i no está en la variación actual
            v[p-1] = i-1;   // p-1 debido al índice base 0
            if (p < n) {
                c[i-1] = CLAVE;
                variaciones(p+1, c);
                // vuelta atrás... si no encuentra solución, repone el índice
                c[i-1] = i-1;
            } else {
                escribir(v);
                v[p-1] = 0;
            }
        }
    }
}

void escribir(int v[]) {
    int k; 
    printf(" (");
    for (k = 1; k <= n; k++) {
        printf("%c", cnj[v[k-1]]);
        printf("%c", (k < n ? ',' : ')'));
    }
}