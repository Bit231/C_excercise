#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 9 leggere da tastiera un numero intero non negativo tra 0 e 15.
   Stampare le 4 cifre della sua rappresentazione binaria dalla
   meno significativa alla piú significativa (suggerimento: usare
   l'operatore % e la divisione e non la funzione pow())
*/

int main(int argc, char **argv){

int num=0, bit=0;

printf("Inserire numero in base decimale positivo compreso tra 0 e 15: ");
scanf("%d", &num);

bit= num%2; //Ricavo il resto che sarà 1 o 0 (il bit)
printf("Il numero inserito in base 2 (binario) lsb --> msd: %d", bit);
num/=2; //Divido per due il numero andando al valore per ottenere il bit successivo

bit= num%2; //Ricavo il resto che sarà 1 o 0 (il bit)
printf("%d", bit);
num/=2; 

bit= num%2; //Ricavo il resto che sarà 1 o 0 (il bit)
printf("%d", bit);
num/=2; //Divido per due il numero andando al valore per ottenere il bit successivo

bit= num%2; //Ricavo il resto che sarà 1 o 0 (il bit)
printf("%d", bit);
num/=2; //Divido per due il numero andando al valore per ottenere il bit successivo

return 0;
}