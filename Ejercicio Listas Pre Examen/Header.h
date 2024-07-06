#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
//--------------------------------------------------------------|

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

struct nodo {
    char *nombre;
    int fecha_lanzamiento;
    float precio;
    struct nodo *psig;
};

typedef struct nodo Nodo;
typedef struct nodo *Lista;
typedef struct nodo *Posicion;

// DEFINICION DE FUNCIONES
Lista l_int_crear(void);
Lista l_int_insertar(Lista l, Posicion pindice, char *nombre, int fecha_lanzamiento, float precio);
Lista l_int_inser_ppo(Lista l, char *nombre, int fecha_lanzamiento, float precio);
Nodo* l_int_primero(Lista l);
Nodo* l_int_ultimo(Lista l);
Nodo* l_int_siguiente(Lista l, Posicion pindice);
Nodo* l_int_anterior(Lista l, Posicion pindice);
int l_int_longitud(Lista l);
Nodo* l_int_localizar(Lista l, const char *nombre);
char* l_int_nombre(Lista l, Posicion pindice);
void l_int_borrar(Lista *l, Posicion pindice);
void l_int_destruir(Lista l);

int Menu();
//--------------------------------------------------------------|
#endif // HEADER_H_INCLUDED
