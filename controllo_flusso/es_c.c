#include<stdio.h>

int main(){

    float n1=0.0, n2=0.0, n3=0.0;
    printf("Inserire primo numero: ");
    scanf("%f", &n1);

    printf("Inserire secondo numero: ");
    scanf("%f", &n2);

    printf("Inserire terzo numero: ");
    scanf("%f", &n3);

    if(n1>n2){
        if(n2>n3){
            printf("n2");
        }else{
            printf("n3");

        }
    }else{
        if(n1>n3){
            printf("n1");
        }else{
            printf("n3");

        }
    }


    return 0;
}