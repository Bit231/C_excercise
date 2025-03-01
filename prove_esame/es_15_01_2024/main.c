#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM_SIGLA (2)
#define DIM_CATASTALE (4)
#define NCOM (7900)

struct comune leggiriga(FILE *fc);
void stampacomuni(struct comune *cm);
void stampaprovincia(struct comune *cm, char sig[DIM_SIGLA]);
void ordinacomuni(struct comune *cm);



struct comune{

    /*
        Il file “comuni.csv” riga per riga contiene i dati dei 7900 comuni italiani, ovvero: il nome, un ‘;’, la
        sigla della provincia (2 caratteri), un ‘;’, il codice catastale del comune (4 caratteri).
    */
    char *nomeComune; //verrà allocato
    char sigla[DIM_SIGLA+1]; //Ricorda carattere di terminazione
    char catastale[DIM_CATASTALE+1]; //Ricorda carattere di terminazione
};

int comp(const void *a, const void *b) {
    const struct comune *primo = a;
    const struct comune *secondo = b;

    return strcmp(primo->sigla, secondo->sigla);
}

int main(){
    /*
    1. (8) Definisce opportuna struttura che permette la memorizzazione dei dati contenuti nel
    file. A tal fine si sfrutti la conoscenza del numero di comuni presenti nel file e la presenza
    di dati a lunghezza fissa; si preveda comunque l’uso dell’allocazione dinamica della
    memoria per il nome del comune.
    */

    struct comune comuni[NCOM];
    /*
    Nella main() si implementi un ciclo che, dopo aver aperto il file, invoca questa funzione e
    riempe la struttura definita nel punto #1.
    */
    FILE *comuniCSV=fopen("comuni.csv", "r");
    if(!comuniCSV){
        printf("FILE NON APERTO CORRETTAMENTE!");
    }
    for(int i=0; i<NCOM; i++){
        comuni[i]=leggiriga(comuniCSV);
    }
    fclose(comuniCSV);
    //printf("%s , %s, %s", comuni[0].nomeComune, comuni[0].sigla, comuni[0].catastale); debug

    //
    char sigletta[DIM_SIGLA];
    printf("Inserire sigla provincia: ");
    scanf("%s", sigletta);

    stampaprovincia(comuni, sigletta);

    stampacomuni(comuni);


}

    /*2. (10) Contenga una funzione ?? leggiriga(FILE *, ??); che legge una singola riga del file
    restituendone il contenuto grazie a quanto definito in “??”. È lasciata scelta allo
    sviluppatore se restituire i dati mediante “return” o mediante il passaggio di argomenti alla
    funzione. Qualora la funzione non riesca a leggere dal file deve terminare il programma.*/

struct comune leggiriga(FILE *fc){
    char nCom[100]; //variabili di appoggio per la lettura
    struct comune cm;

    if(fscanf(fc,"%[^;];%[^;]; %s", nCom, cm.sigla, cm.catastale) != 3){
        exit(EXIT_FAILURE);
    }
    cm.nomeComune=malloc(strlen(nCom)+1);
    strcpy(cm.nomeComune, nCom);
    return cm;

}


/*
3. (3) Contenga una funzione void stampacomuni(??); che stampa il contenuto della
struttura definita nel punto #1.
Nella main() si invochi questa funzione dopo il codice indicato nel punto #2. Dopo aver
verificato il corretto funzionamento, si commenti l’invocazione prima di passare al punto
successivo.
*/

void stampacomuni(struct comune *cm){
    printf("LISTA COMUNI:\n");

    for(int i=0; i<NCOM; i++){
        printf("%s\t%s\t%s\n", cm[i].nomeComune, cm[i].sigla, cm[i].catastale);
    }

}


/*
4. (4) Contenga una funzione void stampaprovincia(??, char []); che prende in ingresso la
struttura dati definita al punto #1 e una stringa contenente la sigla di una provincia. Detta
funzione stampa il nome di tutti i comuni presenti in quella provincia.
Ai fini di debug, nella main(), si invochi questa funzione per valutare il corretto
funzionamento.
*/

void stampaprovincia(struct comune *cm, char sig[DIM_SIGLA]){

    printf("Comuni in provincia %s: \n", sig);
    for(int i=0; i<NCOM; i++){
        if(!strcmp(cm[i].sigla, sig)){
            printf("%s, %s\n", cm[i].nomeComune, cm[i].sigla);
        }
    }
}

/*
5. (6) Contenga una funzione void ordinacomuni(??); che prende in ingresso la struttura
dati definita al punto #1 e, sfruttando la funzione predefinita qsort(), cambia l’ordine degli
elementi della struttura dati di modo che siano ordinati per provincia in ordine crescente.
Nella main() si invochi detta funzione e si usi poi la funzione stampacomuni() definita al
punto #3 per verificare il corretto funzionamento di quanto sviluppato
*/
void ordinacomuni(struct comune *cm){
    qsort(cm->sigla, NCOM, sizeof(struct comune), comp);
}


