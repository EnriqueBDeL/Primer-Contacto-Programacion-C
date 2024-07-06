#include "auto.h"

void agregarCiclistasAutomaticamente(struct Ciclista ciclistas[], int *NC) {
    FILE *Ciclistaf;
    char nombre_fichero[80];
    int i = 0; // Ciclistas

    for (int num = 1; num <= 10; num++) {
        sprintf(nombre_fichero, "Corredor%d.txt", num);
        Ciclistaf = fopen(nombre_fichero, "r");

        if (Ciclistaf == NULL) {
            printf("\nERROR: No se han podido leer los archivos base....");
        } else {
            ciclistas[i].id = malloc(50 * sizeof(char));
            ciclistas[i].nombre = malloc(50 * sizeof(char));

            fscanf(Ciclistaf, "%s", ciclistas[i].id);
            fscanf(Ciclistaf, "%s", ciclistas[i].nombre);
            fscanf(Ciclistaf, "%d", &ciclistas[i].ano);

            i++;
            *NC = i;
            fclose(Ciclistaf);
        }
    }
}
