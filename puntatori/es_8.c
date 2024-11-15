#include<stdlib.h>
#include<stdio.h>
#include<time.h>

/*
8. Si definisca e inizializzi un array di numeri in cui l'ultimo
elemento, e solo lui, contiene 0.

Si inizializzi un opportuno puntatore che inizialmente punti all'inizio dell'array.

Tramite un ciclo for() stampare il contenuto dell'array non usando un indice ma
facendo variare l'indirizzo contenuto nel puntatore di modo che man
mano contenga l'indirizzo dei vari elementi dell'array.
*/

int main(){

srand(time(0));
int dim=rand()%(20);
short int array[dim]; //VLA, Dimensione definita in runtime

for(int i=0; i<dim; i++){
    array[i]=rand()%(20)+1;
    if(i == (dim-1)){
        array[i]=0;
    }
}

short int *pArr=array;




return 0;
}


