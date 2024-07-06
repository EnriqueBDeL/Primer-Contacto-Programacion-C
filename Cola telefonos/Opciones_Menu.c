#include "Header.h"

tipo_cola crear(tipo_cola c) {
    c = (tipo_cola)malloc(sizeof(struct Cola));
    c->cabeza = 0;
    c->cola = 0;
    c->capacidad = 1; // Capacidad inicial
    c->valores = (Telefonos *)malloc(c->capacidad * sizeof(Telefonos));
    return c;
}

// Función para incrementar el índice de la cola circularmente
int suma_uno(tipo_cola c, int i) {
    return ((i + 1) % c->capacidad);
}

// Función para obtener el primer elemento de la cola
Telefonos primero(tipo_cola c) {
    return (c->valores[c->cabeza]);
}

// Función para insertar un teléfono en la cola
void insertar(tipo_cola c, Telefonos telefono) {
    if (suma_uno(c, c->cola) == c->cabeza) {
        // La cola está llena, se necesita expandir
        c->capacidad *= 2;
        c->valores = (Telefonos *)realloc(c->valores, c->capacidad * sizeof(Telefonos));
    }
    c->valores[c->cola] = telefono;
    c->cola = suma_uno(c, c->cola);
}

// Función para eliminar un teléfono de la cola
void eliminar(tipo_cola c) {
    if (c->cabeza == c->cola) {
        printf("Error: cola vacía\n");
        return;
    }

    c->cabeza = suma_uno(c, c->cabeza);
    // Si la cantidad de elementos es 1/4 de la capacidad, reducir la capacidad a la mitad
    if ((c->capacidad > 1) && ((c->cola - c->cabeza + c->capacidad) % c->capacidad) <= c->capacidad / 4) {
        c->capacidad /= 2;
        c->valores = (Telefonos *)realloc(c->valores, c->capacidad * sizeof(Telefonos));
    }
}


