#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enunciado: Dados el siguiente conjunto de números W = {11,13,24,7}, encontrar todos los
// subconjuntos de W que sumen 31


#define N 4
#define MAX_SOLUCIONES 100

int Numeros[N] = {11, 13, 24, 7};
int soluciones[MAX_SOLUCIONES][N];
int total_soluciones = 0;



void imprimirVector(int solucion[N]) {

    printf("[");
    for (int i = 0; i < N; i++) {
        if (solucion[i] == -1)
            printf("-1");
        else
            printf("%d", solucion[i]);

        if (i < N - 1)
            printf(", ");
    }
    printf("]\n");
}




int alcanzable(int solucion[N], int etapa) {

    int suma = 0;

   for (int i = 0; i <= etapa; i++) {
        if (solucion[i] == 1)
            suma += Numeros[i];
    }
    return suma <= 31;
}




int esSolucion(int solucion[N], int etapa) {

    if (etapa != N - 1)
        return 0;

    int suma = 0;

    for (int i = 0; i <= etapa; i++) {
        if (solucion[i] == 1)
            suma += Numeros[i];
    }

    return suma == 31;
}



void guardarSolucion(int solucion[N]) {


    for (int i = 0; i < N; i++) {
        soluciones[total_soluciones][i] = solucion[i];
    }
    total_soluciones++;
}




void NumerosRec(int solucion[N], int etapa) {


    if (etapa > N - 1)
        return;

    for (int valor_actual = 0; valor_actual <= 1; valor_actual++) {
        solucion[etapa] = valor_actual;

        imprimirVector(solucion);

        if (alcanzable(solucion, etapa)) {
            if (esSolucion(solucion, etapa)) {
                guardarSolucion(solucion);
            }

            NumerosRec(solucion, etapa + 1);
        }
    }

    solucion[etapa] = -1;
}




int main() {


    int solucion[N];

    for (int i = 0; i < N; i++)
        solucion[i] = -1;

    printf("Explorando todas las combinaciones:\n\n");

    NumerosRec(solucion, 0);

    printf("\nSubconjuntos cuya suma es 31:\n\n");



    for (int i = 0; i < total_soluciones; i++) {
        printf("{ ");
        for (int j = 0; j < N; j++) {
            if (soluciones[i][j] == 1)
                printf("%d ", Numeros[j]);
        }
        printf("}\n");
    }

    return 0;
}

