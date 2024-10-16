#include <stdio.h>

/*
 1 leggere da tastiera un numero intero (int), stamparlo in formato
   decimale, ottale e esadecimale usando gli specificatori di formato 
   visti a lezione. 
   Cosa cambia tra x e X?
*/

int main(int argc, char **argv){

int num=0;
printf("Inserire valore: ");
scanf("%d", &num);

printf("Il valore inserito formato decimale: %d \n", num);
printf("Il valore inserito formato ottale: %o \n", num);
printf("Il valore inserito formato esadecimale x: %x\n", num);
printf("Il valore inserito formato esadecimale X : %x\n", num);

return 0;
}