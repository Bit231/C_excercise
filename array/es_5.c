/*5. usi rand() per riempire un array di 100 elementi con numeri interi
univoci tra 1 e 300 e lo stampi*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <stdbool.h>


int main(){
    int dim=20, val=0; 
    int numeri[dim];
    srand(time(0));
    bool div=true;

    for (int i = 0; i < dim; i++){
        val=(rand() % 300)+1;

        for(int j=0; j<dim; j++){
            if(numeri[j] == val){
                div=false;
                break;
            }
        }

        if(div){
            numeri[i]=val;
        }else{
            div=true;
        }
    }
        
    

    printf("\nSequenza di numeri finale: ");
    for(int i=0; i< dim; i++){
        if(numeri[i] != 0)
        printf(" %d", numeri[i]);
    }

    printf("\n");


}