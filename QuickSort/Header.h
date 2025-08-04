#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
//---------------------------|
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int Menu();

void intercambio(int a[], int i, int j, int *intercambios);
void QuickSort(int a[], int ini, int fin, int *comparaciones, int *intercambios);

void QuickSortAleatorio(int a[], int ini, int fin, int *comparaciones, int *intercambios);



int *leerArchivo(const char *nombreArchivo, int *cantidad);
void guardarArchivo(const char *nombreArchivo, int *numeros, int cantidad);
//---------------------------|
#endif // HEADER_H_INCLUDED
