#include<stdio.h>
#include<stdlib.h>

int main(){
    /*
    La prima riga contiene un numero intero che indica la lunghezza della sequenza di numeri.
    La seconda riga contiene la sequenza di numeri interi separati da spazi.

    Il programma deve:


    Dopo aver eseguito i calcoli, il programma deve liberare la memoria allocata per l'array
    */
    
    FILE *sequenza=fopen("sequenza.txt", "r");
    //Leggere il numero che rappresenta la lunghezza della sequenza.
    int dimensione=fgetc(sequenza)-'0'; 

    //Allocare dinamicamente un array di interi di quella lunghezza.
    int numeri[dimensione];
    //printf("%d", dimensione);

    //Leggere i numeri dal file e inserirli nell'array.
    for (int i = 0; i < dimensione; i++){
        fscanf(sequenza, "%d ", &numeri[i]);
    }
    
    //Stampare la somma, la media, il valore massimo e il valore minimo della sequenza.
    int somma=0;

    for (int i = 0; i < dimensione; i++){
        somma+=numeri[i];
    }

    printf("Somma: %d\n", somma);

    float media=((float)somma/(float)dimensione);
    printf("Media: %f\n", media);
    
    int max=-1, min=numeri[0]; //Primo valore dell'array

    for (int i = 0; i < dimensione; i++){
        if(numeri[i]>=max){
            max=numeri[i];
        }
        if(numeri[i]<=min){
            min=numeri[i];
        }
    }
    

    printf("Valore massimo: %d\n", max);
    printf("Valore minimo: %d\n", min);
    
    fclose(sequenza);

}