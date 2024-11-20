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
    }while(div!=0); //Il ciclo continua finchè non resta il valore 0 nella divisione, 100 --> 10 --> 1 --> 0, divisione intera del C

    return cont;
}


int main(){
    int valore, cont; 

    printf("Inserire valore: ");
    scanf("%d", &valore);

    cont=ncifre(valore);
    printf("Numero di cifre del numero %d: %d\n", valore, cont); //Stampo valore inserito e numero di cifre
    
}