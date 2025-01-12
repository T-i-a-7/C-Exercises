//Acquisiti 154 caratteri, trovare e visualizzare
//a) La percentuale dei caratteri alfabetici maiuscoli
//b) Quanti sono i caratteri che indicano le operazioni algebriche
//c) Il carattere massimo
//d) Ogni volta che il carattere è un carattere numerico visualizzare "Numero"


#include <stdio.h>

int main() {
    char a;
    int cont;
    int contp=0;
    int contb=0;
    char max;
    for (cont=0; cont<10; cont++) {
        printf("Fornisci un carattere: ");
        scanf(" %c", &a);
        printf("\n");

        if (a>='A'&&a<='Z') {
            contp++;
        }

        if (a=='*'||a=='/'||a=='+'||a=='-') {
            contb++;
        }

        if (cont==0||max<a) {
            max=a;
        }

        if (a>='0'&&a<='9') {
            printf("Numero\n");
        }
    }
    printf("Percentuale caratteri alfabetici maiuscoli: %f\n", (float) contp*100/cont);
    printf("Quanti sono i caratteri che indicano le operazioni algebriche: %d\n", contb);
    printf("Carattere massimo: %c\n", max);
    return 0;
}