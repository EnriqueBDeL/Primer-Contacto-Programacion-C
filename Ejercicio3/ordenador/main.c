
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define LONGITUD_MAX_PALABRA 100
#define CAPACIDAD_INICIAL 1000
#define NUM_BUCKETS 26

typedef struct {
    char** palabras;
    int cantidad;
    int capacidad;
    int comparaciones;
    int intercambios;
} Documento;

typedef struct Nodo {
    char* palabra;
    struct Nodo* siguiente;
} Nodo;

// ------------------ UTILIDADES ------------------

void limpiar_palabra(char* palabra) {
    int j = 0;
    for (int i = 0; palabra[i]; i++) {
        if (isalpha((unsigned char)palabra[i])) {
            palabra[j++] = tolower((unsigned char)palabra[i]);
        }
    }
    palabra[j] = '\0';
}

void agregar_palabra(Documento* doc, const char* palabra) {
    if (doc->cantidad == doc->capacidad) {
        doc->capacidad *= 2;
        doc->palabras = realloc(doc->palabras, doc->capacidad * sizeof(char*));
    }
    doc->palabras[doc->cantidad] = malloc(strlen(palabra) + 1);
    strcpy(doc->palabras[doc->cantidad], palabra);
    doc->cantidad++;
}

Documento leer_documento(const char* ruta) {
    Documento doc;
    doc.cantidad = 0;
    doc.capacidad = CAPACIDAD_INICIAL;
    doc.palabras = malloc(doc.capacidad * sizeof(char*));
    doc.comparaciones = 0;
    doc.intercambios = 0;

    FILE* archivo = fopen(ruta, "r");
    if (!archivo) {
        perror("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }

    char buffer[LONGITUD_MAX_PALABRA];
    while (fscanf(archivo, "%99s", buffer) == 1) {
        limpiar_palabra(buffer);
        if (strlen(buffer) > 0) {
            agregar_palabra(&doc, buffer);
        }
    }

    fclose(archivo);
    return doc;
}

void liberar_documento(Documento* doc) {
    for (int i = 0; i < doc->cantidad; i++) {
        free(doc->palabras[i]);
    }
    free(doc->palabras);
    doc->palabras = NULL;
    doc->cantidad = 0;
    doc->capacidad = 0;
}

void guardar_palabras(const char* archivo, Documento* doc) {
    FILE* salida = fopen(archivo, "w");
    if (!salida) {
        perror("No se pudo abrir el archivo de salida");
        return;
    }
    for (int i = 0; i < doc->cantidad; i++) {
        fprintf(salida, "%s\n", doc->palabras[i]);
    }
    fclose(salida);
}

// ------------------ INSERCIÓN DIRECTA ------------------

void ordenar_insercion(Documento* doc, int ascendente) {
    doc->comparaciones = 0;
    doc->intercambios = 0;

    for (int i = 1; i < doc->cantidad; i++) {
        char* clave = doc->palabras[i];
        int j = i - 1;

        while (j >= 0 && ((ascendente && strcmp(doc->palabras[j], clave) > 0) ||
                          (!ascendente && strcmp(doc->palabras[j], clave) < 0))) {
            doc->comparaciones++;
            doc->palabras[j + 1] = doc->palabras[j];
            doc->intercambios++;
            j--;
        }

        doc->comparaciones++;
        doc->palabras[j + 1] = clave;
        doc->intercambios++;
    }
}

// ------------------ BUCKET SORT ------------------

void insertar_ordenado_en_bucket(Nodo** cabeza, char* palabra, int ascendente, int* comparaciones, int* intercambios) {
    Nodo* nuevo = malloc(sizeof(Nodo));
    nuevo->palabra = palabra;
    nuevo->siguiente = NULL;

    if (*cabeza == NULL ||
        (ascendente && strcmp(palabra, (*cabeza)->palabra) < 0) ||
        (!ascendente && strcmp(palabra, (*cabeza)->palabra) > 0)) {
        (*comparaciones)++;
        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
        (*intercambios)++;
        return;
    }

    Nodo* actual = *cabeza;
    while (actual->siguiente != NULL &&
          ((ascendente && strcmp(palabra, actual->siguiente->palabra) > 0) ||
           (!ascendente && strcmp(palabra, actual->siguiente->palabra) < 0))) {
        (*comparaciones)++;
        actual = actual->siguiente;
    }

    (*comparaciones)++;
    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
    (*intercambios)++;
}

void ordenar_bucket(Documento* doc, int ascendente) {
    Nodo* buckets[NUM_BUCKETS] = {0};
    doc->comparaciones = 0;
    doc->intercambios = 0;

    for (int i = 0; i < doc->cantidad; i++) {
        char* palabra = doc->palabras[i];
        if (palabra[0] < 'a' || palabra[0] > 'z') continue;
        int indice = palabra[0] - 'a';
        insertar_ordenado_en_bucket(&buckets[indice], palabra, ascendente,
                                    &doc->comparaciones, &doc->intercambios);
    }

    int pos = 0;
    if (ascendente) {
        for (int i = 0; i < NUM_BUCKETS; i++) {
            Nodo* actual = buckets[i];
            while (actual) {
                doc->palabras[pos++] = actual->palabra;
                Nodo* temp = actual;
                actual = actual->siguiente;
                free(temp);
            }
        }
    } else {
        for (int i = NUM_BUCKETS - 1; i >= 0; i--) {
            Nodo* actual = buckets[i];
            while (actual) {
                doc->palabras[pos++] = actual->palabra;
                Nodo* temp = actual;
                actual = actual->siguiente;
                free(temp);
            }
        }
    }
}

// ------------------ MENÚ PRINCIPAL ------------------

void menu() {
    int algoritmo, orden;
    char archivo_entrada[100], archivo_salida[100];

    printf("=== ORDENACIÓN DE PALABRAS ===\n");

    printf("Archivo de entrada (.txt): ");
    scanf("%s", archivo_entrada);

    printf("Archivo de salida (.txt): ");
    scanf("%s", archivo_salida);

    printf("Elija algoritmo de ordenación:\n");
    printf("1 - Inserción directa\n");
    printf("2 - Bucket Sort\n");
    printf("Opción: ");
    scanf("%d", &algoritmo);

    printf("Orden:\n");
    printf("1 - Ascendente (A-Z)\n");
    printf("2 - Descendente (Z-A)\n");
    printf("Opción: ");
    scanf("%d", &orden);

    Documento doc = leer_documento(archivo_entrada);

    clock_t inicio = clock();

    if (algoritmo == 1) {
        ordenar_insercion(&doc, orden == 1);
    } else if (algoritmo == 2) {
        ordenar_bucket(&doc, orden == 1);
    } else {
        printf("Algoritmo no válido.\n");
        liberar_documento(&doc);
        return;
    }

    clock_t fin = clock();
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    guardar_palabras(archivo_salida, &doc);

    printf("\n--- RESULTADOS ---\n");
    printf("Palabras ordenadas: %d\n", doc.cantidad);
    printf("Comparaciones: %d\n", doc.comparaciones);
    printf("Intercambios: %d\n", doc.intercambios);
    printf("Tiempo total: %.6f segundos\n", tiempo);

    liberar_documento(&doc);
}

int main() {
    menu();
    return 0;
}
