#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int cuadrado(int x)
{
  x = x*x;
  return x;
}


void intercambio(int *x, int *y)
{
  int temp;

  temp = *x;  /* En temp se guarda el valor apuntado por la direccion de x */
  *x = *y;    /* Pone el valor apuntado por y en x */
  *y = temp;  /* Pone el valor apuntado por x en y */
}


/* Muestra una cadena en mayusculas */
void print_upper(char cadena[])
{
  for(int t=0; cadena[t]; ++t)  {
    cadena[t] = toupper(cadena[t]);
  }
}


/* Devuelve un puntero al caracter c en la cadena s, si existe */
char *encuentra(char c, char *s)
{
  while(c!=*s && *s)
       s++;

  return s;
}



int main()
{
  int numero=5;
  int i=10, j=20;
  char s[80];
  char c, *p1;

  printf("%d es el cuadrado de %d\n", cuadrado(numero), numero);

  printf("i y j antes de intercambio: %d %d\n", i, j);
  intercambio(&i,&j);
  printf("i y j despues de intercambio: %d %d\n", i, j);


  //Pedir una cadena
  printf("Introduce cadena minusculas: ");
  gets(s);
  print_upper(s);
  printf("\nAhora en mayusculas %s\n", s);

  // Pedir un caracter
  printf("Introduce caracter EN MAYUSCULA a buscar en la cadena anterior: ");
  c = getchar();
  p1 = encuentra(c,s);

  if(*p1)  // Caracter encontrado
          printf("Encontrado, cadena a partir del caracter: %s\n",p1);
  else
          printf("No encontrado\n");

  system("PAUSE");
  return 0;
}



/*

    1.  Esa modificación no afecta a la variable numero porque  al hacer cuadrado(numero),
        lo unico que hace es pasar el valor de numero a x, por lo que en ningun momento se -
        trabaja con la variable numero dentro de cuadrado.

    2.  Se le pasa las direcciones de i y j.


        Grafico:

        intercambio(&i,&j); -> Cogemos la direccion de i y j -> intercambio(int *x, int *y) -> metemos en *x

        la drieccion del contenido de i y en y la direccion del contenido de j -> temp = *x; ->

        en temp metemos el valor al que direcciona x -> *x = *y; -> el valor que direcciona y

        lo metemos en la direccion de x -> *y = temp; -> el valor de temp, lo metemos en la direccion de y


    3.  Si, se modifica el contenido de la cadena.

        Cuando pasas un array se pasa todo, tamaño y contenido.

        Para que no se modifique, debes quitar el toupper, que es el que modifica el contenido del array.


    4.  Devuelve una cadena de texto.

        Si, cambiaria la declaración de la función si se devolvira un puntero entero, ya que lo que saco de
        la funcion es un char.




*/
