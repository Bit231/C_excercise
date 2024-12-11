#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIMNUM (3)
void readdata();
int* simul();


int main(){

    FILE *estrazione;
    estrazione=fopen("elezioni.txt", "r");
    int numeri[DIMNUM]={1,2,3}, cont=0;
    int n,m,k;
    while(1){
        readdata(estrazione, numeri);
        printf("%d %d %d \n", numeri[0], numeri[1], numeri[2]);
        if(numeri[0] == 0 && numeri[1]==0 && numeri[2]==0){
                exit(EXIT_SUCCESS);
        }

        m=numeri[0];
        k=numeri[1];
        n=numeri[2];

        simul(m,k,n);





    }

}


void readdata(FILE *file, int *n){
    if(fscanf(file ,"%d %d %d", &n[0], &n[1], &n[2]) != 3 ){
        n[0]=0; n[1]=0; n[2]=0;
    }
}

int* simul(int m, int k, int n){

    /*
        a) definisce opportuna struttura dati da usarsi per la simulazione (si rammenta che le
        �persone� su cui effettuare la conta sono numerate da 1 a M) == 0 a m-1
    */
    int indicePersone=0; //Uso come indice di persone
    int persRimaste=m; //persone rimaste
    int *persone=malloc(sizeof(int)*m); //Possibile utilizzare anche il VLA
    int* arrayEstratti[n];
     //Persone estratte, n persone
    //Inizializzo l'array con i valori da 1 a M
    for(int i =0; i<m; i++){
        persone[i]=i+1;
    }

    //b) esegue la simulazione
    /*
        Estrarre N persone tra le M totali
    */

    while(persRimaste > n){
        for (int i = 1; i <= k; i++){ //Conta k volte
            do
            {
                indicePersone++; //Viene incrementato finchè punta qualcuno a 0
                if(indicePersone==m){ //Alla posizione dopo di fine array, torna a 0
                    indicePersone=0;
                }
            } while (p[indicePersone]==0);
        }
        //Dopo aver contato k volte lo elimina
            persone[indicePersone]=0;
            persRimaste--;

            do //Questo altro ciclo serve a spostarsi alla prima posizione valida
            {
                indicePersone++;
                if(indicePersone==m){
                    indicePersone=0;
                }
            } while (p[indicePersone]==0);

        }
        
    }





