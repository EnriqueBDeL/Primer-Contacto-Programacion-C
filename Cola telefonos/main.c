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
                    printf("\n\nLa cola est� vac�a");
                } else {
                    printf("\n\nLa cola no est� vac�a");
                }
                break;

            case 3:
                if (cola->cabeza == cola->cola) {
                    printf("\n\nLa cola est� vac�a");
                } else {
                    telefono = primero(cola);
                    printf("\n\nTel�fono en primer lugar:\nID: %s\nModelo: %s\nA�o de creaci�n: %d\nPrecio: %.2f\n",
                           telefono.id, telefono.modelo, telefono.anno_creacion, telefono.precio);
                }
                break;

            case 4:
                printf("\nIntroduce el ID del tel�fono: ");
                scanf("%s", id);
                printf("Introduce el modelo del tel�fono: ");
                scanf("%s", modelo);
                printf("Introduce el a�o de creaci�n del tel�fono: ");
                scanf("%d", &anno);
                printf("Introduce el precio del tel�fono: ");
                scanf("%f", &precio);

                telefono.id = strdup(id);
                telefono.modelo = strdup(modelo);
                telefono.anno_creacion = anno;
                telefono.precio = precio;

                insertar(cola, telefono);
                printf("\nTel�fono insertado.");
                break;

            case 5:
                eliminar(cola);
                printf("\nTel�fono eliminado.");
                break;

            case 6:
                printf("\nLista de tel�fonos:");
                for (i = cola->cabeza; i != cola->cola; i = suma_uno(cola, i)) {
                    telefono = cola->valores[i];
                    printf("\nTel�fono %d:\nID: %s\nModelo: %s\nA�o de creaci�n: %d\nPrecio: %.2f\n\n",
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



