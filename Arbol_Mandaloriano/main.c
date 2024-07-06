#include "Header.h"



int main()
{


int opcion;

P_NODO_ARBOL arbol = crearArbol();
Mandalorianos mandaloriano;

char palabra[50];


for(;;){

        opcion = Menu();

    switch(opcion){


case 1:

    printf("\nIntroduce el nombre: "); scanf("%s", palabra);
    mandaloriano.nombre = strdup(palabra);
    printf("\nIntroduce el apodo: "); scanf("%s",palabra);
    mandaloriano.apodo = strdup(palabra);
    printf("\nIntroduce su edad: "); scanf("%d",&mandaloriano.edad);
    arbol = insertar(arbol,mandaloriano);

    break;



case 2:

     printf("Introduce el nombre del mandaloriano a eliminar: "); scanf("%s",palabra);

         if (encontrar(arbol, palabra) != NULL) {

                    printf("Mandaloriano encontrado.\n");

                } else {

                    printf("Mandaloriano no encontrado.\n");
                }


    break;



case 3:


    printf("\nMANDALORIANOS:\n");

    postOrder(arbol);



    break;


case 4:

    printf("\nIntroduce el apodo del mandaloriano a eliminar: "); scanf("%s",palabra);

    arbol = eliminar(arbol, palabra);


    break;


        }
    }
}
