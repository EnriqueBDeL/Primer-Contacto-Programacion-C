#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct pelicula{

     char *nombre;
     char *descripcion;
    int ano;
     float precio;


}Peliculas;





typedef struct nodo_arbol
{
    Peliculas pelicula;                     /* Campo donde almacenaremos el valor */
    struct nodo_arbol *izq;    /* Puntero al hijo izquierdo */
    struct nodo_arbol *der;      /* Puntero al hijo derecho */
}NODO_ARBOL, *P_NODO_ARBOL;


int Menu();
P_NODO_ARBOL crearArbol();
int esVacio(P_NODO_ARBOL a);
P_NODO_ARBOL alojar_nodo_arbol();
P_NODO_ARBOL insertar(P_NODO_ARBOL arbol, Peliculas pelicula);
void inOrder(P_NODO_ARBOL a);
P_NODO_ARBOL encontrar (P_NODO_ARBOL arbol, char *nombre);
P_NODO_ARBOL eliminar(P_NODO_ARBOL a, char  *nombre);

#endif // HEADER_H_INCLUDED
