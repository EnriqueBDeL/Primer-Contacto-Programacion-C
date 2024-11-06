#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
 
    int N, *A;
    int suma = 0;

    printf("\nIntroduce el numero de elementos del Array: ");
    scanf("%d", &N);

    A = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        A[i] = i;
    }

    printf("\n\nElementos del Array:\n");

    for (int i = 0; i < N; i++) {
        printf("|%d|", A[i]);
    }

    for (int i = 0; i < N; i++) {
        suma = suma + A[i];
    }

    printf("\n\nResultado de la suma: %d \n\n", suma);

    return 0;
}
