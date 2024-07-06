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
    return((P_NODO_ARBOL)malloc(sizeof(NODO_ARBOL)));
}


P_NODO_ARBOL insertar(P_NODO_ARBOL arbol, Peliculas pelicula)
/* Inserta el valor "i" en el ·rbol apuntado por "arbol" y devuelve un puntero
 a la raÌz del ·rbol resultado. Esta versiÛn no permite duplicados en el
 arbol */
{
    P_NODO_ARBOL p;    /* Para no perder la cabeza del arbol */

    if (arbol == NULL)
    {
        p = alojar_nodo_arbol();             /* Reservamos memoria */
        p->izq = p->der = NULL;             /* Acabamos de crearlo */
        p->pelicula.nombre = strdup(pelicula.nombre);
        p->pelicula.descripcion = strdup(pelicula.descripcion);
        p->pelicula.ano = pelicula.ano;
        p->pelicula.precio = pelicula.precio;
        return (p);
    }

    if (strcmp(arbol->pelicula.nombre,pelicula.nombre) == 0)    /* El valor ya existe. No hacemos nada porque no
                               permitimos valores duplicados */
        return (arbol);

    if (strcmp(arbol->pelicula.nombre,pelicula.nombre) > 0) /* "i" es menor que el valor que analizo, por tanto,
                           inserto a la izquierda */
        arbol->izq = insertar(arbol->izq, pelicula);
    else  /* "i" es mayor que el valor actual, entonces, inserto a la derecha */
        arbol->der = insertar(arbol->der, pelicula);

    return (arbol);
}

P_NODO_ARBOL encontrar (P_NODO_ARBOL arbol, char *nombre)
/* Devuelve un apuntador al nodo del arbol "arbol" cuyo contenido es "i", o
 NULL en caso de que no se encuentre este valor */
{
    if (arbol == NULL)    /* Arbol vacÌo por tanto devuelve NULL */
        return (NULL);

    if (strcmp(arbol->pelicula.nombre, nombre) == 0)    /* Hemos encontrado el valor */
        return (arbol);
    else if (strcmp(arbol->pelicula.nombre, nombre) > 0)    /* El valor actual es mayor que ir por tanto
                                   vamos hacia la izquierda */
        return(encontrar(arbol->izq, nombre));
    else    /* "i" es mayor que el valor actual */
        return(encontrar(arbol->der, nombre));
}




P_NODO_ARBOL borraNodo(P_NODO_ARBOL nodo)
{
	free(nodo);

    return NULL;
}

P_NODO_ARBOL eliminar(P_NODO_ARBOL a, char  *nombre){

    P_NODO_ARBOL q,p;

    if (a == NULL) return a;

    if (strcmp(a->pelicula.nombre, nombre) > 0) a-> izq = eliminar (a->izq, nombre);
    else if (strcmp(a->pelicula.nombre, nombre) < 0) a-> der = eliminar (a->der, nombre);
    else{
        if ((a->der == NULL)&&(a->izq == NULL)) //caso 1
            return borraNodo(a);
        //Caso 2
        if (a->der == NULL){
            q = a->izq;
            borraNodo (a);
            return q;
        }
        if (a->izq == NULL){
            q = a->der;
            borraNodo (a);
            return q;
        }
        //Caso 3
        for(p=a,q=a->izq; q->der != NULL; q = q->der)
            p=q;
        if (p!=a)
            p-> der = q->izq;
        else
            p->izq =q->izq;
        a->pelicula.nombre =q->pelicula.nombre;
        borraNodo(q);
    }
    return a;
}








void inOrder(P_NODO_ARBOL a)//Simetrico
{
	if (!esVacio(a))
	{
  		inOrder(a->izq);
  		printf("\nNombre: %s | Descipcion: %s | Ano de lanzamiento: %d | Precio entrada: %f", a->pelicula.nombre, a->pelicula.descripcion, a->pelicula.ano, a->pelicula.precio);
  		inOrder(a->der);
	}
}

