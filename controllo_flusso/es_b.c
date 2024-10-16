#include<stdio.h>

int main(){
    int n=0;
    printf("Inserire numero: ");
    scanf("%d", &n);

    if(n%2 == 0){
        printf("IL numero è pari \n");
    }else{
        printf("IL numero è dispari \n");
    }

    return 0;
}