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



P_NODO_ARBOL encontrar (P_NODO_ARBOL arbol, int i) {

    if (arbol == NULL)
        return (NULL);

    if (arbol->control.ID == i)
        return (arbol);
    else if (arbol->control.ID > i)

        return(encontrar(arbol->izq, i));
    else
        return(encontrar(arbol->der, i));
}


P_NODO_ARBOL padre_de(P_NODO_ARBOL arbol, P_NODO_ARBOL nodo)

{
    if (arbol == NULL)
        return (NULL);

    if (arbol->izq == nodo || arbol->der == nodo)
        return (arbol);
    else if (arbol->control.ID > nodo->control.ID)

        return(padre_de(arbol->izq, nodo));
    else
        return(padre_de(arbol->der, nodo));
}



P_NODO_ARBOL insertar(P_NODO_ARBOL arbol,Controles control){

    P_NODO_ARBOL p;
    if (arbol == NULL)
    {
        p = alojar_nodo_arbol();
        p->izq = p->der = NULL;
        p->control.ID = control.ID;
        p->control.lugar = strdup(control.lugar);
        p->control.nivel_agua =control.nivel_agua;
        return (p);
    }

    if (arbol->control.ID == control.ID )
        return (arbol);

    if (arbol->control.ID > control.ID )

        arbol->izq = insertar(arbol->izq, control);
    else
        arbol->der = insertar(arbol->der, control);

    return (arbol);
}


P_NODO_ARBOL borraNodo(P_NODO_ARBOL nodo)
{
	free(nodo);

    return NULL;
}

P_NODO_ARBOL eliminar(P_NODO_ARBOL a, int i){

    P_NODO_ARBOL q,p;

    if (a == NULL) return a;

    if (a->control.ID > i) a-> izq = eliminar (a->izq, i);
    else if (a->control.ID < i) a-> der = eliminar (a->der, i);
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
        a->control.ID =q->control.ID;
        borraNodo(q);
    }
    return a;
}



void preOrder(P_NODO_ARBOL a)
{
	if (!esVacio(a))
	{
		preOrder(a->izq);
		preOrder(a->der);


        printf("(%i | %s | %f)-->", a->control.ID, a->control.lugar, a->control.nivel_agua);
    }

}

void postOrder(P_NODO_ARBOL a)//Previo
{
	if (!esVacio(a))
	{


        printf("(%i | %s | %f)-->", a->control.ID, a->control.lugar, a->control.nivel_agua);
		postOrder(a->izq);
		postOrder(a->der);
	}

}

void inOrder(P_NODO_ARBOL a)//Simetrico
{
	if (!esVacio(a))
	{
  		inOrder(a->izq);

        printf("(%i | %s | %f)-->", a->control.ID, a->control.lugar, a->control.nivel_agua);
  		inOrder(a->der);
	}
}


