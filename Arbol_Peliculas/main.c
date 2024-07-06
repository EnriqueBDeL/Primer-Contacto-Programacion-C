#include "Header.h"

int main()
{

  int opcion;

  P_NODO_ARBOL arbol = crearArbol();

  Peliculas pelicula;

  char palabra[50];



for(;;){

    opcion = Menu();


    switch(opcion){

case 1:

    printf("Introduce el nombre de la peicula: "); scanf("%s",palabra);
    pelicula.nombre = strdup(palabra);
    printf("Introduce la descripcion de la peicula: "); scanf("%s",palabra);
    pelicula.descripcion = strdup(palabra);
    printf("Introduce el ano de lanzamiento de la peicula: "); scanf("%d",&pelicula.ano);
    printf("Introduce el precio de la entrada de la peicula: "); scanf("%f",&pelicula.precio);
    arbol = insertar(arbol,pelicula);

    break;

case 2:

    printf("Introduce el nombre de la pelicula a eliminar: "); scanf("%s", palabra);
    arbol = eliminar(arbol,palabra);

    break;

case 3:

    printf("Introduce el nombre de la pelicula: "); scanf("%s", palabra);

    if(encontrar(arbol,palabra)!= NULL){

    printf("Encontrada");

    }else{

    printf("No exite");

    }

    break;

case 4:

    printf("\nLista de peliculas: ");
    inOrder(arbol);

    break;

    }
}
}
