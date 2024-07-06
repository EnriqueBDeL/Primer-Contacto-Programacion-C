#include "Header.h"

P_NODO_ARBOL crearArbol()
{
	return NULL;
}



int esVacio(P_NODO_ARBOL a)
{
	return (a==NULL);
}


P_NODO_ARBOL alojar_nodo_arbol()
{
    return((P_NODO_ARBOL)malloc(sizeof(NODO_ARBOL))); /* Reservamos memoria */
}


P_NODO_ARBOL insertar(P_NODO_ARBOL arbol, Ciclistas ciclista)
/* Inserta el valor "i" en el ·rbol apuntado por "arbol" y devuelve un puntero
 a la raÌz del ·rbol resultado. Esta versiÛn no permite duplicados en el
 arbol */
{
    P_NODO_ARBOL p;    /* Para no perder la cabeza del arbol */

    if (arbol == NULL)
    {
        p = alojar_nodo_arbol();             /* Reservamos memoria */
        p->izq = p->der = NULL;             /* Acabamos de crearlo */
        p->ciclista.ID = strdup(ciclista.ID);
        p->ciclista.nombre = strdup(ciclista.nombre);
        return (p);
    }

    if (strcmp(arbol->ciclista.nombre,ciclista.nombre) == 0)    /* El valor ya existe. No hacemos nada porque no
                               permitimos valores duplicados */
        return (arbol);

    if (strcmp(arbol->ciclista.nombre,ciclista.nombre) > 0) /* "i" es menor que el valor que analizo, por tanto,
                           inserto a la izquierda */
        arbol->izq = insertar(arbol->izq, ciclista);
    else  /* "i" es mayor que el valor actual, entonces, inserto a la derecha */
        arbol->der = insertar(arbol->der, ciclista);

    return (arbol);
}




P_NODO_ARBOL encontrar (P_NODO_ARBOL arbol, char *nombre)
/* Devuelve un apuntador al nodo del arbol "arbol" cuyo contenido es "i", o
 NULL en caso de que no se encuentre este valor */
{
    if (arbol == NULL)    /* Arbol vacÌo por tanto devuelve NULL */
        return (NULL);

    if (strcmp(arbol->ciclista.nombre,nombre) == 0)    /* Hemos encontrado el valor */
        return (arbol);
    else if (strcmp(arbol->ciclista.nombre,nombre) > 0)    /* El valor actual es mayor que ir por tanto
                                   vamos hacia la izquierda */
        return(encontrar(arbol->izq, nombre));
    else    /* "i" es mayor que el valor actual */
        return(encontrar(arbol->der, nombre));
}


