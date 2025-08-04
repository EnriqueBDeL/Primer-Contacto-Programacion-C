#include "Header.h"

int calcular_tamano_incremento(int size) {
    return size / 2;
}

//-----------------------------------------------------------------------------------|

int calcular_siguiente_incremento(int size, int intervalo) {
    return intervalo / 2;
}

//-----------------------------------------------------------------------------------|

void shell(int array[], int size, int *comp, int *inc, float *tiempo) {

    int intervalo, i, j, temp;

    clock_t start_time, end_time;

    start_time = clock();

    intervalo = calcular_tamano_incremento(size);

    while (intervalo > 0) {

        for (i = intervalo; i < size; i++) {

            j = i;
            temp = array[i];

            while ((j >= intervalo) && (array[j - intervalo] > temp)) {

                array[j] = array[j - intervalo];
                j -= intervalo;
                (*inc)++;
                (*comp)++;
            }

            (*comp)++;
            array[j] = temp;
        }

        intervalo = calcular_siguiente_incremento(size, intervalo);
    }

    end_time = clock();

    *tiempo = (float)(end_time - start_time) / CLOCKS_PER_SEC;

}

void leerFichero(char *entrada, char *salida) {

    FILE *file;
    int *arr = NULL;
    int n = 0, capacidad = 10;
    int comp = 0, inc = 0;
    float tiempo = 0;

    arr = malloc(capacidad * sizeof(int));

    if (arr == NULL) {
        return;
    }

    file = fopen(entrada, "r");

    if (file == NULL) {
        free(arr);
        return;
    }

    while (fscanf(file, "%d", &arr[n]) == 1) {
        n++;

        if (n >= capacidad) {
            capacidad *= 2;
            arr = realloc(arr, capacidad * sizeof(int));

            if (arr == NULL) {
                fclose(file);
                return;
            }
        }
    }
    fclose(file);

    if (n == 0) {
        free(arr);
        return;
    }

    shell(arr, n, &comp, &inc, &tiempo);

    printf("Numero de comparaciones: %d\n", comp);
    printf("Numero de intercambios: %d\n", inc);
    printf("Tiempo de ordenacion: %f s\n", tiempo);

    file = fopen(salida, "w");
    if (file == NULL) {
        free(arr);
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
    free(arr);
}
