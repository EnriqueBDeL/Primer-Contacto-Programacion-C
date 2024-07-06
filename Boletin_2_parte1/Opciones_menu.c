#include "Header.h"
//------------------------------------------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------
//                               OPCIONES EQUIPOS
//---------------------------------------------------------------------------

struct Equipo* l_equipo_crear(void) {
    return NULL;
}



struct Equipo* l_equipo_insertar(struct Equipo *lista, struct Equipo *pindice, struct Equipo *nuevo_equipo) {

    if (pindice == NULL) {

        nuevo_equipo->psigE = lista;

        return nuevo_equipo;
    }

    nuevo_equipo->psigE = pindice->psigE;
    pindice->psigE = nuevo_equipo;

    return lista;
}




struct Equipo* l_equipo_ultimo(struct Equipo *lista) {

    if (lista == NULL){

            return NULL;
    }

    struct Equipo *paux = lista;

    while (paux->psigE != NULL) {

        paux = paux->psigE;
    }
    return paux;
}



//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
struct Ciclista* buscarCiclistaPorID(Lista lista, char *id) {

    struct Ciclista *paux = lista;

    while (paux != NULL) {

        if (strcmp(paux->id, id) == 0) {

            return paux;
        }
        paux = paux->psigC;
    }
    return NULL;
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$



void agregarEquipoDesdeArchivo(ListaE *lista, char *nombre_fichero, Lista lista_ciclistas) {

    FILE *archivo = fopen(nombre_fichero, "r");

    if (archivo == NULL) {

        printf("No se pudo abrir el archivo %s.\n", nombre_fichero);
        return;
    }

    struct Equipo *nuevo_equipo = (struct Equipo*)malloc(sizeof(struct Equipo));

    nuevo_equipo->id = (char*)malloc(50 * sizeof(char));

    nuevo_equipo->nombre = (char*)malloc(50 * sizeof(char));


    fscanf(archivo, "%s", nuevo_equipo->id);
    fscanf(archivo, "%s", nuevo_equipo->nombre);


    int n_ciclistas;

    fscanf(archivo, "%d", &n_ciclistas);

    nuevo_equipo->n_ciclistas = n_ciclistas;

    nuevo_equipo->ciclistas = NULL;


    for (int i = 0; i < n_ciclistas; i++) {


        struct Ciclista *nuevo_ciclista = (struct Ciclista*)malloc(sizeof(struct Ciclista));

        nuevo_ciclista->id = (char*)malloc(50 * sizeof(char));

        fscanf(archivo, "%s", nuevo_ciclista->id);


        struct Ciclista* ciclista_encontrado = buscarCiclistaPorID(lista_ciclistas, nuevo_ciclista->id);

        if (ciclista_encontrado != NULL) {

            nuevo_ciclista->nombre = strdup(ciclista_encontrado->nombre);
        } else {
            nuevo_ciclista->nombre = "Desconocido";
        }

        nuevo_ciclista->psigC = nuevo_equipo->ciclistas;
        nuevo_equipo->ciclistas = nuevo_ciclista;
    }

    *lista = l_equipo_insertar(*lista, l_equipo_ultimo(*lista), nuevo_equipo);
    fclose(archivo);
}




void eliminarEquipo(ListaE *lista, char *id) {

    if (*lista == NULL) {
        printf("La lista de equipos está vacía.\n");
        return;
    }

    struct Equipo *actual = *lista;

    struct Equipo *anterior = NULL;


    while (actual != NULL && strcmp(actual->id, id) != 0) {

        anterior = actual;
        actual = actual->psigE;
    }


    if (actual == NULL) {

        printf("No se encontró el equipo con ID: %s.\n", id);
        return;
    }


    if (anterior == NULL) {

        *lista = actual->psigE;
    } else {
        anterior->psigE = actual->psigE;
    }


    struct Ciclista *ciclista = actual->ciclistas;

    while (ciclista != NULL) {

        struct Ciclista *temp = ciclista;
        ciclista = ciclista->psigC;

        free(temp->id);
        free(temp->nombre);
        free(temp);
    }

    free(actual->id);
    free(actual->nombre);
    free(actual);

    printf("El equipo con ID: %s fue eliminado.\n", id);
}




void eliminarEquipoDesdeArchivo(ListaE *lista, char *nombre_fichero) {

    FILE *archivo = fopen(nombre_fichero, "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", nombre_fichero);
        return;
    }

    char id[50];

    fscanf(archivo, "%s", id);

    fclose(archivo);

    eliminarEquipo(lista, id);
}




//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
void l_equipo_listar(ListaE lista) {

printf("\n\nLista de Equipos:\n");

    struct Equipo* equipo = lista;

    while (equipo != NULL) {

        printf("\n > Equipo ID: %s | Nombre: %s | Numero de ciclistas: %d\n", equipo->id, equipo->nombre, equipo->n_ciclistas);

        struct Ciclista *ciclista = equipo->ciclistas;


        while (ciclista != NULL) {

            printf(" - Nombre del ciclista: %s\n", ciclista->nombre);

            ciclista = ciclista->psigC;
        }

        equipo = equipo->psigE;
        printf("---------------------------------------------------------------------------------------------------------------");
    }
}
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
