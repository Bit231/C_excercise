#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 8 leggere da tastiera una cifra in EUR. Considerando solo le monete
   in EUR (2 EUR, 1 EUR, 50, 20, 10, 5, 2 e 1 eurocent). Calcolare
   quale è il numero minimo di monete e di quale tipo che che si
   possono usare per ottenere quella cifra. Suggerimento: dividere
   la cifra per 2, otterrete così il numero di monete da 2 EUR.
   Sottrarre alla cifra originale l'ammontare complessivo delle monete
   da 2 EUR. Ripetere la procedura sulla cifra rimanente dividendo
   per 1 e ottenendo così il numero di monete da 1 EUR da usare.
   Sottrarre ulteriormente l'ammontare complessivo delle monete da
   1 EUR e ripetere ulteriormente la procedura con tutti i tagli di
   monete rimanenti dal piú grande (50 eurocent) fino al centesimo.
*/

int main(int argc, char **argv){

float cifra=0.0;

int Nmonete=0;

printf("Inserire cifra in EUR: ");
scanf("%f", &cifra);

Nmonete=cifra/2; //Trovo il numero di monete da due euro utilizzabili
printf("Le monete da 2 EUR utilizzate sono: %d\n", Nmonete);
cifra=cifra-Nmonete*2; //sottraggo dalla cifra totale il valore rappresentato dalle monete da due euro, es. 51 euro --> 25 monete da 2 euro --> 51-(25*2)

Nmonete=cifra/1;
printf("Le monete da 1 EUR utilizzate sono: %d\n", Nmonete);
cifra=cifra-Nmonete*1;

//Passo ai centesimi, moltiplico per 100 in modo da usare gli interi
cifra*=100;

Nmonete=cifra/50;
printf("Le monete da 50cent utilizzate sono: %d\n", Nmonete);
cifra=cifra-Nmonete*50;

Nmonete=cifra/20;
printf("Le monete da 20cent utilizzate sono: %d\n", Nmonete);
cifra=cifra-Nmonete*20;

Nmonete=cifra/10;
printf("Le monete da 10cent utilizzate sono: %d\n", Nmonete);
cifra=cifra-Nmonete*10;

//printf("Quantità cifra: %.2f\n", cifra);

Nmonete=cifra/5;
printf("Le monete da 5cent utilizzate sono: %d\n", Nmonete);
cifra=cifra-Nmonete*5;

Nmonete=cifra/2;
printf("Le monete da 2cent utilizzate sono: %d\n", Nmonete);
cifra=cifra-Nmonete*2;

Nmonete= cifra/1; //Assegna a Nmonete valore 0

printf("Nmonete: %d\n", Nmonete);

//printf("Quantità cifra: %.2f\n", Nmonete);
printf("Le monete da 1cent utilizzate sono: %d\n", Nmonete);
cifra=cifra-Nmonete*1;


return 0;
}