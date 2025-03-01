#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define DIM (34)

int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(){
    srand(time(NULL)); //Inizializzazione time per il rand
    char nomeFile[100]="binario.bin"; //Nome del file utilizzato (binario)
    int dim=DIM; //Dimensione uguale alla costante definita (usata in seguito per la scrittura
    int valori[DIM]; //Vettore inizializzato staticamente

    //Uso rand --> ricorda (max-min+1)+min
    for(int i=0; i<DIM; i++){
        valori[i]=rand()%(DIM+1); //Riempio l'array con valori casuali tra 1 e 34
    }

/*
    Prova precedente con inserimento manuale del nome
    printf("Inserire nome file: ");
    scanf(" %s", nomeFile);
*/

    FILE* fileBinario=fopen(nomeFile, "wb"); //Apertura file binario in modalità scritttura
    //Controllo corretta apertura
    if(!fileBinario){
        printf("FILE NON APERTO CORRETTAMENTE");
        exit(EXIT_SUCCESS);
    }

    //Scrittura nel file binario, elementi interi
    fwrite(&dim, sizeof(int), 1, fileBinario);
    //indirizzo variabile/vettore primo eleemento, dimensione tipo variabile, dimensione(byte, numero di elementi che vengono scritti, file in cui scrivere
    fwrite(valori, sizeof(int), DIM, fileBinario);

    //fseek(fileBinario, 0, SEEK_SET); //Riposiziono l'indice se poi devo fare altre operazioni
    //Oppure chiudo il file e lo riapro in un'altra modalità
    fclose(fileBinario);
    fopen(nomeFile, "rb"); //Aperto in modalità lettura, sono di nuovo all'inizio
    //Prova di lettura interi

    int *vettoreMono = NULL; //Vettore allocato dinamicamente inizializzato vuoto
    int dimensione=0; //Dimensione che otterrò dal file
    fread(&dimensione, sizeof(int), 1, fileBinario);
    //indirizzo variabile/vettore in cui scrivere, dimensione del tipo, nelementi da leggere (byte), file da cui leggere
    vettoreMono=calloc(dimensione, sizeof(int)); //Allocazione dinamica definendo a 0 ciò che non c'è, calloc(dimensione array, dimensione tipo) != da malloc(dimensione*dimensionte tipo)
    fread(vettoreMono, sizeof(int), dimensione, fileBinario);
    printf("dimensione: %d\n", dimensione);

    //Stampo il contenuto
    for(int i=0; i<dimensione; i++){
        printf("%d ", vettoreMono[i]);
    }
    printf("\n");

    //Ordinamento valori
    qsort(vettoreMono, dimensione, sizeof(int), comp);
    //qsort(indirizzoVettore, dimensione, dimensione singolo elemento, funzione comp per il confronto)

    //stampa dopo l'ordinamento
    printf("Post ordinamento: ");
    for(int i=0; i<dimensione; i++){
        printf("%d ", vettoreMono[i]);
    }


}
