#include<stdio.h>
#include<stdlib.h>

int main(){
    /*
    15 Iterativamente chiedere all'utente un numero intero fino a che
   l'utente non inserisce 0. Stampare quindi il piu' grande e il piu'
   piccolo dei numeri inseriti dall'utente.
    */

   int n=0, max=-1;


   do{
    printf("Inserire numero:");
    scanf("%d", &n);

    if(n>max){
        max=n;
    }
   }while(n!=0);

   printf("Il numero più grande --> %d\n", max);
}