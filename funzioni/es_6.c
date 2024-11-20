#include<stdio.h>
#include<stdlib.h>

/*
6. scrivere una funzione "num_giorno" che restituisce, dopo aver preso
   in ingresso una data come giorno mese e anno, quanti giorni sono
   passati dall'inizio dell'anno fino a quella data
*/

bool bisestile(int anno){
    if((anno%4==0) || (anno%400==0 && anno%100!=0)){ //Sarebbe anno divisibile per oppure quando è divisibile per 400 ma non per 100
        return true;
    }else{
        return false;
    }
}

int num_giorno(int giorno, int mese, int anno){
   int t=giorno;
   int days[]={31,28,31,30,30,31,31,30,31,30,31};
   //Controllo bisestile
    if(mese == 2 && bisestile(anno)){
        days[1] = 29;
    }
    //Sommo i giorni dal primo mese fino a quello voluto, prima ho aggiunto il numero del mese inserito
    for (int i = 0; i < (mese-1); i++){ //array da 0 a 11
        t+=days[i];
    }
    return t;
}

int main(){
   int giorno, mese, anno, tempo_passato;

   printf("Inserire giorno: ");
    scanf("%d", &giorno);

    printf("Gennaio:\t1\n   Febbraio:\t2\n  Marzo:\t3\n Aprile:\t4\n    Maggio:\t5\n    Giugno:\t6\n    Luglio:\t7\n    Agosto:\t8\n    Settembre:\t9\n Ottobre:\t10\n  Novembre:\t11\n Dicembre:\t12\n" );

    printf("Inserire numero mese: ");
    scanf("%d", &mese);

    printf("Inserire anno: ");
    scanf("%d", &anno);

   tempo_passato=num_giorno(giorno, mese, anno);
   printf("Giorni passati: %d\n", tempo_passato);
}