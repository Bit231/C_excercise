#include<stdlib.h>
#include<stdio.h>

/*
7. scrivere una funzione che viene invocata passando due variabili. La
   funzione deve scambiare il contenuto delle due variabili. Si riesce
   a farlo? Si puà fare con i puntatori
*/


void scambio(int* pA,int* pB){
    int tmp; //Salvo i contenuti per scambiarli
    //Scambio i contenuti degli indirizzi
    tmp=*pA;
    *pA=*pB;
    *pB=tmp;
}

int main(){
    int a,b;

    printf("Inserire primo numero: ");
    scanf("%d", &a);

    printf("Inserire secondo numero: ");
    scanf("%d", &b);

    scambio(&a, &b); //Passo l'indirizzo della variabile così ogni variazione verrà replicata sull'indirizzo e quindi direttamente sulla variabile

    printf("%d %d\n", a, b);
    

}