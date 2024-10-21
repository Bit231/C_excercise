/*
5. prendere in ingresso un numero e stamparne il fattoriale
*/

#include<stdio.h>
#include<stdlib.h>

int main(){

int n;
long int facts=1;

    printf("Inserire un numero: ");
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        facts*=i;
    }

printf("Fattoriale calcolato: %d\n", facts);

}
