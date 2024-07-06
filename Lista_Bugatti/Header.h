#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura del coche
typedef struct coche {
    char *modelo;
    char *comprador;
    int precio;
} Coche;

// Estructura del nodo de la lista enlazada
typedef struct nodo {
    Coche coche;
    struct nodo *siguiente;
} Nodo;

// Definición del tipo Lista y Posicion
typedef Nodo *Lista;
typedef Nodo *Posicion;

int Menu();
Lista l_int_crear(void);
Lista l_int_insertar(Lista l, Posicion pindice, Coche datos);
Lista l_int_inser_ppo(Lista l, Coche datos);
Posicion l_int_primero(Lista l);
Posicion l_int_ultimo(Lista l);
Posicion l_int_siguiente(Lista l, Posicion pindice);
Posicion l_int_anterior(Lista l, Posicion pindice);
int l_int_longitud(Lista l);
Posicion l_int_localizar(Lista l, const char *modelo);
Coche l_int_elemento(Lista l, Posicion pindice);
Lista l_int_borrar(Lista l, const char *modelo);
void l_int_destruir(Lista l);

#endif // HEADER_H_INCLUDED
