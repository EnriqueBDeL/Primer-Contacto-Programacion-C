#include "Header.h"


// Funciones de la lista enlazada
Lista l_int_crear(void) {
    return NULL;
}

Lista l_int_insertar(Lista l, Posicion pindice, char *nombre, int fecha_lanzamiento, float precio) {
    Nodo *paux = (Nodo *)malloc(sizeof(Nodo));
    if (paux != NULL) {
        paux->nombre = strdup(nombre);
        paux->fecha_lanzamiento = fecha_lanzamiento;
        paux->precio = precio;
        paux->psig = NULL;

        if (l == NULL) {
            l = paux;
        } else {
            paux->psig = pindice->psig;
            pindice->psig = paux;
        }
    }
    return l;
}

Lista l_int_inser_ppo(Lista l, char *nombre, int fecha_lanzamiento, float precio) {
    Nodo *paux = (Nodo *)malloc(sizeof(Nodo));
    if (paux != NULL) {
        paux->nombre = strdup(nombre);
        paux->fecha_lanzamiento = fecha_lanzamiento;
        paux->precio = precio;
        paux->psig = l;
        l = paux;
    }
    return l;
}

Nodo* l_int_primero(Lista l) {
    return l;
}

Nodo* l_int_ultimo(Lista l) {
    Nodo *paux = l;
    while (paux != NULL && paux->psig != NULL)
        paux = paux->psig;
    return paux;
}

Nodo* l_int_siguiente(Lista l, Posicion pindice) {
    if (pindice != NULL)
        return pindice->psig;
    else
        return NULL;
}

Nodo* l_int_anterior(Lista l, Posicion pindice) {
    Nodo *paux;
    if ((pindice == l) || (l == NULL)) return NULL;
    else {
        paux = l;
        while (paux->psig != pindice)
            paux = paux->psig;
        return paux;
    }
}

int l_int_longitud(Lista l) {
    int contador = 0;
    Nodo *paux = l;
    while (paux != NULL) {
        contador++;
        paux = paux->psig;
    }
    return contador;
}

Nodo* l_int_localizar(Lista l, const char *nombre) {
    Nodo* paux = l;
    while (paux != NULL) {
        if (strcmp(paux->nombre, nombre) == 0)
            return paux;
        paux = paux->psig;
    }
    return NULL;
}

char* l_int_nombre(Lista l, Posicion pindice) {
    if (pindice != NULL)
        return pindice->nombre;
    else
        return NULL;
}

void l_int_borrar(Lista *l, Posicion pindice) {
    if (*l == pindice) {
        *l = pindice->psig;
        free(pindice->nombre);
        free(pindice);
    } else {
        Nodo *paux = *l;
        while (paux != NULL && paux->psig != pindice)
            paux = paux->psig;
        if (paux != NULL) {
            paux->psig = pindice->psig;
            free(pindice->nombre);
            free(pindice);
        }
    }
}

void l_int_destruir(Lista l) {
    Nodo *pborra;
    while (l != NULL) {
        pborra = l;
        l = l->psig;
        free(pborra->nombre);
        free(pborra);
    }
}
