#include<stdlib.h>
#include<stdio.h>
#define RIGHE (512)
#define COLONNE (20)
int main(){

    //PUNTO 1, LETTURA CORRETTA DEL FILE
    //Dichiario i puntatori FILE
    FILE *fileletto, *fileScritto;
    char nomefile[]="polinomi.txt";

    //fopen per leggere il file
        fileletto=fopen(nomefile, "r");

        //Controllo se aperto correttamente
            if(!fileletto){
                printf("File non aperto correttamente!");
                exit(EXIT_FAILURE);
            }

    //lettura contenuto, inserisco nell'aray bidimensionale sufficientemente grande
    int polinomi[RIGHE][COLONNE]; //Valore letto all'interno del contenuto
    int numero;
    int indRighe=0, indColonne=0;
    char aCapo;
    while (fscanf(fileletto, "%d", &numero) == 1){
        printf("%d", numero);
        if((aCapo=fgetc(fileletto)) == '\n'){
            printf("\n");
            indRighe++;
            indColonne=0;
        }else{
            printf("Savlo numero");
            polinomi[indRighe][indColonne]=numero;
            indColonne++;
        }
    }

    for (int i = 0; i < RIGHE; i++){
            printf("Polinomio %d: ", i+1);
        for (int j = 0; j < COLONNE; j++){
            printf(" %d ", polinomi[i][j]);
        }
        printf("\n");
    }





        
}