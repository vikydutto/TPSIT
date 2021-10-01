#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LUNG 60

void leggiChar(char s[], char frase[LUNG]) {
    printf("%s", frase);
    fflush(stdin);
    scanf("%s", s);
}

bool isMinuscolo(char car) {
    bool ok = false;
    if( car >= 'a' && car <= 'z') {
        ok = true;
    }
    return ok;
}

char upper (char s[], int l) {
    for(int k = 0; k < l; k++) {
        if(isMinuscolo(s[k])) {
            s[k] -= 32;
        }
    }
    return s;
}

int main() {
    char s[LUNG];

    leggiChar(s, "Inserire la parola: ");
    int l = strlen(s);
    upper (s, l);
    printf("%s", s);
    printf("\n");
    system("pause");
    return 0;
}
