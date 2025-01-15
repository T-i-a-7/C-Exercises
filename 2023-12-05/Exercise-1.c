//Acquisiti per N giorni i numeri di auto in entrata ad un casello autostradale, si devono trovare e visualizzare: 
//a) Massimo di accessi, quante volte compare ed il primo giorno in cui si verifica
//b) Minimo degli accessi se maggiori di un riferimento, quante volte compare e l'ultimo giorno in cui si verifica
//c) Media accessi se compresi nell'intervallo (10000; 100000]
//d) Percentuale giorni in cui gli accessi sono inferiori a 5000
//e) Ogni volta che la giornata non ha avuto accessi, visualizzare "Nessuna entrata"


#include <stdio.h>

int main() {
    int cont, ng, contmax, primog, 
    float auto, max, 

    do {
        printf("Numero di giorni: ");
        scanf("%d", &ng);
        printf("\n");
    } while (ng<=0);

    for (cont=0; cont<ng; cont++) {
        do {
            printf("Numero di auto: ");
            scanf("%f", auto);
            printf("\n");
        } while (auto<0);

        if (cont==0||max<auto) {
            max=auto;
            contmax=1;
        }
        else {
            if (max==auto) {
                contmax++;
            }
        }

        if (cont=0) {
            contg=cont
        }
        else {
            if (max<auto) {

            }
        }
    }
}