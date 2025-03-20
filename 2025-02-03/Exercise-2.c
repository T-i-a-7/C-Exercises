/*
Acquisiti 3 valori, controllare che siano i lati di un triangolo ed in quel caso calcolare e visualizzare il
perimetro (4 fn) 
*/



#include <stdio.h>

void acquisizione(float *pA, float *pB, float *pC) {    
    do {
        printf("Fornisci primo valore: ");
        scanf("%f", &*pA);
        printf("Fornisci secondo valore: ");
        scanf("%f", &*pB);
        printf("Fornisci terzo valore: ");
        scanf("%f", &*pC);
    } while (*pA<=0 || *pB<=0 || *pC<=0);
}

int controllo(float a, float b, float c) {
    if (a+b>c && a+c>b && c+b>a) {
        return 1;
    } else {
        return 0;
    }
}

float calcolo(float a, float b, float c) {
    return a+b+c;
}

void visualizzazione(float p) {
    printf("Perimetro: %f", p);
}

int main() {

    float a, b, c;

    acquisizione(&a, &b, &c);
    if (controllo(a, b, c) == 1) {
        float p = calcolo(a, b, c);
        visualizzazione(p);
    } else {
        printf("I tre numeri forniti non sono i lati di un triangolo.");
    }
    
    return 0;
}