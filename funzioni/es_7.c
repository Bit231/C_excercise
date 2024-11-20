#include<stdlib.h>
#include<stdio.h>

/*
7. scrivere una funzione che viene invocata passando due variabili. La
   funzione deve scambiare il contenuto delle due variabili. Si riesce
   a farlo? Si puà fare con i puntatori
*/


void scambio(int a,int b){
    int* pA=&a;    
    int* pB=&b;
    int* c;

    c=pA;
    pA=pB;
    pB=c;
}

int main(){
    int a,b;

    printf("Inserire primo numero: ");
    scanf("%d", &a);
    printf("%p", &a);

    printf("Inserire secondo numero: ");
    scanf("%d", &b);

    scambio(a, b);

    printf("%d %d", a, b);
    

}