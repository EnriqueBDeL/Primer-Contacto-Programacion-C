#include "Header.h"
int main() {
    Lista a = NULL;
    Posicion c1;
    int opcion;

    for (;;) {
        opcion = Menu();
        switch (opcion) {
            case 1:
                printf("Ingrese el nombre del monitor: ");
                char nombre[50];
                scanf("%s", nombre);
                printf("Ingrese la fecha de lanzamiento del monitor: ");
                int fecha_lanzamiento;
                scanf("%d", &fecha_lanzamiento);
                printf("Ingrese el precio del monitor: ");
                float precio;
                scanf("%f", &precio);
                a = l_int_insertar(a, l_int_primero(a), nombre, fecha_lanzamiento, precio);
                break;
            case 2:
               printf("Ingrese el nombre del monitor que desea eliminar: ");
    char nombre_eliminar[50];
    scanf("%s", nombre_eliminar);
    c1 = l_int_localizar(a, nombre_eliminar);
    if (c1 != NULL) {
        l_int_borrar(&a, c1);
        printf("Monitor eliminado correctamente.\n");
    } else {
        printf("Monitor no encontrado.\n");
    }
                break;
            case 3:
                printf("Listado de monitores:\n");
                c1 = l_int_primero(a);
                while (c1 != NULL) {
                    printf("Nombre: %s, Fecha de lanzamiento: %d, Precio: %.2f\n", l_int_nombre(a, c1), c1->fecha_lanzamiento, c1->precio);
                    c1 = l_int_siguiente(a, c1);
                }
                break;
            case 4:
                printf("Saliendo...\n");
                l_int_destruir(a);
                return 0;
            default:
                printf("Opción no válida.\n");
                break;
        }
    }

    return 0;
}
