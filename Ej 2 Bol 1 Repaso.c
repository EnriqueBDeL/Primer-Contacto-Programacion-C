// EJERCICIO 2


#include <stdio.h>
#include <stdlib.h>

// VARIABLES GLOBALES
int x = 5;
int y = 3;
// f1 recibe un parametro


void f1(float p) {

int y; // VARIABLE LOCAL
static int z = 7;
y = (int) p;
y += z; // y = y + z
z++;
x++; // x = x + 1

printf("Valor X (en f1): %d\n", x);
printf("Valor Y (en f1): %d\n", y);
printf("Valor Z (en f1): %d\n", z);

return;

}


int main(int argc, char *argv[]){


float param = 21.0;

f1(param);
printf("\n");
f1(param);
printf("\n");
f1(param);
printf("\n");


printf("\n");
printf("Valor X: %d\n", x);
printf("Valor Y: %d\n", y);

system("PAUSE");

return 0;

}


/*

1.


X)  Se declara x de forma global con un balor de 5. En el f1(), se le suma 1 a x. En el main imprime la x.

Y)  Se declara y de forma global con un balor de 3. En el main se declara param con el valor 21.0 .
    Este es introducido de forma local dentro de f1, pero con el nombre p. Dentro de f1,  se pasa el -
    valor de p a entero y se gurada en y, lo que hace que y tenga el valor 21. Echo esto, se suma a z.
    Y en el main se imprime el valor de y que tras la suma se queda como 28.


2.

   Z no puede usarse dentro del main porque no está declarada en el.

   param no se puede utilizar en el f1, poruqe no está declarada. La unica forma de utilizarla, es -
   escribiendo p, que es como se llama la variable que contienen la direccion de param.


3.

    No es el mismo nombre. Porque en el main lo que haces es como "enviar" a f1() una variable float.
    En f1() para usar ese valor float, lo tines que declarar y es aquí donde puedes utilizar el nombre que quieras.


4.

    No compila, ya que y está declarada en f1() como un balor enetero y este nuevo y es tipo float.


5.

    Si compila. El return; da error porque int() necesita que el return; tenga un valor numérico para funcionar.


6.

   1º Z conserva el valor de z++.

    2º Al poner z estatica, al repetir el f1(), no se vuelve a declarar int z = 7, por lo que z conserva el valor de la suma anteriror.


7.

    1º Cambias p de tipo float a tipo int.
    2º Es necesario, porque un int no purde tener un valor float.
    3. casting explícito
    4. Existen mas expresiones de este tipo como: float, char, etc.


*/




