#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
//------------------------------------------------------------------------------------------------------------------------------------------
int Menu() {
    int opcion;
    printf("\n\n\nMENU:");
    printf("\n1. Dar de alta una o varias pruebas ciclistas.");
    printf("\n2. Dar de baja a una o a varias pruebas en el sistema dado su identificador.");
    printf("\n3. Dar de baja TOTAL a una o a varias pruebas en el sistema dada su clave.");
    printf("\n4. Dar de alta uno o varios equipos ciclistas.");
    printf("\n5. Eliminar uno o varios equipos ciclistas.");
    printf("\n6. Guardar el estado del programa.");
    printf("\n7. Cargar el estado del programa.");
    printf("\n8. Listar datos.");
    printf("\n9. Salir.");
    printf("\n\nIntroduce una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
//------------------------------------------------------------------------------------------------------------------------------------------
#endif // MENU_H_INCLUDED

