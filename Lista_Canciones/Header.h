#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cancion {
    char *nombre;
    int duracion;
} Canciones;

typedef struct t_lista {
    Canciones *cancion;
    struct t_lista *siguiente;  // puntero a siguiente
    struct t_lista *anterior;   // puntero a anterior
} NODO_LISTA, *P_NODO_LISTA;

int Menu();
int es_vacia(P_NODO_LISTA lista);
P_NODO_LISTA insertar(P_NODO_LISTA lst, Canciones *cancion);
P_NODO_LISTA borrar(P_NODO_LISTA lst, char *nombre);
P_NODO_LISTA buscar(P_NODO_LISTA lst, char *nombre);
void imprimir_lista(P_NODO_LISTA lst);

#endif // HEADER_H_INCLUDED
