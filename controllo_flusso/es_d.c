#include<stdio.h>
#include<stdlib.h>

int main(){
    int val=0;

    do{
        printf("Inserire un valore compreso tra 10 e 20: ");
        scanf("%d", &val);
    }while(val>10 && val <20);

    printf("Valore inserito corretto!\n");

}