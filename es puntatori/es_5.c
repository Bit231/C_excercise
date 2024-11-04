#include<stdlib.h>
#include<stdio.h>
#include<time.h>
/*
5. si definisca un VLA di short dimensionandolo usando rand() per
generare un numero a caso tra 80 e 100. Lo si riempa con numeri

casuali tra 1 e 20. Mediante allocazione dinamica della memoria,

allocare dinamicamente un secondo array di dimensione pari al primo

sempre di short. Si ricopi il contenuto del primo array nel secondo.
*/

int main(){

srand(time(0));
int dim=rand()%(21)+80;
short int array[dim]; //VLA, Dimensione definita in runtime

for(int i=0; i<dim; i++){
    array[i]=rand()%(20)+1;
}

short int *array2=malloc(sizeof(short int) * dim); //Array dinamico

for(int i=0; i<dim; i++){
    array2[i]=array[i];
}

printf("Contenuto array VLA: ");
for(int i=0; i<dim; i++){
    printf("Valore in posizione %d: %d\n", i, array[i]);
}

printf("\n");

printf("Contenuto array dinamico: ");
for(int i=0; i<dim; i++){
    printf("Valore in posizione %d: %d\n", i, array2[i]);
}


free(array2);


return 0;
}


