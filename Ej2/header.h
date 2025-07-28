#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
//------------------------|

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
    char nombre[50];
    float precio;
    int marca;
    int categoria;
} Producto;


int controlCategoria(char* categoria);
int controlMarcas(char* marca, char marcas[][50], int* numMarcas);
int leerFichero(char* nombre_fichero, Producto productos[], int* numProductos, char marcas[][50], int* numMarcas);
int yaUsado(int lote[], int etapa, int candidato);
void ordenar(int lote[], int ordenado[]);
int loteEnLista(int lote[], int listaLotesValidos[][5], int numLotes);
int validacion(int lote[], Producto productos[], float maxPrecio);
void imprimirLote(int lote[], Producto productos[], int numeroLote);
void backtracking(int lote[], int etapa, float maxPrecio, Producto productos[], int listaLotesValidos[][5], int* numLotes, int* totalNodos, int* contadorLotes, int numProductos);

//---------------------------|
#endif // HEADER_H_INCLUDED
