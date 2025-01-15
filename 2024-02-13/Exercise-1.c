//Acquisiti una sequenza di valori che termina con il primo valore inserito negativo (<0), trovare e visualizzare:
//a. Valore minimo e quante volte compare, ad esclusione dello 0
//b. Valore massimo
//c. Percentuale valori multipli di 7
//d. Media valori fuori da (9;12]
//e. Ogni volta che il valore è nullo visualizzare NULLO


#include <stdio.h>

int main () {
    int cont=0, contmin=0, contp=0, contm=0, cont2=0;
    float val, min=0, max, somma=0;

    printf("Valore: ");
    scanf("%f", &val);

    while (val>=0) {
        if (val!=0) {
            if (cont2==0||min>val) {
                min=val;
                contmin=1;
            }
            else if (min==val) {
                contmin++;
            }
        }

        if (cont==0||max<val) {
            max=val;
        }
 
        if ((int) val%7==0) {
            contp++;
        }

        if (val<=9||val>12) {
            contm++;
            somma=somma+val;
        }

        if (val==0) {
            printf("Valore nullo.\n");
        }

        if (min!=0) {
            cont2++;
        }

        cont++;

        printf("Valore: ");
        scanf("%f", &val);
    }

    if (cont==0) {
        printf("Ciclo impossibile.\n");
    }
    else {
        printf("\n");

        printf("Valore minimo: %f\n", min);
        printf("Quante volte compare: %d\n", contmin);
    
        printf("Valore massimo: %f\n", max);

        printf("Percentuale valori multipli di 7: %f\n", (float) contp*100/cont);

        if (contm==0) {
            printf("Media impossibile.\n");
        }
        else {
            printf("Media valori fuori da (9;12]: %f\n", (float) somma/contm);
        }
    }

    return 0;
}