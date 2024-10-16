/*
13 le attuali aliquote IRPEF prevedono una tassazione del 23% per la
   quota di reddito imponibile fino a 15.000 EUR, del 25% per la parte
   tra 15.001 e 28.000 EUR del 35% per la quota tra 28.001 e 50.000
   EUR, e del 43% per quanto oltre i 50.000. Chiedere all'utente una
   cifra di imponibile e stampare a video l'ammontare IRPEF e la
   relativa aliquota media.
 */

#include<stdio.h>
#include<stdlib.h>

#define cost1 15000;
#define cost2 28000;
#define cost3 50000;


int main(){
    float imponibile=0.0;

    printf("Inserire l'imponibile: ");
    scanf("%f", &imponibile);

    //x <=15k --> 23%
    if(imponibile<=15){
        //23%
    }else if(imponibile<=28){
        //25%            
    }else if(imponibile<=50){
        //35
    }else{
        //43%
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    ->25%

    //28 < x <=50 --> 35%
    
    // x > 50k --> 43%
}