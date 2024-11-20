#include<stdio.h>
#include<stdlib.h>

/*
3. scrivere una funzione che restituisce il numero di cifre del numero
   intero passato come argomento
*/

int ncifre(int valore){
    int cont=0;
    int div=valore;
    do{
        cont++;
        div/=10;
    }while(div!=0);

    return cont;
}


int main(){
    int valore, cont; 

    printf("Inserire valore: ");
    scanf("%d", &valore);

    cont=ncifre(valore);
    printf("Numero di cifre del numero %d: %d", valore, cont);
    
}