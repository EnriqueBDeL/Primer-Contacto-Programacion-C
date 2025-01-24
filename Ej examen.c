#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[200];
    int trabajadores;
    char correo[200];
} categoria;

categoria c[100];
int i = 0;

// MENU
int menu() {
    int opciones;

    printf("\n\n*****MENU*****\n");
    printf("\n1. A�adir categor�a");
    printf("\n2. Eliminar categor�a");
    printf("\n3. Mostrar categor�as");
    printf("\n4. Editar categor�a");

    return opciones;
}

// A�ADIR CATEGOR�A
void anadir_categoria() {
    printf("\nIntroduce el nombre de la categor�a: ");
    fflush(stdin);
    gets(c[i].nombre);
    printf("\nIntroduce el n�mero de trabajadores: ");
    fflush(stdin);
    scanf("%d", &c[i].trabajadores);
    printf("\nIntroduce el correo electr�nico: ");
    fflush(stdin);
    gets(c[i].correo);

    i++;
}

// ELIMINAR CATEGOR�A
void eliminar_categoria() {
    char comp[200];
    int r, a;

    printf("\nIntroduce el nombre de la categor�a: ");
    fflush(stdin);
    gets(comp);

    for (r = 0; r < i; r++) {
        if (strcmp(c[r].nombre, comp) == 0) {
            printf("\nCategor�a encontrada");
            a = r;
            break;
        }
    }

    if (r < i) {
        for (int j = a; j < i - 1; j++) {
            c[j] = c[j + 1];
        }
        i--; // Reducir el contador de categor�as

        printf("\nCategor�a eliminada");
    } else {
        printf("\nCategor�a no encontrada");
    }
}

// MOSTRAR CATEGOR�A
void mostrar_categoria() {
    int w;

    for (w = 0; w < i; w++) {
        printf("\n\n******************\n");
        printf("\nNombre de la categor�a: %s", c[w].nombre);
        printf("\nN�mero de trabajadores: %d", c[w].trabajadores);
        printf("\nCorreo electr�nico: %s", c[w].correo);
    }
}

// EDITAR CATEGOR�A
void editar_categoria() {
    char comp[200];
    int r;

    printf("\nIntroduce el nombre de la categor�a a editar: ");
    fflush(stdin);
    gets(comp);

    for (r = 0; r < i; r++) {
        if (strcmp(c[r].nombre, comp) == 0) {
            printf("\nCategor�a encontrada");

            printf("\nIntroduce el nuevo nombre de la categor�a: ");
            fflush(stdin);
            gets(c[r].nombre);

            printf("\nIntroduce el nuevo n�mero de trabajadores: ");
            fflush(stdin);
            scanf("%d", &c[r].trabajadores);

            printf("\nIntroduce el nuevo correo electr�nico: ");
            fflush(stdin);
            gets(c[r].correo);

            printf("\nCategor�a editada");
            break;
        }
    }

    if (r == i) {
        printf("\nCategor�a no encontrada");
    }
}

// MAIN
int main() {
    int opciones;

    for (;;) {
        menu();

        printf("\nIntroduce una opci�n: ");
        fflush(stdin);
        scanf("%d", &opciones);

        switch (opciones) {
            case 1:
                anadir_categoria();
                break;

            case 2:
                eliminar_categoria();
                break;

            case 3:
                mostrar_categoria();
                break;

            case 4:
                editar_categoria();
                break;

            case 0:
                printf("\nSaliendo...\n");
                return 0;
        }
    }
}
