#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
int main(){
    srand(time(NULL));
    FILE *dizionario;
    char nomeFile[]="dizionario.txt";
    char **arrayDizionario = NULL;
    char tmp[100], carattere;
    int dimensione=0, nParola, tentativi=0;
    /*
        1. il programma legge e memorizza in una struttura allocata dinamicamente le parole contenute
        (una per riga) nel file “dizionario.txt”;
    */
    dizionario=fopen(nomeFile, "r");

    while (fscanf(dizionario, "%s", tmp) == 1){ //Condizione per leggere fino alla fine
        dimensione++; //Parola in più == aumento dimensione array
        arrayDizionario=realloc(arrayDizionario, sizeof(char*)*dimensione); //Aggiungo una cella all'array
        arrayDizionario[dimensione-1]=malloc(strlen(tmp)+1); //Alloco dinamicamente la cella aggiunta
        strcpy(arrayDizionario[dimensione-1], tmp);
    }
    fclose(dizionario);
    /* Stampa di prova
    for (int i = 0; i < dimensione; i++){
        printf("%s\n", arrayDizionario[i]);
    }*/
    //printf("Sono presenti %d parole\n", dimensione);

    //2. estrae una parola in maniera casuale;
    nParola=rand()%dimensione; //Numero parola
    char parolaScelta[100];
    strcpy(parolaScelta, arrayDizionario[nParola]);
    
    //printf("Estratta la parola: %s\n", arrayDizionario[nParola]);
    /*
    printf("La parola: ");
    for (int i = 0; i < strlen(arrayDizionario[nParola]); i++){
        printf("*");
    }
    printf("\n");*/
    tentativi=strlen(arrayDizionario[nParola])+2; //Tentativi = lunghezza parola estratta+2
    
    char parolaNascosta[strlen(arrayDizionario[nParola])+1];
    for (int i = 0; i < strlen(arrayDizionario[nParola]); i++){
        parolaNascosta[i]='*';
    }
    parolaNascosta[strlen(arrayDizionario[nParola])]='\0';
    
   do{
        printf("Devi indovinare la parola [%s], ti restano %d tentativi, inserisci una lettera minuscola: ", parolaNascosta, tentativi);
        scanf(" %c", &carattere);
        

        for(int i=0; i<strlen(parolaNascosta); i++){
            if(carattere == parolaScelta[i]){ //Confronto ogni carattere della parola con quello inserito
                parolaNascosta[i]=carattere;
            }
        }

        if(strcmp(parolaNascosta, arrayDizionario[nParola]) == 0){
            printf("Complimenti hai indovinato la parola [%s]!", parolaNascosta);
            exit(EXIT_SUCCESS);
        }

    --tentativi;
   }while(tentativi>0);
   
    printf("HAI ESAURITO I TENTATIVI! MI DISPIACE");
     

}