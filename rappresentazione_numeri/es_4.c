/*  
 4 come il #1 ma stampare la cifra esadecimale corrispondente
   (calcolandola, non usando gli specificatori di formato %x o %X)
   Richiede l'uso del costrutto if()

*/

#include <stdio.h>


int main(int argc, char **argv){

int num=0;

printf("Inserire numero in base decimale positivo compreso tra 0 e 15: ");
scanf("%d", &num);


if(num < 10){ 
    printf("Il numero in esadecimale è: %d\n", num);
}else{

char cifra=0;    

//Calcolo il simbolo da stampare, tolgo dieci per riportarlo tra 0 e 5 e aggiugno il primo simbolo di quelli che voglio ottenere
// 10 (0 + il carattere) --> A, 11(1 + il carattere) --> B, 12 --> C, .....
cifra=(num-10)+'A'; 

    printf("Il numero in esadecimale è: %c\n", cifra);
}

return 0;
}

