/*
7. Nelle vecchie tastiere dei telefoni vi erano associazioni numero -> lettere (1=ABC, 2=DEF, 3=GHI, 4=JKL, 5=MNO, 6=PQR, 7=ST, 8=UV, 9=WX, 0=YZ.)
   Data in ingresso una sequenza di caratteri stampare i corrispondenti numeri.
   Ad esempio MASSIMO -> 5177355
*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    char c;

    printf("Inserire caratteri: ");
    scanf("%c", &c);

        printf("Numeri corrispondenti: ");
    do{
        switch(c){
    case 'A':
    case 'B':
    case 'C':{
        printf("%d", 1);
    }break;

        case 'D':
    case 'E':
    case 'F':{
        printf("%d", 2);
    }break;

        case 'G':
    case 'H':
    case 'I':{
        printf("%d", 3);
    }break;

        case 'J':
    case 'K':
    case 'L':{
        printf("%d", 4);
    }break;

        case 'M':
    case 'N':
    case 'O':{
        printf("%d", 5);
    }break;



        }

    }while(c == 'LF');


}
