#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
4. scrivere una funzione "bisestile" che prende in ingresso un anno e
   restituisce vero o falso a seconda che l'anno in questione sia o
   meno bisestile. 
   Si rammenta che sono bisestili gli anni esattamente divisibili per 4 

   con l'eccezione di quelli divisibili esattamente da 100 ma non da 400
*/

bool bisestile(int anno){
    if((anno%4==0 && anno%100!=0) || (anno%400==0)){ //Chiedere
        return true;
    }else{
        return false;
    }
}

int main(){
    int anno;

    printf("Inserire anno: ");
    scanf("%4d", &anno);

    if(bisestile(anno)){
        printf("L'anno %d e' bisestile", anno);
    }else{
        printf("L'anno %d non e' bisestile", anno);
    }

}