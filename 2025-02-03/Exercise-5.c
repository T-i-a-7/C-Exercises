/*
Acquisiti N valori pari, trovare e visualizzare la percentuale dei valori maggiori di un riferimento pari
acquisito una sola volta. (3 fn). Non si devono usare vettori.
*/



#include <stdio.h>

int acquisizione(int n, int rif, int *pCount) {
    int x, i=0;

    while (i<n) {
        do {
            printf("Fornisci valore pari: ");
            scanf("%d", &x);
        } while (x<=0 || x%2!=0);

        if (x>rif) {
            (*pCount)++;
        }

        i++;
    }
    return *pCount;
}

float percentuale(int count, int n) {
    return ((float) count/n) * 100;
}

void visualizzazione(float p) {
    printf("Percentuale: %f", p);
}

int main() {

    int n, rif, count=0;

    do {
        printf("Fornisci numero di valori: ");
        scanf("%d", &n);
    } while (n<=0);

    do {
        printf("Fornisci riferimento: ");
        scanf("%d", &rif);
    } while (rif<=0 || rif%2!=0);

    acquisizione(n, rif, &count);
    float p = percentuale(count, n);
    visualizzazione(p);
    
    return 0;
}