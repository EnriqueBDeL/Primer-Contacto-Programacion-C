#include "Header.h"

int main()
{
  int opcion;

  P_NODO_ARBOL arbol = crearArbol();

  Pokemons pokemon;

  char palabra[50];

  for(;;){
        opcion = Menu();
    switch(opcion){

    case 1:

        printf("Introduce el nombre: "); scanf("%s", palabra);
        pokemon.nombre = strdup(palabra);
        printf("Introduce el mote: "); scanf("%s", palabra);
        pokemon.mote = strdup(palabra);
        printf("Introduce el nivel: "); scanf("%d", &pokemon.nivel);

        arbol = insertar(arbol,pokemon);

        break;


    case 2:

             printf("Introduce el mote a borrar: "); scanf("%s", palabra);
             arbol = eliminar(arbol,palabra);

        break;

    case 3:

        printf("Introduce el nombre a buscar: "); scanf("%s",palabra);

        if(encontrar(arbol,palabra) != NULL){

            printf("Encontrado");

        }else{

          printf("No Encontrado");
        }


        break;


    case 4:

        inOrder(arbol);

        break;


    }
  }
}
