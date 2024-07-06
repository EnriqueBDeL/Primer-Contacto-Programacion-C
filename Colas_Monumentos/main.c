#include "Header.h"

int main(){
 tipo_cola cola;
    crear(&cola);
    int opcion;

    do {
        opcion = Menu();

        switch (opcion) {
            case 1: {
                // A�adir monumento
                Monumentos *nuevo_monumento = (Monumentos *)malloc(sizeof(Monumentos));

                nuevo_monumento->nombre = (char *)malloc(50 * sizeof(char)); // Ejemplo, ajusta seg�n necesidad

                printf("Ingrese nombre del monumento: ");
                scanf(" %[^\n]", nuevo_monumento->nombre);
                printf("Ingrese a�o de construcci�n: ");
                scanf("%d", &nuevo_monumento->ano);

                push(&cola, nuevo_monumento);
                printf("Monumento a�adido a la cola.\n");
                break;
            }
            case 2: {
                // Eliminar monumento por nombre
                char nombre_eliminar[50];
                printf("Ingrese el nombre del monumento a eliminar: ");
                scanf(" %[^\n]", nombre_eliminar);

                int resultado = pop(&cola, nombre_eliminar);
                if (resultado) {
                    printf("Se elimin� el monumento: %s\n", nombre_eliminar);
                } else {
                    printf("No se encontr� ning�n monumento con ese nombre.\n");
                }
                break;
            }
            case 3: {
                // Mostrar monumentos
                imprimir_cola(cola);
                break;
            }
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opci�n inv�lida. Intente de nuevo.\n");
        }

    } while (opcion != 4);

    // Vaciar la cola antes de salir
    vaciar(&cola);

    return 0;
}
