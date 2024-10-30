#include<stdio.h>
#include<stdlib.h>
//PRATICAMENTE IDENTICO AL PRIMO, CAMBIA IL RANGE DI VALORI GENERATI
/*
2. usi rand() per riempire un array di 100 elementi con numeri interi
casuali tra 10 e 80 e lo stampi
*/

#define DIM (100); //Costante utilizzata come dimensione dell'array
int main(){
    int numeri[DIM];
    
        printf("Sequenza numerica: ");
    for(int i=0; i< DIM; i++){
        numeri[i]=(rand() % 71) + 10;
        printf(" %d\n", numeri[i]);
    }
    printf("\n");
}