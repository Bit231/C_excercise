#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 2 leggere da tastiera un'ammontare in euro (quale tipo di dato
   dovreste usare tra int e float?), applicare l'IVA del 22% e
   stampare il risultato (si ricorda che per le valute vanno stampate
   2 e solo 2 cifre dopo la virgola).
*/

int main(int argc, char **argv){

float euro=0.0, totale=0.0;

printf("Inserire valore in euro: ");
scanf("%f", &euro);

totale=(euro*22/100)+euro;

printf("L'ammontare totale in euro: %.2f", totale);

return 0;
}