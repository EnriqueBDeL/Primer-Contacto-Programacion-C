#include "Cabecera.h"
#include "Menu.h"
#include "auto.h"
//------------------------------------------------------------------------------------------------------------------------------------------
int main() {

    FILE *Ciclistaf, *Pruebasf, *Equiposf, *Guardarf, *Cargarf;
    int opciones;
    int num;
    int i = 0; // Ciclistas
    int j = 0; // Pruebas
    int e = 0; // Equipos
    int NE = 0;// Nº Equipos
    int NC = 0;// Nº Ciclistas
    int NP = 0;// Nº Pruebas
    int encontrado = 0;
    int indice_equipo_eliminar = -1;
    char nombre_fichero[80];
    char identificadoreliminar[80];
    char clave[80];
    struct Ciclista ciclistas[10];
    struct Prueba *pruebas = NULL;

  agregarCiclistasAutomaticamente(ciclistas, &NC); //Añadir cilcistas automaticamente

//------------------------------------------------------------------------------------------------------------------------------------------
for (;;) {

opciones = Menu();

switch (opciones) {

case 1: //Añadir prueba

printf("Ingrese el nombre del archivo de texto que contiene la informacion de las nuevas pruebas: "); scanf("%s", nombre_fichero);
Pruebasf = fopen(nombre_fichero, "r");

    if (Pruebasf == NULL) {
        printf("Error al abrir el archivo.\n");
        } else {
            printf("Archivo abierto correctamente...\n");
            NP++;

            pruebas = (struct Prueba*)realloc(pruebas, NP * sizeof(struct Prueba));

            pruebas[NP-1].clave = (char*)malloc(50 * sizeof(char));

            pruebas[NP - 1].nombre = (char *)malloc(50 * sizeof(char));

            fscanf(Pruebasf, "%s", pruebas[NP-1].clave);
            fscanf(Pruebasf, "%s", pruebas[NP-1].nombre);
            fscanf(Pruebasf, "%d", &pruebas[NP-1].ano_celebracion);



            fclose(Pruebasf);

            pruebas[NP-1].numero_de_equipos = 0;
            pruebas[NP-1].equipos = NULL;
        }
break;
//------------------------------------------------------------------------------------------------------------------------------------------
case 2:   //Eliminar prueba con ID

printf("Ingrese el identificador de la prueba que desea dar de baja: "); fflush(stdin); scanf("%s", identificadoreliminar);

    for (int k = 0; k < NP; k++) {

        if (strcmp(pruebas[k].clave, identificadoreliminar) == 0) {

            free(pruebas[k].clave);
            free(pruebas[k].nombre);

            for (int l = k; l < NP - 1; l++) {

                pruebas[l] = pruebas[l + 1];

                }

            pruebas = realloc(pruebas, (NP - 1) * sizeof(struct Prueba));

            NP--;
            encontrado = 1;

            printf("La prueba con identificador %s ha sido eliminada exitosamente.\n", identificadoreliminar);
            break;
            }
        }
        if (!encontrado) {
            printf("No se encontró ninguna prueba con el identificador %s.\n", identificadoreliminar);
        }
break;
//------------------------------------------------------------------------------------------------------------------------------------------
case 3: //Eliminar prueba con fichero


printf("Ingrese el nombre del archivo de texto que contiene la informacion de las pruebas a eliminar: "); scanf("%s", nombre_fichero);
Pruebasf = fopen(nombre_fichero, "r");

    if (Pruebasf == NULL) {

        printf("Error al abrir el archivo.\n");

        break;
    }
    while (fscanf(Pruebasf, "%s", clave) == 1) {

        int encontrado = 0;

        for (int k = 0; k < NP; k++) {

            if (strcmp(pruebas[k].clave, clave) == 0) {

                encontrado = 1;
                printf("Se ha encontrado la prueba con clave %s: %s\n", pruebas[k].clave, pruebas[k].nombre);
                char respuesta;
                printf("Desea eliminar esta prueba? (s/n): ");
                scanf(" %c", &respuesta);
                if (respuesta == 's' || respuesta == 'S') {

                    for (int l = k; l < NP - 1; l++) {

                        strcpy(pruebas[l].clave, pruebas[l + 1].clave);
                        strcpy(pruebas[l].nombre, pruebas[l + 1].nombre);
                        pruebas[l].ano_celebracion = pruebas[l + 1].ano_celebracion;
                    }
                    NP--;
                    printf("La prueba ha sido eliminada.\n");
                    break;
                } else {
                    printf("La prueba no ha sido eliminada.\n");
                }
            }
        }
        if (!encontrado) {
            printf("No se encontró ninguna prueba con la clave %s.\n", clave);
        }
    }
    fclose(Pruebasf);

break;
//------------------------------------------------------------------------------------------------------------------------------------------
case 4: //Añadir equipo

printf("Ingrese el nombre del archivo de texto que contiene la informacion del equipo: "); scanf("%s", nombre_fichero);
Equiposf = fopen(nombre_fichero, "r");

            if (Equiposf == NULL) {
                printf("\nERROR: No se han podido leer los archivos base....");
            } else {

                int ultima_prueba = NP - 1; // Índice de la última prueba

                pruebas[ultima_prueba].equipos = (struct Equipo*)realloc(pruebas[ultima_prueba].equipos, (pruebas[ultima_prueba].numero_de_equipos + 1) * sizeof(struct Equipo));

                pruebas[ultima_prueba].equipos[pruebas[ultima_prueba].numero_de_equipos].id = (char*)malloc(50 * sizeof(char));

                pruebas[ultima_prueba].equipos[pruebas[ultima_prueba].numero_de_equipos].nombre = (char*)malloc(50 * sizeof(char));


                fscanf(Equiposf, "%s", pruebas[ultima_prueba].equipos[pruebas[ultima_prueba].numero_de_equipos].id);//ID equipo
                fscanf(Equiposf, "%s", pruebas[ultima_prueba].equipos[pruebas[ultima_prueba].numero_de_equipos].nombre);//Nombre equipo
                fscanf(Equiposf, "%d", &pruebas[ultima_prueba].equipos[pruebas[ultima_prueba].numero_de_equipos].n_ciclistas);//Nº Ciclistas


                pruebas[ultima_prueba].equipos[pruebas[ultima_prueba].numero_de_equipos].ciclistas = malloc(pruebas[ultima_prueba].equipos[pruebas[ultima_prueba].numero_de_equipos].n_ciclistas * sizeof(struct Ciclista));

                int encontrado = 1;

                for (int f = 0; f < pruebas[ultima_prueba].equipos[pruebas[ultima_prueba].numero_de_equipos].n_ciclistas; f++) { //Lee y almacena los ciclistas

                    encontrado = 0;

                    pruebas[ultima_prueba].equipos[pruebas[ultima_prueba].numero_de_equipos].ciclistas[f].id = malloc(50 * sizeof(char));

                    fscanf(Equiposf, "%s", pruebas[ultima_prueba].equipos[pruebas[ultima_prueba].numero_de_equipos].ciclistas[f].id);


                    for (int c = 0; c < NC; c++) { //Localiza si existe el ciclista

                        if (strcmp(pruebas[ultima_prueba].equipos[pruebas[ultima_prueba].numero_de_equipos].ciclistas[f].id, ciclistas[c].id) == 0) {
                            encontrado = 1;
                            break;
                        }
                    }
                    if (!encontrado) {

                        printf("El ciclista con ID %s no está registrado. No se puede dar de alta el Equipo.\n", pruebas[ultima_prueba].equipos[pruebas[ultima_prueba].numero_de_equipos].ciclistas[f].id);

                        break;
                    }
                }
                if (encontrado) {

                    pruebas[ultima_prueba].numero_de_equipos++;
                    NE++;
                    printf("Se agregó correctamente el equipo.\n");

                } else {

                    for (int f = 0; f < pruebas[ultima_prueba].equipos[pruebas[ultima_prueba].numero_de_equipos].n_ciclistas; f++) {

                        free(pruebas[ultima_prueba].equipos[pruebas[ultima_prueba].numero_de_equipos].ciclistas[f].id);

                    }
                    free(pruebas[ultima_prueba].equipos[pruebas[ultima_prueba].numero_de_equipos].ciclistas);
                }
            }
            fclose(Equiposf);
break;
//------------------------------------------------------------------------------------------------------------------------------------------
case 5:

printf("Ingrese el nombre del archivo de texto que contiene el ID del equipo que desea eliminar: "); scanf("%s", nombre_fichero);
Equiposf = fopen(nombre_fichero, "r");

    if (Equiposf == NULL) {

        printf("Error al abrir el archivo.\n");

    } else {

        char id_equipo_eliminar[TAM_ID_EQUIPOS];

        fscanf(Equiposf, "%s", id_equipo_eliminar);

        fclose(Equiposf);

        int indice_equipo_eliminar = -1; // Inicializar el índice del equipo a eliminar

        for (int k = 0; k < NP; k++) {

            for (int f = 0; f < pruebas[k].numero_de_equipos; f++) {

                if (strcmp(pruebas[k].equipos[f].id, id_equipo_eliminar) == 0) {

                    indice_equipo_eliminar = f;
                    break;
                }
            }
            if (indice_equipo_eliminar != -1) {

                for (int c = 0; c < pruebas[k].equipos[indice_equipo_eliminar].n_ciclistas; c++) {

                    free(pruebas[k].equipos[indice_equipo_eliminar].ciclistas[c].id);
                }

                free(pruebas[k].equipos[indice_equipo_eliminar].ciclistas);
                free(pruebas[k].equipos[indice_equipo_eliminar].id);
                free(pruebas[k].equipos[indice_equipo_eliminar].nombre);

                for (int l = indice_equipo_eliminar; l < pruebas[k].numero_de_equipos - 1; l++) {

                    pruebas[k].equipos[l] = pruebas[k].equipos[l + 1];

                }
                pruebas[k].numero_de_equipos--;
                printf("El equipo con identificador %s ha sido eliminado exitosamente de la prueba %s.\n", id_equipo_eliminar, pruebas[k].nombre);
                NE--;
                break;
            }
        }
        if (indice_equipo_eliminar == -1) {

            printf("No se encontró ningún equipo con el identificador %s.\n", id_equipo_eliminar);
        }
    }
break;
//------------------------------------------------------------------------------------------------------------------------------------------
case 6: // Guardar en memoria

printf("Ingrese el nombre del archivo donde desea guardar el estado del programa: "); scanf("%s", nombre_fichero);
Guardarf = fopen(nombre_fichero, "w");

    if (Guardarf == NULL) {
        printf("Error al abrir el archivo para guardar.\n");
        break;
    }

    // Guardar el número de ciclistas, equipos y pruebas
    fprintf(Guardarf, "%d\n", NC);
    fprintf(Guardarf, "%d\n", NE);
    fprintf(Guardarf, "%d\n", NP);

    // Guardar datos de ciclistas
    for (int k = 0; k < NC; k++) {
        fprintf(Guardarf, "%s %s %d\n", ciclistas[k].id, ciclistas[k].nombre, ciclistas[k].ano);
    }

    for (int k = 0; k < NP; k++) {
        // Guardar datos de pruebas
        fprintf(Guardarf, "%s %s %d\n", pruebas[k].clave, pruebas[k].nombre, pruebas[k].ano_celebracion);
        fprintf(Guardarf, "%d\n", pruebas[k].numero_de_equipos);

        for (int f = 0; f < pruebas[k].numero_de_equipos; f++) {
            // Guardar datos de equipos y sus ciclistas asociados
            fprintf(Guardarf, "%s %s %d\n", pruebas[k].equipos[f].id, pruebas[k].equipos[f].nombre, pruebas[k].equipos[f].n_ciclistas);
            for (int c = 0; c < pruebas[k].equipos[f].n_ciclistas; c++) {
                fprintf(Guardarf, "%s\n", pruebas[k].equipos[f].ciclistas[c].id);
            }
        }
    }

    fclose(Guardarf);
    printf("Guardado en %s.\n", nombre_fichero);

break;
//------------------------------------------------------------------------------------------------------------------------------------------
case 7: // Cargar desde archivo

printf("Ingrese el nombre del archivo desde donde desea cargar el estado del programa: "); scanf("%s", nombre_fichero);
FILE *Cargarf = fopen(nombre_fichero, "r");

    if (Cargarf == NULL) {
        printf("Error al abrir el archivo para cargar.\n");
        break;
    }

    // Leer el número de ciclistas, equipos y pruebas
    fscanf(Cargarf, "%d", &NC);
    fscanf(Cargarf, "%d", &NE);
    fscanf(Cargarf, "%d", &NP);

    pruebas = (struct Prueba *)realloc(pruebas, NP * sizeof(struct Prueba));

    // Leer datos de ciclistas
    for (int k = 0; k < NC; k++) {
        ciclistas[k].id = (char *)malloc(50 * sizeof(char));
        ciclistas[k].nombre = (char *)malloc(50 * sizeof(char));
        fscanf(Cargarf, "%s %s %d", ciclistas[k].id, ciclistas[k].nombre, &ciclistas[k].ano);
    }

    // Leer datos de pruebas y equipos
    for (int k = 0; k < NP; k++) {
        pruebas[k].clave = (char *)malloc(50 * sizeof(char));
        pruebas[k].nombre = (char *)malloc(50 * sizeof(char));
        fscanf(Cargarf, "%s %s %d", pruebas[k].clave, pruebas[k].nombre, &pruebas[k].ano_celebracion);
        fscanf(Cargarf, "%d", &pruebas[k].numero_de_equipos);
        pruebas[k].equipos = (struct Equipo *)malloc(pruebas[k].numero_de_equipos * sizeof(struct Equipo));

        for (int f = 0; f < pruebas[k].numero_de_equipos; f++) {
            pruebas[k].equipos[f].id = (char *)malloc(50 * sizeof(char));
            pruebas[k].equipos[f].nombre = (char *)malloc(50 * sizeof(char));
            fscanf(Cargarf, "%s %s %d", pruebas[k].equipos[f].id, pruebas[k].equipos[f].nombre, &pruebas[k].equipos[f].n_ciclistas);
            pruebas[k].equipos[f].ciclistas = (struct Ciclista *)malloc(pruebas[k].equipos[f].n_ciclistas * sizeof(struct Ciclista));

            for (int c = 0; c < pruebas[k].equipos[f].n_ciclistas; c++) {
                pruebas[k].equipos[f].ciclistas[c].id = (char *)malloc(50 * sizeof(char));
                fscanf(Cargarf, "%s", pruebas[k].equipos[f].ciclistas[c].id);
            }
        }
    }

    fclose(Cargarf);
    printf("Datos cargados desde %s.\n", nombre_fichero);

break;
//------------------------------------------------------------------------------------------------------------------------------------------
case 8: //Listar datos

    printf("\nCiclistas registrados:\n");
    for (int k = 0; k < NC; k++) {

        printf("%s %s %d\n", ciclistas[k].id, ciclistas[k].nombre, ciclistas[k].ano);

    }
    printf("\nEquipos registrados:\n");

    for (int k = 0; k < NP; k++) {

        if (pruebas[k].numero_de_equipos > 0) {

            for (int f = 0; f < pruebas[k].numero_de_equipos; f++) {

                printf("Equipo ID: %s, Nombre: %s, Numero de Ciclistas: %d\n", pruebas[k].equipos[f].id, pruebas[k].equipos[f].nombre, pruebas[k].equipos[f].n_ciclistas);
                printf("Ciclistas:\n");

                if (pruebas[k].equipos[f].ciclistas != NULL) {

                    for (int c = 0; c < pruebas[k].equipos[f].n_ciclistas; c++) {

                        if (pruebas[k].equipos[f].ciclistas[c].id != NULL) {

                            printf("%s\n", pruebas[k].equipos[f].ciclistas[c].id);
                        }
                    }
                }
                printf("\n");
            }
        }
    }
    printf("\nPruebas registradas:\n");

    for (int k = 0; k < NP; k++) {

        if (pruebas[k].clave != NULL && pruebas[k].nombre != NULL) {

            printf("%s %s %d\n", pruebas[k].clave, pruebas[k].nombre, pruebas[k].ano_celebracion);
        }
    }

break;
//------------------------------------------------------------------------------------------------------------------------------------------
case 9: //Salir

    free(pruebas);
    printf("\nPresiona enter para salir.");
    return 0;

break;
        }//end switch
    }//end for
}//end main
