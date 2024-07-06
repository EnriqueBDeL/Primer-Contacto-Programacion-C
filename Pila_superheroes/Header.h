#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct superheroe{

    char *nombreS;
    char *nombreR;
    int edad;


}Superheroes;



typedef struct pila{

    Superheroes *superheroe;
    struct pila *sgte;

}nodo_pila, *pto_pila;



int Menu();
pto_pila crear();
pto_pila push(pto_pila p, char *nombreS, char *nombreR, int edad);
pto_pila pop(pto_pila p, char *nombreS);
Superheroes *tope(pto_pila p);
pto_pila vaciar(pto_pila p);
int es_vacia(pto_pila p);
void imprimir_pila(pto_pila p);

#endif // HEADER_H_INCLUDED
