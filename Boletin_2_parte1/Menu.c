#include "Header.h"
//------------------------------------------------------------------------------------------------------------------------------------------

int Menu() {
    int opcion;
    printf("\n\n\nMENU:");
    printf("\n1. Dar de alta una o varias pruebas ciclistas.");
    printf("\n2. Dar de baja a una o a varias pruebas en el sistema dado su identificador.");
    printf("\n3. Dar de baja TOTAL a una o a varias pruebas en el sistema dada su clave.");
    printf("\n4. Dar de alta uno o varios equipos ciclistas.");
    printf("\n5. Eliminar uno o varios equipos ciclistas.");
    printf("\n6. Listar datos.");
    printf("\n7. Salir.");
    printf("\n\nIntroduce una opcion: "); scanf("%d", &opcion);
    return opcion;
}
