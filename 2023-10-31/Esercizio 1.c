//Acquisiti 7 caratteri trovare e visualizzare:
//a) Carattere minimo
//b) Percentuale caratteri numerici
//c) Ogni volta che il carattere è @ visualizzare "E-mail"



#include <stdio.h>

int main() {
    char a;
    char min;
    int cont;
    int contp=0;
    for(cont=0;cont<7;cont++) {
        printf("Fornisci un carattere: ");
        scanf(" %c\n", &a);
        if(cont==0) {
            min=a;
        }
        else {
            if(min>a) {
                min=a;
            }
        }
        if(a>='0' && a<='9') {
            contp++;
        }
        if(a=='@') {
            printf("E-mail\n");
        }
    }
    printf("carattere minimo = %c\n", min);
    printf("Percentuale caratteri numerici = %d\n", contp*100/cont);
    return 0;
}