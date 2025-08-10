#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
//--------------------------|

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void seleccion(int v[], int size, int *comparaciones, int *intercambios);
void guardarEnArchivo(char *nombreArchivo, int v[], int size);
int leerDesdeArchivo(char *nombreArchivo, int **v);


//--------------------------|
#endif // HEADER_H_INCLUDED
