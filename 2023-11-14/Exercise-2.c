//Acquisiti i prezzi per N prodotti di un supermercato, trovare e visualizzare:
//a) Prezzo minimo, quante volte compare e ultima posizione
//b) Percentuale prodotti con prezzo in [10;50)
//c) Media prezzi minori di un euro
//d) Quanti prezzi sono uguali ad un riferimento fornito dall’utente


#include <stdio.h>

int main() {
    int con, np, contmin, lastp=0, contp=0, contm=0, contrif=0;
    float prz, min, somma=0, rif;
    do {
        printf("Numero di prodotti: ");
        scanf("%f", &np);
        printf("\n");
    } while (np<=0);

    printf("Riferimento di prezzo: ");
    scanf("%f", rif);
    printf("\n");

    for (cont=0; cont<np; cont++) {
        printf("Prezzo: ");
        scanf("%f", prz);
        printf("\n");

        if(cont==0) {
            lastp=cont;
        }

        if(cont==0||min>prz) {
            min=prz;
            contmin=1;
        }
        else {
            if(min==prz) {
                contmin++;
                lasp=cont;
            }
        }

        if(prz>=10&&prz<50) {
            contp++;
        }

        if(prz<1) {
            contm++;
            somma=somma+prz;
        }

        if(prz==rif) {
            contrif++;
        }
    }

    printf("Prezzo minimo: %f\n", min);
    printf("Compare: %d volte\n", contmin);
    printf("Ultima posizione minimo: %d\n", lastp);
    printf("Percentuale prezzo in [10;50): %f\n", (float) contp*100/cont);
    if(contm==0) {
        printf("Media impossibile!\n");
    }
    else {
        printf("Media prezzi minori di 1 euro: %f\n", (float) somma/contm);
    }
    printf("Numero prezzi uguali a riferimento: %d\n", contrif);

    return 0;
}