/*
Leggere da tastiera un numero, stampare quante cifre ha
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n=0;
    int cont=0, div=0;
        printf("Inserire un valore numerico: ");
        scanf("%d", &n);

        do{
            n/=10;
            cont++;
        }while(n != 0);


    printf("Il numero ha %d cifre \n", cont);
}
