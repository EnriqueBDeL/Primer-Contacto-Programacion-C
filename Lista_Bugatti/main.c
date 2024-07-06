#include "Header.h"




int main()
{
   Lista a = NULL;
    Posicion c1;
    int conta;

    // Bucle del menú
    while (1) {
        int opcion = Menu();

        switch (opcion) {
            case 1:
                {
                    Coche coche;
                    coche.modelo = (char *)malloc(50 * sizeof(char));
                    coche.comprador = (char *)malloc(50 * sizeof(char));

                    printf("Introduce el modelo del Bugatti: ");
                    scanf("%s", coche.modelo);

                    printf("Introduce el nombre del comprador: ");
                    scanf("%s", coche.comprador);

                    printf("Introduce el precio del Bugatti: ");
                    scanf("%d", &coche.precio);

                    c1 = l_int_primero(a);
                    a = l_int_insertar(a, c1, coche);

                    printf("Bugatti insertado correctamente.\n");

                    break;
                }

            case 2:
                {
                    char modelo[50];
                    printf("Introduce el modelo del Bugatti a borrar: ");
                    scanf("%s", modelo);

                    a = l_int_borrar(a, modelo);
                    break;
                }

            case 3:
                {
                    printf("Contenido de la lista de Bugattis:\n");
                    c1 = l_int_primero(a);
                    while (c1 != NULL) {
                        Coche coche = l_int_elemento(a, c1);
                        printf("Modelo: %s, Comprador: %s, Precio: %d\n", coche.modelo, coche.comprador, coche.precio);
                        c1 = l_int_siguiente(a, c1);
                    }
                    break;
                }

            case 0:
                {
                    printf("Saliendo del programa.\n");
                    l_int_destruir(a);
                    return 0;
                }

            default:
                printf("Opción no válida. Inténtalo de nuevo.\n");
                break;
        }
    }

    l_int_destruir(a);
    return 0;
}
