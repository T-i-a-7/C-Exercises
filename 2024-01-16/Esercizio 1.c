//Acquisita una sequenza di valori numerici reali positivi che termina con il primo valore fuori dall'intervallo [10;2000),
//senza comprendere il valore di fine sequenza, trovare e visualizzare:
//1) Valore massimo fra i valori minori di un riferimento acquisito una sola volta, la prima occorrenza e quante volte compare
//2) Media,dei valori maggiori di 35
//3) Minimo, ultima occorrenza e quante volte compare
//4) Percentuale dei valori uguali a 22
//5) Ogni volta che il valore è maggiore di 1000, visualizzare "Elevato"


#include <stdio.h>

int main() {
    int cont=0, flag=0, firstp, contmax=0, contm=0, lastp, contmin=0, contp=0;
    float num, rif, max, somma=0, min;

    do {
        printf("Riferimento: ");
        scanf("%f", &rif);
    } while (rif<0);

    do {
        printf("Valore numerico: ");
        scanf("%f", &num);
    } while (num<=0);

    while (!(num<10||num>=2000)) {
        if (num<rif) {
            if (flag==0) {
                max=num;
                flag=1;
                firstp=cont+1;
                contmax=1;
            }
            else if (max<num) {
                max=num;
                firstp=cont+1;
                contmax=1;
            }
            else if (max==num) {
                contmax++;
            }
        }

        if (num>35) {
            contm++;
            somma=somma+num;
        }

        if (cont==0) {
            min=num;
            lastp=cont+1;
            contmin=1;
        }
        else if (min>num) {
            min=num;
            lastp=cont+1;
            contmin=1;
        }
        else if (min==num) {
            lastp=cont+1;
            contmin++;
        }

        if (num==22) {
            contp++;
        }

        if (num>1000) {
            printf("Elevato\n");
        }

        cont++;

        do {
            printf("Valore numerico: ");
            scanf("%f", &num);
        } while (num<=0);
    }

    if (cont==0) {
        printf("sequnza nulla\n");
    }

    if (flag==0) {
        printf("Nessun valore minore del riferimento\n");
    }

    printf("Massimo tra valori minori di rif: %f\n", max);
    printf("Prima occorrenza: %d\n", firstp);
    printf("Quante volte compare: %d\n", contmax);

    if (contm==0) {
        printf("Media impossibile\n");
    }
    else {
        printf("Media valori maggiori di 35: %f\n", (float) somma/contm);
    }

    printf("Minimo: %f\n", min);
    printf("Ultima occorrenza: %d\n", lastp);
    printf("Quante volte compare: %d\n", contmin);

    printf("Percentuale valori uguali a 22: %f", (float) contp*100/cont);

    return 0;
}