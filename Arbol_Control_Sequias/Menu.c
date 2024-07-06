#include "Header.h"

int Menu(){
int opcion;
printf("\n\n****MENU****");
printf("\n1. Insertar control.");
printf("\n2. Eliminar control.");
printf("\n3. Mostrar controles.");
printf("\n4. Salir.");
printf("\nIntroduce una opcion: "); scanf("%d",&opcion);
return opcion;
}
