#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 4 leggere da tastiera il raggio di una sfera. Calcolarne e stamparne
   il volume. Usare la formula v = 4/3 * PI * R^3. Verificate
   il risultato...
*/

int main(int argc, char **argv){

float r=0.0, v=0.0, PI=3.14;

printf("Inserire valore raggio: ");
scanf("%f", &r);

v=4/3*PI*(r*r*r);

printf("Risultato formula presentata: %.2f\n", v);

v=(4*(PI*(r*r*r)))/3; //Correzione formula poichè tutto il calcolo precendente deve essere diviso per 3 e non solo 4

printf("Risultato con correzione formula: %.2f\n", v);

return 0;
}