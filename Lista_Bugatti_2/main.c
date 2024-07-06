#include "Header.h"


int main() {
    Lista lista = NULL;
    int opcion;
    char modelo[50];
    char comprador[50];
    int precio;

    do {
        opcion = Menu();

        switch (opcion) {
              case 1:
                printf("\nIntroduce el nombre del modelo: ");
                fflush(stdin); // Limpiar el buffer de entrada
                fgets(modelo, sizeof(modelo), stdin);
                modelo[strcspn(modelo, "\n")] = '\0'; // Eliminar el salto de línea final
                printf("Introduce el nombre del comprador: ");
                fflush(stdin); // Limpiar el buffer de entrada
                fgets(comprador, sizeof(comprador), stdin);
                comprador[strcspn(comprador, "\n")] = '\0'; // Eliminar el salto de línea final
                printf("Introduce el precio: ");
                scanf("%d", &precio);
                lista = l_int_inser_ppo(lista, modelo, comprador, precio);
                break;
            case 2:
                if (lista == NULL) {
        printf("\nLa lista está vacía. No hay elementos para borrar.\n");
    } else {
        int posicion;
        printf("\nIntroduce la posicion del Bugatti que deseas borrar (0-%d): ", l_int_longitud(lista) - 1);
        scanf("%d", &posicion);

        if (posicion < 0 || posicion >= l_int_longitud(lista)) {
            printf("\nPosicion invalida. Introduce una posicion valida (0-%d).\n", l_int_longitud(lista) - 1);
        } else {
            Posicion pborrar = l_int_localizar(lista, posicion);
            lista = l_int_borrar(lista, pborrar);
            printf("\nBugatti en la posicion %d borrado correctamente.\n", posicion);
        }
    }
                break;
            case 3:
                 if (lista == NULL) {
        printf("\nLa lista está vacía. No hay elementos para listar.\n");
    } else {
        printf("\nListando contenido de la lista:\n");
        Posicion pactual = l_int_primero(lista);
        int contador = 0;
        while (pactual != NULL) {
            printf("\nBugatti en la posicion %d:", contador);
            printf("\n  Modelo: %s", l_int_elemento_modelo(lista, pactual));
            printf("\n  Comprador: %s", l_int_elemento_comprador(lista, pactual));
            printf("\n  Precio: %d\n", l_int_elemento_precio(lista, pactual));
            pactual = l_int_siguiente(lista, pactual);
            contador++;
        }
    }
                break;
            case 4:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpcion invalida. Introduce una opcion valida (1-4).");
                break;
        }

    } while (opcion != 4);

    l_int_destruir(lista);
    return 0;
}
