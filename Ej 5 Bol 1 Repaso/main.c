#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

/* Accede a la cadena como puntero */
void putstr(char *s)
{
  while(*s) {
            putchar(*s++);
  }
}



int main(void)
{
  char cadena1[MAX]="I love punteros\n";
  char cadena2[MAX]="Me gusta C\n";


  int x = 99;
  int y;
  int *p1, *p2;  // Variables punteros
  char *c1 = NULL;  // Forma habitual de iniciar un puntero
  int *p3 = NULL;

  p1 = &x;  // Direccion de x a p1
  p2 = p1;
  y = *p2;
  y++;



  /* Imprime el valor de x dos veces */
  printf("Values at p1 and p2: %d %d\n", *p1, *p2); // Acceso a una direccion

  /* Imprime la direccion de x dos veces */
  printf("Addresses pointed to by p1 and p2: %p %p\n", p1, p2);

  printf("Values x and y: %d %d\n", x, y); // Acceso a una direccion



  // p1++;

 //printf("Addresses pointed to by p1 and p2: %p %p\n", p1, p2);

  //printf("Values x and y: %d %d\n", x, y); // Acceso a una direccion



  c1 = cadena1;
  printf("%s",c1);


  putstr(cadena2);



  p3 = (int *) malloc(50*sizeof(int));  // Asignación dinamica de punteros



  if(!p3) {
          printf("Out of memory.\n");
          exit(1);
  }



int r = 100;
 for(int g = 0; g<=50; g++){

    p3[g] = r;
    printf("\n%d",p3[g]);
    r++;

 }


     int tamano;
    char *cadena;

    printf("Introduce el tamano de la cadena: ");
    scanf("%d", &tamano);

    cadena = (char *)malloc(tamano * sizeof(char));

    while (getchar() != '\n');

    printf("Introduce la cadena: ");
    fgets(cadena, tamano, stdin);

    if (strlen(cadena) >= tamano) {
        printf("Error: La cadena es mayor que el tamano permitido.\n");
    } else {
        printf("La cadena introducida es: %s", cadena);
    }

    free(cadena);

  free(p3);  // Liberacion de memoria
  system("PAUSE");

  return 0;
}


/*


    1.  No se modifica porque x no tiene nada que ver con y.

    2.  El puntero p1, apuntaria al mismo registro, pero p2 apuntaria a 000000000061FDC0.
        El valor de x no se ve modificado.

    3.  La funcon putsrt(), carga el string en *s y va imprimiendo cada caracter de la cadena hasta
        llegar al final.

        La forma de hacerlo usando la indexacion de array es:

            for (int i = 0; s[i] != '\0'; i++) {
                  putchar(s[i]);
            }

    4.  Esa asignacio sirve para darle un valor inicial a una variable.

        p3 alberca una cantdad de 50 enteros.


    6.  Memoria filas: int** matriz = (int**)malloc(5 * sizeof(int*));

        Memoria columnas:

        for (int i = 0; i < 5; i++) {

        matriz[i] = (int*)malloc(5 * sizeof(int));

        }

*/
