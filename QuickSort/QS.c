#include "Header.h"





int Menu(){
int opcion;
printf("\n****MENU****:");
printf("\n1. Variante 1.");
printf("\n2. Variante 2.");
printf("\n3. Variante 3.");
printf("\n\nIntroduce una opcion: ");scanf("%d",&opcion);
return opcion;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void intercambio(int a[], int i, int j, int *intercambios) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    (*intercambios)++;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void QuickSort(int a[], int ini, int fin, int *comparaciones, int *intercambios) {
    int pivote;
    int i, j;

    if (ini >= fin) return;

    if (ini + 1 == fin) {
        (*comparaciones)++;
        if (a[ini] > a[fin]) {
            intercambio(a, ini, fin, intercambios);
        }
        return;
    }

    int medio = (ini + fin) / 2;
    intercambio(a, medio, fin, intercambios);
    pivote = a[fin];

    for (i = ini, j = fin - 1;;) {
        while ((i <= fin - 1) && (a[i] < pivote)) {
            i++;
            (*comparaciones)++;
        }
        while ((j >= ini) && (pivote < a[j])) {
            j--;
            (*comparaciones)++;
        }
        if (i < j) {
            intercambio(a, i, j, intercambios);
            i++;
            j--;
        } else {
            break;
        }
    }

    intercambio(a, i, fin, intercambios);
    QuickSort(a, ini, i - 1, comparaciones, intercambios);
    QuickSort(a, i + 1, fin, comparaciones, intercambios);
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void QuickSortAleatorio(int a[], int ini, int fin, int *comparaciones, int *intercambios) {
    int pivote;
    int i, j;

    if (ini >= fin) return;

    if (ini + 1 == fin) {
        (*comparaciones)++;
        if (a[ini] > a[fin]) {
            intercambio(a, ini, fin, intercambios);
        }
        return;
    }

    int aleatorio = ini + rand() % (fin - ini + 1);
    intercambio(a, aleatorio, fin, intercambios);
    pivote = a[fin];

    for (i = ini, j = fin - 1;;) {
        while ((i <= fin - 1) && (a[i] < pivote)) {
            i++;
            (*comparaciones)++;
        }
        while ((j >= ini) && (pivote < a[j])) {
            j--;
            (*comparaciones)++;
        }
        if (i < j) {
            intercambio(a, i, j, intercambios);
            i++;
            j--;
        } else {
            break;
        }
    }

    intercambio(a, i, fin, intercambios); // Colocar el pivote en su posición final
    QuickSortAleatorio(a, ini, i - 1, comparaciones, intercambios);
    QuickSortAleatorio(a, i + 1, fin, comparaciones, intercambios);
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||



//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

int *leerArchivo(const char *nombreArchivo, int *cantidad) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        printf("Error al abrir el archivo de entrada.\n");
        return NULL;
    }

    int capacidad = 50000;
    int *numeros = (int *)malloc(capacidad * sizeof(int));
    if (numeros == NULL) {
        printf("Error al asignar memoria.\n");
        fclose(archivo);
        return NULL;
    }

    *cantidad = 0;
    while (fscanf(archivo, "%d", &numeros[*cantidad]) == 1) {
        (*cantidad)++;
        if (*cantidad == capacidad) {
            capacidad *= 2;
            numeros = (int *)realloc(numeros, capacidad * sizeof(int));
            if (numeros == NULL) {
                printf("Error al redimensionar memoria.\n");
                fclose(archivo);
                return NULL;
            }
        }
    }
    fclose(archivo);
    return numeros;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void guardarArchivo(const char *nombreArchivo, int *numeros, int cantidad) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if (!archivo) {
        printf("Error al abrir el archivo de salida.\n");
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        fprintf(archivo, "%d\n", numeros[i]);
    }
    fclose(archivo);
}
