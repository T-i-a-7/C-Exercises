//Acquisiti 5 valori che rappresentano i prezzi dei prodotti di un supermercato, memorizzarli in un vettore. Successivamente calcolare e visualizzare:
//a) massimo e tutte le posizioni in cui compare
//b) percentuale prezzi fuori dall'intervallo (2; 15)
//c) media dei prezzi maggiori di un riferimento
//d) ogni volta che il valore è maggiore della media calcolata nel punto c, visualizzare "Elevato"


#include <stdio.h>

int main () {
    int i, contp=0, contm=0, 
    float p[5], max=0, rif, somma=0, 

    for (i=0; i<5; i++) {
        do {
            printf("Prezzo del prodotto %d: ", i+1);
            scanf("%f", &p[i]);
        } while (p[i]<=0);
    }

    do {
        printf("Riferimento: ");
        scanf("%f", &rif);
    } while (rif<0);

    for (i=0; i<5; i++) {
        if (i==0 || p[i]>max) {
            max=p[i];
        }

        if (p[i]<=2||p[i]>=15) {
            contp++;
        }

        if (p[i]>rif) {
            somma=somma+p[i];
            contm++;
        }
    }

    printf("Massimo: %f\n", max);

    for (i=0; i<5; i++) {
        if (p[i]==max) {
            printf("Posizioni massimo: %d", i+1);
        }
    }
}