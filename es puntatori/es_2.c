#include<stdlib.h>

/*
2. Leggere da tastiera due numeri interi nelle variabili i1 e i2.
Si definiscano e inizializzino due puntatori di modo da contenere
gli indirizzi delle due variabili i1 e i2. Si definisca una terza
variabile sum e relativo puntatore ad essa. Si memorizzi in sum il
risultato della somma di i1 e i2 usando esclusivamente i puntatori. Si
stampi per verifica il contenuto di sum.
*/

int main(){

int i1, i2, sum=0;
int *p1, *p2, *psum;

printf("Inserisci primo numero: ");
scanf("%d", &i1);
p1=&i1;

printf("Inserisci secondo numero: ");
scanf("%d", &i2);
p2=&i2; //Assegno l'indirizzo di memoria

psum=&sum;

*psum=*p1+*p2;


printf("Indirizzo della variabili x: %d\n", *psum);


return 0;
}

