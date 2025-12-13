/*
Acquisito un valore intero positivo, visualizzare un messaggio che indica se è primo oppure no (2 funzioni)
*/



#include <stdio.h>

int primo(int X) {
    int i;

    if (X<=1) {
        return 0;
    }
    for (i=2; i*i<=X; i++) {
        if (X % i == 0) {
            return 0;
        }
    }
    return 1;
}

void messaggio(int X) {
    if(primo(X)) {
        printf("Il numero %d è primo.\n", X);
    } else {
        printf("Il numero %d non è primo.\n", X);
    }
}

int main() {

    int x;

    do {
        printf("Fornisci valore: ");
        scanf("%d", &x);
    } while (x<=0);

    messaggio(x);

    return 0;
}