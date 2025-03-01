#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NCOMUNI (7900)
#define DIM_SIGLA (2)
#define DIM_CAT (4)
    /*
    1.Definisce opportuna struttura che permette la memorizzazione dei dati contenuti nel
    file. A tal fine si sfrutti la conoscenza del numero di comuni presenti nel file e la presenza
    di dati a lunghezza fissa; si preveda comunque l’uso dell’allocazione dinamica della
    memoria per il nome del comune.
    */

    struct comune{
        char *nomeComune;
        char sigProvincia[DIM_SIGLA+1]; //Per il carattere di terminazione
        char catastale[DIM_CAT+1]; //Per il carattere di terminazione
    };

struct comune leggiriga(FILE* fp);
void stampacomuni(struct comune *cm);
void stampaprovincia(struct comune *cm, char *sig);
void ordinacomuni(struct comune *cm);

int main()
{

    //Apro il file comuni in lettura
    FILE *listaCom=fopen("comuni.csv", "r");
    if(!listaCom){
        printf("FILE NON APERTO CORRETTAMENTE\n");
    }
    struct comune comuni[NCOMUNI];

    for(int i=0; i<NCOMUNI; i++){
        comuni[i]=leggiriga(listaCom);
    }

    //printf("%s %s %s", comuni[0].nomeComune, comuni[0].sigProvincia, comuni[0].catastale);
    /*
    Nella main() si invochi questa funzione dopo il codice indicato nel punto #2. Dopo aver
    verificato il corretto funzionamento, si commenti l’invocazione prima di passare al punto
    successivo.
    */
    //stampacomuni(comuni);

    //Ricerca comuni tramite provincia
    char sig[DIM_SIGLA];
    printf("Inserire sigla provincia: ");
    scanf("%s", sig);

    stampaprovincia(comuni, sig); //Ai fini di debug, nella main(), si invochi questa funzione per valutare il corretto funzionamento.

    /*Nella main() si invochi detta funzione e si usi poi la funzione stampacomuni() definita al
    punto #3 per verificare il corretto funzionamento di quanto sviluppato
    */

    ordinacomuni(comuni);
    stampacomuni(comuni);
}

/*
2. (10) Contenga una funzione ?? leggiriga(FILE *, ??); che legge una singola riga del file
restituendone il contenuto grazie a quanto definito in “??”. È lasciata scelta allo
sviluppatore se restituire i dati mediante “return” o mediante il passaggio di argomenti alla
funzione. Qualora la funzione non riesca a leggere dal file deve terminare il programma.
Nella main() si implementi un ciclo che, dopo aver aperto il file, invoca questa funzione e
riempe la struttura definita nel punto #1.
*/

 struct comune leggiriga(FILE* fp){

    struct comune riga;
    char nomeCom[100];
    if(fscanf(fp, "%[^;];%[^;];%s", nomeCom, riga.sigProvincia, riga.catastale)==3){
        riga.nomeComune=malloc(strlen(nomeCom)+1);
        strcpy(riga.nomeComune, nomeCom);
        return riga;
    }else{
        exit(EXIT_FAILURE);
    }
 }

 /*
 3. (3) Contenga una funzione void stampacomuni(??); che stampa il contenuto della
struttura definita nel punto #1.
 */
 void stampacomuni(struct comune *cm){

    for(int i=0; i<NCOMUNI; i++){
        printf("%s\t%s\t%s\t\n", cm[i].nomeComune, cm[i].sigProvincia, cm[i].catastale);
    }

 }

 /*
 4. (4) Contenga una funzione void stampaprovincia(??, char []); che prende in ingresso la
struttura dati definita al punto #1 e una stringa contenente la sigla di una provincia. Detta
funzione stampa il nome di tutti i comuni presenti in quella provincia.
Ai fini di debug, nella main(), si invochi questa funzione per valutare il corretto
funzionamento.
 */
 void stampaprovincia(struct comune *cm, char *sig){
    for(int i=0; i<NCOMUNI; i++){
        if(!strcmp(cm[i].sigProvincia, sig)){
            printf("%s\t%s\t%s\t\n", cm[i].nomeComune, cm[i].sigProvincia, cm[i].catastale);
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

int comp(const void *a, const void *b) {

    const struct comune *primo = a;
    const struct comune *secondo = b;

    return strcmp(primo->sigProvincia, secondo->sigProvincia);


}


void ordinacomuni(struct comune *cm){
    qsort(cm, NCOMUNI, sizeof(struct comune), comp);
}

