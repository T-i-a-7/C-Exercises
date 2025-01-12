/*
In seguito ad una campagna di licenziamenti, per N dipendenti di una multinazionale vengono inseriti l'importo della liquidazione e l'importo di un eventuale bonus.
L'importo totale deve essere memorizzato in un vettore. Dopo l'acquisizione devono essere trovate e visualizzate:
    a) Media importi maggiori di 50000 euro
    b) Percentuale importi maggiori della media del punto a
    c) Minimo importo se maggiore di un riferimento
    d) Cancellare un valore (supposto unico)
    e) Modificare un valore (supposto unico), incrementandolo di un valore fornito dall'utente
*/


#include <stdio.h>

int main() {
    float lqd, bonus, somma=0, media=0, rif, min, canc, edit, increase;
    int n, i, contm=0, contp=0, flag=0, t;

    do {
        printf("Numero dipendenti: ");
        scanf("%d", &n);
    } while (n<=0);

    float vtot[n];

    for (i=0; i<n; i++) {
        do {
            printf("Importo liquidazione: ");
            scanf("%f", &lqd);
        } while (lqd<=0);

        do {
            printf("Importo bonus: ");
            scanf("%f", &bonus);
        } while (bonus<0);

        vtot[i] = lqd+bonus;
    }

    for (i=0; i<n; i++) {
        if (vtot[i]>50000) {
            contm++;
            somma=somma+vtot[i];
        }
    }

    if (contm==0) {
        printf("Media impossibile.\n");
        printf("Percentuale impossibile.\n");
    }
    else {
        media = somma/contm;
    }

    for (i=0; i<n; i++) {
        if (vtot[i]>media) {
            contp++;
        }
    }

    do {
        printf("Riferimento: ");
        scanf("%f", &rif);
    } while (rif<0);

    for (i=0; i<n; i++) {
        if (vtot[i]>rif) {
            if (flag==0) {
                min=vtot[i];
                flag=1;
            }
            else if (min>vtot[i]) {
                min=vtot[i];
            }
        }
    }

    do {
        printf("Valore da cancellare: ");
        scanf("%f", &canc);
    } while (canc<0);

    for (i=0; i<n; i++) {
        if (vtot[i]==canc) {
            for (t=i; t<n-1; t++) {
                vtot[t]=vtot[t+1];
            }
            n--;
        }
    }

    do {
        printf("Valore da modificare: ");
        scanf("%f", &edit);
        printf("Valore da incrementare: ");
        scanf("%f", &increase);
    } while (edit<0&&increase<0);

    for (i=0; i<n; i++) {
        if (vtot[i]==edit) {
            vtot[i]=vtot[i]+increase;
        }
    }

    printf("Media: %f\n", media);
    printf("Percentuale: %f\n", (float) contp*100/n);

    if (flag==0) {
        printf("Ciclo impossibile.\n");
    }
    else {
        printf("Minimo: %f\n", min);
    }

    for (i=0; i<n; i++) {
        printf("Valore %d: %f\n", i+1, vtot[i]);
    }

    return 0;
}