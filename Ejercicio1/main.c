#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TABLA 128
#define CLAVE_MAX 20
#define NOMBRE_MAX 50
#define EMAIL_MAX 50
#define FECHA_MAX 12

typedef struct Empleado {
    char nombre[NOMBRE_MAX];
    char dni[CLAVE_MAX];
    char email[EMAIL_MAX];
    char fecha_nacimiento[FECHA_MAX];
    struct Empleado* siguiente;
} Empleado;

// Tabla hash: array de punteros a listas de empleados
typedef struct {
    Empleado* tabla[TAM_TABLA];
} TablaHash;

// Hash simple por suma ASCII
int funcion_hash(const char* clave) {
    int suma = 0;
    for (int i = 0; clave[i]; i++) {
        suma += clave[i];
    }
    return suma % TAM_TABLA;
}

// Inicializa tabla
TablaHash* crear_tabla() {
    TablaHash* tabla = malloc(sizeof(TablaHash));
    for (int i = 0; i < TAM_TABLA; i++) {
        tabla->tabla[i] = NULL;
    }
    return tabla;
}

// Crea un nuevo nodo Empleado
Empleado* crear_empleado(const char* nombre, const char* dni, const char* email, const char* fecha) {
    Empleado* emp = malloc(sizeof(Empleado));
    strncpy(emp->nombre, nombre, NOMBRE_MAX);
    strncpy(emp->dni, dni, CLAVE_MAX);
    strncpy(emp->email, email, EMAIL_MAX);
    strncpy(emp->fecha_nacimiento, fecha, FECHA_MAX);
    emp->siguiente = NULL;
    return emp;
}

// Inserta usando encadenamiento
void insertar(TablaHash* tabla, const char* nombre, const char* dni, const char* email, const char* fecha) {
    int indice = funcion_hash(dni);
    Empleado* nuevo = crear_empleado(nombre, dni, email, fecha);
    nuevo->siguiente = tabla->tabla[indice];
    tabla->tabla[indice] = nuevo;
}

// Leer CSV e insertar en la tabla
void leer_csv_e_insertar(TablaHash* tabla, const char* ruta) {
    FILE* archivo = fopen(ruta, "r");
    if (!archivo) {
        perror("Error al abrir CSV");
        exit(EXIT_FAILURE);
    }

    char linea[256];
    fgets(linea, sizeof(linea), archivo); // Saltar encabezado

    while (fgets(linea, sizeof(linea), archivo)) {
        char* nombre = strtok(linea, ",");
        char* dni = strtok(NULL, ",");
        char* email = strtok(NULL, ",");
        char* fecha = strtok(NULL, ",\n");

        if (nombre && dni && email && fecha) {
            insertar(tabla, nombre, dni, email, fecha);
        }
    }

    fclose(archivo);
}

// Imprimir contenido de la tabla
void imprimir_tabla(TablaHash* tabla) {
    for (int i = 0; i < TAM_TABLA; i++) {
        printf("Índice %d:\n", i);
        Empleado* actual = tabla->tabla[i];
        while (actual) {
            printf("  %s | %s | %s | %s\n",
                   actual->nombre, actual->dni, actual->email, actual->fecha_nacimiento);
            actual = actual->siguiente;
        }
    }
}

// Liberar memoria
void liberar_tabla(TablaHash* tabla) {
    for (int i = 0; i < TAM_TABLA; i++) {
        Empleado* actual = tabla->tabla[i];
        while (actual) {
            Empleado* tmp = actual;
            actual = actual->siguiente;
            free(tmp);
        }
    }
    free(tabla);
}

// MAIN
int main() {
    TablaHash* tabla = crear_tabla();

    leer_csv_e_insertar(tabla, "datos-personales.csv");

    printf("Contenido de la tabla hash (encadenamiento):\n");
    imprimir_tabla(tabla);

    liberar_tabla(tabla);
    return 0;
}
