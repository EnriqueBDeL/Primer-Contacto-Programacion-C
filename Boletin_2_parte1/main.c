#include "Header.h"
//------------------------------------------------------------------------------------------------------------------------------------------

int main() {


    int opciones;

    char nombre_fichero[80];

    Lista lista_ciclistas = l_int_crear();

    ListaE lista_equipos = l_equipo_crear();

    ListaP lista_pruebas = l_prueba_crear();

    agregarCiclistasAutomaticamente(&lista_ciclistas);

//-------------------------------------------------------------------------------

for (;;) {

    opciones = Menu();

switch (opciones) {

case 1:

    printf("Introduce el nombre del archivo para agregar una prueba (Ej: Prueba1.txt): "); fflush(stdin); scanf("%s", nombre_fichero);

    agregarPruebaDesdeArchivo(&lista_pruebas, nombre_fichero, lista_equipos);


    break;

case 2:

    printf("Introduce el nombre del archivo que contiene el identificador para eliminar la prueba(Ej: ElimPrueba.txt): "); fflush(stdin); scanf("%s", nombre_fichero);

    eliminarPruebaDesdeArchivo(&lista_pruebas, nombre_fichero);

    break;

case 3:

    printf("Introduce el nombre del archivo que contiene la clave para eliminar la prueba(Ej: ElimCode.txt): "); fflush(stdin); scanf("%s", nombre_fichero);

    eliminarPruebasDesdeArchivoClave(&lista_pruebas, nombre_fichero);

    break;

case 4: //Añadir equipo

     printf("Introduce el nombre del archivo del equipo (Ej: Equipo1.txt): "); fflush(stdin); scanf("%s", nombre_fichero);

     agregarEquipoDesdeArchivo(&lista_equipos, nombre_fichero, lista_ciclistas);

    break;

case 5:

    printf("Introduce el nombre del archivo con el ID del equipo a eliminar (Ej: EquipElim.txt): "); fflush(stdin); scanf("%s", nombre_fichero);

    eliminarEquipoDesdeArchivo(&lista_equipos, nombre_fichero);

    break;

case 6://Listar

    // l_int_listar(lista_ciclistas);

    l_prueba_listar(lista_pruebas);

    l_equipo_listar(lista_equipos);

    break;

case 7://Salir

    printf("Presiona enter para salir...");
    return 0;

    break;

        }
    }
}
