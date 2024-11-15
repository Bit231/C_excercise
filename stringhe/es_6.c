#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
6. legga da tastiera una frase e la converta in l33t (basic)
   ovvero converta le seguenti lettere (maiuscole e minuscole) con i caratteri o sequenze di caratteri indicati
   A -> 4
   E -> 3
   G -> 6
   I -> 1
   O -> 0
   S -> 5
   T -> 7
*/

int main(){
    char frase[400]="";

    printf("Inserire frase: ");
    scanf(" %[^\n]", &frase);
    //int lung=strlen(frase);

    //Conversione in 133t
    //For per scorrere la stringa iniziale
    for(int i=0; i<strlen(frase); i++){
        switch(frase[i]){ //In base al carattere entra nel case ed effettua la conversione
            case 'A':
            case 'a':
                frase[i]='4';
            break;


            case 'E':
            case 'e':
                frase[i]='3';
            break;

            case 'G':
            case 'g':
                frase[i]='6';
            break;

            case 'I':
            case 'i':
                frase[i]='1';
            break;

            case 'O':
            case 'o':
                frase[i]='0';
            break;

            case 'S':
            case 's':
                frase[i]='5';
            break;

            case 'T':
            case 't':
                frase[i]='7';
            break;
        }


    }

    printf("%s", frase); //Stampo la stringa
}
