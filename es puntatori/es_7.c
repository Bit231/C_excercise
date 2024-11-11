#include<stdio.h>
#include<stdlib.h>

/*
7. si riprenda l'esercizio E01.11. Si memorizzi la sequenza ottenuta
nel ciclo (b) usando array allocato dinamicamente. Dato che la
lunghezza della sequenza � ignota a priori si usi realloc() per
estendere l'array man mano che vengono generati i numeri.
Stampare la sequenza ottenuta solo al termine del ciclo.
*/
 int main(int argc, char **argv){
    int n;
    printf("Dammi un numero n: ");
    scanf("%d", &n);

  int *array=NULL; //Puntatore a int per salvare i numeri
   int lungh = 0; // usata con realloc per inserire sempre la nuova memoria

   // PUNTO b
   while(n != 1){
      lungh++; //Incremento la dimensione dell'array
   // PUNTO c
    printf("%d ", n);

     // PUNTO d
    if(n%2){
       n = 3*n + 1;
        array=realloc(array, sizeof(int)*lungh); //Aggiungo un elemento, incremento la dimensione dell'array orima di farlo
        array[lungh-1]=n;
    }else{
      n = n/2;
    array=realloc(array, sizeof(int)*lungh);
    array[lungh-1]=n;
    }
     } // incremento il numero di ripetizioni
   printf("\nLa sequenza ottenuta e' formata da %d numeri\n", lungh);
 
  // anche un for() era utilizzabile
  // for(lungh = 0; n != 1; ++lungh)
   //   if(n%2)...
    for(int i=0; i<(sizeof(array)); i++){
    printf("Indirizzo posizione %d: %d\n", i, array[i]);
}
  return 0;
 }


