#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char menu();
int *genera(int*);
void stampa(int*, int*);
void salva(int*, int*);
int *load(int* );

int main(){
    char c;
    int dim=0;
    int *pDim=&dim;
    int* quadrato = NULL;
    /*
        1. (6) Iterativamente dalla main() chiami la funzione indicata al punto successivo e, in base, a
        quanto restituito da questa invochi le altre funzioni da sviluppare o esca.
    */

    do{
        c=menu();

        switch (c){
        case 'G':
            //Controllo pari/dispari
            do{
                printf("Inserire un numero dispari: ");
                scanf("%d", &dim);
            }while(dim%2==0);
            quadrato=genera(pDim);



        break;
        
        case 'L':
            quadrato=load(pDim);
        break;
        
        case 'S':
            salva(quadrato, pDim);
        break;
        
        case 'P':
            stampa(quadrato, pDim);
        break;
        }

    }while(c!='X');


}



char menu(){
   /*
        2. (6) Contenga la funzione char menu(); chieda all’utente se vuole: G – generare un nuovo
        quadrato magico, L – caricarlo da file, S – salvarlo su file, P – stampa, X – esci.
   */
    char scelta;

    printf("G - generare un nuovo quadrato magico\n");
    printf("L - caricarlo da file\n");
    printf("S - salvarlo su file\n");
    printf("P - stampa\n");
    printf("X - esci\n");
    printf("Scegliere opzione: ");
    scanf(" %c", &scelta);
    scelta=toupper(scelta);

    return scelta;
}

int *genera(int *size){

    int righe=*size;
    int colonne=*size;
    int contRighe=0, contColonne=colonne/2, numeri=1;
    int vecchie_col, vecchie_rig;
    /*3. (10) Contenga la funzione int *genera(int *size); che chiede all’utente un numero dispari
    (scrivendolo in *size e verificando che sia effettivamente dispari), genera il relativo
    quadrato magico e restituisce un vettore allocato dinamicamente che lo contiene.*/
        //printf("Dimensione passata %d", *size);
        int *matrice=calloc(sizeof(int), (righe*colonne)); //Genero matrice r*c


        //Si comincia posizionando un “1” nella posizione centrale della prima riga; 
        matrice[(contRighe*colonne)+contColonne]=numeri;

        /*
         per inserire il successivo numero, ci si sposta di una posizione in alto e a sinistra incrementando il valore da
        scrivere e si va avanti così (le righe e le colonne esterne si considerano connesse come in una
        superficie toroidale). Se la posizione sulla quale si arriva è già occupata, si torna alla posizione
        precedente e ci si sposta di una riga in basso.
        */

            for (int i = 2; i <= righe*colonne; i++){
                contColonne--; //Mi sposto a sinistra
                if(contColonne<0){
                    contColonne=colonne-1;
                }
                contRighe--; //Mi sposto in alto
                if(contRighe<0){
                    contRighe=righe-1;
                }

                if(matrice[(contRighe*colonne)+contColonne] != 0){
                    
                    contRighe=vecchie_rig+1;
                    contColonne=vecchie_col;
                    matrice[(contRighe*colonne)+contColonne]=i;
                }else{
                    matrice[(contRighe*colonne)+contColonne]=i;
                }

                vecchie_col=contColonne;
                vecchie_rig=contRighe;
            }
        return matrice;

}

/*
4. (5) Contenga la funzione void stampa(int *q, int size) che stampa il contenuto del
quadrato magico passato.
*/
void stampa(int *q, int *size){

    int righe=*size;
    int colonne=*size;

    if(!size){
        printf("Quadrato vuoto\n");
        return;
    }

    printf("Matrice generata\n");
        for (int y = 0; y < righe; y++) {
            for (int x = 0; x < colonne; x++) {
            printf("|%4d ", q[y * colonne + x]);
            }
            printf("\n");
        }
    printf("\n");
}

/*
5. (3) Contenga la funzione void salva(int *q, int size); che chiede all’utente il nome di un
file e salvi il contenuto del quadrato magico in un file binario. Nel file il primo “int”
contiene la dimensione del quadrato magico, i successivi il relativo contenuto.
*/

void salva(int *q, int *size){
    int righe=*size;
    int colonne=*size;
    FILE *fp=fopen("quadrati.bin", "wb");
    if(!fp){
        printf("File non aperto correttamente!");
    }

    fwrite(size, sizeof(int), 1, fp); //Scrivo righe e colonne
    fwrite(q, sizeof(int), righe*colonne, fp);   

    fclose(fp);
}

/*6. (3) Contenga la funzione int *load(int *size); che carica da file -avente lo stesso formato
descritto nel punto precedente- un quadrato magico, restituisce un vettore allocato
dinamicamente con i valori e deposita in *size la dimensione. Detta funzione verifica anche
la correttezza del quadrato magico caricato.*/

int *load(int *size){
    FILE *fp=fopen("quadrati.bin", "rb");
    if(!fp){
        printf("File non aperto correttamente!");
    }
    
    fread(size, sizeof(int), 1, fp);
    printf("Dim: %d\n", *size);
    int righe=*size;
    int colonne=*size;
    int *matrice=malloc(sizeof(int)*(righe*colonne)); //Genero matrice r*c
    fread(matrice, sizeof(int), (righe*colonne), fp);
    fclose(fp);
    return matrice;

}