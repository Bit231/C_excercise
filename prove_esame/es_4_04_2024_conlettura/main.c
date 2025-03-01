#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int ferm(unsigned int n);

int main(){
    //1. definire un array allocato dinamicamente di unsigned int inizialmente vuoto
    unsigned int *array = NULL;
    int n=0, dim=0;
    //2. chiedere all’utente un numero intero n > 1
    do{
        printf("Inserire un numero n > 1: ");
        scanf("%d", &n);
    }while(n<=1);

    /*
        3. per tutti i numeri x da 1 a n si invochi la funzione ferm(x) che restituisce il numero di
        divisori primi del numero passato per argomento. Se tale funzione restituisce 2, si
        incrementi la dimensione dell’array definito al punto #1 e si aggiunga il numero x a tale
        array
    */
    for(int x=1; x<=n; x++){
        if(ferm(x) == 2){
            dim++;
            array=realloc(array, sizeof(int)*dim);
            array[dim-1]=x; //Metto il valore x nell'array
        }
    }

    /*
        5. Il programma termina stampando quanti numeri primi sono presenti nell’intervallo [1, n] e
        i relativi valori
    */

        printf("Nell'intervallo [1,%d] ci sono %d valori: ", n, dim);
        for(int i=0; i<dim; i++){
            printf("%d ", array[i]);
        }

    printf("\n");
    //6. scrivere i valori su un file binario e rileggerli mettendoli su un altro array, inserire prima la dimensione

    FILE *filebinario=fopen("primi.bin", "wb"); //Apro in scrittura
    unsigned int *valoriBinari = NULL;
    //Scrittura nel file
    fwrite(&dim, sizeof(int), 1, filebinario);
    fwrite(array, sizeof(unsigned int), dim, filebinario);
    fclose(filebinario);

    filebinario=fopen("primi.bin", "rb"); //Apro in lettura
    int dimensione=0;
    fread(&dimensione, sizeof(int), 1, filebinario);//Leggo la dimensione
    valoriBinari = malloc(sizeof(unsigned int)*dimensione);
    fread(valoriBinari, sizeof(unsigned int), dimensione, filebinario);
    fclose(filebinario);

    printf("Valori letti dal file binario, dimensione %d:  ", dimensione);
    for(int i=0; i<dimensione; i++){
        printf("%d ", valoriBinari[i]);
    }

}

int ferm(unsigned int n){
    /*
        4. si implementi la funzione ricorsiva unsigned int ferm(unsigned int n) che svolge i
        seguenti passi
    */
    //a) se n è uguale a 0 restituisce 0
    if(n==0)return 0;
    //b) se n è uguale a 1 restituisce 1
    if(n==1)return 1;
    //c) se n è pari restituisce 1 + ferm(n/2)
    if(n%2==0)return 1+ferm(n/2);

    /*
    d) in alternativa si definiscono tre variabili di tipo intero di appoggio: a, b e b2



    fino a che b2 non è un quadrato esatto si incrementa a e si ricalcolano i valori di b e b2
    come indicato
    al termine del ciclo se a + b è uguale a n la funzione restituisce 2, altrimenti restituisce
    1 + ferm(a + b)
    */

    int a=ceil(sqrt(n)); //a viene inizializzata con l’approssimazione per eccesso della radice quadrata di n
    int b2=a*a-n; //b2 viene inizializzata con a × a - n
    int b=sqrt(b2); //b viene inizializzata con la parte intera della radice quadrata di b2, casting implicito

    //fino a che b2 non è un quadrato esatto si incrementa a e si ricalcolano i valori di b e b2 come indicato
    do{
        a++;
        b2=a*a-n;
        b=sqrt(b2);
    }while(b2 != b*b); //fino a che b2 non è un quadrato perfetto, quindi deve essere == al prodotto della sua radice ovvero b*b

    if(a+b == n){
        return 2;
    }else{
        return 1+ferm(a+b);
    }
}
