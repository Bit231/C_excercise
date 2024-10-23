/*6. Calcolare il numero piu' grande per cui io riesco a calcolare il fattoriale*/

//Inizio a calcolare il fattoriale di n e lo confronto con quello prima, quando quello dopo sarà minore di quello prima --> overflow perchè riparte da capo e quindi ho trovato il numero


#include<stdio.h>
#include<stdlib.h>

int main(){

int n=1;
int facts=1, prec=0;

do{
    facts=1;
    for(int i=1; i<=n; i++){
        facts*=i;
    }
    printf("%d\n", facts);
    prec=facts;
    n++;
    printf("Fattoriale di %d: %d\n", n, facts);

} while (facts >= prec);


}
