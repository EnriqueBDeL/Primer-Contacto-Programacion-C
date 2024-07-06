#include "Header.h"

pto_pila crear() {
    return NULL;
}

pto_pila push(pto_pila p, char *nombreS, char *nombreR, int edad) {


    pto_pila paux = (pto_pila)malloc(sizeof(nodo_pila));


    paux->superheroe = (Superheroes *)malloc(sizeof(Superheroes));

    paux->superheroe->nombreS = (char *)malloc(strlen(nombreS) + 1);
    strcpy(paux->superheroe->nombreS, nombreS);


    paux->superheroe->nombreR = (char *)malloc(strlen(nombreR) + 1);
    strcpy(paux->superheroe->nombreR, nombreR);

    paux->superheroe->edad = edad;
    paux->sgte = p;
    return paux;
}

pto_pila pop(pto_pila p, char *nombreS) {

    if (p == NULL) return NULL;

    pto_pila actual = p, anterior = NULL;

    while (actual != NULL && strcmp(actual->superheroe->nombreS, nombreS) != 0) {
        anterior = actual;
        actual = actual->sgte;
    }

    if (actual == NULL) {
        printf("Superhéroe no encontrado.\n");
        return p;
    }

    if (anterior == NULL) {
        p = actual->sgte;
    } else {
        anterior->sgte = actual->sgte;
    }

    printf("Superhéroe eliminado: %s\n", actual->superheroe->nombreS);
    free(actual->superheroe->nombreS);
    free(actual->superheroe->nombreR);
    free(actual->superheroe);
    free(actual);
    return p;
}

Superheroes *tope(pto_pila p) {
    if (p == NULL) return NULL;
    return p->superheroe;
}

pto_pila vaciar(pto_pila p) {
    while (p != NULL) {
        pto_pila paux = p;
        p = p->sgte;
        free(paux->superheroe->nombreS);
        free(paux->superheroe->nombreR);
        free(paux->superheroe);
        free(paux);
    }
    return NULL;
}

int es_vacia(pto_pila p) {
    return p == NULL;
}

void imprimir_pila(pto_pila p) {
    pto_pila paux = p;
    printf("El contenido de la pila es:\n");
    while (paux != NULL) {
        printf("Nombre Superhéroe: %s\n", paux->superheroe->nombreS);
        printf("Nombre Real: %s\n", paux->superheroe->nombreR);
        printf("Edad: %d\n", paux->superheroe->edad);
        paux = paux->sgte;
    }
}
