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



P_NODO_ARBOL insertar(P_NODO_ARBOL arbol, Mandalorianos mandaloriano)

{
    P_NODO_ARBOL p;    /* Para no perder la cabeza del arbol */

    if (arbol == NULL)
    {
        p = alojar_nodo_arbol();             /* Reservamos memoria */
        p->izq = p->der = NULL;             /* Acabamos de crearlo */
        p->mandaloriano.nombre = strdup(mandaloriano.nombre);
        p->mandaloriano.apodo = strdup(mandaloriano.apodo);
        p->mandaloriano.edad = mandaloriano.edad ;
        return (p);
    }

    if (strcmp( arbol->mandaloriano.nombre,mandaloriano.nombre) == 0)    /* El valor ya existe. No hacemos nada porque no
                               permitimos valores duplicados */
        return (arbol);

    if (strcmp(arbol->mandaloriano.nombre,mandaloriano.nombre) > 0) /* "i" es menor que el valor que analizo, por tanto,
                           inserto a la izquierda */
        arbol->izq = insertar(arbol->izq, mandaloriano);
    else  /* "i" es mayor que el valor actual, entonces, inserto a la derecha */
        arbol->der = insertar(arbol->der, mandaloriano);

    return (arbol);
}



P_NODO_ARBOL encontrar (P_NODO_ARBOL arbol, char *nombre)


{
    if (arbol == NULL)    /* Arbol vacÌo por tanto devuelve NULL */
        return (NULL);

    if (strcmp(arbol->mandaloriano.nombre, nombre) == 0)    /* Hemos encontrado el valor */
        return (arbol);
    else if (strcmp(arbol->mandaloriano.nombre, nombre)  > 0)    /* El valor actual es mayor que ir por tanto
                                   vamos hacia la izquierda */
        return(encontrar(arbol->izq, nombre));
    else    /* "i" es mayor que el valor actual */
        return(encontrar(arbol->der, nombre));
}



void postOrder(P_NODO_ARBOL a)//Posterior
{
	if (!esVacio(a))
	{
		postOrder(a->izq);
		postOrder(a->der);


        printf("( %s | %s | %d )-->", a->mandaloriano.nombre, a->mandaloriano.apodo, a->mandaloriano.edad);
    }

}

P_NODO_ARBOL borraNodo(P_NODO_ARBOL nodo)
{
	free(nodo);

    return NULL;
}


P_NODO_ARBOL eliminar(P_NODO_ARBOL a, char *apodo){

    P_NODO_ARBOL q,p;

    if (a == NULL) return a;

    if (strcmp(a->mandaloriano.apodo,apodo) > 0) a-> izq = eliminar (a->izq, apodo);
    else if (strcmp(a->mandaloriano.apodo,apodo) < 0) a-> der = eliminar (a->der, apodo);
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
        a->mandaloriano.apodo=q->mandaloriano.apodo;
        borraNodo(q);
    }
    return a;
}

