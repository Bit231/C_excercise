#include<stdlib.h>
#include<stdio.h>

/*1. legga da tastiera una stringa che non contiene caratteri di spaziatura e la stampi*/

int main(){
    char s[]="";

    printf("Inserire una parola: ");
    scanf("%s", &s); //Specificatore di formato s che non considera gli spazi


    printf("Parola inserita: %s\n", s);
}