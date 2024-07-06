#include "Header.h"


void crear(tipo_cola *q) {
    q->cabeza = NULL;
    q->cola = NULL;
}

int es_vacia(tipo_cola *q) {
    return (q->cabeza == NULL);
}

void push(tipo_cola *q, Monumentos *m) {
    P_nodo_cola paux;
    paux = (P_nodo_cola)malloc(sizeof(nodo_cola));

    paux->monumento = m;
    paux->sgte = NULL;

    if (es_vacia(q)) {
        q->cabeza = q->cola = paux;
    } else {
        q->cola->sgte = paux;
        q->cola = paux;
    }
}

int pop(tipo_cola *q, char *nombre) {
    P_nodo_cola p, anterior = NULL;
    Monumentos *m = NULL;

    p = q->cabeza;
    while (p != NULL) {
        if (strcmp(p->monumento->nombre, nombre) == 0) {
            if (p == q->cabeza) {
                q->cabeza = q->cabeza->sgte;
            } else {
                anterior->sgte = p->sgte;
            }
            m = p->monumento;
            if (p == q->cola) {
                q->cola = anterior;
            }
            free(p);
            free(m->nombre);
            free(m);
            return 1;  // Éxito
        }
        anterior = p;
        p = p->sgte;
    }
    return 0;  // No encontrado
}

void vaciar(tipo_cola *q) {
    P_nodo_cola p, t;

    p = q->cabeza;
    while (p != NULL) {
        t = p;
        p = p->sgte;
        free(t->monumento->nombre); // Liberar nombre del monumento
        free(t->monumento);         // Liberar el monumento
        free(t);
    }
    q->cabeza = q->cola = NULL;
}

void imprimir_cola(tipo_cola cola) {
    P_nodo_cola paux;

    printf("Monumentos en la cola:\n");
    for (paux = cola.cabeza; paux != NULL; paux = paux->sgte) {
        printf("%s - Año: %d\n", paux->monumento->nombre, paux->monumento->ano);
    }
    printf("\n");
}
