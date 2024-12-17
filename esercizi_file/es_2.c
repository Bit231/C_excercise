#include<stdio.h>
#include<stdlib.h>

int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(){
   /*
   Scrivere un programma che:
    Esegua una ricerca binaria per trovare un numero dato inserito dall'utente.
   */

    /*
        Legga una sequenza di numeri interi da un file numeri.txt.
        Utilizzi l'allocazione dinamica per memorizzare i numeri.
    */
    FILE *filenum=fopen("numeri.txt", "r");
    int *numeri= NULL;
    int dim=0, num=0;

    while (fscanf(filenum, "%d ", &num) == 1){
        dim++;
        numeri=realloc(numeri, sizeof(int)*dim);
        numeri[dim-1]=num;
    }

    //Ordini la sequenza di numeri in ordine crescente utilizzando l'algoritmo di ordinamento a scelta (ad esempio, quicksort o bubblesort).
    qsort(numeri, dim, sizeof(int), comp);

    int scelta;

    printf("Inserire un numero da cercare: ");
    scanf("%d", &scelta);

    printf("Lista numeri: ");
    for (int i = 0; i < dim; i++){
        printf("%d ", numeri[i]);
    }
    printf("\n");


    for (int i = 0; i < dim; i++){
        if(numeri[i]==scelta){
            printf("Valore trovato in posizione %d!", i+1);
            exit(EXIT_SUCCESS);
        }
    }

    printf("Valore non trovato -_-");

}