/*
5. implementi la seguente funzione di modo da correggere l'errore di "lingering pointer" presente:
   char *read_line(void){
    char tmp[2000];
    scanf("%[^\n]", tmp);
    return tmp;
   }
*/

#include<stdio.h>
#include<stdlib.h>
char *read_line(void){
    int dim=2000;
    char tmp[dim];
    char *nuovoBuff; //Puntatore alla cella di memoria
    scanf("%[^\n]", tmp);

    nuovoBuff=malloc(dim*sizeof(char)); //Alloco la memoria necessaria a contenere la frase

    for(int i=0; i<dim; i++){
        nuovoBuff[i]=tmp[i]; //Assegno il contenuto di tmp a nuovo buff
    }

    return nuovoBuff; //return dell'indirizzo in posizione 0
}


int main(){
    char *p=read_line();
    int cont=0;

    printf("La frase inserita: ");

        printf("%s", p);


    printf("\n");
}

