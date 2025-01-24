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
    printf("\n1. Añadir categoría");
    printf("\n2. Eliminar categoría");
    printf("\n3. Mostrar categorías");
    printf("\n4. Editar categoría");

    return opciones;
}

// AÑADIR CATEGORÍA
void anadir_categoria() {
    printf("\nIntroduce el nombre de la categoría: ");
    fflush(stdin);
    gets(c[i].nombre);
    printf("\nIntroduce el número de trabajadores: ");
    fflush(stdin);
    scanf("%d", &c[i].trabajadores);
    printf("\nIntroduce el correo electrónico: ");
    fflush(stdin);
    gets(c[i].correo);

    i++;
}

// ELIMINAR CATEGORÍA
void eliminar_categoria() {
    char comp[200];
    int r, a;

    printf("\nIntroduce el nombre de la categoría: ");
    fflush(stdin);
    gets(comp);

    for (r = 0; r < i; r++) {
        if (strcmp(c[r].nombre, comp) == 0) {
            printf("\nCategoría encontrada");
            a = r;
            break;
        }
    }

    if (r < i) {
        for (int j = a; j < i - 1; j++) {
            c[j] = c[j + 1];
        }
        i--; // Reducir el contador de categorías

        printf("\nCategoría eliminada");
    } else {
        printf("\nCategoría no encontrada");
    }
}

// MOSTRAR CATEGORÍA
void mostrar_categoria() {
    int w;

    for (w = 0; w < i; w++) {
        printf("\n\n******************\n");
        printf("\nNombre de la categoría: %s", c[w].nombre);
        printf("\nNúmero de trabajadores: %d", c[w].trabajadores);
        printf("\nCorreo electrónico: %s", c[w].correo);
    }
}

// EDITAR CATEGORÍA
void editar_categoria() {
    char comp[200];
    int r;

    printf("\nIntroduce el nombre de la categoría a editar: ");
    fflush(stdin);
    gets(comp);

    for (r = 0; r < i; r++) {
        if (strcmp(c[r].nombre, comp) == 0) {
            printf("\nCategoría encontrada");

            printf("\nIntroduce el nuevo nombre de la categoría: ");
            fflush(stdin);
            gets(c[r].nombre);

            printf("\nIntroduce el nuevo número de trabajadores: ");
            fflush(stdin);
            scanf("%d", &c[r].trabajadores);

            printf("\nIntroduce el nuevo correo electrónico: ");
            fflush(stdin);
            gets(c[r].correo);

            printf("\nCategoría editada");
            break;
        }
    }

    if (r == i) {
        printf("\nCategoría no encontrada");
    }
}

// MAIN
int main() {
    int opciones;

    for (;;) {
        menu();

        printf("\nIntroduce una opción: ");
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
