#include "Header.h"

int Menu(){
int opcion;
printf("\n1. Anadir monitor\n");
printf("2. Eliminar monitor\n");
printf("3. Mostrar monitores\n");
printf("4. Salir\n");
printf("Seleccione una opcion: ");  scanf("%d", &opcion);
return opcion;
}
