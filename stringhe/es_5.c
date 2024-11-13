/*
5. implementi la seguente funzione di modo da correggere l'errore di "lingering pointer" presente:
  il problema è presente perchè una volta arrivato in fondo alla funzione, la variabile viene distrutta e
  la porzione di memoria non è più raggiungibile

   char *read_line(void){
    char tmp[2000];
    scanf("%[^\n]", tmp);
    return tmp;
   }
*/

//Soluzione solo con malloc risulta dispendiosa a livello di memoria
//Una ottimizzazione è con realloc dopo aver letto la stringa
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *read_line(void){
    int dim=2000;
    char *tmp=malloc(dim*sizeof(char));//Alloco la memoria necessaria a contenere la frase in un puntatore differente
    //In questo modo la memoria resterà allocata, terrò il primo indirizzo che restituirà
    scanf("%[^\n]", tmp);
    tmp=realloc(tmp, (strlen(tmp)+1)*sizeof(char)); //Realloc la utilizzo per riallocare la memoria e conservare spazio
     

    return tmp; //return dell'indirizzo in posizione 0
}


int main(){
    char *p=read_line();
    int cont=0;

    printf("La frase inserita: ");
    printf("%s", p);
    printf("\n");
}

