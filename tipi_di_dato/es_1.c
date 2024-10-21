#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*

1. Per calcolare la radice quadrata di un numero si puo' usare l'algoritmo di Newton. Dato un numero n di cui calcolare la radice, inizializzo il risultato r a 1. Ad ogni iterazione aggiorno r come
valor medio tra r stesso e n/r (in pratica (r + n/r)/2 )
Mi fermo quando il valore assoluto della differenza tra il valore con cui aggiorno r e il valore precedente di r e' inferiore a 10^-6 Confrontare il risultato con quanto restituito da sqrt(n)

*/

int main(){

int num=0;
double rad=1.0, prec=0.0, confr=1.0; //Con il double si ottiene più precisione e quindi lo stesso risultato

printf("Inserire numero: ");
scanf("%d", &num);

do{

    prec=rad; //Salvo il valore precedente
    rad=((rad + num/rad)/2); //Nuova radice
    confr=(rad-prec); //Calcolo la differenza
    confr=fabs(confr);

}while(confr > pow(10, -6));

printf("Radice di Newton: %f\n", rad);
printf("Radice con square: %f\n", sqrt(num));


}
