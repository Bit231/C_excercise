#include<stdlib.h>
#include<stdio.h>
/*
1. Leggere da tastiera un numero decimale memorizzandolo in opportuna
variabile x.
Definire un puntatore p che possa contenere l'indirizzo
di x e inizializzarlo con tale indirizzo. Stampare: l'indirizzo di
x, il contenuto di p, l'indirizzo di p, il contenuto di x, il valore
contenuto all'indirizzo contenuto in p.
*/

int main(){

int x;
int *p;

printf("Inserisci numero: ");
scanf("%d", &x);

p=&x; //Assegno l'indirizzo di memoria

printf("Indirizzo della variabili x: %p\n", p);
printf("Contenuto della variabile puntatore p: %p\n", p);
printf("Indirizzo della variabile p: %p\n", &p);
printf("Indirizzo della variabili x: %d\n", x);
printf("Contenuto dell'indirizzo contenuto in p: %d\n", *p);



return 0;
}
