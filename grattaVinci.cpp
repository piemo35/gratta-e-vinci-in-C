#include <cstdio>
#include <cstdlib>
#include <ctime>

/**
 * @author Pietro Piemontese

 * @version 1.0 | November 2018

 * @warning Copyright � 2018 Gratta e vinci by Pietro Piemontese. All rights reserved

 * @mainpage Gratta e vinci in C
*/

int inizio(int vinc);
void sorteggio(int vinc,int numeri[5][5]);
bool controllo(int vinc, int numeri[5][5]);

int main(){
	srand(time(nullptr));
	int numeri[5][5]; //array numeri sorteggiati
	int vinc; //variabile che contiene numero vincente

    int continua=1;
    bool esito = false;

    while (continua==1) {
	    vinc = inizio(vinc);
	    sorteggio(vinc,numeri);
	    esito = controllo(vinc,numeri);
        if (esito)
            printf("\nCOMPLIMENTI, HAI VINTO!\n");
        else
            printf("\nHAI PERSO... RITENTA\n");

        printf("\nVuoi continuare? \n1-si\n2-no \n");
        scanf("%d",&continua);
    }

	return 0;
}


int inizio(int vinc){  ///La funzione inizio() permette di decidere se scegliere un numero o sorteggiarlo, poi prende quel numero e lo mette nella variabile 'vinc'.
	int scelta = 0;

    printf("Vuoi scegliere un numero o sorteggiarlo?\n");
	printf("Per scegliere premi 1\n");
	printf("Per sorteggiare premi 2\n");

	scanf("%d",&scelta);

	switch(scelta){
		case 1:
			printf("Scegli un numero: ");
			scanf("%d",&vinc);
			break;
		case 2:
			vinc=(rand()%100);
			break;
	    default:
	    	printf("Numero non valido");
	}
	return vinc;
}
void sorteggio(int vinc,int numeri[5][5]){  ///La funzione sorteggio() genera 25 numeri da 0 a 99 attraverso la rand()%100 e li mette nella matrice numeri[5][5]
  int i,c;
  printf("\nNumero vincente: %d\n",vinc);
	printf("\nI tuoi numeri:\n\n");
	for(i=0;i<5;i++){
		for(c=0;c<5;c++){
		numeri[i][c]=(rand()%100);
		printf("%d\t",numeri[i][c]);
		}
		printf("\n");
	}
}

bool controllo(int vinc, int numeri[5][5]){ ///La funzione controllo() verifica se il numero scelto dall'esecutore del programma e' uguale ad almeno uno dei numeri sorteggiati, se il controllo risulta vero stampera' la frase 'hai vinto'.
	int i;
	int c;
	for(i=0;i<5;i++){
		for(c=0;c<5;c++) if(numeri[i][c]==vinc)return true;
	}
    return false;
}

