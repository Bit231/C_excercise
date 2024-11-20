#include<stdio.h>
#include<stdlib.h>
/*
1. scrivere una funzione di nome "isprime" che restituisce vero o
   falso a seconda che le sia passato un numero primo o meno
*/

int isprime(int val){
    
    for (int i = 1; i < val/2; i++){
        if(val%i == 0){
            return 0; //Se è divisibile per almeno uno dei valori i allora non è primo
        }
    }
    return 1;
}


int main(){
    int valore=0;

    printf("Inserire il valore: ");
    scanf("%d", &valore);

    if(isprime(valore) == 1){ 
        printf("Il numero %d e' primo\n", valore);
    }else{
        printf("Il numero %d non e' primo\n", valore);
    }



}