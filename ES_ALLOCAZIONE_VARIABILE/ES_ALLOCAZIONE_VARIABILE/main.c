//
//  main.c
//  ES_ALLOCAZIONE_VARIABILE
//
//  Created by Vittoria Dutto on 04/03/22.
//

#include <stdio.h>
#include <stdlib.h>

/*Crea il programma Allocazione che:
- dichiari una variabile come
  puntatore a char;
- dichiari una variabile come
  puntatore a int;
- allochi correttamente la
  memoria per le due variabili e assegni loro un valore;
- stampi il valore dei due
  puntatori (indirizzo) e il contenuto delle celle di memoria da loro
  puntate;*/



int main(){
    char c;
    int i;
    char *pc;
    int *pi;

    c = 'a';
    i = 5;

    *pc = c;
    *pi = i;

    printf("%c", c);
    printf("\n");
    printf(pc);
    printf("\n");
    printf("%d", i);
    printf("\n");
    printf(pi);

    return 0;
}
