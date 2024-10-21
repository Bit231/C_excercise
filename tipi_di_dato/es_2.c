#include<stdio.h>
#include<stdlib.h>

/*
2. sviluppare un programma che legga un char da input e scriva se e' una lettera maiuscola, minuscola, cifra oppure, se nessuna delle precedenti si applica, e' un carattere speciale
*/

int main(){

char c;

printf("Inserire un carattere: ");
scanf("%c", &c);

if(c>='a' && c<='z'){
    printf("Il carattere inserito e' minuscolo\n");
}else if(c>='A' && c<='Z'){
    printf("Il carattere inserito e' maiuscolo\n");
}else if(c>='0' && c<='9'){
    printf("Il carattere inserito e' una cifra\n");
}else{
    printf("Il carattere inserito e' un carattere speciale\n");
}


}
