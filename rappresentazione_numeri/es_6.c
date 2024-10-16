/* 6 prendere in ingresso una singola cifra esadecimale e stamparne
   il valore in formato decimale
   Richiede l'uso del costrutto if()*/

#include <stdio.h>

int main(int argc, char **argv){

char num=0;

printf("Inserire numero in base esadecimale positivo compreso tra 0 e 9 oppure una lettera da A e E: ");
scanf("%c", &num);


if(num <= '9' && num >= '0'){ 
    printf("Il numero in decimale è: %c\n", num);
}else{

int valore=0;

valore= (num - 'A')+10; 
    printf("Il numero in esadecimale è: %d\n", valore);
}

return 0;
}
