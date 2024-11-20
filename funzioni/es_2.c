#include<stdio.h>
#include<stdlib.h>

/*
2. scrivere una funzione del tipo max(a,b) che restituisce il valore
   massimo tra a e b Implementare successivamente una seconda funzione
   che, sfruttando la precedente, restituisce il massimo tra 4 valori
*/

int ismax(int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

int max4(int c, int d, int maxAB){
    int max=ismax(c, d);
    max=ismax(max, maxAB);
    return max;
}

int main(){
    int a, b, max, c, d;

    printf("Inserire il primo valore: ");
    scanf("%d", &a);
    
    printf("Inserire il secondo valore: ");
    scanf("%d", &b);

    max=ismax(a,b);

    printf("Il massimo tra %d e %d e': %d\n", a, b, max);

    printf("Inserire il terzo valore: ");
    scanf("%d", &c);
    
    printf("Inserire il quarto valore: ");
    scanf("%d", &d);

    max=max4(c,d,max);

    printf("Il massimo tra i 4 valori e': %d\n", max);
    

}