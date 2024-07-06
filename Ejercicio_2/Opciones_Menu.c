#include "Header.h"

P_NODO buscar(P_NODO n, char *nombre) {

    P_NODO paux = n;

    while (paux != NULL) {

        if (strcmp(paux->nombre, nombre) == 0) {
            return paux;

        } else {
        paux = paux->sgte;
        }
    }
    return NULL;
}


void listarArcos(P_NODO n) {

    char nombre[100];

    printf("\nIntroduce el nombre del nodo: "); scanf("%s", nombre);

    P_ARCO arc;
    P_NODO paux = buscar(n, nombre);

    if (paux == NULL) {

        printf("\n***El nodo no existe");
    } else {

        printf("\nNodo: %s ", paux->nombre);
        arc = paux->apunta;

        while (arc != NULL) {

            printf("-> arco: %s (distancia: %.1f horas)", arc->apunta->nombre, arc->distancia);
        arc = arc->sgte;

        }
    }
}

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
/*

void listarNodos(P_NODO n) {

    P_NODO paux = n;

    if (paux == NULL) {

        printf("No hay nodos disponibles.\n");
        return;
    }

    printf("\nLista de nodos:\n");

    while (paux != NULL) {

        printf("Nodo: %s\n", paux->nombre);
        paux = paux->sgte;
    }
}

*/
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""



P_NODO nuevo(P_NODO *n, char *nombre) {

    P_NODO nodo_existente = buscar(*n, nombre);

    if (nodo_existente == NULL) {

        P_NODO paux = (P_NODO)malloc(sizeof(NODO));


        paux->nombre = strdup(nombre);
        paux->apunta = NULL;
        paux->distancia_minima = INFINITO;
        paux->anterior = NULL;
        paux->visitado = 0;
        paux->sgte = *n;
        *n = paux;

        return paux;
    } else {
        return nodo_existente;
    }
}

void arco(P_NODO origen, P_NODO destino, float distancia) {

    P_ARCO paux = (P_ARCO)malloc(sizeof(ARCO));

    paux->apunta = destino;
     paux->distancia = distancia;
  paux->sgte = origen->apunta;

    origen->apunta = paux;
}


void cargarDatos(P_NODO *n) {

    FILE *fp;
    char nombre_archivo[] = "aeropuertos.txt";

    char ciudad_origen[100];
    char ciudad_destino[100];
    float distancia;

    fp = fopen(nombre_archivo, "r");
    if (fp == NULL) {

        printf("Error al abrir el archivo %s\n", nombre_archivo);
        exit(1);
    }

    while (fscanf(fp, "%s %s %f", ciudad_origen, ciudad_destino, &distancia) == 3) {

        P_NODO aux_origen = nuevo(n, ciudad_origen);

     P_NODO aux_destino = nuevo(n, ciudad_destino);

        arco(aux_origen, aux_destino, distancia);
    }

    fclose(fp);
}

P_NODO extraerMinimo(P_NODO n) {

    P_NODO minNodo = NULL;

float minDistancia = INFINITO;

    P_NODO paux = n;

    while (paux != NULL) {
        if (!paux->visitado && paux->distancia_minima < minDistancia) {

              minDistancia = paux->distancia_minima;
            minNodo = paux;
        }
        paux = paux->sgte;
    }

    return minNodo;
}
// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


void dijkstra(P_NODO n, char *origen, char *destino) {

  P_NODO inicio = buscar(n, origen);
     P_NODO fin = buscar(n, destino);

    if (inicio == NULL || fin == NULL) {

        printf("Una o ambas ciudades no existen.\n");
        return;
    }

    P_NODO paux = n;

    while (paux != NULL) {

        paux->distancia_minima = INFINITO;
         paux->anterior = NULL;
        paux->visitado = 0;
        paux = paux->sgte;
    }
    inicio->distancia_minima = 0;

    P_NODO actual;

    while ((actual = extraerMinimo(n)) != NULL) {

        actual->visitado = 1;
        P_ARCO arc = actual->apunta;
        while (arc != NULL) {

            P_NODO vecino = arc->apunta;
            float nueva_distancia = actual->distancia_minima + arc->distancia;

            if (nueva_distancia < vecino->distancia_minima) {

                vecino->distancia_minima = nueva_distancia;
                vecino->anterior = actual;
            }
            arc = arc->sgte;
        }
    }

    if (fin->distancia_minima == INFINITO) {

        printf("No hay ruta desde %s a %s\n", origen, destino);
        return;
    }

    printf("Ruta mas corta desde %s a %s: ", origen, destino);

    P_NODO ruta = fin;

    while (ruta != NULL) {

        printf("%s ", ruta->nombre);
        ruta = ruta->anterior;
    }
    printf("\nDistancia: %.2f horas\n", fin->distancia_minima);
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


void comprobarValidez(P_NODO n) {

    P_NODO paux = n;

     int ciudades_incompletas = 0;

    while (paux != NULL) {

         if (paux->apunta == NULL) {

            printf("La ciudad %s no tiene conexiones.\n", paux->nombre);
            ciudades_incompletas++;
    }
        paux = paux->sgte;
    }

    if (ciudades_incompletas == 0) {

        printf("Todas las ciudades tienen conexiones.\n");
    }
}
