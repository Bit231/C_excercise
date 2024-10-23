/*
    8. redigere un programma che prende in ingresso una sequenza di caratteri e calcola quante vocali contiene.
*/

#include<stdio.h>
#include<stdlib.h>

int main(){

    int nVoc=0;
    char c;

    printf("Inserire parola: ");
    scanf("%c", &c);

    do{
        switch (c)
        {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            nVoc++;
        }
        scanf("%c", &c);
    }while(c != '\n');

    printf("Il numero di vocali nella parola: %d\n", nVoc);
}