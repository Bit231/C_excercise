#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIMCODICI (14)
#define DIMPAESI (97)


int controllo(char*);
//Si suggerisce di svolgere i punti richiesti nell’ordine 2.a, 2.b, 2.c, 1 e 2.d.

struct countries{
    int intervallomin;
    int intervalloMax;
    char paese[85];
};

int main(){

    FILE *fileletto=fopen("codici.txt", "r"); //File codici
    FILE *filecountries=fopen("countries.txt", "r"); //File countries
    struct countries paesi[DIMPAESI];
    char ean13[DIMCODICI]; //13 cifre e carattere di terminazione
    int intervalloMax=0, intervalloMin=0, dimensione=0, contPaesi=0, codiceConfronto=0, scambioMM=0;
    char tmp, tmpcodice[4]; //Uso per controllare se c'è l'intervallo, suo per salvare le prime tre cifre
//Punto 1

    while (fscanf(filecountries, "%d", &intervalloMin) == 1) //Così legge solo il primo e poi potrò leggere direttamente il carattere dopo
    {
        paesi[contPaesi].intervallomin=intervalloMin; //Metto il rpimo valore 
        tmp=fgetc(filecountries); //Leggo se c'è il -
        if(tmp == '-'){
            fscanf(filecountries, "%d %[^\n]", &intervalloMax, &paesi[contPaesi].paese);
            paesi[contPaesi].intervalloMax=intervalloMax; //La scanf legge così quello che c'è dopo la getc e la scan f precedente quindi prende il valore dopo -
            contPaesi++;
        }else{
            fscanf(filecountries, " %[^\n]", &paesi[contPaesi].paese); //Se non c'è il -, allora dopo ci sarà direttamente la stringa con il paese
            scambioMM=intervalloMin;
            paesi[contPaesi].intervallomin=0;
            paesi[contPaesi].intervalloMax=scambioMM;
            contPaesi++;
        }
    }


    for (int i = 0; i < DIMPAESI; i++)    
    {
        printf("%d-%d %s\n", paesi[i].intervallomin, paesi[i].intervalloMax, paesi[i].paese);
    }




//Punto 2
    while(fscanf(fileletto, "%s", ean13)==1){
        //a. Stampi il codice letto dal file
        printf("Codice letto: %s\n", ean13); 

        //b. Tramite opportuna funzione verifichi che il codice sia corretto e restituisca vero/falso
        //c. Stampi se il codice è corretto in base al risultato della funzione
        if(controllo(ean13)){
            printf("Codice corretto\n");

            //d. Individui nella struttura creata nel punto (1) il relativo paese di provenienza e lo stampi.
            //prendo le prime tre cifre di ean13 e confronto
            strncpy(tmpcodice, ean13, 3); //primi tre caratteri
            codiceConfronto=atoi(tmpcodice); //atoi() funzione che converte stringa in intero
            printf("%d", codiceConfronto);
            for(int i=0; i<DIMPAESI; i++){
                if(codiceConfronto>=paesi[i].intervallomin && codiceConfronto<=paesi[i].intervalloMax){
                    printf("La merce con codice %d proviene da %s\n", codiceConfronto, paesi[i].paese);
                    break;
            }
    }

        }else{
            printf("Codice non corretto\n");
        }
        printf("\n");
    }
    fclose(fileletto);
    fclose(filecountries);

}   




int controllo(char *codice){
    /*
L’EAN-13 è un tipo di codifica utilizzato per i codici a barre di diversi tipi di merci.
Consiste, come il nome può far supporre, in 13 cifre. s1s2s3s4s5s6s7s8s9s10s11s12s13
• L’ultima cifra (s13) permette di verificare che nella lettura del codice a barre non vi siano stati
errori. Questa viene calcolata sommando i valori delle cifre con indice pari tra 2 e 12 a cui si
aggiunge la somma delle cifre con indice dispari tra 1 e 11 moltiplicata per 3.
In pratica SUM = ∑ spari × 3 + ∑ sdispari
s13 rappresenta l’intero che sommato a SUM rende il risultato divisibile per 10
    */

   int sommaPari=0, sommaDispari=0, sum=0;

   //Il codice passato ha dimensione 14 per il carattere di terminazione quindi l'ultima cifra sarà DIM-1

    //Somma pari
    for (int i = 1; i < (DIMCODICI-2); i+=2){
        sommaPari+=(codice[i] - '0'); //Trasformo in intero dall'ASCII
    }

    //printf("%d\n", sommaPari);

    //Somma Dispari
    for (int i = 0; i < (DIMCODICI-3); i+=2){
        sommaDispari+=(codice[i] - '0'); //Trasformo in intero dall'ASCII
    }

    //printf("%d\n", sommaDispari);

    //SUM = ∑ spari × 3 + ∑ sdispari
    sum=(sommaPari*3)+sommaDispari;
    sum+=codice[DIMCODICI-2]-'0';
    printf("%d", sum);


    //s13 rappresenta l’intero che sommato a SUM rende il risultato divisibile per 10
    if(sum%10 == 0)
        return sum;
    else
        return 0;
}   