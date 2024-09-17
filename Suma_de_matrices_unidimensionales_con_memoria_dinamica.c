#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    int *matriz1 = NULL, *matriz2 = NULL, *suma = NULL;

    int num, count1 = 0, count2 = 0;

    char respuesta;



//Matriz 1
for(;;){
    printf("\n> Introduce un valor para la Matriz 1:"); fflush(stdin); scanf("%d",&num);

    matriz1 = realloc(matriz1, (count1 + 1) * sizeof(int));
    matriz1[count1] = num;
    count1++;

    printf("\n> Quieres seguir anadiendo valores?\n> Contesta con 'S' o 'N'.\n~ Respuesta:"); fflush(stdin); scanf("%c",&respuesta);

           if (respuesta == 'N' || respuesta == 'n') {
            break;
        }

}


// Matriz 2
for(;;){
    printf("\n> Introduce un valor para la Matriz 2:"); fflush(stdin); scanf("%d",&num);


    matriz2 = realloc(matriz2, (count2 + 1) * sizeof(int));
    matriz2[count2] = num;
    count2++;

    printf("\n> Quieres seguir anadiendo valores?\n> Contesta con 'S' o 'N'.\n~ Respuesta:"); fflush(stdin); scanf("%c",&respuesta);

           if (respuesta == 'N' || respuesta == 'n') {
            break;
        }

}


//Comprueba si son iguales las matrices
  if (count1 != count2) {
        printf("\nError: Las dos matrices deben tener el mismo tamaño para poder sumarse.\n");

        return 1;
    }


//Suma
    suma = malloc(count1 * sizeof(int));
    for (int i = 0; i < count1; i++) {
        suma[i] = matriz1[i] + matriz2[i];
    }

    printf("\nLa suma de las dos matrices es:\n");
    for (int i = 0; i < count1; i++) {
        printf("|%d|", suma[i]);
    }


    return 0;
}
