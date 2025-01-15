//Acquisiti 7 valori, trovare e visualizzare
//a) Valore minimo e quante volte compare
//b) valore massimo
//c) percentuale valori multipli di 7
//d) media valori fuori da (9;12]
//e) ogni volta che il valore è nullo visualizzare NULLO


#include <stdio.h>

int main() {
    int a;
    int cont;
    int min;
    int contmin=0;
    int max;
    int contp=0;
    int contm=0;
    int somma=0;
    for (cont=0; cont<7; cont++) {
        printf("Fornisi un valore: ");
        scanf("%d", &a);
        
        if (cont==0||min>a) {
            min=a;
            contmin=1;
        }
        else {
            if (min==a) {
                contmin++;
            }
        }
        
        if (cont==0||max<a) {
            max=a;
        }

        if (a%7==0) {
            contp++;
        }

        if (a<=9||a>12) {
            contm++;
            somma=somma+a;
        }

        if (a==0) {
            printf("NULLO\n");
        }
    }
    printf("Minimo: %d\n", min);
    printf("Quante volte compare: %d\n", contmin);
    printf("Massimo: %d\n", max);
    printf("Percentuale valori multipli di 7: %f\n", (float) contp*100/cont);
    printf("Media valori fuori da (9;12]: %f\n", (float) somma/contm);
    return 0;
}