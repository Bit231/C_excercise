#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 3 leggere da tastiera 2 numeri interi, calcolare il risultato della
   divisione tra di loro e stamparlo. Cosa notate? 

   Si può notare che viene tagliata la parte decimale in caso si tratti di
   una divisione tra valori che non sono divisibili tra loro. Il resto non viene presentato
*/

int main(int argc, char **argv){

int num1=0, num2=0, divisione=0;

printf("Inserire valore 1: ");
scanf("%d", &num1);

printf("Inserire valore 2: ");
scanf("%d", &num2);

divisione=(num1/num2);

printf("Risultato divisione: %d", divisione);

return 0;
}