/*
11 si implementi il seguente algoritmo:
   a: input n
   b: fino a che n e' diverso da 1 ripetere i punti c e d:
       c: output n
       d: se n è dispari aggiornare n come
             n <-- 3n+1:  
          altrimenti 
             n <-- n/2 (divisione intera)
   e: stampare la lunghezza della sequenza ottenuta ovvero quanti
      numeri sono stati stampati
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n=0, cont=0;

    printf("Inserire il valore n: ");
    scanf("%d", &n);

    do{
        printf("Il valore n: %d\n", n);
        cont++;
        if(n%2!=0){
            n=3*n+1;
        }else{
            n=n/2;
        }

    }while(n!=1);

    /*while(n!=1){
                printf("Il valore n: %d\n", n);
        cont++;
        if(n%2!=0){
            n=3*n+1;
        }else{
            n=n/2;
        }
    }*/


    printf("La lunghezza della sequenza ottenuta: %d\n", cont);

}
