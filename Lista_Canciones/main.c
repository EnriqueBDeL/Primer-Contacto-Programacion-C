#include "Header.h"

int main() {
    P_NODO_LISTA lista = NULL;
    int opcion;
    char nombre[100];
    int duracion;
    Canciones *cancion;
    P_NODO_LISTA nodo;

    for (;;) {
        opcion = Menu();

        switch (opcion) {
        case 1:
            cancion = (Canciones *)malloc(sizeof(Canciones));
            printf("Introduce el nombre de la cancion: ");
            scanf("%s", nombre);
            cancion->nombre = strdup(nombre);
            printf("Introduce la duracion de la cancion: ");
            scanf("%d", &duracion);
            cancion->duracion = duracion;
            lista = insertar(lista, cancion);
            break;
        case 2:
            printf("Introduce el nombre de la cancion a borrar: ");
            scanf("%s", nombre);
            lista = borrar(lista, nombre);
            break;
        case 3:
            printf("Introduce el nombre de la cancion a buscar: ");
            scanf("%s", nombre);
            nodo = buscar(lista, nombre);
            if (nodo != NULL) {
                printf("Cancion encontrada: %s, Duracion: %d\n", nodo->cancion->nombre, nodo->cancion->duracion);
            } else {
                printf("Cancion no encontrada\n");
            }
            break;
        case 4:
            imprimir_lista(lista);
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
    }
    return 0;
}
