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

printf("Indirizzo della variabili x: %p\n", &x); //& per l'indirizzo
printf("Contenuto della variabile puntatore p: %p\n", p); //Il contenuto della variabile x è l'indirizzo
printf("Indirizzo della variabile p: %p\n", &p); //Indirizzo della variabile puntatore
printf("Contenuto della variabile x: %d\n", x); //Contenuto classico
printf("Contenuto dell'indirizzo contenuto in p: %d\n", *p); //* Contenuto della variabile a cui punta



return 0;
}
