/*
 3 leggere da tastiera una cifra come char. Stamparne il codice
   ASCII. Successivamente, memorizzare il valore che rappresenta 
   (quindi non il codice ASCII ma un valore tra 0 e 9) in una 
   variabile di tipo int e stamparla.
*/

#include <stdio.h>

int main(int argc, char **argv){
    char simbolo=0;
    int valore=0;
    
    printf("Inserire una cifra: ");
    scanf("%c", &simbolo);

    printf("Il valore nella tabella ASCII è %d e rappresenta '%c' \n", simbolo, simbolo);
    

    // per convertire il codice ascii nel relativo valore che rappresenta, basta sottrarre il codice ASCCI del simbolo 0 che vale 48
    valore=simbolo-48; //il 48 rappresenta il codice di 0, se mi serve effettivamente 1 come valore numerico, nell'ASCII è 49, tolto 48, ottengo 1
    //Gli altri si susseguono

    //Altro modo: int valore = cifra - '0'
    //Un singolo carattere tra apici singoli equivale al suo codice ASCII
    
    printf("Il valore effettivo del simbolo inserito rappresenta il numero: %d\n", valore);


return 0;
}