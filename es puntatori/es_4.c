#include<stdlib.h>
#include<stdio.h>

/*
4. come il precedente ma inizializzando l'array allocato a 0. Si
verifichi che abbia funzionato stampando il contenuto dell'array prima
di leggere i numeri con cui riempirlo.
*/


int main(){

int dim;

printf("Inserire dimensione memoria: ");
scanf("%d", &dim);

float *array=malloc(sizeof(float) * dim); //Alloco dim celle di memoria per l'array

//Inizializzo l'array a 0
for(int i=0; i<dim; i++){
    array[i]=0;
}

//Stampa dell'array
for(int i=0; i<dim; i++){
    printf("Valore in posizione %d: %f\n", i, array[i]);
}

//Inserimento valori
for(int i=0; i<dim; i++){
    printf("Inserire valore float: ");
    scanf("%f", &array[i]);
}

printf("\n");

//Stampa inversa post inserimento
for(int i=dim-1; i>=0; i--){
    printf("Valore in posizione %d: %f\n", i, array[i]);
}

free(array);


return 0;
}


