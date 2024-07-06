#include "Header.h"



Lista l_int_crear(void)
{
    return NULL;
}

Lista l_int_insertar(Lista l, Posicion pindice, Coche datos)
{
    Nodo *paux = (Nodo *) malloc(sizeof(Nodo));

    if (paux != NULL) {
        paux->coche = datos;

        if (l == NULL) {
            paux->siguiente = NULL;
            l = paux;
        } else {
            paux->siguiente = pindice->siguiente;
            pindice->siguiente = paux;
        }
    }

    return l;
}

Lista l_int_inser_ppo(Lista l, Coche datos)
{
    Nodo *paux = (Nodo *) malloc(sizeof(Nodo));

    if (paux != NULL) {
        paux->coche = datos;

        if (l == NULL) {
            paux->siguiente = NULL;
            l = paux;
        } else {
            paux->siguiente = l;
            l = paux;
        }
    }

    return l;
}

Posicion l_int_primero(Lista l)
{
    return l;
}

Posicion l_int_ultimo(Lista l)
{
    Nodo *paux = l;
    while (paux != NULL && paux->siguiente != NULL) {
        paux = paux->siguiente;
    }
    return paux;
}

Posicion l_int_siguiente(Lista l, Posicion pindice)
{
    if (pindice != NULL) {
        return pindice->siguiente;
    } else {
        return NULL;
    }
}

Posicion l_int_anterior(Lista l, Posicion pindice)
{
    Nodo *paux = l;
    if (pindice == l || l == NULL) {
        return NULL;
    } else {
        while (paux->siguiente != pindice && paux->siguiente != NULL) {
            paux = paux->siguiente;
        }
        return paux;
    }
}

int l_int_longitud(Lista l)
{
    int contador = 0;
    Nodo *paux = l;
    while (paux != NULL) {
        contador++;
        paux = paux->siguiente;
    }
    return contador;
}

Posicion l_int_localizar(Lista l, const char *modelo)
{
    Nodo *paux = l;
    while (paux != NULL) {
        if (strcmp(paux->coche.modelo, modelo) == 0) {
            return paux;
        }
        paux = paux->siguiente;
    }
    return NULL;
}

Coche l_int_elemento(Lista l, Posicion pindice)
{
    if (pindice != NULL) {
        return pindice->coche;
    } else {
        Coche coche_vacio = {"", "", 0}; // Coche vacío en caso de posición nula
        return coche_vacio;
    }
}

Lista l_int_borrar(Lista l, const char *modelo)
{
    Nodo *paux, *previo = NULL, *borrar = NULL;

    // Buscar el nodo que contiene el coche con el modelo especificado
    paux = l;
    while (paux != NULL) {
        if (strcmp(paux->coche.modelo, modelo) == 0) {
            borrar = paux;
            break;
        }
        previo = paux;
        paux = paux->siguiente;
    }

    // Si se encontró el nodo, proceder a borrarlo
    if (borrar != NULL) {
        if (previo == NULL) { // El nodo a borrar es el primero
            l = l->siguiente;
        } else {
            previo->siguiente = borrar->siguiente;
        }
        free(borrar->coche.modelo);
        free(borrar->coche.comprador);
        free(borrar);
        printf("Coche con modelo '%s' eliminado.\n", modelo);
    } else {
        printf("No se encontró ningún coche con modelo '%s'.\n", modelo);
    }

    return l;
}

void l_int_destruir(Lista l)
{
    Nodo *pborra;
    while (l != NULL) {
        pborra = l;
        l = l->siguiente;
        free(pborra->coche.modelo);
        free(pborra->coche.comprador);
        free(pborra);
    }
}
