// Acquisiti il numero di clienti giornalieri di un ristorante per N giorni, memorizzarli in un vettore.
// Successivamente trovare il numero massimo di clienti e visualizzare tutti i giorni in cui si è verificato.


#include <stdio.h>

int main () {
    int n, i;
    float max=0;

    do {
        printf("Numero di giorni: ");
        scanf("%d", &n);
    } while (n<=0);

    float c[n];

    for (i=0; i<n; i++) {
        do {
            printf("Numero di clienti giorno %d: ", i+1);
            scanf("%f", &c[i]);
        } while (c[i]<0);    
    }

    for (i=0; i<n; i++) {
        if (i==0||max<c[i]) {
            max=c[i];
        }
    }

    printf("Massimo: %f\n", max);
    printf("Si è verificato: ");

    for (i=0; i<n; i++) {
        if (c[i]==max) {
            printf("giorno %d, ", i+1);
        }
    }

    return 0;
}