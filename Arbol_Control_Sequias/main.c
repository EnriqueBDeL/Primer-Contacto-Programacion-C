#include "Header.h"


int main()
{

    int opcion, id,orden_opc;

    char nom[50];

    P_NODO_ARBOL a = crearArbol();

    Controles control;

for(;;){

   opcion = Menu();

switch(opcion){

case 1:

       printf("\nID del control: "); scanf("%d",&control.ID);

        printf("\nLugar del control: "); scanf("%s",nom);
        control.lugar = strdup(nom);

        printf("\nNivel del agua: ");  scanf("%f",&control.nivel_agua);
        a = insertar(a, control);

        printf("\nElemento insertado");
    break;

case 2:

        printf("Ingrese ID a eliminar: "); scanf("%d", &id);
        a = eliminar(a, id);

    break;

case 3:
    printf("\n1.Orden previo\n");
            printf("2.Orden simetrico\n");
            printf("3.Orden posterior\n");
            printf("\nIntroduce una opcion: ");
            scanf("%d",&orden_opc);

            switch (orden_opc)
            {
            case 1:
                preOrder(a);
                break;

            case 2:
                inOrder(a);
                break;

            case 3:
                postOrder(a);
                break;
            }
            break;
    break;

case 4:

    return 0;

    break;

}

}

}
