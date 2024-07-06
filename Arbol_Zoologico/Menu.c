#include "Header.h"


int Menu(){
int opcion;
printf("\nMenu:");
printf("\n1. Añadir animal.");
printf("\n2. Eliminar animal.");
printf("\n3. Mostrar animales.");
printf("\n4. Buscar animal.");
printf("\n\nIntroduce un opcion:"); scanf("%d",&opcion);
return opcion;
}
