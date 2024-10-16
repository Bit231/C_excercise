#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 5 leggere da tastiera una temperatura espressa in gradi celsius,
   convertirla in farenheit e stamparla (la formula è F = 32 + 9/5C)
*/

int main(int argc, char **argv){

float tempC=0.0, tempF=0.0;

printf("Inserire valore temperatura celsius: ");
scanf("%f", &tempC);

tempF=32+((9*tempC)/5);

printf("Temperatura: %.2f\n", tempF);

return 0;
}