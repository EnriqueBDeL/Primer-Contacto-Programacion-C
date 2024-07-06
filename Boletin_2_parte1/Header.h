#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
//------------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//------------------------------------------------------------------------------------------------------------------------------------------
struct Ciclista {
    char *id;
    char *nombre;
    int ano;
    struct Ciclista *psigC;
};
//------------------------------------------------------------------------------------------------------------------------------------------
struct Equipo {
    char *id;
    char *nombre;
    int n_ciclistas;
    struct Ciclista *ciclistas;
    struct Equipo *psigE;
};
//------------------------------------------------------------------------------------------------------------------------------------------
struct Prueba {
    char *clave;
    char *nombre;
    char *identificador;
    int ano_celebracion;
    int numero_de_equipos;
    struct Equipo *equipos;
    struct Prueba *psigP;
};




  int Menu();



    typedef struct Ciclista *Lista;
    typedef struct Ciclista *Posicion;

    typedef struct Equipo *ListaE;
    typedef struct Equipo *PosicionE;

    typedef struct Equipo *ListaE;
    typedef struct Equipo *PosicionE;

    typedef struct Prueba *ListaP;
    typedef struct Prueba *PosicionP;




//Ciclistas
char *Anadir_Ciclista(char *buffer);
struct Ciclista* l_int_crear(void);
struct Ciclista* l_int_insertar(struct Ciclista *l, struct Ciclista *pindice, struct Ciclista *nuevo_ciclista);
struct Ciclista* l_int_inser_ppo(struct Ciclista *l,struct Ciclista *pindice, char *p);
struct Ciclista* l_int_primero(struct Ciclista *l);
struct Ciclista* l_int_ultimo(struct Ciclista *l);
struct Ciclista* l_int_siguiente(struct Ciclista *l, struct Ciclista *pindice);
void agregarCiclistasAutomaticamente(Lista *lista);
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
void l_int_listar(Lista l);
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""



//Equipos
struct Equipo* l_equipo_crear(void);
struct Equipo* l_equipo_insertar(struct Equipo *lista, struct Equipo *pindice, struct Equipo *nuevo_equipo);
struct Equipo* l_equipo_ultimo(struct Equipo *lista);
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
struct Ciclista* buscarCiclistaPorID(Lista lista, char *id);
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void agregarEquipoDesdeArchivo(ListaE *lista, char *nombre_fichero, Lista lista_ciclistas);
void eliminarEquipo(ListaE *lista, char *id);
void eliminarEquipoDesdeArchivo(ListaE *lista, char *nombre_fichero);
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
void l_equipo_listar(ListaE lista);
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""



//Pruebas

void generarIdentificador(char *buffer,char *clave, int ano_celebracion);
struct Prueba* l_prueba_crear(void);
struct Prueba* l_prueba_insertar(ListaP lista, ListaP nueva_prueba);
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
struct Equipo* buscarEquipoPorID(ListaE lista,char *id);
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void agregarPruebaDesdeArchivo(ListaP *lista_pruebas,char *nombre_fichero, ListaE lista_equipos);
void eliminarPrueba(ListaP *lista,char *identificador);
void eliminarPruebaDesdeArchivo(ListaP *lista,char *nombre_fichero);
void eliminarPruebaPorClave(ListaP *lista, char *clave);
void eliminarPruebasDesdeArchivoClave(ListaP *lista, char *nombre_fichero);
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
void l_prueba_listar(ListaP lista_pruebas);
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""





//------------------------------------------------------------------------------------------------------------------------------------------
#endif // HEADER_H_INCLUDED

