#include <stdio.h>

// algoritmo de las 8 reinas consiste en colocar
// 8 reinas dentro del tablero de ajedrez de forma que ninguna de ellas
// pueda atacarse entre sí. Este es un ejemplo de uso de los algoritmos de
// vuelta atrás (backtracking), que emplea recursividad para solucionar
// cada problema.

#define N 8
#define n (N+1)

// colocar reina
void colocaReina(int i, int* solucion);
// verifica si el movimiento es válido
int valido(int j);
// escribe la solución del problema.
void escribirUbicacion();
// declaración de las 8 reinas
int reinas[n];

int main() 
{
    int tieneSolucion;
    colocaReina(1, &tieneSolucion);
    if (tieneSolucion)
        escribirUbicacion();
    return 0;
}

// colocar reinas en el tablero de ajedrez
void colocaReina(int i, int* solucion) 
{
    // declaramos k, que representa a la fila en la que se sitúa a la reina
    int k;
    // asignamos 0 a solucion
    *solucion = 0;
    k = 0;

    // bucle para realizar la tarea de colocar las reinas
    do 
    {
        // incrementa k en 1
        k++;
        // situamos parcialmente a la reina i en la fila k del tablero
        reinas[i] = k;
        // validamos que el movimiento sea válido
        if (valido(i)) 
        {
            if (i < N)
            {
                colocaReina(i + 1, solucion);
                if (!(*solucion))
                    reinas[i] = 0;
            } 
            else *solucion = 1;
        }
    }
    while (!(*solucion) && (k < 8));
}

int valido(int j)
{
    /*
     * Inspecciona si la reina de la columna j es atacada por alguna reina colocada
     * anteriormente.
    */

    // índice de reina colocada previamente 
    int r;
    int v; //interruptor, toma 1 si la posición es válida.
    v = 1;
    for (r = 1; r <= j - 1; r++)
    {
        // que no esté en la misma fila
        v = v && (reinas[r] != reinas[j]); 
        // que no esté en la primera diagonal
        v = v && ((reinas[j] + j) != (reinas[r] + r));
        // que no esté en la segunda diagonal
        v = v && ((reinas[j] - j) != (reinas[r] - r));
    }
    // devuelve 1 válido; 0 inválido.
    return v;
}

void escribirUbicacion() 
{
    int k;
    puts("\n Número de fila donde se coloca cada reina.\n");
    for (k = 1; k <= N; k++)
        printf("\t Reina %d en fila %d \n", k, reinas[k]);
}