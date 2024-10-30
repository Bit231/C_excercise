/*
6. riempa un array di 100 elementi con i numeri tra 1 e 100 in ordine
e successivamente lo "mescoli", ovvero scambi di posizione in maniera
casuale i vari elementi dell'array, e poi lo stampi. Suggerimento: si
scorra l'array elemento per elemento e per ciascun elemento generare
casualmente (rand()) l'indice di un altro elemento con cui scambiarlo.
 */

#include<stdio.h>
#include<stdlib.h>

int main(){
    int dim=100, temp=0, indrand; 
    int numeri[dim];
    
    printf("Sequenza numerica: ");
    for(int i=0; i< dim; i++){
        numeri[i]=(rand() % 100) + 1;
    }

    //Ordinamento
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
        if(numeri[j] > numeri[j+1]){
            //Scambio variabili
            temp=numeri[j+1];
            numeri[j+1]=numeri[j];
            numeri[j]=temp;
        }
        }
    }

    //Stampo la sequenza ordinata
    printf("\nSequenza di numeri ordinata: ");
    for(int i=0; i< dim; i++){
        if(numeri[i] != 0)
            printf(" %d", numeri[i]);
    }
    printf("\n");

    for(int i=0; i< dim; i++){
        indrand=rand() % 100; //Genera indice da 0 a 99
        //Scambio dei due valori
        temp=numeri[indrand]; 
        numeri[indrand]=numeri[i];
        numeri[i]=temp;
    }

    //Stampo la sequenza finale
    printf("\nSequenza di numeri disordinata: ");
    for(int i=0; i< dim; i++){
        if(numeri[i] != 0)
            printf(" %d", numeri[i]);
    }
    printf("\n");






}
