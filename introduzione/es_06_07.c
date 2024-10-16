#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 6 leggere da tastiera il valore di una variabile x. Calcolare e
   stampare il valore del polinomio 4x^5 + 2x^3 + 7x +5
   Non usate pow()

 7 ottimizzare il programma precedente riducendo al massimo le
   moltiplicazioni (sempre senza usare pow())
*/

int main(int argc, char **argv){

int x=0, pol=0;
printf("Inserire valore variabile x: ");
scanf("%d", &x);

int raccMolt=x*x*x;

pol=4*(raccMolt*x*x) + 2*raccMolt + 7*x+5;

printf("Risultato polinomio: %d\n", pol);

return 0;
}