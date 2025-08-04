#include "Header.h"

int main() {

    int opcion;


    int cantidad1, cantidad2;
    int *numeros1, *numeros2;

    int comparaciones1 = 0, comparaciones2 = 0;
    int intercambios1 = 0, intercambios2 = 0;


    char nombref[100], nombreSalida[100];

    double tiempo1, tiempo2;


    printf("Ingrese el nombre del archivo de entrada: "); scanf("%s", nombref);

    opcion = Menu();

    switch (opcion) {

        case 1:


            numeros1 = leerArchivo(nombref, &cantidad1);

//................................................................|
            clock_t inicio1 = clock();
//................................................................|


            QuickSort(numeros1, 0, cantidad1 - 1, &comparaciones1, &intercambios1);


//................................................................|
            clock_t fin1 = clock();
            tiempo1 = (double)(fin1 - inicio1) / CLOCKS_PER_SEC;
//................................................................|


            printf("\nIngrese el nombre del archivo de salida: "); scanf("%s", nombreSalida);

            guardarArchivo(nombreSalida, numeros1, cantidad1);

            free(numeros1);

            printf("Numero de comparaciones realizadas: %d\n", comparaciones1);
            printf("Numero de intercambios realizados: %d\n", intercambios1);
            printf("Tiempo empleado en la ordenacion: %f segundos\n", tiempo1);

            break;

        case 2:


            numeros2 = leerArchivo(nombref, &cantidad2);

//................................................................|
            clock_t inicio2 = clock();
//................................................................|

            QuickSortAleatorio(numeros2, 0, cantidad2 - 1, &comparaciones2, &intercambios2);

//................................................................|
            clock_t fin2 = clock();
            tiempo2 = (double)(fin2 - inicio2) / CLOCKS_PER_SEC;
//................................................................|

            printf("\nIngrese el nombre del archivo de salida: "); scanf("%s", nombreSalida);

            guardarArchivo(nombreSalida, numeros2, cantidad2);

            free(numeros2);

            printf("Numero de comparaciones realizadas: %d\n", comparaciones2);
            printf("Numero de intercambios realizados: %d\n", intercambios2);
            printf("Tiempo empleado en la ordenacion: %f segundos\n", tiempo2);
            break;

        case 3:

            break;


    }

    return 0;
}

