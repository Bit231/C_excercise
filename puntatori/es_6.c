

#include<stdlib.h>
#include<stdio.h>
#include<time.h>

/*
6. si allochino dinamicamente due array di 100 elementi mediante
calloc() e si stampino gli indirizzi di dove si trovano in memoria.


Utilizzando realloc() si estendano gli array in modo da poter
contenere 200 elementi e si stampino nuovamente gli indirizzi di
dove si trovano.

 Sempre usando realloc() si "accorcino" gli array di
modo da poter contenere 50 elementi e si stampi nuovamente il loro
indirizzo in memoria. Cosa notate?
*/

int main(){

int dim=100;
int *array=calloc(dim, sizeof(int)); //calloc(n elementi, size)
int *array2=calloc(dim,sizeof(int));

printf("Indirizzi del primo array: \n");
for(int i=0; i<dim; i++){
    printf("Indirizzo posizione %d: %p\n", i, &array[i]);
}

printf("Indirizzi del secondo array: \n");
for(int i=0; i<dim; i++){
    printf("Indirizzo posizione %d: %p\n", i, &array2[i]);
}

//Realloc per estendere l'array
    dim+=100;
 array=realloc(array, sizeof(int)*(dim));
 array2=realloc(array2,sizeof(int)*(dim));

//Dimensione aumentata di 100
printf("Indirizzi del primo array dimensione 200: \n");
for(int i=0; i<dim; i++){
    printf("Indirizzo posizione %d: %p\n", i, &array[i]);
}

printf("Indirizzi del secondo array dimensione 200: \n");
for(int i=0; i<dim; i++){
    printf("Indirizzo posizione %d: %p\n", i, &array2[i]);
}

//Diminuisco la dimensione dell'array con realloc
dim=50;

 array=realloc(array, sizeof(int)*(dim));
 array2=realloc(array2,sizeof(int)*(dim));

//Stampo l'array con dimensione 50
printf("Indirizzi del primo array dimensione 50: \n");
for(int i=0; i<dim; i++){
    printf("Indirizzo posizione %d: %p\n", i, &array[i]);
}

printf("Indirizzi del secondo array dimensione 50: \n");
for(int i=0; i<dim; i++){
    printf("Indirizzo posizione %d: %p\n", i, &array2[i]);
}
return 0;
}




