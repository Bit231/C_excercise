/*
12 si prenda in ingresso un ammontare in EUR, un tasso di interesse
   annuale (x in %), e una durata in anni n. Si stampi come varia
   l'ammontare inserito anno per anno se ogni anno applichiamo il
   tasso di interesse x per n anni.
*/

#include<stdio.h>
#include<stdlib.h>

int main(){

float ammontare=0.0;
int tasso=0, anni=0;



printf("Inserire ammontare di EURO: ");
scanf("%f", &ammontare);

printf("Inserire tasso di interesse: ");
scanf("%d", &tasso);

printf("Inserire anni: ");
scanf("%d", &anni);

for(int i=0; i<anni; i++){
    ammontare+= (ammontare*tasso/100);

    printf("L'ammontare nell'anno: %f\n", ammontare);
}
}
