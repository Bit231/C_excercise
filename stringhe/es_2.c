#include<stdlib.h>
#include<stdio.h>
/*2. legga da tastiera una stringa che contiene caratteri di spaziatura e la stampi*/
int main(){
    char s[]="";

    printf("Inserire una parola: ");
    scanf("%[^\n]", &s); //Specificatore che legge anche gli spazi


    printf("Parola inserita: %s\n", s);
}