#include "Header.h"


int main(void) {
    tipo_cola cola = NULL;
    int opcion, anno, i;
    float precio;
    char id[20];
    char modelo[50];
    Telefonos telefono;

    for (;;) {
        opcion = Menu();

        switch (opcion) {
            case 1:
                cola = crear(cola);
                printf("\nCola creada.");
                break;

            case 2:
                if (cola->cabeza == cola->cola) {
                    printf("\n\nLa cola está vacía");
                } else {
                    printf("\n\nLa cola no está vacía");
                }
                break;

            case 3:
                if (cola->cabeza == cola->cola) {
                    printf("\n\nLa cola está vacía");
                } else {
                    telefono = primero(cola);
                    printf("\n\nTeléfono en primer lugar:\nID: %s\nModelo: %s\nAño de creación: %d\nPrecio: %.2f\n",
                           telefono.id, telefono.modelo, telefono.anno_creacion, telefono.precio);
                }
                break;

            case 4:
                printf("\nIntroduce el ID del teléfono: ");
                scanf("%s", id);
                printf("Introduce el modelo del teléfono: ");
                scanf("%s", modelo);
                printf("Introduce el año de creación del teléfono: ");
                scanf("%d", &anno);
                printf("Introduce el precio del teléfono: ");
                scanf("%f", &precio);

                telefono.id = strdup(id);
                telefono.modelo = strdup(modelo);
                telefono.anno_creacion = anno;
                telefono.precio = precio;

                insertar(cola, telefono);
                printf("\nTeléfono insertado.");
                break;

            case 5:
                eliminar(cola);
                printf("\nTeléfono eliminado.");
                break;

            case 6:
                printf("\nLista de teléfonos:");
                for (i = cola->cabeza; i != cola->cola; i = suma_uno(cola, i)) {
                    telefono = cola->valores[i];
                    printf("\nTeléfono %d:\nID: %s\nModelo: %s\nAño de creación: %d\nPrecio: %.2f\n\n",
                           i + 1, telefono.id, telefono.modelo, telefono.anno_creacion, telefono.precio);
                }
                break;

            case 7:
                printf("\nSaliendo...");

                return 0;
                break;

        }
    }
    return 0;
}



