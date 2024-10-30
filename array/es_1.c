#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
1. usi rand() per riempire un array di 100 elementi con numeri interi
casuali tra 0 e 70 e lo stampi (suggerimento, usare "%")
*/

#define DIM (100); //Costante utilizzata come dimensione dell'array
int main(){
    srand(time(0)); //Inizializzo a zero la funzione rand

    int numeri[DIM]; //DIchiaro l'array a dimensione 100
    
        printf("Sequenza numerica: ");
        //For di riempimento e stampa dell'array
    for(int i=0; i< DIM; i++){
        numeri[i]=(rand() % 70 - 0 +1) + 0;
        printf(" %d", numeri[i]);
    }
    printf("\n");
}