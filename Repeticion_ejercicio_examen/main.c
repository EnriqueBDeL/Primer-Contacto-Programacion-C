#include "Header.h"

int main()
{
     int opcion;

    P_NODO_ARBOL arbol = crearArbol();

    Ciclistas ciclista;

    char palabra[50];

    for (;;) {

        opcion = Menu();

        switch (opcion) {

            case 1:

                printf("\n Introduce el ID: "); scanf("%s",palabra);
                ciclista.ID = strdup(palabra);
                printf("\n Introduce el nombre: "); scanf("%s",palabra);
                ciclista.nombre = strdup(palabra);

                arbol = insertar(arbol, ciclista);

                break;

            case 2:

     printf("\n Introduce el nombre del ciclista a buscar: "); scanf("%s",palabra);

        if( encontrar(arbol, palabra) != NULL ){

            printf("\nEncontrado");

        }else{

                  printf("\nNO Encontrado");

        }


                break;

            case 3:

                break;


        }
    }
}
