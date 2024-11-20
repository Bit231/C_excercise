#include<stdio.h>
#include<stdlib.h>

/*
6. scrivere una funzione "num_giorno" che restituisce, dopo aver preso
   in ingresso una data come giorno mese e anno, quanti giorni sono
   passati dall'inizio dell'anno fino a quella data
*/

int num_giorno(int giorno, int mese){
   int t=giorno;

   for(int i=1; i<mese; i++){ //Parto dal mese 1 (gennaio) e arrivo fino a quello voluto
      switch (i){ 
        case 1:
            t+=31;
        break;
        
        case 2:
            t+=28;
        break;

        case 3:
            t+=31;
        break;
        
        case 4:
            t+=30;
        break;
        
        case 5:
            t+=31;
        break;
        
        case 6:
            t+=30;
        break;
        
        case 7:
            t+=31;
        break;
        
        case 8:
            t+=31;
        break;
        
        case 9:
            t+=30;
        break;
        
        case 10:
            t+=31;
        break;

        case 11:
            t+=30;
        break;

        case 12:
            t+=31;
        break;

    default:
        break;
   }

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

   tempo_passato=num_giorno(giorno, mese);
   printf("Giorni passati: %d\n", tempo_passato);
}