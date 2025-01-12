//Acquisiti 852 valori numerici, trovare e visualizzare
//a) Il valore massimo e quante volte compare
//b) Quanti valori sono dispari e fuori da (6;27]
//c) La percentuale dei valori fuori da [45;120)
//d) La media dei valori pari ma non multipli di 11


#include <stdio.h>

int main() {
    int a;
    int cont;
    int max;
    int contmax=0;
    int contb=0;
    int contp=0;
    int contm=0;
    int somma=0;
    for (cont=0; cont<8; cont++) {
        printf("Fornisci un valore: ");
        scanf("%d", &a);
        printf("\n");
        
        if (cont==0||max<a) {
            max=a;
            contmax=1;
        }
        else {
           if (max==a) {
                contmax++;
            } 
        }
        
        if ((!(a%2==0))||(a<=6||a>27)) {
            contb++;
        }
        
        if (a<45||a>=120) {
            contp++;
        }
        
        if ((a%2==0)&&(!(a%11==0))) {
            contm++;
            somma=somma+a;
        }
    }
    printf("Massimo: %d\n", max);
    printf("Compare %d volte\n", contmax);
    printf("Quanti valori sono dispari e fuori da (6;27]: %d\n", contb);
    printf("Percentuale dei valori fuori da [45;120): %f\n", (float) contp*100/cont);
    if (contm==0) {
        printf("Media impossibile");
    }
    else {
        printf("Media dei valori pari ma non multipli di 11: %f", (float) somma/contm);
    }
    return 0;
}