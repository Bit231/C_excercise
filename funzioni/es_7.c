#include<stdlib.h>
#include<stdio.h>

/*
7. scrivere una funzione che viene invocata passando due variabili. La
   funzione deve scambiare il contenuto delle due variabili. Si riesce
   a farlo? Si puà fare con i puntatori
*/


void scambio(int* pA,int* pB){
    int* c;
    *c=*pA;
    *pA=*pB;
    *pB=*c;
}

int main(){
    int a,b;
    int* pA;
    int* pB;
    printf("Inserire primo numero: ");
    scanf("%d", &a);

    printf("Inserire secondo numero: ");
    scanf("%d", &b);

    pA=&a;
    pB=&b;

    scambio(pA, pB);

    printf("%d %d\n", a, b);
    

}