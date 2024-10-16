/* 
 7 prendere in ingresso 4 cifre binarie e stampare il valore
   del numero che rappresentano in formato decimale*/

#include <stdio.h>

int main(int argc, char **argv){

int bit3=0, bit2=0, bit1=0, bit0=0;
int valore_dec=0;

printf("Inserire numero binario: ");
scanf("%1d%1d%1d%1d", &bit3, &bit2, &bit1, &bit0); //L'1 negli specificatori di formato serve a fare leggere una e una sola cifra

valore_dec=bit3*8+bit2*4+bit1*2+bit0;

printf("Valore decimale: %d\n", valore_dec);




return 0;
}
