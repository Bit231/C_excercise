#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){
    char s[100]="";

    printf("Inserire una parola: ");
    scanf("%[^\n]", s);


    printf("Parola inserita: '%s'\n", s);
    printf("Lunghezza stringa: %d\n", strlen(s));
}