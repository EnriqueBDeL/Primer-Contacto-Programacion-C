#include "Header.h"


int Menu(){
int opcion;
printf("\n****MENU***");
printf("\n1. Anadir superheroe.");
printf("\n2. Eliminar superheroe.");
printf("\n3. Listar superheroes.");
printf("\n\nIntroduce una opcion: "); scanf("%d",&opcion);
return opcion;
}
