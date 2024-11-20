#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <math.h>
/*
1. scrivere una funzione di nome "isprime" che restituisce vero o
   falso a seconda che le sia passato un numero primo o meno
*/

bool isprime(int val){
    bool prime=false;
    int radice=sqrt(val), cont=3;
    printf("Rad: %d\n", radice);

    //Controllo se i valori sono <1 così posso dire subito se è primo o no
    if(val>1){
        if(val==2){ //Se è =2 è primo
            prime=true;
        }else if(val%2!=0){ //Se il numero è >2 e non è pari, cerco i valori da 3 a radn che potrebbero dividerlo, se lo fanno non è primo
            do{
                if(val%cont==0){ //Se il resto tra il valore e il contatore (parte da 3 perchè verifica i numeri >2) è == 0 anche solo in una iterazione allora fermo il ciclo poichè il numero è divisibile per 1, se stesso e un altro valore --> numero non primo
                    prime=false;
                    cont++;
                    break;
                }else{ //Altrimenti lo assegno true come numero primo man mano che cresce il contatore, basterà solo un numero che lo divide e prime tornerà a false definendo il valore come non primo
                    prime=true;
                    cont++;
                }
            } while (cont<=radice); //Controllo fino alla radice quadrata del numero == a (n-1)
        }
    }


    return prime;
}


int main(){
    int valore=0;

    printf("Inserire il valore: ");
    scanf("%d", &valore);

    if(isprime(valore)){ //Funzione booleana che mi restituisce direttamente true o false
        printf("Il numero %d e' primo\n", valore);
    }else{
        printf("Il numero %d non e' primo\n", valore);
    }



}