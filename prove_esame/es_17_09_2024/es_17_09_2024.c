#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUM_NAVI (20);

void place_ship(int n, char griglia[n][n], int l);
void stampa_griglia(int n, char griglia[n][n]);
int shoot(int n, char griglia[n][n], int c, int r);

int main(){
    srand(time(NULL));
    /*1. Generare casualmente un numero n nell’intervallo [9,13] e inizializzare opportuna
    struttura per memorizzare la griglia n×n in cui dislocare le navi. Tale struttura va allocata
    dinamicamente*/
    int n=rand()%(5)+9; //(max-min+1)+min --> [9, 13]
    int c,r;
    //Utilizzo il VLA come struttura variabile
    char griglia[n][n];
    int contNavi=NUM_NAVI;
    //Inizializzo la struttura con gli spazi vuoti
    for(int r=0; r<n; r++){
        for (int c = 0; c < n; c++){
            griglia[r][c]=' ';
        }
    }

    /*
    3. Invocare la funzione precedentemente sviluppata per inserire: 1 nave che occupa 4 celle, 2
    navi che occupano 3 celle, 3 navi che occupano 2 celle e 4 navi che occupano una cella sola
    */
    place_ship(n, griglia, 4); //Nave 4 celle
    place_ship(n, griglia, 3); //Nave 3 celle
    place_ship(n, griglia, 3); //Nave 3 celle
    place_ship(n, griglia, 2); //Nave 2 celle
    place_ship(n, griglia, 2); //Nave 2 celle
    place_ship(n, griglia, 2); //Nave 2 celle
    place_ship(n, griglia, 1); //Nave 1 celle
    place_ship(n, griglia, 1); //Nave 1 celle
    place_ship(n, griglia, 1); //Nave 1 celle
    place_ship(n, griglia, 1); //Nave 1 celle


    stampa_griglia(n, griglia);
    
    do{
        printf("Inserire numero riga tra 1 e %d: ", n);
        scanf("%d", &r);
        r--; //Indice array == dim-1
        printf("Inserire numero colonna tra 1 e %d: ", n);
        scanf("%d", &c);
        c--; //Indice array == dim-1

        if(shoot(n, griglia, c, r)){
            printf("Nave colpita\n");
            stampa_griglia(n, griglia);
            contNavi--;
        }else{
            printf("Mancato\n");
            stampa_griglia(n, griglia);
        }
    }while(contNavi > 0);

    printf("TUTTE LE NAVI SONO AFFONDATE!");
}

void place_ship(int n, char griglia[n][n], int l){
    /*2. Sviluppare la funzione void place_ship(??, int l); che inserisce nella struttura
    precedentemente definita in posizione e direzione casuali una nave di lunghezza l di modo
    che non si sovrapponga a navi già precedentemente inserite*/

    unsigned short int direzione=rand()%2; //0 orizzontale, 1 verticale
    int riga; //Genero la riga da cui partire e poi incremento riga/colonna in base alla direzione
    int colonna; //Genero la colonna da cui partire e poi incremento riga/colonna in base alla direzione
        //Rigenero i numeri casuali se lì c'è una x
    int contVerifica=1;


        //controllo se nelle due direzioni c'è qualcosa per la lunghezza l
    do{
            riga=rand()%n;
            colonna=rand()%n;
            contVerifica = 0;
            direzione=rand()%2;

        if(colonna+l <= n){ //Orizzontale, controllo che non sia fuori dai bordi
            if(direzione==0){ //Direzione orizzontale
                for (int c = 0; c < l; c++){ //Ciclo per controllare che tutte le posizioni siano libere
                    if(griglia[riga][colonna+c]==' '){
                        contVerifica++; //Aumento cont verifica finchè ho posizioni vuote
                    }else{
                        contVerifica=0;
                        break;
                    }
                }
            }
        }
        
        if(riga+l <= n){ //Verticale, controllo che non sia fuori dai bordi
            if (direzione==1){ //Direzione verticale
                for (int r = 0; r < l; r++){
                    if(griglia[riga+r][colonna]==' '){
                        contVerifica++;
                    }else{
                        contVerifica=0;
                        break;
                    }
                }
            }
        }
    }while(contVerifica != l); //Qunado è == a l significa che c'è spazio
        


    //pezzo finale in cui piazza tutto
        if(direzione == 0){
            for (int i = 0; i < l; i++){
                griglia[riga][colonna+i]='X';
            }
        }else{
            for (int i = 0; i < l; i++){
                griglia[riga+i][colonna]='X';
            }
        }
        
}



void stampa_griglia(int n, char griglia[n][n]){
    printf("    ");
    for(int i=0; i<n; i++){
        printf(" %d |", i+1);
    }
    printf("\n");
    
    for (int r = 0; r < n; r++){
        printf(" %d |", r+1);
        for (int c = 0; c < n; c++){
            printf(" %c |", griglia[r][c]);
        }
        printf("\n");
    }
}

int shoot(int n, char griglia[n][n], int c, int r){
    
   /*4. Sviluppare la funzione int shoot(??, int c, int r); che “spara” un colpo nella cella di
    coordinate (c, r). Tale funzione, oltre a modificare la struttura dati definita al punto #1,
    restituisce 0 se non sono state colpite navi e 1 se, viceversa, è stata colpita una nave.*/

    if(griglia[r][c] == 'X'){
        griglia[r][c]='O';
        return 1;
    }else{
        griglia[r][c]='V';
        return 0;
    }

}