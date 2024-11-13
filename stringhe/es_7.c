#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
7. come il (6) in cui per� si convertono anche:
   B -> |3
   D -> |)
   R -> |2
   U -> (_)
*/

int main(){
    
    int dim=400;
    char frase[dim];
    char frase_tradotta[dim];
    int cont=0;


    printf("Inserire frase: ");
    scanf(" %[^\n]", &frase);
    int lung=strlen(frase);

    //Conversione in 133t
    for(int i=0; i<lung; i++){
        switch(frase[i]){
            case 'A':
            case 'a':
                frase_tradotta[cont]='4';
                cont++;
            break;


            case 'B':
            case 'b':
                frase_tradotta[cont]='|';
                frase_tradotta[cont+1]='3';
                cont+=2;
            break;

            case 'D':
            case 'd':
                frase_tradotta[cont]='|';
                frase_tradotta[cont+1]=')';
                cont+=2;
            break;

            case 'E':
            case 'e':
                frase_tradotta[cont]='3';
                cont++;
            
            break;


            case 'G':
            case 'g':
                frase_tradotta[cont]='6';
                cont++;
            break;

            case 'I':
            case 'i':
                frase_tradotta[cont]='1';
                cont++;

            break;

            case 'O':
            case 'o':
                frase_tradotta[cont]='0';
                cont++;
   
            break;

            case 'R':
            case 'r':
                frase_tradotta[cont]='|';
                frase_tradotta[cont+1]='2';
                cont+=2;
            break;

            case 'S':
            case 's':
                frase_tradotta[cont]='5';
                cont++;
            break;

            case 'T':
            case 't':
                frase_tradotta[cont]='7';
                cont++;
    
            break;

            case 'U':
            case 'u':
                frase_tradotta[cont]='(';
                frase_tradotta[cont+1]='_';
                frase_tradotta[cont+2]=')';
                cont+=3;
            break;

            default:{
                frase_tradotta[cont]=frase[i];
                cont++;
                break;
            }


        }


    }

    printf("%s\n", frase_tradotta);
}

