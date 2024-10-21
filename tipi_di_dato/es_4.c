/*
4. sviluppare un programma che prenda in ingresso un carattere e ripeta fintanto che non sia stato inserito S o N
*/
#include<stdio.h>
int main(){

char c;
do{
    printf("Inserire un carattere: ");
    scanf(" %c", &c);
}while(c == 'S' || c == 'N');

printf("Il carattere inserito: %c\n", c);

}
