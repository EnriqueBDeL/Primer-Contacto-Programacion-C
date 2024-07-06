#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
//---------------------------------------------------------------------------------------------------------|
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITO 99999 //Es un valor muy alto para el Dijkstra


typedef struct arco {

    struct arco *sgte;
    struct nodo *apunta;

    float distancia;

} ARCO, *P_ARCO;



typedef struct nodo {

    char *nombre;

    struct nodo *sgte;
    struct arco *apunta;

    float distancia_minima;

    struct nodo *anterior;

    int visitado;
} NODO, *P_NODO;




int Menu();


P_NODO buscar(P_NODO n, char *nombre);

void listarArcos(P_NODO n);
void listarNodos(P_NODO n);

P_NODO nuevo(P_NODO *n, char *nombre);

void arco(P_NODO origen, P_NODO destino, float distancia);
void cargarDatos(P_NODO *n);
void dijkstra(P_NODO n, char *origen, char *destino);
void comprobarValidez(P_NODO n);
//---------------------------------------------------------------------------------------------------------|
#endif // HEADER_H_INCLUDED
