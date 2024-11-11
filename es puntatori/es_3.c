#include<stdlib.h>
#include<stdio.h>

/*
3. chiedere all'utente un numero intero n, allocare array di n float
dinamicamente con malloc(), leggere n numeri a virgola mobile e
memorizzarli nell'array. Al termine stampare i numeri nell'ordine
inverso rispetto a quando li si e' letti. Liberare la memoria prima di
uscire dal programma.
*/

int main(){

int dim;

printf("Inserire dimensione memoria: ");
scanf("%d", &dim);

float *array=malloc(sizeof(float) * dim); //Alloco n celle di memoria per l'array, la dimensione dell'array equivale a dim, sizeof ci restituisce la dimensione del float

//Inserimento dei valori float
for(int i=0; i<dim; i++){
    printf("Inserire valore float: ");
    scanf("%f", &array[i]);
}

printf("\n");

//Stampo i valori nell'ordine inverso
for(int i=dim-1; i>=0; i--){
    printf("Valore in posizione %d: %f\n", i, array[i]);
}

free(array);


return 0;
}


