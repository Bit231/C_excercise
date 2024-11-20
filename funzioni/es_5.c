#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*
5. scrivere una funzione "check_data" che restituisce vero o falso a
   seconda che la data passata come argomento (giorno, mese e anno)
   sia valida o meno. Suggerimento, ricordate la filastrocca sui mesi? 
   "Trenta giorni ha novembre, con april, giugno e settembre..."
*/

bool check_data(int giorno, int mese, int anno){
    if(anno>2024 || giorno>31 || mese>12)return false;
    
    switch (mese){
        case 1:
            if(giorno>31)return false;
            else return true;
        break;
        
        case 2:
            if(giorno>28)return false;
            else return true;
        break;

        case 3:
            if(giorno>31)return false;
            else return true;
        break;
        
        case 4:
            if(giorno>30)return false;
            else return true;
        break;
        
        case 5:
            if(giorno>31)return false;
            else return true;
        break;
        
        case 6:
            if(giorno>30)return false;
            else return true;
        break;
        
        case 7:
            if(giorno>31)return false;
            else return true;
        break;
        
        case 8:
            if(giorno>31)return false;
            else return true;
        break;
        
        case 9:
            if(giorno>30)return false;
            else return true;
        break;
        
        case 10:
            if(giorno>31)return false;
            else return true;
        break;

        case 11:
            if(giorno>30)return false;
            else return true;
        break;

        case 12:
            if(giorno>31)return false;
                else return true;
        break;

    default:
        break;
    }

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