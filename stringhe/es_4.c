#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){
    char s1[10]="";
    char s2[10]="";

    printf("Inserire una stringa 10 caratteri: ");
    scanf(" %[^\n]", &s1);

    printf("Inserire un'altra stringa 10 caratteri: ");
    scanf(" %[^\n]", &s2);

    printf("Lunghezza prima stringa: %d\n", strlen(s1));
    printf("Lunghezza seconda stringa: %d\n", strlen(s2));

    if(strcmp(s1, s2) < 0){
        printf("Ordine alfabetico prima s1 e poi s2: \n");
        printf("%s\n", s1);
        printf("%s\n", s2);
    }else{
        printf("Ordine alfabetico prima s2 e poi s1: \n");
        printf("%s\n", s1);
        printf("%s\n", s2);
    }



}