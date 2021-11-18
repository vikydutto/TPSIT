#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Scrivere un programma che permette all’utente di inizializzare un array unidimensionale
di float e ( facendo uso dell’aritmetica dei puntatori:
- individui gli elementi con valore ripetuti
- sommi i numeri rimasti*/


int main(){
    float *vet;//dichiaro un vettore senza specificare la dimensione perchè verrà specificata successivamente nell'allocazione
    int n;//variabile in cui verrà salvata la dimensione
    int k;//puntatore del ciclo for per il riempimento del vettore
    bool ok = true;
    int q;
    float somma = 0;

    printf("Inserisci la dimensione del vettore: ");
    scanf("%d", &n);

    vet = (float*)malloc(n * sizeof(float));//allocazione dinamica del vettore vet

    for(k = 0; k < n; k++){//riempimento del vettore usando l'aritmetica dei puntatori
        printf("Inserisci il valore: ");
        scanf("%.2f", *(vet + k));
    }

    for(k = 0; k < n; k++){
        for(q = 0; q < n; k++){
            if((vet + k) != (vet + q)){
                if(*(vet + k) == *(vet + q)){
                    ok = false;
                    printf("Valore presente piu' volte");
                }
            }
        }
        if(ok == true){
            somma = somma + *(vet + k);
        }
    }

    printf("La somma degli elementi presenti una sola volta è: %.2f", somma);


    return 0;
}
