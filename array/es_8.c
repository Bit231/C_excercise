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
    int M=0;
    char scacchiera[dim];

        for (int y = 0; y < righe; y++){
            for (int x = 0; x < colonne; x++){
                if((x+y)%2 == 0){
                    scacchiera[x+(colonne*y)] = 'N';
                }else{
                    scacchiera[x+(colonne*y)] = 'B';
                }

            }
            
        }
        
    for (int y = 0; y < righe; y++){
        printf("\n");
        for(int x=0; x<colonne; x++){
            printf("%c", scacchiera[x+(colonne*y)]);
        }
    } ''
    
    

}