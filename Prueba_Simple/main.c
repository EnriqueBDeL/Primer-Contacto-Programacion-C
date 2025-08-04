#include <stdio.h>
#include <stdbool.h>

#define MAX_CARTAS 60
#define MAX_CARTAS_TIPO 6
#define MAX_CONSECUTIVAS 4

// Variables globales para almacenar el mazo y los contadores
int mazo[MAX_CARTAS];  // 0: Criatura, 1: Hechizo, 2: Artefacto, 3: Tierra
int numCriaturas = 0, numHechizos = 0, numArtefactos = 0, numTierras = 0;
int consecutivas = 0;  // Para contar las cartas consecutivas del mismo tipo
int tipoUltimaCarta = -1;  // Para saber el �ltimo tipo de carta a�adida

// Funci�n para imprimir el mazo
void imprimirMazo() {
    for (int i = 0; i < MAX_CARTAS; i++) {
        if (mazo[i] == 0) printf("C ");
        else if (mazo[i] == 1) printf("H ");
        else if (mazo[i] == 2) printf("A ");
        else printf("T ");
    }
    printf("\n");
}

// Funci�n que inicializa los valores posibles para esta etapa
void iniciarValores(int* valores) {
    // Inicializa los valores posibles (0: Criatura, 1: Hechizo, 2: Artefacto, 3: Tierra)
    valores[0] = 0;  // Criatura
    valores[1] = 1;  // Hechizo
    valores[2] = 2;  // Artefacto
    valores[3] = 3;  // Tierra
}

// Funci�n para verificar si el mazo parcial es alcanzable (cumple restricciones)
bool alcanzable(int etapa) {
    // Verifica que no se haya excedido el n�mero de cartas por tipo
    if (numCriaturas > MAX_CARTAS_TIPO || numHechizos > MAX_CARTAS_TIPO || numArtefactos > MAX_CARTAS_TIPO)
        return false;

    // Verifica que no haya m�s de 4 cartas consecutivas del mismo tipo (excepto Tierras)
    if (tipoUltimaCarta != 3 && consecutivas > MAX_CONSECUTIVAS)
        return false;

    return true;
}

// Funci�n que verifica si la soluci�n es completa (si el mazo tiene 60 cartas)
bool esSolucion(int etapa) {
    return (etapa == MAX_CARTAS);
}

// Funci�n para procesar la soluci�n cuando se haya completado el mazo
void procesarSolucion() {
    imprimirMazo();  // Simplemente imprimimos el mazo
}

// Funci�n recursiva de backtracking (BTRec)
void BTRec(int* solucion, int etapa) {
    // Caso base: Si el mazo tiene 60 cartas, es una soluci�n
    if (esSolucion(etapa)) {
        procesarSolucion();  // Procesamos la soluci�n encontrada
        return;
    }

    // Inicializar los valores posibles para esta etapa
    int valores[4];
    iniciarValores(valores);

    // Repetir para cada valor posible
    for (int i = 0; i < 4; i++) {
        int nuevoValor = valores[i];

        // Si es alcanzable y v�lido
        if (nuevoValor == 0 && numCriaturas < MAX_CARTAS_TIPO) {  // Criaturas
            solucion[etapa] = 0;
            numCriaturas++;
        } else if (nuevoValor == 1 && numHechizos < MAX_CARTAS_TIPO) {  // Hechizos
            solucion[etapa] = 1;
            numHechizos++;
        } else if (nuevoValor == 2 && numArtefactos < MAX_CARTAS_TIPO) {  // Artefactos
            solucion[etapa] = 2;
            numArtefactos++;
        } else if (nuevoValor == 3) {  // Tierras (sin l�mite de cantidad)
            solucion[etapa] = 3;
            numTierras++;
        }

        // Verificamos si la soluci�n parcial es alcanzable
        if (alcanzable(etapa)) {
            tipoUltimaCarta = nuevoValor;
            consecutivas = (nuevoValor == tipoUltimaCarta) ? consecutivas + 1 : 1;
            BTRec(solucion, etapa + 1);  // Recursi�n para la siguiente etapa
        }

        // Retrocedemos (deshacemos la elecci�n)
        if (nuevoValor == 0) {
            numCriaturas--;
        } else if (nuevoValor == 1) {
            numHechizos--;
        } else if (nuevoValor == 2) {
            numArtefactos--;
        } else if (nuevoValor == 3) {
            numTierras--;
        }
        solucion[etapa] = -1;  // Vaciar el valor de la carta en la soluci�n
    }
}

// Funci�n principal
int main() {
    int solucion[MAX_CARTAS];  // Soluci�n parcial
    for (int i = 0; i < MAX_CARTAS; i++) {
        solucion[i] = -1;  // Inicializamos la soluci�n con valores vac�os
    }

    BTRec(solucion, 0);  // Comienza el backtracking desde la etapa 0

    imprimirMazo();

    return 0;
}

