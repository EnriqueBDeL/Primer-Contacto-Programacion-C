#include "Header.h"
//------------------------------------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------
//                               OPCIONES CICLISTAS
//---------------------------------------------------------------------------



char *Anadir_Ciclista (char *buffer){
    char *p;
    int l = strlen(buffer);
    p = (char *)malloc(sizeof(char)*(l+1));
    strcpy(p,buffer);
    return p;
}



struct Ciclista* l_int_crear(void){

  return (NULL);

};



struct Ciclista* l_int_insertar(struct Ciclista *l, struct Ciclista *pindice, struct Ciclista *nuevo_ciclista) {

    if (pindice == NULL) {

        nuevo_ciclista->psigC = l;

        return nuevo_ciclista;
    }

    nuevo_ciclista->psigC = pindice->psigC;
    pindice->psigC = nuevo_ciclista;

    return l;
}



struct Ciclista* l_int_inser_ppo(struct Ciclista *l,struct Ciclista *pindice, char *p){

  struct Ciclista *paux;

    paux = (struct Ciclista *) malloc(sizeof (struct Ciclista));

    if (paux != NULL) {
       //paux->elemento = n;
        paux->id = p;
       if (l == NULL) {

         paux->psigC = NULL;
          l = paux;


       }
       else {


        paux->psigC = pindice->psigC;
        pindice->psigC = paux;

    }
   }

    return(l);


};





struct Ciclista* l_int_primero(struct Ciclista *l){

    return (l);
}



struct Ciclista* l_int_ultimo(struct Ciclista *l) {
    if (l == NULL) return NULL;

    struct Ciclista *paux = l;

    while (paux->psigC != NULL)
        paux = paux->psigC;
    return paux;
}





//................................................................................................
struct Ciclista* l_int_siguiente(struct Ciclista *l, struct Ciclista *pindice){

    return (pindice->psigC);
}

struct Ciclista* l_int_anterior(struct Ciclista *l, struct Ciclista *pindice){

    struct Ciclista *paux;

    if ((pindice == l) || (l == NULL)) return(NULL);

    else {

      paux = l;
      while (paux->psigC != pindice)
        paux=paux->psigC;
      return (paux);
   }
}
//................................................................................................



void agregarCiclistasAutomaticamente(Lista *lista) {

    FILE *Ciclistaf;

    char nombre_fichero[80];

    for (int num = 1; num <= 10; num++) {

        sprintf(nombre_fichero, "Corredor%d.txt", num);
        Ciclistaf = fopen(nombre_fichero, "r");

        if (Ciclistaf == NULL) {
            printf("\nERROR: No se ha podido abrir el archivo %s.\n", nombre_fichero);
            continue;
        }

        struct Ciclista *nuevo_ciclista = (struct Ciclista*)malloc(sizeof(struct Ciclista));


        nuevo_ciclista->id = (char*)malloc(50 * sizeof(char));

        nuevo_ciclista->nombre = (char*)malloc(50 * sizeof(char));

        fscanf(Ciclistaf, "%s", nuevo_ciclista->id);
        fscanf(Ciclistaf, "%s", nuevo_ciclista->nombre);
        fscanf(Ciclistaf, "%d", &nuevo_ciclista->ano);

        nuevo_ciclista->psigC = NULL;

        *lista = l_int_insertar(*lista, l_int_ultimo(*lista), nuevo_ciclista);

        fclose(Ciclistaf);
    }
}




//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
void l_int_listar(Lista l) {

    struct Ciclista* paux = l;

    while (paux != NULL) {

        printf("ID: %s, Nombre: %s, Ano: %d\n", paux->id, paux->nombre, paux->ano);

        paux = paux->psigC;
    }
}
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
