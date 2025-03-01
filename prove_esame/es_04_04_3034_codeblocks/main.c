#include<stdio.h>
#include<stdlib.h>
#include<math.h>

unsigned int ferm(unsigned int n);

int main(){

    //1. definire un array allocato dinamicamente di unsigned int inizialmente vuoto
    unsigned int *nprimi = NULL; //Array numeri primi
    int n, dim=0, cont=0;

   //2. chiedere all’utente un numero intero n > 1

        printf("Inserire un numero intero: ");
        scanf("%d", &n);

/*
3. per tutti i numeri x da 1 a n si invochi la funzione ferm(x) che restituisce il numero di
divisori primi del numero passato per argomento. Se tale funzione restituisce 2, si
incrementi la dimensione dell’array definito al punto #1 e si aggiunga il numero x a tale
array
*/


//int a=sqrt(n);
//printf("%d", a);

    for (int x = 1; x <= n; x++){ //numeri x da 1 a n
        if(ferm(x) == 2){
            dim++;
            nprimi=realloc(nprimi, sizeof(unsigned int)*dim);
            nprimi[cont]=x;
            cont++;
        }
    }



/*
5. Il programma termina stampando quanti numeri primi sono presenti nell’intervallo [1, n] e
i relativi valori
*/
    printf("Nell'intervallo [1,%d] sono presenti %d valori: ", n, dim);
    for (int i = 0; i < cont; i++){
        printf("%u ", nprimi[i]);
    }
    printf("\n");

    //Voglio scrivere nel file binario i valori primi
    FILE* filebinario=fopen("binario.bin", "w+b");
    if(!filebinario){
        printf("File non aperto correttamente!");
        exit(EXIT_SUCCESS);
    }

    fwrite(&dim, sizeof(unsigned int), 1, filebinario); //Scrivo dimensione per postuma lettura
    fwrite(nprimi, sizeof(unsigned int), dim, filebinario); //Scrivo l'array nel file

    //fseek(filebinario, 1, SEEK_SET); //Torno all'inizio
    fclose(filebinario);
    filebinario=fopen("binario.bin", "rb");

    unsigned int vectDim;
    fread(&vectDim, sizeof(unsigned int), 1, filebinario);
    unsigned int *vettorePrimi = malloc(sizeof(unsigned int)*vectDim);
    fread(vettorePrimi, sizeof(unsigned int), vectDim, filebinario);

    printf("Numeri presi dal binario:");
    for (int i = 0; i < dim; i++){
        printf(" %u", vettorePrimi[i]);
    }


}


unsigned int ferm(unsigned int n){
    /*
4. si implementi la funzione ricorsiva unsigned int ferm(unsigned int n) che svolge i
seguenti passi
*/

//a) se n è uguale a 0 restituisce 0
if(n==0)return 0;

//b) se n è uguale a 1 restituisce 1
if(n==1)return 1;

//c) se n è pari restituisce 1 + ferm(n/2)
if(n%2==0){
    return 1+ferm(n/2);
}
    //d) in alternativa si definiscono tre variabili di tipo intero di appoggio: a, b e b2
    float a=ceil(sqrt(n)); //a viene inizializzata con l’approssimazione per eccesso della radice quadrata di n
    float b2=a*a-n; //b2 viene inizializzata con a × a - n
    int b=sqrt(b2); //b viene inizializzata con la parte intera della radice quadrata di b2


    do{
        //fino a che b2 non è un quadrato esatto si incrementa a e si ricalcolano i valori di b e b2 come indicato
        a++; //Incremento a
        b2=a*a-n;
        b=sqrt(b2);
    }while(b2 != b*b); //finchè b2 non è un quadratp esatto, b*b ci da b2


    /*
    al termine del ciclo se a + b è uguale a n la funzione restituisce 2, altrimenti restituisce
    1 + ferm(a + b)
    */

   if((a+b)==n){
        return 2;
   }else{
        return (1+ferm(a+b));
   }

}


