//Acquisiti 97 valori numerici, trovare e visualizzare:
//a) Il valore minimo e quante volte compare
//b) La media dei valori in [35;230]
//c) La percentuale dei valori positivi fuori dall'intervallo [180;390]
//d) Ogni volta che il valore è nullo visualizzare "Valore non accettabile"


#include <stdio.h>

int main() {
    int a;
    int cont;
    int min;
    int contmin;
    int contm;
    int somma;
    int contp;
    for (cont=0; cont<97; cont++) {
        printf("Fornisci un valore: ");
        scanf("%d", &a);
        printf("\n");

        if (cont==0||min>a) {
            min=a;
            contmin=1;
        }
        else {
            if (min==a) {
                contmin++;
            }
        }

        if (a>=35&&a<=230) {
            contm++;
            somma=somma+a;
        }

        if (a>0&&(a<180||a>390)) {
            contp++;
        }

        if (a==0) {
            printf("Valore non accettabile\n");
        }
    }
    printf("Minimo: %d\n", min);
    printf("Quante volte compare: %d\n", contmin);
    if (contm==0) {
        printf("Media impossibile");
    }
    else {
        printf("Media dei valori in [35;230]: %f\n", (float) somma/contm);
    }
    printf("Percentuale dei valori positivi fuori dall'intervallo [180;390]: %f\n", (float) contp*100/cont);
    return 0;
}