#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define MAX_POLINOMIO (20)

int *leggi_polinomio(FILE*);
void stampa_polinomio(int **, int);
int *somma_polinomi(int **, int, int);

int main(){
        srand(time(NULL));
/*
    1. legge e memorizza in opportuna struttura dati il contenuto del file “polinomi.txt” che
    contiene, riga per riga, la sequenza di costanti ed esponenti che mi rappresentano un
    singolo polinomio separati da uno o piú spazi. Non necessariamente ordinate per
    esponente.
*/

    FILE *fp=fopen("polinomi.txt", "r");
    if(!fp){
        printf("Il file non è stato aperto correttamente");
        exit(EXIT_SUCCESS);
    }
    int **polinomi=NULL; //Matrice organizzata così : polinomi[npolinomio][esponente]=coefficiente;
    //Tipo il primo polinomio con un'esponente di 16 e un coefficiente 4 : polinomi[0][16]=4
    
    int npolinomi = 0; //Tengo conto dei polinomi

    //Lettura dal file secondo questa organizzazione
    //Uso un array di appoggio per leggere il singolo polinomio
    int *pol;
    while(pol=leggi_polinomio(fp)){
        npolinomi++;
        polinomi=realloc(polinomi, sizeof(int *)*npolinomi);
        polinomi[npolinomi-1]=pol; //Salvo il polinomio nella prima riga della matrice
    }

    printf("Ho letto %d polinomi dal file\n", npolinomi);
   /*     
    2. iterativamente:
    a. considerando il numero dei polinomi contenuti nel file generi due numeri casuali tali
    da poter selezionare, casualmente, due polinomi tra quelli letti e memorizzati dal file
    b. stampi i due polinomi “estratti” nel formato ordinato anx^n + a(n-1)x^(n-1) + … + a0
    c. calcoli la somma dei due polinomi e la stampi usando il formato indicato
*/

    /*a. considerando il numero dei polinomi contenuti nel file generi due numeri casuali tali
    da poter selezionare, casualmente, due polinomi tra quelli letti e memorizzati dal file*/

    int rand1=rand()%npolinomi;
    int rand2=rand()%npolinomi;

    //b. stampi i due polinomi “estratti” nel formato ordinato anx^n + a(n-1)x^(n-1) + … + a0
    printf("Sono stati estratti il polinomio numero %d e il numero %d\n", rand1, rand2);
    printf("Polinomio 1: ");
    stampa_polinomio(polinomi, rand1);
    printf("\n");
    printf("Polinomio 2: ");
    stampa_polinomio(polinomi, rand2);
    printf("\n");

    //c. calcoli la somma dei due polinomi e la stampi usando il formato indicato
        int *somma_poli=somma_polinomi(polinomi, rand1, rand2);
    printf("Somma: ");
    for (int i = MAX_POLINOMIO-1; i >= 0; i--){

        if(somma_poli[i]!=0 && somma_poli[i]>0){
            if(i == 0){
                printf("+%d", somma_poli[i]);
            }else{
                printf("+%dx^%d", somma_poli[i], i);
            }
        
        }else if(somma_poli[i]<0){
            if(i == 0){
                printf("%d", somma_poli[i]);
            }else{
                printf("%dx^%d", somma_poli[i], i);
            }
        
        }
    }

    fclose(fp);
}




int *leggi_polinomio(FILE* fp){
    int coef, exp;
    char c;
    int *polinomio=calloc(sizeof(int), (MAX_POLINOMIO+1)); //Inizializzo a un massimo di grado 20

        do{
        
            if(fscanf(fp, "%d %d", &coef, &exp) == 2){
                polinomio[exp]=coef;
            }else{
                return NULL;
            }

            c=fgetc(fp);
        }while(c == ' ');
        
        return polinomio;
    }


void stampa_polinomio(int **poly, int n_estratto){
    for (int i = MAX_POLINOMIO-1; i >= 0; i--){

        if(poly[n_estratto][i]!=0 && poly[n_estratto][i]>0){
            if(i == 0){
                printf("+%d", poly[n_estratto][i], i);
            }else{
                printf("+%dx^%d", poly[n_estratto][i], i);
            }
        
        }else if(poly[n_estratto][i]<0){
            if(i == 0){
                printf("%d", poly[n_estratto][i], i);
            }else{
                printf("%dx^%d", poly[n_estratto][i], i);
            }
        
        }
    }
    

}

int* somma_polinomi(int **poly, int n1, int n2){
    int *somma=calloc(sizeof(int), (MAX_POLINOMIO+1)); //Polinomio che conterrà la somma

    for (int i = MAX_POLINOMIO-1; i >= 0; i--){
            somma[i]=poly[n1][i]+poly[n2][i];
    }

    return somma;

}