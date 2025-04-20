#include <stdio.h>
#include <stdlib.h>
#include <string.h>








int main()
{


char c[]="Espero que te esten alludando estos apuntes";

int n,i,s;

s = 0;


n = strlen(c);


for(i = 0; i<n; i++){

 if(c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' ||c[i] == 'u' ||c[i] == 'A' || c[i] == 'E' ||c[i] == 'I' ||  c[i] == 'O' ||  c[i] == 'U' ){

    s++;

 }

}

printf("\nOracion: Espero que te esten alludando estos apuntes.");
printf("\nNumero de vocales: %d\n",s);


//--------------------------------------------------------------------------------------------


char p[50];

int w,a,b;
b = 0;



printf("Introduce una oracion: "); fflush(stdin); gets(p);

w = strlen(p);


for(a = 0; a<w; a++){

 if(p[a] == 'a' || p[a]  == 'e' || p[a]  == 'i' || p[a]  == 'o' ||p[a]  == 'u' ||p[a]  == 'A' || p[a]  == 'E' ||p[a]  == 'I' ||  p[a]  == 'O' ||  p[a]  == 'U' ){

    b++;

 }

}


printf("\nOracion: %s.",p);
printf("\nNumero de vocales: %d\n",b);



    return 0;
}
