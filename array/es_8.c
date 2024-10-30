/*
8. come il precedente ma usando un array monodimensionale...
(suggerimento: data una matrice di N righe e M colonne è possibile
memorizzarla in un array monodimensionale di dimensioni MxN; l'accesso
all'elemento in riga y e colonna x lo posso effettuare accedendo
all'elemento di indice x + M*y)
 */
#include<stdio.h>

int main(){
    //N Righe e M colonne
    int righe=8, colonne=8, dim=righe*colonne;
    char scacchiera[dim];

        for (int y = 0; y < righe; y++){
            for (int x = 0; x < colonne; x++){
                if((x+y)%2 == 0){ //Se la somma tra righe e colonne è pari inserice N altrimenti B
                    scacchiera[x+(colonne*y)] = 'N'; //accedo all'elemento di indice x + M*y)
                }else{
                    scacchiera[x+(colonne*y)] = 'B';
                }

            }
            
        }
        
        //Stampo l'array
    for (int y = 0; y < righe; y++){
        printf("\n");
        for(int x=0; x<colonne; x++){
            printf("%c", scacchiera[x+(colonne*y)]);
        }
    } 
    
    

}