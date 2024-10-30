/*5. usi rand() per riempire un array di 100 elementi con numeri interi
univoci tra 1 e 300 e lo stampi*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <stdbool.h>


int main(){
    int dim=1000000, val=0, valNuovo; 
    int numeri[dim];
    srand(time(0));
    bool div=true;

    for (int i = 0; i < dim; i++){
        do{
            valNuovo=(rand() % 300)+1;            
        }while(valNuovo==val); //Continuerà a generare il valore finchè è uguale a quello precedente
        val=valNuovo;
        numeri[i]=valNuovo;
    }
        
    
    //Stampo la sequenza finale di valori
    printf("\nSequenza di numeri finale: ");
    for(int i=0; i< dim; i++){
        if(numeri[i] != 0)
        printf(" %d", numeri[i]);
    }

    printf("\n");


}