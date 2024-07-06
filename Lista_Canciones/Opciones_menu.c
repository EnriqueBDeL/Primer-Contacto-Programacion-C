#include "Header.h"

// Función para verificar si la lista está vacía
int es_vacia(P_NODO_LISTA lista) {
    return lista == NULL;
}

// Función para insertar una canción al final de la lista
P_NODO_LISTA insertar(P_NODO_LISTA lst, Canciones *cancion) {
    P_NODO_LISTA nuevo_nodo = (P_NODO_LISTA)malloc(sizeof(NODO_LISTA));
    nuevo_nodo->cancion = cancion;
    nuevo_nodo->siguiente = NULL;

    if (es_vacia(lst)) {
        nuevo_nodo->anterior = NULL;
        return nuevo_nodo;
    }

    P_NODO_LISTA temp = lst;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }
    temp->siguiente = nuevo_nodo;
    nuevo_nodo->anterior = temp;

    return lst;
}

// Función para borrar una canción de la lista por nombre
P_NODO_LISTA borrar(P_NODO_LISTA lst, char *nombre) {
    P_NODO_LISTA temp = lst;

    while (temp != NULL && strcmp(temp->cancion->nombre, nombre) != 0) {
        temp = temp->siguiente;
    }

    if (temp == NULL) {
        printf("ERROR, Cancion no encontrada\n");
        return lst;
    }

    if (temp->anterior != NULL) {
        temp->anterior->siguiente = temp->siguiente;
    } else {
        lst = temp->siguiente;
    }

    if (temp->siguiente != NULL) {
        temp->siguiente->anterior = temp->anterior;
    }

    printf("Cancion borrada: %s\n", temp->cancion->nombre);
    free(temp->cancion->nombre);
    free(temp->cancion);
    free(temp);

    return lst;
}

// Función para buscar una canción en la lista por nombre
P_NODO_LISTA buscar(P_NODO_LISTA lst, char *nombre) {
    P_NODO_LISTA laux;
    for (laux = lst; laux != NULL; laux = laux->siguiente)
        if (strcmp(laux->cancion->nombre, nombre) == 0)
            break;

    return laux;
}

// Función para imprimir la lista de canciones
void imprimir_lista(P_NODO_LISTA lst) {
    P_NODO_LISTA p;
    p = lst;

    while (p != NULL) {
        printf("Nombre: %s, Duracion: %d\n", p->cancion->nombre, p->cancion->duracion);
        p = p->siguiente;
    }
    printf("\n");
}
