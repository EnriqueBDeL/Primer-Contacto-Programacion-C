#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct monumento {
    char *nombre;
    int ano;
} Monumentos;

typedef struct n_cola {
    Monumentos *monumento;
    struct n_cola *sgte;
} nodo_cola, *P_nodo_cola;

typedef struct t_cola {
    P_nodo_cola cabeza;
    P_nodo_cola cola;
} tipo_cola;


int Menu();
void crear(tipo_cola *q);
int es_vacia(tipo_cola *q);
void push(tipo_cola *q, Monumentos *m);
int pop(tipo_cola *q, char *nombre);
void vaciar(tipo_cola *q);
void imprimir_cola(tipo_cola cola);


#endif // HEADER_H_INCLUDED
