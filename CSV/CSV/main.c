//  CSV
//  Created by Vittoria Dutto on 25/02/22.

/* La videoteca "Ciak film" necessita di un programma che carichi la lista film in un array di struttura e che stampi a video i 5 campi : numero, titolo film, genere, anno di uscita, disponibilità film*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 300
#define DIM 100

//il film con ogni suo dato
typedef struct {
    int num;
    int data;
    char titolo[LUNG];
    char disp[LUNG];
    char genere[LUNG];
} film;

//funzione per dividere la sringa in piccole parti
void modificaStringa(char *str, film * x)
{
    char * p=strtok(str, ",");
    strcpy(x->titolo, p);
    p=strtok(NULL, ",");
    strcpy(x->genere, p);
    p=strtok(NULL, ",");
    x->data=atoi(p);
    p=strtok(NULL, ",");
    strcpy(x->disp, p);
}
int contaRighe();
//funzione per contare le righe
int contaRighe(){
    int conta=0;
    FILE*fp=fopen("tabella.txt","r");
    char riga[LUNG];

    while(fgets(riga, LUNG, fp)!=NULL)
    {
        conta++;
    }

    fclose(fp);
    return conta;
}

int main() {
    FILE*fp;
    //allocazione dinamica
    film * tabella;
    tabella=(film*) malloc(contaRighe()*sizeof(film));
    char appoggio[LUNG];
    char nomeFile[LUNG]="listafilm.csv.txt";
    //apre il file
    fp=fopen(nomeFile,"r");
    int k=0;

    //stampa a schermo la tabella
    while(fscanf(fp, "%d,",&(tabella+k)->num)!=EOF) {
        fgets(appoggio, 70,fp);
        modificaStringa(appoggio, tabella+k);
        k++;
    }

    for(int j=0; j<k; j++) {
        printf("Num: %2d, Tit:%s, gen: %s, data: %d, disp: %s\n",(tabella+j)->num, (tabella+j)->titolo,(tabella+j)->genere,(tabella+j)->data,(tabella+j)->disp);
    }

    free(tabella);
    fclose(fp);
    system("pause");
    return 0;
}


