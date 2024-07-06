#include "Header.h"
//------------------------------------------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------
//                               OPCIONES PRUEBAS
//---------------------------------------------------------------------------



void generarIdentificador(char *buffer,char *clave, int ano_celebracion) {

    sprintf(buffer, "%s_%d", clave, ano_celebracion);

}


struct Prueba* l_prueba_crear(void) {

    return NULL;
}


struct Prueba* l_prueba_insertar(ListaP lista, ListaP nueva_prueba) {

    if (lista == NULL) {
        return nueva_prueba;
    }

    struct Prueba* actual = lista;

    while (actual->psigP != NULL) {

        actual = actual->psigP;
    }

    actual->psigP = nueva_prueba;

    return lista;
}


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
struct Equipo* buscarEquipoPorID(ListaE lista,char *id) {

    struct Equipo *paux = lista;

    while (paux != NULL) {
        if (strcmp(paux->id, id) == 0) {
            return paux;
        }
        paux = paux->psigE;
    }

    return NULL;
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

void agregarPruebaDesdeArchivo(ListaP *lista_pruebas,char *nombre_fichero, ListaE lista_equipos) {

    FILE *archivo = fopen(nombre_fichero, "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_fichero);
        return;
    }

    struct Prueba *nueva_prueba = (struct Prueba*)malloc(sizeof(struct Prueba));

    nueva_prueba->clave = (char*)malloc(50 * sizeof(char));
    nueva_prueba->nombre = (char*)malloc(50 * sizeof(char));
    nueva_prueba->identificador = (char*)malloc(50 * sizeof(char));

    fscanf(archivo, "%s", nueva_prueba->clave);
    fscanf(archivo, "%s", nueva_prueba->nombre);
    fscanf(archivo, "%d", &nueva_prueba->ano_celebracion);


    generarIdentificador(nueva_prueba->identificador, nueva_prueba->clave, nueva_prueba->ano_celebracion);

    int numero_de_equipos;

    fscanf(archivo, "%d", &numero_de_equipos);
    nueva_prueba->numero_de_equipos = numero_de_equipos;

    nueva_prueba->equipos = NULL;


    for (int i = 0; i < numero_de_equipos; i++) {
        char id_equipo[50];
        fscanf(archivo, "%s", id_equipo);

        struct Equipo* equipo_encontrado = buscarEquipoPorID(lista_equipos, id_equipo);
        if (equipo_encontrado != NULL) {
            struct Equipo *nuevo_equipo = (struct Equipo*)malloc(sizeof(struct Equipo));
            nuevo_equipo->id = strdup(equipo_encontrado->id);
            nuevo_equipo->nombre = strdup(equipo_encontrado->nombre);

            nuevo_equipo->psigE = nueva_prueba->equipos;
            nueva_prueba->equipos = nuevo_equipo;
        }
    }

    *lista_pruebas = l_prueba_insertar(*lista_pruebas, nueva_prueba);
    fclose(archivo);
}



//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
void eliminarPrueba(ListaP *lista,char *identificador) {

    if (*lista == NULL) {
        printf("La lista de pruebas está vacía.\n");
        return;
    }

    struct Prueba *actual = *lista;
    struct Prueba *anterior = NULL;


    while (actual != NULL && strcmp(actual->identificador, identificador) != 0) {

        anterior = actual;
        actual = actual->psigP;
    }


    if (actual == NULL) {

        printf("No se encontró la prueba con identificador: %s.\n", identificador);
        return;
    }


    if (anterior == NULL) {

        *lista = actual->psigP;

    } else {

        anterior->psigP = actual->psigP;
    }


    free(actual->clave);
    free(actual->nombre);
    free(actual->identificador);
    free(actual);

    printf("La prueba con identificador: %s fue eliminada.\n", identificador);
}


void eliminarPruebaDesdeArchivo(ListaP *lista,char *nombre_fichero) {

    FILE *archivo = fopen(nombre_fichero, "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_fichero);
        return;
    }

    char identificador[50];

    fscanf(archivo, "%s", identificador);
    fclose(archivo);

    eliminarPrueba(lista, identificador);
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^







//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
void eliminarPruebaPorClave(ListaP *lista, char *clave) {


    if (*lista == NULL) {
        printf("La lista de pruebas está vacía.\n");
        return;
    }

    struct Prueba *actual = *lista;
    struct Prueba *anterior = NULL;

    while (actual != NULL) {

        if (strcmp(actual->clave, clave) == 0) {

            if (anterior == NULL) {

                *lista = actual->psigP;

            } else {

                anterior->psigP = actual->psigP;
            }


            free(actual->clave);
            free(actual->nombre);
            free(actual->identificador);

            struct Prueba *eliminada = actual;

            actual = actual->psigP;

            free(eliminada);

            printf("La prueba con clave: %s fue eliminada.\n", clave);

        } else {

            anterior = actual;
            actual = actual->psigP;
        }
    }
}


void eliminarPruebasDesdeArchivoClave(ListaP *lista, char *nombre_fichero) {

    FILE *archivo = fopen(nombre_fichero, "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_fichero);
        return;
    }

    char clave[50];


    while (fscanf(archivo, "%s", clave) == 1) {
        eliminarPruebaPorClave(lista, clave);
    }

    fclose(archivo);
}
//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[





//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
void l_prueba_listar(ListaP lista_pruebas) {
    struct Prueba* prueba = lista_pruebas;

    printf("\n\nLista de Pruebas:\n");

    while (prueba != NULL) {
        printf("\n > Identificador: %s | Clave: %s | Nombre: %s | Ano de celebracion: %d | Numero de equipos: %d\n",
               prueba->identificador, prueba->clave, prueba->nombre, prueba->ano_celebracion, prueba->numero_de_equipos);

        struct Equipo *equipo = prueba->equipos;

        while (equipo != NULL) {
            printf(" - Nombre del equipo: %s\n", equipo->nombre);
            equipo = equipo->psigE;
        }

        prueba = prueba->psigP;
        printf("---------------------------------------------------------------------------------------------------------------");
    }
}
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
