#include<stdio.h>

int main(){

    int num1=0, num2=0, val=0;
    printf("Inserire numero: ");
    scanf("%d", &num1);

    val=(num1%10)*10;
    num2=val;
    val=num1/10;
    num2+=val;

    printf("Il numero con le cifre invertite: %d\n", num2);
    
    return 0;
}