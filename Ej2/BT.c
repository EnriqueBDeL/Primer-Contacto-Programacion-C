#include "header.h"



int controlCategoria(char* categoria) {

    if (strcmp(categoria, "Bebidas") == 0){
            return 1;
    }

    if (strcmp(categoria, "Fresco") == 0){
            return 2;
    }

    if (strcmp(categoria, "Postre") == 0){
            return 3;
    }

    printf("Categoria desconocida: %s\n", categoria);
    return 0;

}

//-----------------------------------------------------------------------------------------------------------------------------|

int controlMarcas(char* marca, char marcas[][50], int* numMarcas) {

    for (int i = 0; i < *numMarcas; i++) {

        if (strcmp(marcas[i], marca) == 0){
                return i + 1;
        }
    }

    strcpy(marcas[*numMarcas], marca);
    (*numMarcas)++;
    return *numMarcas;
}

//-----------------------------------------------------------------------------------------------------------------------------|

int leerFichero(char* nombre_fichero, Producto productos[], int* numProductos, char marcas[][50], int* numMarcas) {

    FILE* fp = fopen(nombre_fichero, "r");

    if (fp == NULL) {
        printf("Error al abrir el archivo.\n");
        return -1;
    }


    char linea[400];

    while (fgets(linea, sizeof(linea), fp)) {

        Producto p;
        char* token = strtok(linea, ",");

        if (token) {
            strcpy(p.nombre, token);

            token = strtok(NULL, ",");

            if (token) {
                p.precio = atof(token);

                token = strtok(NULL, ",");

                if (token) {
                    p.marca = controlMarcas(token, marcas, numMarcas);

                    token = strtok(NULL, "\n");

                    if (token) {
                        p.categoria = controlCategoria(token);

                        if (p.categoria != 0) {
                            productos[(*numProductos)++] = p;
                        }
                    }
                }
            }
        }
    }

    fclose(fp);
    return *numProductos;
}


//-----------------------------------------------------------------------------------------------------------------------------|

int yaUsado(int lote[], int etapa, int candidato) {

    for (int i = 0; i < etapa; i++) {

        if (lote[i] == candidato){
                return 1;
        }
    }
    return 0;
}

//-----------------------------------------------------------------------------------------------------------------------------|

void ordenar(int lote[], int ordenado[]) {

    memcpy(ordenado, lote, sizeof(int) * 5);

    for (int i = 0; i < 4; i++) {

        for (int j = i + 1; j < 5; j++) {

            if (ordenado[i] > ordenado[j]) {

                int tmp = ordenado[i];
                ordenado[i] = ordenado[j];
                ordenado[j] = tmp;
            }
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------------|

int loteEnLista(int lote[], int listaLotesValidos[][5], int numLotes) {

    int ordenado[5];

    ordenar(lote, ordenado);  // Ordena el lote actual para comparar mejor

    for (int i = 0; i < numLotes; i++) {

        int coincide = 1;

        for (int j = 0; j < 5; j++) {

            if (listaLotesValidos[i][j] != ordenado[j]) {

                coincide = 0;
                break;
            }

        }
        if (coincide){
                return 1;
        }
    }
    return 0;
}

//-----------------------------------------------------------------------------------------------------------------------------|

int validacion(int lote[], Producto productos[], float maxPrecio) {

    float suma = 0.0f;
    int marcasContador[100] = {0};
    int categoriasContador[4] = {0};

    for (int i = 0; i < 5; i++) {

        Producto p = productos[lote[i]];

        suma += p.precio;

        marcasContador[p.marca]++;

        categoriasContador[p.categoria]++;

        if (marcasContador[p.marca] > 2){
                return 0;
        }
    }

    if (suma < 15 || suma > maxPrecio){
            return 0;
    }

    if (categoriasContador[1] == 0 || categoriasContador[2] == 0 || categoriasContador[3] == 0){
            return 0;
    }

    return 1;
}

//-----------------------------------------------------------------------------------------------------------------------------|

void imprimirLote(int lote[], Producto productos[], int numeroLote) {

    float total = 0.0f;

    printf("\n[ Lote valido N %d ]\n", numeroLote);

    for (int i = 0; i < 5; i++) {

        Producto p = productos[lote[i]];
        printf("Producto %d: %s | %.2f$ | Marca: %d | Categoria: %d\n", i + 1, p.nombre, p.precio, p.marca, p.categoria);
        total += p.precio;
    }

    printf("Total del lote: %.2f$\n", total);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|

void backtracking(int lote[], int etapa, float maxPrecio, Producto productos[], int listaLotesValidos[][5], int* numLotes, int* totalNodos, int* contadorLotes, int numProductos) {

    (*totalNodos)++;

    if (etapa == 5) {

        if (validacion(lote, productos, maxPrecio) && !loteEnLista(lote, listaLotesValidos, *numLotes)) {

            imprimirLote(lote, productos, ++(*contadorLotes));
            memcpy(listaLotesValidos[*numLotes], lote, sizeof(int) * 5);
            (*numLotes)++;

        }

        return;
    }

    for (int i = 0; i < numProductos; i++) {

        if (!yaUsado(lote, etapa, i)) {

            lote[etapa] = i;

            backtracking(lote, etapa + 1, maxPrecio, productos, listaLotesValidos, numLotes, totalNodos, contadorLotes, numProductos);

            lote[etapa] = -1;
        }
    }
}

//---------------------------------------------------------------------------------------------------------------------------------------|
