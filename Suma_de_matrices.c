#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){


    int M1 [4][4];
    int M2 [4][4];
    int M3 [4][4];




    printf("\Matriz 1:");

for(int c2 = 0; c2 < 4; c2++){

for(int c = 0; c < 4; c++){

    printf("\nIntroduce un numero a la matriz:"); scanf("%d",&M1[c][c2]);


}
}



    printf("\nMatriz 2:");

for(int c2 = 0; c2 < 4; c2++){

for(int c = 0; c < 4; c++){

    printf("\nIntroduce un numero a la matriz:"); scanf("%d",&M2[c][c2]);


}
}

   printf("\n\nMatriz 1:");

for(int c2 = 0; c2 < 4; c2++){
printf("\n");
for(int c = 0; c < 4; c++){

    printf("%d",M1[c][c2]);
    printf("|");


}
}


    printf("\n\nMatriz 2:");

for(int c2 = 0; c2 < 4; c2++){
printf("\n");
for(int c = 0; c < 4; c++){

    printf("%d",M2[c][c2]);
       printf("|");


}
}



for(int c2 = 0; c2 < 4; c2++){

for(int c = 0; c < 4; c++){

   M3[c][c2] = M1[c][c2] + M2[c][c2];

}
}
    printf("\n\nSuma:");

for(int c2 = 0; c2 < 4; c2++){
printf("\n");
for(int c = 0; c < 4; c++){

    printf("%d",M3[c][c2]);
       printf("|");


}
}



return 0;
}
