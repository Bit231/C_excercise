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
float numero;

printf("Inserire dimensione memoria: ");
scanf("%d", &dim);

float *array=malloc(sizeof(int) * dim); //Alloco dim celle di memoria per l'array

   if(!array) // equivalente a a==NULL
 {     printf("ERRORE: non e' stato possibile allocare la memoria richiesta per %lu interi (%d byte)\n", dim, dim*sizeof(int));     exit(1);
   }

for(int i=0; i<dim; i++){
    printf("Inserire valore float: ");
    scanf("%f", &numero);
    array[i]=numero;
}

printf("\n");

for(int i=dim-1; i>=0; i--){
    printf("Valore in posizione %d: %f\n", i, array[i]);
}

free(array);


return 0;
}


