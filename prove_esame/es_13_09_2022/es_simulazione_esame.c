#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// costanti da usare per quanto possibile
#define NCARTE 40
#define NCARTE_GIOCATORE (NCARTE/2)

// FUNZIONI GIA' DISPONIBILI
void stampa_carta(int c);      // stampa una singola carta
void stampa_carte(int *c);     // stampa le carte di un giocatore
void stampa_mazzo(int *m);     // stampa carte del mazzo
void ordina_carte(int *carte); // ordina le carte di un singolo giocatore
int  n_carte(int *carte);      // restituisce il n. di carte di un giocatore
int  check(int *g);            // restituisce 1 se il giocatore ha ancora carte e 0 se non ne ha piu'

// FUNZIONI DA IMPLEMENTARE
int *genera_mazzo(void);
void distribuisci_carte(int *mazzo, int *primo, int *secondo);
void elimina_cavallo(int *primo, int *secondo);
void elimina_doppi(int *carte);
void scambio(int *src, int *dst);


// LA MAIN NON VA TOCCATA SALVO COMMENTARE/SCOMMENTARE MESSAGGI DI STAMPA DEL MAZZO GENERATO E LA RELATIVA free(mazzo)
int main(int argc, char **argv){

  srand(time(0));

  int *mazzo = genera_mazzo();

  printf("Mazzo generato: ");
  stampa_mazzo(mazzo);
  printf("Fine mazzo\n");

  // alloco i mazzi dei due giocatori inizializzando tutte le carte a 0
  int *giocatore1=calloc(NCARTE_GIOCATORE, sizeof(int));
  int *giocatore2=calloc(NCARTE_GIOCATORE, sizeof(int));

  // distribuisco le carte ai due giocatori
  distribuisci_carte(mazzo, giocatore1, giocatore2);
    free(mazzo); // non serve piu'

  printf("Dopo aver distribuito le carte, il primo   giocatore ha in mano %2d carte: ", n_carte(giocatore1));
  stampa_carte(giocatore1);
  printf("Dopo aver distribuito le carte, il secondo giocatore ha in mano %2d carte: ", n_carte(giocatore2));
  stampa_carte(giocatore2);

  elimina_cavallo(giocatore1, giocatore2);

  printf("Dopo aver eliminato il cavallo, il primo   giocatore ha in mano %2d carte: ", n_carte(giocatore1));
  stampa_carte(giocatore1);
  printf("Dopo aver eliminato il cavallo, il secondo giocatore ha in mano %2d carte: ", n_carte(giocatore2));
  stampa_carte(giocatore2);
  
  ordina_carte(giocatore1);
  ordina_carte(giocatore2);

  printf("Dopo aver ordinato le carte,    il primo   giocatore ha in mano %2d carte: ", n_carte(giocatore1));
  stampa_carte(giocatore1);
  printf("Dopo aver ordinato le carte,    il secondo giocatore ha in mano %2d carte: ", n_carte(giocatore2));
  stampa_carte(giocatore2);

  elimina_doppi(giocatore1);
  elimina_doppi(giocatore2);

  printf("Dopo aver eliminato i doppi,    il primo   giocatore ha in mano %2d carte: ", n_carte(giocatore1));
  stampa_carte(giocatore1);
  printf("Dopo aver eliminato i doppi,    il secondo giocatore ha in mano %2d carte: ", n_carte(giocatore2));
  stampa_carte(giocatore2);

  int nscambi=1;
  while(1)
  {
    scambio(giocatore1, giocatore2);
    printf("Dopo lo scambio %3d,            il secondo giocatore ha in mano %2d carte: ", nscambi++, n_carte(giocatore2));
    stampa_carte(giocatore2);
    if(!check(giocatore2) || !check(giocatore1))
      break;

    getchar();

    scambio(giocatore2, giocatore1);
    printf("Dopo lo scambio %3d,            il primo   giocatore ha in mano %2d carte: ", nscambi++, n_carte(giocatore1));
    stampa_carte(giocatore1);
    if(!check(giocatore1) || !check(giocatore2))
      break;

    getchar();
  }

  printf("\n");
  if(!check(giocatore1))
  {
    printf("Il primo   giocatore ha vinto,  il secondo e' rimasto con       %2d carte: ", n_carte(giocatore2));
    stampa_carte(giocatore2);
  }
  else
  {
    printf("Il secondo giocatore ha vinto,  il primo   e' rimasto con       %2d carte: ", n_carte(giocatore1));
    stampa_carte(giocatore1);
  }

  free(giocatore1);
  free(giocatore2);

  return 0;
}

int *genera_mazzo(void)
{

    //Alloco dinamicamente il mazzo
    int *mazzo=malloc(NCARTE*sizeof(int));
    int cont=1, temp;
    for(int i=0; i<NCARTE; i++){
        mazzo[i]=cont; //Riempo con numeri da 1 a 40
        cont++;
    }

    for(int i=0; i<NCARTE; i++){
        cont=rand()%40;
        temp=mazzo[cont];
        mazzo[cont]=mazzo[i];
        mazzo[i]=temp;
    }

    return mazzo;
}

void distribuisci_carte(int *mazzo, int *primo, int *secondo)
{
    int cont1=0, cont2=0, contM=0;
    while(contM<NCARTE){
        //Carta al primo giocatore
        primo[cont1]=mazzo[contM];
        cont1++;
        contM++;
        //Carta al secondo
        secondo[cont2]=mazzo[contM];
        cont2++;
        contM++;
    }
}

void elimina_cavallo(int *primo, int *secondo)
{
    int cavallo=39;
    for(int i=0; i<NCARTE_GIOCATORE; i++){
        if(primo[i]==cavallo){
           primo[i]=0;
        }

        if(secondo[i]==cavallo){
           secondo[i]=0;
        }
    }
}

void elimina_doppi(int *carte)
{
    /*
        4. implementare la funzione void elimina_doppi(int *carte) che prende in ingresso le 20
            carte di uno dei due giocatori ed elimina le possibile coppie di carte che hanno lo stesso
            valore. Ad esempio se uno dei giocatori ha tra le sue carte il 2, il 12 e il 32 significa che ha
            tre 2. Questa funzione eliminer� due di queste carte sostituendole con 0
            Si assuma che le carte di ciascun giocatore siano ordinate per valore (quindi per l�esempio
            in questione i tre 2 sarebbero consecutivi)
    */

    ordina_carte(carte);
    stampa_carte(carte);
    printf("\n");

    for(int i=0; i<NCARTE_GIOCATORE-1; i++){
        if(((carte[i]%10)==(carte[i+1]%10)) && carte[i]!=0){ //Essendo ordinate, se la carta prima � uguale alla seconda
            carte[i]=0;
            carte[i+1]=0;
        }
    }

}


void scambio(int *src, int *dst)
{

    /*
    implementare la funzione void scambio(int *src, int *dst) che prende in ingresso le carte
    di due giocatori, preleva -a caso- una carta (che non sia 0) dal mazzo src e l�aggiunge al
    mazzo dst. Tale funzione, prima di terminare, invoca ordina_carte(dst) e
    elimina_doppi(dst).
    */
        int index=0, cont=0;
            do{
                index=rand()%20;
            }while(src[index]==0);

            printf("passato il dowhile %d\n", src[index]);

        while(cont<NCARTE_GIOCATORE){
            if(dst[cont] == 0){
                    printf("Cambio i valori %d\n", dst[cont]);
                dst[cont] = src[index];
                    printf(" %d\n", dst[cont]);
                break;
            }
            cont++;
        }
  // DA LASCIARE IN FONDO ALLA FUNZIONE COME ULTIME ISTRUZIONI
  ordina_carte(dst);
  elimina_doppi(dst);
}












/*****************************************************
  FUNZIONI GIA' DEFINITE -> NON MODIFICARE
*****************************************************/
void stampa_carta(int c)
{
  char semi[] = "CQFP";
  printf("%2d%c ", (c-1)%10+1, semi[(c-1)/10]);
}

void stampa(int *c, int n)
{
  for(int i=0; i<n; ++i)
    if(c[i]) // non stampo posizioni vuote
      stampa_carta(c[i]);
  printf("\n");
}

void stampa_carte(int *c)
{
  stampa(c, NCARTE_GIOCATORE);
}

void stampa_mazzo(int *c)
{
  stampa(c, NCARTE);
}

int _compara_carte(const void *a, const void *b)
{
  int ca = *((int *)a);
  int cb = *((int *)b);

  return ((ca-1)%10 - (cb-1)%10);
}

void ordina_carte(int *carte)
{
  qsort(carte, NCARTE_GIOCATORE, sizeof(int), _compara_carte);
}

int n_carte(int *carte)
{
  int i, c=0;
  for(i=0; i<NCARTE_GIOCATORE; ++i)
    if(carte[i])
      ++c;
  return c;
}


int  check(int *g)
{
  if(n_carte(g))
    return 1;
  return 0;
}
