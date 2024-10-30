#include<stdio.h>

/*3. come il (2) in cui però non si stampa ma, solo dopo aver riempito
l'array, si richiede all'utente un numero, lo si ricerca nell'array
e si stampa se esiste e in quale posizione si trovi (limitarsi alla
prima occorrenza del numero cercato)*/

#include<stdlib.h>
#include<stdbool.h>

#define DIM (100); //Costante utilizzata come dimensione dell'array
int main(){
    int val; 
    int numeri[DIM];
    bool trovato= false;
    //Riempio l'array
    for(int i=0; i< DIM; i++){
        numeri[i]=(rand() % 71) + 10;
    }

    printf("Inserire numero da ricercare: ");
    scanf("%d", &val);

    //Ciclo in cui effettua la ricerca
    for (int i = 0; i < DIM; i++){
        if(val==numeri[i]){
            printf("Numero trovato in posizione: %d\n", i);
            trovato=true; //Trovato diventa true per non far stampare che non l'ha trovato
            break;
        }
    }

    if(!trovato){
        printf("Non è stato trovato alcun valore\n");
    }
    

}