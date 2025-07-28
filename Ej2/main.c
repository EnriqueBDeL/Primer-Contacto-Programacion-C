#include "header.h"



int main() {

    Producto productos[16]; //"...stock ilimitado de 16 productos distintos..."
    char marcas[100][50]; // 100 marcas de 50 caracteres
    int listaLotesValidos[5000][5]; // 5000 lotes de 5 productos
    int lote[5]; //lote de 5 productos

    int numProductos = 0, numMarcas = 0, numLotes = 0, totalNodos = 0, contadorLotes = 0;
    float maxPrecio;


    printf("Introduce el precio maximo por lote: "); scanf("%f", &maxPrecio);



    leerFichero("Mercanova.txt", productos, &numProductos, marcas, &numMarcas);



    for (int i = 0; i < 5; i++){
            lote[i] = -1;
    }

    backtracking(lote, 0, maxPrecio, productos, listaLotesValidos, &numLotes, &totalNodos, &contadorLotes, numProductos);

    printf("\n-----------------------------\n");
    printf("*** Resultado final ***\n");
    printf("Lotes validos generados: %d\n", contadorLotes);
    printf("Nodos generados: %d\n", totalNodos);
    printf("-----------------------------\n");

    return 0;
}
