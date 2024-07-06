#include "Header.h"



Lista l_int_crear(void) {
    return NULL;
}

Lista l_int_insertar(Lista l, Posicion pindice, char *modelo, char *comprador, int precio) {
    struct nodo *paux = (struct nodo *)malloc(sizeof(struct nodo));
    if (paux != NULL) {
        paux->modelo = (char *)malloc((strlen(modelo) + 1) * sizeof(char));
        strcpy(paux->modelo, modelo);

        paux->comprador = (char *)malloc((strlen(comprador) + 1) * sizeof(char));
        strcpy(paux->comprador, comprador);

        paux->precio = precio;

        if (l == NULL) {
            paux->psig = NULL;
            l = paux;
        } else {
            if (pindice == NULL) {
                // Insertar al principio
                paux->psig = l;
                l = paux;
            } else {
                paux->psig = pindice->psig;
                pindice->psig = paux;
            }
        }
    }
    return l;
}

Lista l_int_inser_ppo(Lista l, char *modelo, char *comprador, int precio) {
    return l_int_insertar(l, NULL, modelo, comprador, precio);
}

Posicion l_int_primero(Lista l) {
    return l;
}

Posicion l_int_ultimo(Lista l) {
    if (l == NULL) return NULL;
    struct nodo *paux = l;
    while (paux->psig != NULL) {
        paux = paux->psig;
    }
    return paux;
}

Posicion l_int_siguiente(Lista l, Posicion pindice) {
    if (pindice == NULL) return NULL;
    return pindice->psig;
}

Posicion l_int_anterior(Lista l, Posicion pindice) {
    if (pindice == NULL || l == NULL) return NULL;
    if (pindice == l) return NULL;
    struct nodo *paux = l;
    while (paux != NULL && paux->psig != pindice) {
        paux = paux->psig;
    }
    return paux;
}

int l_int_longitud(Lista l) {
    int contador = 0;
    struct nodo *paux = l;
    while (paux != NULL) {
        contador++;
        paux = paux->psig;
    }
    return contador;
}

Posicion l_int_localizar(Lista l, const int posicion) {
    if (posicion < 0 || l == NULL) return NULL;
    int c = 0;
    struct nodo *paux = l;
    while (c < posicion && paux != NULL) {
        paux = paux->psig;
        c++;
    }
    return paux;
}

char* l_int_elemento_modelo(Lista l, Posicion pindice) {
    if (pindice == NULL) {
        fprintf(stderr, "Error: Posicion no valida\n");
        exit(EXIT_FAILURE);
    }
    return pindice->modelo;
}

char* l_int_elemento_comprador(Lista l, Posicion pindice) {
    if (pindice == NULL) {
        fprintf(stderr, "Error: Posicion no valida\n");
        exit(EXIT_FAILURE);
    }
    return pindice->comprador;
}

int l_int_elemento_precio(Lista l, Posicion pindice) {
    if (pindice == NULL) {
        fprintf(stderr, "Error: Posicion no valida\n");
        exit(EXIT_FAILURE);
    }
    return pindice->precio;
}

Lista l_int_borrar(Lista l, Posicion pindice) {
    if (l == NULL || pindice == NULL) return l;
    if (l == pindice) {
        l = pindice->psig;
        free(pindice->modelo);
        free(pindice->comprador);
        free(pindice);
    } else {
        struct nodo *paux = l_int_anterior(l, pindice);
        if (paux != NULL) {
            paux->psig = pindice->psig;
            free(pindice->modelo);
            free(pindice->comprador);
            free(pindice);
        }
    }
    return l;
}

void l_int_destruir(Lista l) {
    struct nodo *pborra;
    while (l != NULL) {
        pborra = l;
        l = l->psig;
        free(pborra->modelo);
        free(pborra->comprador);
        free(pborra);
    }
}
