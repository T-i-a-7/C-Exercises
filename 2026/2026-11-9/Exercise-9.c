#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int inizializzazione (int v[], int n);
int cambi_parita (int v[], int n);
int alternanza_massima (int v[], int n);

int main () {
    int n = 0;
    int v[MAX];

    n = inizializzazione(v, n);

    printf("Cambi: %d\n", cambi_parita(v, n));
    printf("Lunghezza: %d\n", alternanza_massima(v, n));

    return 0;
}

int inizializzazione (int v[], int n) {
    do {
        scanf("%d", &n);
    } while (n<1 || n>20);

    for (int i=0; i<n; i++) {
        do {
            scanf("%d", &v[i]);
        } while (v[i]<0 || v[i]>50);
    }

    return n;
}

int cambi_parita (int v[], int n) {
    int cambi = 0;

    for (int i=1; i<n; i++) {
        if ((v[i] % 2) != (v[i-1] % 2)) {
            cambi ++;
        }
    }

    return cambi;
}

int alternanza_massima (int v[], int n) {
    int len = 1, tmp = 1;

    for (int i=1; i<n; i++) {
        if ((v[i] % 2) != (v[i-1] % 2)) {
            len ++;
        } else {
            if (tmp < len) {
                tmp = len;
            }
            len = 1;
        }
    }

    if (tmp > len) {
        return tmp;
    } else {
        return len;
    }
}