#include<stdio.h>

/*4. come il (2) in cui però prima della stampa si eliminino gli
elementi duplicati*/

#include<stdlib.h>
#include<time.h>
int main(){
    int dim=20, eli=0, val; 
    int numeri[dim];
    srand(time(0));

    for(int i=0; i< dim; i++){
        numeri[i]=(rand() % 71) + 10;
    }

    for(int i=0; i< dim; i++){
        printf(" %d", numeri[i]);
    }

        
    for (int i = 0; i < dim; i++){
        val=numeri[i];
        for (int j = i+1; j < dim; j++){
            if((val == numeri[j]) && (numeri[j] != 0)){
                numeri[j]=0;
                eli++;
            }
        }
        
    }
    

    printf("\nSequenza di numeri finale: ");
    for(int i=0; i< dim; i++){
        if(numeri[i] != 0)
        printf(" %d", numeri[i]);
    }
    
    printf("\n Valori eliminati: %d", eli);

}