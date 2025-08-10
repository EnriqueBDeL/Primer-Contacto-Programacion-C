#include "Header.h"


void seleccion(int v[], int size, int *comparaciones, int *intercambios) {

    int i, j, pos, temp;

    *comparaciones = 0;

    *intercambios = 0;

    for (i = 0; i < size - 1; i++) {

        pos = i;

        for (j = i + 1; j < size; j++) {

            (*comparaciones)++;

            if (v[j] < v[pos]) {
                pos = j;
            }

        }

        if (pos != i) {

            temp = v[pos];

            v[pos] = v[i];

            v[i] = temp;

            (*intercambios)++;

        }
    }
}

//-------------------------------------------------------------------------------------|

void guardarEnArchivo(char *nombreArchivo, int v[], int size) {

    FILE *archivo = fopen(nombreArchivo, "w");


    for (int i = 0; i < size; i++) {

        fprintf(archivo, "%d\n", v[i]);
    }

    fclose(archivo);
}

//-------------------------------------------------------------------------------------|

int leerDesdeArchivo(char *nombreArchivo, int **v) {

    FILE *archivo = fopen(nombreArchivo, "r");


    int temp, size = 0;


    int maxCapacidad = 10000000;
    *v = malloc(maxCapacidad * sizeof(int));

    if (!*v) {
        printf("Error al asignar memoria.\n");
        fclose(archivo);
        return -1;
    }

    while (fscanf(archivo, "%d", &temp) == 1) {
        if (size < maxCapacidad) {
            (*v)[size++] = temp;
        } else {
            printf("Error: archivo excede el tamaño permitido.\n");
            free(*v);
            fclose(archivo);
            return -1;
        }
    }

    fclose(archivo);
    return size;
}

