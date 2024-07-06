#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar los controles
typedef struct control {
    int ID;
    char *lugar;
    float nivel_agua;
} Controles;

// Estructura para el nodo del árbol binario
typedef struct nodo_arbol {
    Controles control;
    struct nodo_arbol *izq;
    struct nodo_arbol *der;
} NODO_ARBOL, *P_NODO_ARBOL;

// Declaración de funciones
int Menu();
P_NODO_ARBOL crearArbol();
int esVacio(P_NODO_ARBOL a);
P_NODO_ARBOL encontrar(P_NODO_ARBOL arbol, int i);
P_NODO_ARBOL padre_de(P_NODO_ARBOL arbol, P_NODO_ARBOL nodo);
P_NODO_ARBOL insertar(P_NODO_ARBOL arbol, Controles control);
P_NODO_ARBOL borraNodo(P_NODO_ARBOL nodo);
P_NODO_ARBOL eliminar(P_NODO_ARBOL a, int i);
void preOrder(P_NODO_ARBOL a);
void postOrder(P_NODO_ARBOL a);
void inOrder(P_NODO_ARBOL a);
#endif // HEADER_H_INCLUDED
