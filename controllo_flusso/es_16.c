#include<stdio.h>
#include<stdlib.h>

int main(){
    /*
        16 Prendere in ingresso da tastiera un numero intero n e quindi
        stampare tutti i numeri interi presenti nell'intervallo [1,n] che
        sono anche cubi di altri numeri interi
    */

   int n=0;

    printf("Inserire un numero N: ");
    scanf("%d", &n);

    for(int i=1; (i*i*i)<=n; i++){
        printf("Il cubo di %d : %d\n", i, (i*i*i));
    }
} 