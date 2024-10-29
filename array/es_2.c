#include<stdio.h>
#include<stdlib.h>
/*
2. usi rand() per riempire un array di 100 elementi con numeri interi
casuali tra 10 e 80 e lo stampi
*/

int main(){
    int dim=100; 
    int numeri[dim];
    
        printf("Sequenza numerica: ");
    for(int i=0; i< dim; i++){
        numeri[i]=(rand() % 80 - 10 +1) + 10;
        printf(" %d", numeri[i]);
    }
    printf("\n");
}