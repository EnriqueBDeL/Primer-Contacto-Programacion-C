#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void f1(int a1[MAX]) {
  printf("En f1...");
  for(int i = 0; i < MAX; i++)
          printf("%d ",a1[i]);

  printf("\n");

}

void f2(int a1[]) {
  printf("En f2...");
  for(int i = 0; i <= MAX; i++)
          printf("%d ",a1[i]);

  printf("\n");

}

void f3(int *a1) {
  printf("En f3...");
  for(int i = 0; i < MAX; i++)
          printf("%d ",a1[i]);

  printf("\n");

}


void cadenas(char cadena1[],char cadena2[]){


    printf("Longitud de cadena1: %zu\n", strlen(cadena1));
    printf("Longitud de cadena2: %zu\n", strlen(cadena2));


    int resultado = strcmp(cadena1, cadena2);
        if (resultado == 0) {
            printf("Las cadenas son iguales.\n");
        } else {
            printf("Las cadenas son diferentes.\n");
        }

    char concatenada[100];
    strcpy(concatenada, cadena1);
    strcat(concatenada, cadena2);


    printf("Cadena concatenada: %s\n", concatenada);


}





void imprime_matriz(int matriz[5][2]) {


 for (int i = 0; i < 5; i++) {
        printf("\n");
        for (int j = 0; j < 2; j++) {
            printf("|%d| ", matriz[i][j]);
        }
 }
    printf("\n");
}


void doble_matriz(int matriz[5][2]){


 for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 2; j++) {

          matriz[i][j]  = matriz[i][j] * 2;
        }
 }
}


void cadena_cadena(){

 char cadenas[5][100];

    for (int i = 0; i < 5; i++) {
        printf("Introduce la cadena %d: ", i + 1);
        fgets(cadenas[i], 100, stdin);

    }
    printf("\nCadenas introducidas:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", cadenas[i]);
    }

}


int main(int argc, char *argv[]){

    int a1[MAX] = {1,2,3,4,5,6,7,8,9,10};
    char cadena1[15]="hola que haces"; // tam cadena + 1 para caracter final '/0'
    char cadena2[]="Otra forma de crear cadenas sin indicar tamaño\n";

    int matriz[5][2] = {{1,2}, {3,4}, {5,6}, {7,8}, {9,10}};







    f1(a1); f2(a1); f3(a1);


    cadenas(cadena1,cadena2);

    doble_matriz(matriz);
    imprime_matriz(matriz);

    cadena_cadena();

    system("PAUSE");
    return 0;
}


/*

    1. La primera me resulta mas comoda.

    2. Empieza en 0 porque el 0 es la primera posicion del array.
       Es i<MAX porque MAX tiene el valor 10, pero realmente ocupa 11 porque el espacio 0 tambien cuenta.
       Así que de 0 a i<MAX son 10 posiciones.

    3.

        a1[0] contiene: 1
        a1[1] contiene: 2
        a1[9] contiene: 10
        a1[10] contiene: Un contenido indeterminado. en este caso 16.


    4.  Se imprimen las cadenas unidas.

        No hace falta un bucle.


    5. El que está vacio son las filas y el dos son las columnas.

        No se puede declarar int [][] porque tienen que haber minimo uno.


    8.



*/



