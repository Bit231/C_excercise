#include<stdio.h>

/*4. come il (2) in cui però prima della stampa si eliminino gli
elementi duplicati*/

#include<stdlib.h>
#include<time.h>

#define DIM (100); //Costante utilizzata come dimensione dell'array
int main(){
    int eli=0, val; 
    int numeri[DIM];
    srand(time(0));
    //Riempio l'array
    for(int i=0; i< DIM; i++){
        numeri[i]=(rand() % 71) + 10;
    }

    //Stampo l'array con possibili duplicati
    for(int i=0; i< DIM; i++){
        printf(" %d", numeri[i]);
    }

    //For di ricerca ed "eliminazione"     
    for (int i = 0; i < DIM; i++){
        val=numeri[i]; //Assegno il valore in quella determinata posizione a una variabile di appoggio per confrontarlo
        for (int j = i+1; j < DIM; j++){
            if((val == numeri[j]) && (numeri[j] != 0)){ //Se il val di appoggio è uguale a un valore in un'altra posizione 
                numeri[j]=0; //A quel valore assegno 0
                eli++; //Incremento di uno il conto delle eliminaioni
            }
        }
        
    }
    

    printf("\nSequenza di numeri finale: ");
    for(int i=0; i< dim; i++){
        if(numeri[i] != 0) //Stampo solo i valori diversi da 0, quindi non eliminati
        printf(" %d", numeri[i]);
    }
    
    printf("\n Valori eliminati: %d", eli); //Numero di valori eliminati

}