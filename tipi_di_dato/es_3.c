#include<stdio.h>

/*
3. sviluppare un programma che legga un char da input, se e' una lettera minuscola lo trasformi in maiuscola, stampi il carattere
*/

int main(){

char c;
int temp=0;
printf("Inserire un carattere: ");
scanf("%c", &c);

if(c>='a' && c<='z'){
    c=c-'a'+'A';
    printf("Il carattere inserito e' %c\n", c);
}else{
    printf("Il carattere inserito e' %c\n", c);
}


}
