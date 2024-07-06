#include "Header.h"

int Menu() {
    int opcion;
    printf("\n\n****MENU****");
    printf("\n1. Introducir ciclista.");
    printf("\n2. Buscar ciclista.");
    printf("\n\n Introduce una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
