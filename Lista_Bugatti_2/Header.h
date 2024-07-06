#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Definición de estructuras
struct nodo {
    char *modelo;       // Nombre del modelo del Bugatti
    char *comprador;    // Nombre del comprador
    int precio;         // Precio del Bugatti
    struct nodo *psig;
};

// Definición de tipos de datos
typedef struct nodo *Lista;
typedef struct nodo *Posicion;

// Declaración de funciones
int Menu();
Lista l_int_crear(void);
Lista l_int_insertar(Lista l, Posicion pindice, char *modelo, char *comprador, int precio);
Lista l_int_inser_ppo(Lista l, char *modelo, char *comprador, int precio);
Posicion l_int_primero(Lista l);
Posicion l_int_ultimo(Lista l);
Posicion l_int_siguiente(Lista l, Posicion pindice);
Posicion l_int_anterior(Lista l, Posicion pindice);
int l_int_longitud(Lista l);
Posicion l_int_localizar(Lista l, const int posicion);
char* l_int_elemento_modelo(Lista l, Posicion pindice);
char* l_int_elemento_comprador(Lista l, Posicion pindice);
int l_int_elemento_precio(Lista l, Posicion pindice);
Lista l_int_borrar(Lista l, Posicion pindice);
void l_int_destruir(Lista l);

#endif // HEADER_H_INCLUDED
