#include "Header.h"



P_NODO_ARBOL crearArbol() {
    return NULL;
}

int esVacio(P_NODO_ARBOL a) {
    return (a == NULL);
}

P_NODO_ARBOL alojar_nodo_arbol() {
    return ((P_NODO_ARBOL)malloc(sizeof(NODO_ARBOL))); /* Reservamos memoria */
}

P_NODO_ARBOL insertar(P_NODO_ARBOL arbol, Ciclistas *ciclista) {
    P_NODO_ARBOL p;    /* Para no perder la cabeza del arbol */

    if (arbol == NULL) {
        p = alojar_nodo_arbol();             /* Reservamos memoria */
        p->izq = p->der = NULL;              /* Acabamos de crearlo */
        p->ciclista = ciclista;
        return (p);
    }

    if (strcmp(arbol->ciclista->ID, ciclista->ID) == 0) {
        return arbol; /* El valor ya existe. No permitimos valores duplicados */
    }

    if (strcmp(arbol->ciclista->ID, ciclista->ID) > 0) {
        arbol->izq = insertar(arbol->izq, ciclista);
    } else {
        arbol->der = insertar(arbol->der, ciclista);
    }

    return arbol;
}

void recorrer_inorden_y_encontrar(P_NODO_ARBOL arbol, char *nombre, P_NODO_ARBOL *resultado) {
    if (arbol == NULL) {
        return;
    }
    recorrer_inorden_y_encontrar(arbol->izq, nombre, resultado);
    if (*resultado == NULL && strcmp(arbol->ciclista->nombre, nombre) == 0) {
        *resultado = arbol;
    }
    recorrer_inorden_y_encontrar(arbol->der, nombre, resultado);
}

P_NODO_ARBOL encontrar_por_nombre(P_NODO_ARBOL arbol, char *nombre) {
    P_NODO_ARBOL resultado = NULL;
    recorrer_inorden_y_encontrar(arbol, nombre, &resultado);
    return resultado;
}
