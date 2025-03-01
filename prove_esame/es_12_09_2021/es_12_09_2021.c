#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char *leggi_parola(FILE *fp);

int main(){
    FILE* parole=fopen("parole.txt", "r");
    char *tmp = leggi_parola(parole);
    //printf("post dichiarazione %s", tmp);
    unsigned char **testo=NULL; //array di stringhe
    unsigned long long int dim=0;
    if(!tmp){
        printf("File non aperto correttamente!");
    }else{
        /*
            2. sfruttando la precedente funzione legga il file in opportuna struttura allocata
            dinamicamente
        */
       //printf("pre while");

    while(tmp = leggi_parola(parole)){
        //printf("%llu si ", dim);
        dim++;
    
        testo=realloc(testo, sizeof(char *)*dim); //Estendo l'array
        testo[dim-1]=tmp;
    }

    fclose(parole);
    /*
    for(int i=0; i<dim; i++){
        printf("%s ", testo[i]);
    }*/
    /*
        3. chieda all’utente un numero intero n
    */
    int n=0;
    printf("Inserire un numero intero: ");
    scanf("%d", &n);

    //4. stampi il numero di parole lette che hanno lunghezza n
    printf("Le parole di lunghezza %d sono: \n", n);
    for(int i=0; i<dim; i++){
        if(strlen(testo[i]) == n){
            printf("%s\n", testo[i]);
        }
    }
    printf("\n");

    //5. stampi la piú lunga sequenza di parole di lunghezza n, la relativa lunghezza e in che punto (indice) parte.
    int contSequenza=0, maxSequenza=-1;
    int cont=0, indice=0;
    for(int i=0; i<dim; i++){
        if(strlen(testo[i]) == n){
            cont=i; //Se la lunghezza va bene prendo questo indice
            do{
                contSequenza++; 
                cont++;
            }while ((strlen(testo[cont]) == n)); //Finchè le parole vanno bene aumento il conto
            if(contSequenza>=maxSequenza){ //Se questa sequenza è > dell'altra, allora sotituisco i valori
                indice=i; //Indice di partenza della sequenza nuova
                maxSequenza=contSequenza; //Mi definisce anche la lunghezza
                contSequenza=0; //Reset del contatore per la prossima iterazione
                i=cont;
            }else{
                contSequenza=0;
                i=cont;
            }
        }
    }

    printf("Sequenza di %d parole di lunghezza %d piu' lunga, parte dall'indice %d:\n", maxSequenza, n, indice);
    for (int i = indice; i < maxSequenza+indice; i++){
        printf("%s ", testo[i]);
    }
        
    }

}


    /*
        1. definisca una funzione char *leggi_parola(FILE *fp); che legge una singola parola dal file
        restituendo una stringa allocata dinamicamente oppure NULL se la lettura non è possibile
    */
char *leggi_parola(FILE *fp){
    char *parola=NULL;
    char tmp[100];
    if(!fp){
        return NULL;
    }

        if(fscanf(fp, "%s ", tmp) == 1){
            parola=malloc(strlen(tmp)+1);
            strcpy(parola, tmp);
            return parola;
        }else{
            return NULL;
        }
}
