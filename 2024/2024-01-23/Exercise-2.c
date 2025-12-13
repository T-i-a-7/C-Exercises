/*
Acquisita una sequenza di caratteri che termina con il carattere #, trovare e visualizzare:
1. Il carattere minimo e quante volte compare
2. Il carattere massimo fra gli alfabetici maiuscoli e la prima occorrenza
3. La percentuale dei caratteri numerici
4. Quanti caratteri "&" compaiono.
Non si deve comprendere il carattere di fine sequenza nell'elaborazione.
*/


#include <stdio.h>

int main() {
    char carattere, min, max;
    int contmin, cont=0, firstp, contp=0, conte=0;

    printf("Carattere: ");
    scanf("%c", &carattere);

    while (carattere!='#') {
        if (cont==0||min>carattere) {
            min=carattere;
            contmin=1;
        }
        else if (min==carattere) {
            contmin++;
        }

        if (carattere>='A'&&carattere<='Z') {
            if (cont==0||max<carattere) {
                max=carattere;
                firstp=cont+1;
            }
        }

        if (carattere>='0'&&carattere<='9') {
            contp++;
        }

        if (carattere=='&') {
            conte++;
        }

        cont++;

        printf("Carattere: ");
        scanf("%c", &carattere);
    }

    if (cont==0) {
        printf("Ciclo impossibile!\n");
    }
    else {
        printf("Carattere minimo: %c\n", min);
        printf("Quante volte compare: %d\n", contmin);

        printf("Carattere massimo tra gli alfabetici maiuscoli: %c\n", max);
        printf("Prima occorrenza: %d\n", firstp);

        printf("Percentuale numerici: %f\n", (float) cont*100/cont);

        printf("Caratteri &: %d\n", conte);
    }

    return 0;
}