#include <stdio.h>
#include <stdlib.h>
#define MAX 50



void imprimir_cuadrados() {

//int i;
  int i = 1;

// i = MAX+1;
do{
   // for(int i = 1 /*i*/; i <= MAX/*/2*/; i++) {
   // while (i <= MAX){
        int z;

     //   int w;

         //  w = i % 2;

              //  if( w == 0){

              //  }else{

            z = i * i;

                printf("El cuadrado de %d es %d\n",i,z);

                //}

    i++;

    }while(i <= MAX);

    return;

}


int main(int argc, char *argv[]){

        imprimir_cuadrados();
    system("PAUSE");
return 0;

}

/*


    1. Sirve para declarar una variable global.

    2.  1º se declara la variable tipo entero i con el valor 1.
        2º se mira si el valor de i es <= que MAX, que es una variable global con valor 50.
        3º se le suma 1 a la variable i.

        No se ejecutaria ni una vez el bucle.

    3.  No es necesario poner las tres componentes del bucle for.
        Se pueden omitr todas las que quieras.

        Si quitas la condicion de terminacion, se ejecutá el bucle de forma infinita.

        No es de buena practica el modificar el indice dentro de bucle for.

        Solo se puede utilizar una unica variable.


    4. Si, puede existir.
       Ejemplo:    for (i = 0; i < 34; i++)  En este bucle, va incrementando i hasta llegar al valor 34.


    5. No se puede usar z fuera del bucle, porque z está declarada dentro del bucle, lo que hace que solo pueda funcionar
       en el.


    6. i <= MAX/2


    7.

    int w;

           w = i % 2;

               if( w == 0){

            }else{

                z = i * i;

                printf("El cuadrado de %d es %d\n",i,z);

            }



    8. A la hora de compilar, los dos dan el mismo resultado. Pero la diferencia entre uno y otro, es que en el while tienes que delcarar la variable
       fuera y el incremento dentro del este, en cambio en el for, puedes declarar todo en en el for().


    9. En el bucle for, en su estructura principal, se pueden declarar variables, establecer condiciones e implementar incrementos.
       En cambio, en el bucle do-while, únicamente se puede declarar la condición que determina si el ciclo continuará ejecutándose.
       Ademas, para usar una variable, deves declararla antes del do-while.


*/
