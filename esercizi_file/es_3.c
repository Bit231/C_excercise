#include<stdio.h>
#include<stdlib.h>

int main(){
    /*
    Scrivere un programma che:

    //Stampa il numero di numeri primi trovati.
    */

    //Legga una sequenza di numeri interi da un file numeri.txt.
    //Utilizzi l'allocazione dinamica per memorizzare i numeri.

    FILE *numeri=fopen("numeri.txt", "r");

    if(!numeri){
        printf("File non aperto correttamente");
    }

    int *valori= NULL;
    int dimensione=0, num=0;

    while (fscanf(numeri, "%d ", &num)==1){
        dimensione++;
        valori=realloc(valori, sizeof(int)*dimensione);
        valori[dimensione-1]=num;
    }


    for (int i = 0; i < dimensione; i++){
        printf("%d ", valori[i]);
    }
    printf("\n");

    //Verifichi quanti numeri della sequenza sono numeri primi.
    unsigned int contNprimi=0;

    for (int i = 0; i < dimensione; i++){
        if(valori[i]==2 || valori[i]==3)contNprimi++;
        if((valori[i]%2 == 0 || valori[i]%3 == 0) ){
            continue;
        }else{
            contNprimi++;
        }
    }

    printf("Sono presenti %d numeri primi\n", contNprimi);
    fclose(numeri);
    free(valori);
}