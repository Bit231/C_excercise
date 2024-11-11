#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
7. come il (6) in cui però si convertono anche:
   B -> |3
   D -> |)
   R -> |2
   U -> (_)
*/

int main(){
    char frase[400]="";

    printf("Inserire frase: ");
    scanf(" %[^\n]", &frase);
    int lung=strlen(frase);

    //Conversione in 133t
    for(int i=0; i<lung; i++){
        switch(frase[i]){
            case 'A':
            case 'a':
                frase[i]='4';
            break;


            case 'B':
            case 'b':{
                char temp[400]="";
                int cont=0;
            for(int j=i+1; j<400; j++){
                temp[cont]=frase[j];
                cont++;
            }
                frase[i]='|';
                frase[i+1]='3';
                cont=0;

                for(int j=i+2; j<400; j++){
                    frase[j]=temp[cont];
                    cont++;
                }
            break;}

            case 'E':
            case 'e':
                frase[i]='3';
                break;


            case 'G':
            case 'g':
                frase[i]='6';
            break;

            case 'I':
            case 'i':
                frase[i]='1';
            break;

            case 'O':
            case 'o':
                frase[i]='0';
            break;

            case 'S':
            case 's':
                frase[i]='5';
            break;

            case 'T':
            case 't':
                frase[i]='7';
            break;
        }


    }

    printf("%s", frase);
}

