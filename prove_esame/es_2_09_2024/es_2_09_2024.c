#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct coppie{
    char *parola1;
    char *parola2;
};

int check_palindromi(); //Punto 2
int check_anagrammi(); //Punto 3

int comp(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main(){
    /*
        1. Memorizza il contenuto del file “parole.txt” in una struttura dati, scelta a piacere, e allocata
        dinamicamente
    */
   char tmp1[100], tmp2[100]; //Stringhe di appoggio
    FILE *fp;
    struct coppie *parole = NULL;
    int ncoppie=0, coppia=0, npalindromi=0;
    fp=fopen("parole.txt", "r"); //Apro il file in modalità lettura
    //Leggo il contenuto del file e lo passo nell'array
    
    while(fscanf(fp, "%s %s", tmp1, tmp2) == 2){//Finchè legge entrambe le parole continua
        ncoppie++; //Se la condizione è vera vuol dire che c'è un'altra coppia, quindi aumenta il numero di coppie e lo userò poi come contatore per i cicli
        parole=realloc(parole, sizeof(struct coppie)*ncoppie); //Realloco parole[ncoppie] dove in ogni indicec'è la struct, il tipo di parole == struct
                                                              //Ogni volta aggiungo la dimensione struct per la coppia di parole successiva
        //Alloco dinamicamente ogni componente di parole in modo che punti al suo indirizzo e non a tmp1
        parole[coppia].parola1=malloc(strlen(tmp1)+1); //+1 per carattere terminatore
        parole[coppia].parola2=malloc(strlen(tmp2)+1); //+1 per carattere terminatore

        strcpy(parole[coppia].parola1, tmp1);
        strcpy(parole[coppia].parola2, tmp2);
        coppia++;        
    } 
    fclose(fp);


    for (int i = 0; i < ncoppie; i++){
        printf("La coppia '%s' '%s' ", parole[i].parola1, parole[i].parola2);
        
        //Controllo palindromi
        npalindromi=check_palindromi(parole[i].parola1, parole[i].parola2);
        if(npalindromi==2)printf("contiene %d parole palindrome ", npalindromi);
        if(npalindromi==1)printf("contiene %d parola palindroma ", npalindromi);
        if(npalindromi==0)printf("non contiene parole palindrome ", npalindromi);

        //Controllo anagrammi
        if(check_anagrammi(parole[i].parola1, parole[i].parola2)){
            printf("e sono anagrammi una dell'altra\n");
        }else{
            printf("\n");
        }
    }
    
}        


int check_palindromi(char *parola1, char *parola2){
    /*
        Per ciascuna coppia di parole memorizzata invoca la funzione int check_palindromi(??)
        che, avvalendosi a sua volta di altre funzioni, controlla se nella coppia di parole passata vi
        siano parole palindrome (si definisce palindroma una parola che letta in senso inverso
        rimane comunque uguale, esempio “kayak”). Detta funzione restituisce il numero di parole
        palindrome presenti nella coppia, ovvero 0 se non ve ne sono, 1 se almeno una delle parole
        è palindroma o 2 se le sono entrambe.
    */
   int npalindromi=0;
   char pali1[strlen(parola1)+1];
   char pali2[strlen(parola2)+1];
    int contInverso=0;
    for(int i=strlen(parola1)-1; i>=0; i--){
        pali1[contInverso]=parola1[i];
        contInverso++;
    }
    pali1[contInverso]='\0'; //Inserisco il carattere di terminazione

    //Se vera allora è palindroma
    if(!strcmp(parola1, pali1)){
        npalindromi++;
    }

//////////////////////////////////////////////////////////////////////////////////
    //Stesso controllo con la seconda parola
    contInverso=0;
    for(int i=strlen(parola2)-1; i>=0; i--){
        pali2[contInverso]=parola2[i];
        contInverso++;
    }
    pali2[contInverso]='\0'; //Inserisco il carattere di terminazione

    //Se vera allora è palindroma
    if(!strcmp(parola2, pali2)){
        npalindromi++;
    }

    return npalindromi;
}

int check_anagrammi(char *parola1, char *parola2){
    //Ordino mediante la qsort le lettere, se l'ordine è identico allora sono una l'anagramma dell'altra
    qsort(parola1, strlen(parola1), sizeof(char), comp);
    qsort(parola2, strlen(parola2), sizeof(char), comp);
    
    if(!strcmp(parola1, parola2)){
        return 1;
    }else{
        return 0;
    }


} //Punto 3
