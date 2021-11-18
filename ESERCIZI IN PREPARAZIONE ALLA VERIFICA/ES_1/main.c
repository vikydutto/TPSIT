#include <stdio.h>
#include <stdlib.h>

/*Scrivere un programma per leggere e stampare
array bidimensionale di interi. Il programma richiede all’utente il numero
di righe e di colonne dopo di che richiede ad uno ad uno gli elementi da inserire
nell'array. Il programma inoltre deve gestire dinamicamente l'allocazione
e la deallocazione della memoria.*/


int main(){
    int **mat;//creo una matrice senza specificare la dimensione perchè verrà allocata dinamicamente e quindi specificata in seguito
    int nr;//creo due variabili per salvare il numero di righe e di colonne della matrice per poi allocarla dinamicamente
    int nc;
    int k; //creo una variabile da usare come contatore nel ciclo for per l'allocazione dinamica
    int q;//contatori per i cicli for per il riempimento della matrice
    int i;


    printf("Inserici il numero di righe della matrice: ");
    scanf("%d", &nr);
    printf("Inserisci il numero di colonne della matrice: ");
    scanf("%d", &nc);

    mat = (int**)malloc(nr * sizeof(int*));//faccio una prima malloc per allocare dinamicamente le righe della matrice
    for(k = 0; k < nr; k++){//faccio poi un for perchè per ogni riga devo allocare tutte le colonne
        mat[k] = (int*)malloc(nc * sizeof(int));
    }

    for(q = 0; q < nr; q++){//doppio for per caricare la matrice
        for(i = 0; i < nc; i++){
            printf("Inserisci il valore: ");
            scanf("%d", &mat[q][i]);
        }
    }

    for(q = 0; q < nr; q++){//doppio for per stampare la matrice
        for(i = 0; i < nc; i++){
            printf(" %d", mat[q][i]);
        }
        printf("\n");
    }

    return 0;
}
