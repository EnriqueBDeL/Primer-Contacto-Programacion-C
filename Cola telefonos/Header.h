#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct telefono {

    char *id;
    char *modelo;
    int anno_creacion;
    float precio;

} Telefonos;



typedef struct Cola {
    int cabeza, cola;
    int capacidad;
    Telefonos *valores;
} *tipo_cola;


int Menu();


tipo_cola crear(tipo_cola c);
int suma_uno(tipo_cola c, int i);
Telefonos primero(tipo_cola c);
void insertar(tipo_cola c, Telefonos telefono);
void eliminar(tipo_cola c);


#endif // HEADER_H_INCLUDED
