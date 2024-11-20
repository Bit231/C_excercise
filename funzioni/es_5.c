#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
5. scrivere una funzione "check_data" che restituisce vero o falso a
   seconda che la data passata come argomento (giorno, mese e anno)
   sia valida o meno. Suggerimento, ricordate la filastrocca sui mesi? 
   "Trenta giorni ha novembre, con april, giugno e settembre..."
*/

bool bisestile(int anno){
    if((anno%4==0) || (anno%400==0 && anno%100!=0)){ //Sarebbe anno divisibile per oppure quando è divisibile per 400 ma non per 100
        return true;
    }else{
        return false;
    }
}

bool check_data(int giorno, int mese, int anno){

   int days[]={31,28,31,30,30,31,31,30,31,30,31}; //In base all'indice(Il mese) confronto il numero di giorni
    //controllo bisestile

    if(mese == 2 && bisestile(anno)){
        days[1] = 29;
    }
    
    if((mese >= 1 && mese<=12) && (giorno>= 1 && giorno <= days[mese-1]))return true;
    else return false;

}



int main(){
    int giorno, mese, anno;

    printf("Inserire giorno: ");
    scanf("%d", &giorno);

    printf("Gennaio:\t1\n   Febbraio:\t2\n  Marzo:\t3\n Aprile:\t4\n    Maggio:\t5\n    Giugno:\t6\n    Luglio:\t7\n    Agosto:\t8\n    Settembre:\t9\n Ottobre:\t10\n  Novembre:\t11\n Dicembre:\t12\n" );

    printf("Inserire numero mese: ");
    scanf("%d", &mese);

    printf("Inserire anno: ");
    scanf("%d", &anno);

    if(check_data(giorno, mese, anno)){
        printf("Data valida");
    }else{
        printf("Data non valida");
    }
    
}