#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){
    char s1[11]=""; //11 perchè è presente anche il carattere di terminazione
    char s2[11]="";

    printf("Inserire una stringa 10 caratteri: ");
    scanf(" %[^\n]", &s1); 

    printf("Inserire un'altra stringa 10 caratteri: ");
    scanf(" %[^\n]", &s2); //Inserire uno spazio per evitare di leggere ciò che è già presente nel buffer

    //Stampo le lunghezze
    printf("Lunghezza prima stringa: %d\n", strlen(s1));
    printf("Lunghezza seconda stringa: %d\n", strlen(s2));

    if(strcmp(s1, s2) < 0){ //strcmp effettua un confronto delle stringhe in base all'ordine ASCII, =0 sono uguali, <0 prima s1, >0 prima s2
        printf("Ordine alfabetico prima s1 e poi s2: \n");
        printf("%s\n", s1);
        printf("%s\n", s2);
    }else{
        printf("Ordine alfabetico prima s2 e poi s1: \n");
        printf("%s\n", s1);
        printf("%s\n", s2);
    }



}