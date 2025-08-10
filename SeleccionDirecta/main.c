#include "Header.h"



int main() {


    char nombreArchivo[100], archivoOrdenado[100];

    int *valores = NULL;
    int size;
    int comparaciones = 0, intercambios = 0;
    clock_t inicio, fin;

    double tiempoOrdenacion;


    printf("Nombre del archivo a leer: "); scanf("%s", nombreArchivo);


    size = leerDesdeArchivo(nombreArchivo, &valores);
    if (size == -1) {
        printf("Error al leer el archivo.\n");
        return 1;
    }

//.....................|
    inicio = clock();
//.....................|

    seleccion(valores, size, &comparaciones, &intercambios);

//.............................................................|
    fin = clock();
    tiempoOrdenacion = (double)(fin - inicio) / CLOCKS_PER_SEC;
//.............................................................|



    printf("Nombre del archivo para guardar: "); scanf("%s", archivoOrdenado);
    guardarEnArchivo(archivoOrdenado, valores, size);



    printf("Comparaciones: %d\n", comparaciones);
    printf("Intercambios: %d\n", intercambios);
    printf("Tiempo: %.2f segundos\n", tiempoOrdenacion);


    free(valores);
    return 0;
}
