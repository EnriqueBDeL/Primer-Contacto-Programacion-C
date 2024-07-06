#include "Header.h"


int Menu(){
int opcion;
printf("\n****MENU****");
printf("\n1. Anadir monumento");
printf("\n2. Eliminar monumento");
printf("\n3. Mostrar monumentos");
printf("\n\nInserta una opcion: "); scanf("%d", &opcion);
return opcion;
}
