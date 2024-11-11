#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
8. chieda due parole e verifichi se una e' anagramma dell'altra
*/

int compare(const void* a, const void* b) {
   return (*(char*)a - *(char*)b);
}

int main(){
    int dim=20;
    char p1[dim], p2[dim];

    printf("Inserire prima parola: ");
    scanf(" %[^\n]", &p1);

    
    printf("Inserire seconda parola: ");
    scanf(" %[^\n]", &p2);

    //Primo controllo sulla lunghezza
    /*
    printf("%d\n", strlen(p1));

    printf("%d\n", strlen(p2));
    */
    if(strlen(p1) != strlen(p2)){
        printf("Le due parole non sono una l'anagramma dell'altra");
    }else{
        //Ordino in caratteri per ordine alfabetico e confronto se le stringhe sono uguali
        qsort(p1, strlen(p1), sizeof(char), compare);
        qsort(p2, strlen(p2), sizeof(char), compare);

        if(strcmp(p1, p2) == 0){ //strcmp restituisce 0 se uguali, <0 se p1 < p2, >0 se p1 > p2 
            printf("Le due stringhe sono anagrammi\n");
        }else{
            printf("Le due stringhe non sono anagrammi\n");
        }

    }
}