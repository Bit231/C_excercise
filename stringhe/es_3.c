#include<stdlib.h>
#include<stdio.h>
#include<string.h>
/*3. legga da tastiera una stringa che contiene caratteri di spaziatura e la stampi, ne stampi anche la lunghezza*/

int main(){
    char s[100]="";

    printf("Inserire una parola: ");
    scanf("%[^\n]", s);


    printf("Parola inserita: '%s'\n", s);
    printf("Lunghezza stringa: %d\n", strlen(s)); //strlen(s) restituisce la lunghezza della stringa