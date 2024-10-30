/*
7. usi un array per memorizzare le caselle di una scacchiera 8x8, lo
inizializzi usando uno o piú cicli mettendo 'N' per le caselle nere e
'B' per quelle chiare e successivamente lo stampi:

N   B   N   B   N   B   N   B
B   N   B   N   B   N   B   N
N   B   N   B   N   B   N   B
B   N   B   N   B   N   B   N
N   B   N   B   N   B   N   B
B   N   B   N   B   N   B   N
N   B   N   B   N   B   N   B
B   N   B   N   B   N   B   N
 */

#include<stdio.h>

int main(){
    int righe=8, colonne=8;
    char scacchiera[righe][colonne]; //Matrice 8x8

    for(int i=0; i<righe; i++){ //Scorre le righe dopo aver passato tute le colonne di una riga
        for(int j=0; j<colonne; j++){ //Scorre le colonne di una riga
            if(((i+j)%2) == 0){ //Se la posizione è pari inserisce N, altrimenti B
                scacchiera[i][j] = 'N';
            }else{
                scacchiera[i][j] = 'B';
            }
        }
    }

    //Stampo la matrice
    for (int i = 0; i < righe; i++){
        printf("\n");
        for (int j = 0; j < colonne; j++){
            printf("%c", scacchiera[i][j]);
    }
    }
    

}