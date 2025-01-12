//Acquisiti i numeri di visitatori di una grande fiera per N giorni, trovare e visualizzare:
//a) Numero massimo di visitatori, quante volte compare 
//b) Media visitatori se superiori a 50000
//c) Percentuale giorni senza visitatori 
//d) Ogni volta che i visitatori sono minori di 1000, visualizzare “Bassa affluenza”


#include <stdio.h>

int main() {
    int cont, ng, contmax, contm=0, contp=0;
    float vis, max, somma=0;
    do {
        printf("Numero di giorni della fiera: ");
        scanf("%d", &ng);
        printf("\n");
    } while (ng<=0);

    for (cont=0; cont<n; cont++) {
        do {
            printf("Numero di visitatori: ");
            scanf("%f", vis);
            printf("\n");
        } while (vis<0);

        if (cont==0||max<vis) {
            max=vis;
            contmax=1;
        }
        else {
            if (max==vis) {
                contmax++;
            }
        }

        if (vis>50000) {
            contm++;
            somma=somma+vis;
        }

        if (vis==0) {
            contp++;
        }

        if (vis<1000) {
            printf("Bassa affluenza\n");
        }
    }

    printf("Massimo: %f\n", max);
    printf("Compare: %d volte\n", contmax);
    if (contm==0) {
        printf("Media impossibile!\n");
    }
    else {
        printf("Media visitatori se superiori a 50000: %f", (float) somma/contm);
    }
    printf("Percentuale giorni senza visitatori: %f", (float) cont*100/cont);

    return 0;
}