//Acquisite le altezze (in m) di N allievi di un scuola primaria, trovare e visualizzare:
//a) Altezza massima, quante volte compare, la prima e l'ultima occorrenza
//b) Media delle altezze superiori a 1,5 m
//c) Percentuale altezze inferiori ad 1 m
//d) Ogni volta che l'altezza è uguale ad un valore di riferimento, visualizzare "Soglia"


#include <stdio.h>

int main() {
    int na, cont, contmax, firstmax=0 , lastmax=0, contm=0, contp=0;
    float h, rif, max, somma=0;

    do {
        printf("Numero di allievi: ");
        scanf(" %d", &na);
        printf("\n");
    } while (na<=0);

    do
    {
        printf("Riferimento: ");
        scanf("%f", &rif);
        printf("\n");
    } while (rif<=0);

    for (cont=0; cont<na; cont++) {
        do {
            printf("Altezza allievo: ");
            scanf("%f", &h);
        } while (h<=0);
        
        if (cont==0||max<h) {
            max=h;
            contmax=1;
            firstmax=cont+1;
            lastmax=cont+1;
        }
        else {
            if (max==h) {
                contmax++;
                lastmax=cont+1;
            }            
        }

        if (h>1.5) {
            contm++;
            somma=somma+h;
        }

        if (h<1) {
            contp++;
        }

        if (h==rif) {
            printf("Soglia\n");
        }
    }

    printf("Altezza massima: %f\n", max);
    printf("Quante volte compare: %d\n", contmax);
    printf("La prima volta in cui compare: %d\n", firstmax);
    printf("L'ultima volta in cui compare: %d\n", lastmax);

    if (contm==0) {
        printf("Media impossibile\n");
    }
    else {
        printf("Media altezza se maggiore di 1.5 metri: %f\n", (float) somma/contm);
    }

    printf("Percentuale altezze inferiori ad 1 metro: %f\n", (float) contp*100/cont);
    
    return 0;
}