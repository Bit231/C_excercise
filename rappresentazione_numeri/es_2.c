/*  2 Leggere da tastiera un simbolo. Sommare a quel simbolo 1 e
   stamparlo sia come simbolo che come codice ASCII. Cosa succede? E
   perche'?
   */

#include <stdio.h>

int main(int argc, char **argv){
    char simbolo=0;

    printf("Inserire un simbolo: ");
    scanf("%c", &simbolo);

    simbolo++;

    printf("Il valore in simbolo: %c\n", simbolo);
    printf("Il valore in numero: %d\n", simbolo);


return 0;
}