/*
    Inserire un valore n, stampare la somma dei numeri pari da 0 a N
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n=0, somma=0;
        printf("Inserire un valore N : ");
        scanf("%d", &n);

    for(int i=1; i<=n; i++){
        if(i%2==0)
            somma+=i;
    }
    printf("La somma dei numeri pari da 0 a N: %d\n", somma);
}