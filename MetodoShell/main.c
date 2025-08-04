#include "Header.h"

int main() {


   char entrada[100], salida[100];

    printf("Introduce el nombre del archivo de entrada: "); scanf("%s", entrada);

    printf("Introduce el nombre del archivo de salida: "); scanf("%s", salida);

    leerFichero(entrada, salida);

    return 0;

}
