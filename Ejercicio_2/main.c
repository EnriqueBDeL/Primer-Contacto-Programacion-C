#include "Header.h"



int main(void) {

    P_NODO n = NULL;

    cargarDatos(&n);

    int opcion;
    char ciudado[100];
    char ciudadd[100];

    for (;;) {
        opcion = Menu();

        switch (opcion) {

            case 1:

                comprobarValidez(n);

                break;

            case 2:

                printf("Introduce la ciudad de origen: ");  scanf("%s", ciudado);
                printf("Introduce la ciudad de destino: "); scanf("%s", ciudadd);
                dijkstra(n, ciudado, ciudadd);

                break;

            case 3:

                printf("\nPresiona enter para salir...");
                return 0;

         /*   case 4:
                listarNodos(n);
                break;*/
        }
    }
    return 0;
}
