#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{



    printf("Ejemplo 6 (Matriz en C):\n");




    int matriz[3][3];
    int fila, columna;






    // Introducir valores en la matriz
    for (fila = 0; fila < 3; fila++) {
        for (columna = 0; columna < 3; columna++) {
            printf("Introduce un numero para la posicion [%d][%d]: ", fila, columna);
            scanf("%d", &matriz[fila][columna]);
        }
    }






    // Imprimir la matriz
    printf("\nLa matriz ingresada es:\n");
    for (fila = 0; fila < 3; fila++) {
        for (columna = 0; columna < 3; columna++) {
            printf("|%d|", matriz[fila][columna]);
        }
        printf("\n");
    }





//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------






    printf("\n\n\nEjemplo 7 (Matriz en C):\n");


    int matriz2[4][4];
    int fila2, columna2;






    // Introducir valores en la matriz
     for (columna2 = 0; columna2 < 4; columna2++) {
        for (fila2 = 0; fila2 < 4; fila2++) {
            printf("Introduce un numero para la posicion [%d][%d]: ", fila2, columna2);
            scanf("%d", &matriz2[fila2][columna2]);
        }
    }






    // Imprimir la matriz
    printf("\nLa matriz ingresada es:\n");

    for (columna2 = 0; columna2 < 4; columna2++) {
        for (fila2 = 0; fila2 < 4; fila2++) {
            printf("|%d|", matriz2[fila2][columna2]);
        }
        printf("\n");
    }




//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------




    printf("\n\n\nEjemplo 8 (Matriz en C):\n");



    char almacenamiento[2][2];






    for (fila = 0; fila < 2; fila++) {
        for (columna = 0; columna < 2; columna++) {
            printf("Introduce un caracter para la posicion [%d][%d]: ", fila, columna);
            while (getchar() != '\n');
            scanf("%c", &almacenamiento[fila][columna]);
        }
    }




   printf("\nLa matriz ingresada es:\n");
    for (fila = 0; fila < 2; fila++) {
        for (columna = 0; columna < 2; columna++) {
            printf("|%c|", almacenamiento[fila][columna]);
        }
        printf("\n");
    }















    return 0;
}
