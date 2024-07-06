#include "Header.h"

int main()
{

int opcion;

P_NODO_ARBOL arbol = crearArbol();

Animales animal;


char palabra[50];



for(;;){

        opcion = Menu();

    switch(opcion){



case 1:

    printf("\nInserta el nombre del animal: "); scanf("%s",palabra);
    animal.nombre = strdup(palabra);
    printf("\nIntroduce la edad del animal: "); scanf("%d",&animal.edad);
    arbol = insertar(arbol,animal);


    break;


case 2:



 printf("\nIntroduce el nombre del aniaml a eliminar: "); scanf("%s",palabra);

 arbol = eliminar(arbol, palabra);


    break;




case 3:

  printf("\nLista Animales:");

  inOrder(arbol);



    break;




case 4:

     printf("\nIntroduce el nombre del animal que quieres buscar: "); scanf("%s",palabra);

     if (encontrar(arbol, palabra) != NULL ){

        printf("Encontrado");

     }else{


        printf("NO Encontrado");
     }

    break;

    }

}
}
