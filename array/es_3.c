#include<stdio.h>

/*3. come il (2) in cui però non si stampa ma, solo dopo aver riempito
l'array, si richiede all'utente un numero, lo si ricerca nell'array
e si stampa se esiste e in quale posizione si trovi (limitarsi alla
prima occorrenza del numero cercato)*/

#include<stdlib.h>
#include<stdbool.h>

int main(){
    int dim=100, val; 
    int numeri[dim];
    bool trovato= false;
    for(int i=0; i< dim; i++){
        numeri[i]=(rand() % 71) + 10;
    }

    printf("Inserire numero da ricercare: ");
    scanf("%d", &val);

    for (int i = 0; i < dim; i++){
        if(val==numeri[i]){
            printf("Numero trovato in posizione: %d\n", i);
            trovato=true;
            break;
        }
    }

    if(!trovato){
        printf("Non è stato trovato alcun valore\n");
    }
    

}