#include<stdio.h>
#include<stdlib.h>
/*
1. usi rand() per riempire un array di 100 elementi con numeri interi
casuali tra 0 e 70 e lo stampi (suggerimento, usare "%")
*/

int main(){
    int dim=100; 
    int numeri[dim];
    
        printf("Sequenza numerica: ");
    for(int i=0; i< dim; i++){
        numeri[i]=(rand() % 70 - 0 +1) + 0;
        printf(" %d", numeri[i]);
    }
    printf("\n");
}