#include "Header.h"

int main() {

    pto_pila pila = crear();

    int opcion;
    char nombreS[50];
    char nombreR[50];
    int edad;

    for(;;){

        opcion = Menu();

        switch(opcion) {

            case 1:
                printf("Introduce el nombre del superhéroe: ");
                scanf("%s", nombreS);

                printf("Introduce el nombre real del superhéroe: ");
                scanf("%s", nombreR);

                printf("Introduce la edad del superhéroe: ");
                scanf("%d", &edad);


                pila = push(pila, nombreS, nombreR, edad);

                break;
            case 2:

                  printf("Introduce el nombre del superhéroe a eliminar: ");
                scanf("%s", nombreS);

                pila = pop(pila, nombreS);

                break;
            case 3:

                imprimir_pila(pila);

                break;

        }
    }
}
