/*
Per un supermercato si vogliono gestire le informazioni relative a N prodotti in vendita.
Ciascun prodotto è descritto dalle informazioni:
    - Codice (14 caratteri)
    - Prezzo unitario
    - Quantità 
    - Fornitore (10 caratteri)

Si deve impostare un programma con le strutture che preveda un menù ripetibile con le seguenti richieste:
    0) Visualizzare tutto
    1) Ordine: si devono visualizzare i codici dei prodotti con quantità inferiore ad un riferimento 
    2) Modifiche: si devono modificare per un prodotto, di cui viene fornito il codice, il prezzo (a sostituzione) o la quantità (a incremento)
    3) Cancellazione: si devono cancellare tutte le informazioni di un prodotto di cui è fornito il codice solo se la quantità è inferiore a 10
    4) Percentuale: dei prodotti con prezzo superiore a 30 euro
    5) Media: dei prezzi dei prodotti con quantità > 150
    6) Vettore dei codici e delle quantità dei prodotti di un fornitore specificato dall'utente. Si deve poi visualizzare il vettore costruito
    7) Massimo dei prezzi per i prodotti con una quantità maggiore di un riferimento. Si visualizzino i codici dei prodotti con tale massimo
    8) Fine
*/


#include <stdio.h>
#include <string.h>

int main () {
    int n, i, scelta;

    struct Informazioni {
        char codice[15];
        float prezzo;
        int quantità;
        char fornitore[11];
    };

    struct Informazioni Prodotto[1000];

    do {
        printf("Numero prodotti: ");
        scanf("%d", &n);
    } while (n<=0||n>1000);

    //Acquisizioni
    for (i=0; i<n; i++) {
        printf("\n");
        printf("Informazioni prodotto %d\n", i+1);
        printf("Codice: ");
        scanf("%s", Prodotto[i].codice);
        do {
            printf("Prezzo unitario: ");
            scanf("%f", &Prodotto[i].prezzo);
        } while (Prodotto[i].prezzo<=0);
        do {
            printf("Quantità: ");
            scanf("%d", &Prodotto[i].quantità);
        } while (Prodotto[i].quantità<0);
        printf("Fornitore: ");
        scanf("%s", Prodotto[i].fornitore);
    }

    do {
        printf("\n");
        printf("┌───────────────────────────────────────────────────────────────────────┐\n");
        printf("│                             --- MENÙ ---                              │\n");
        printf("├───────────────────────────────────────────────────────────────────────┤\n");
        printf("│  0) Visualizzare tutto                                                │\n");
        printf("│  1) Ordine: visualizzare i codici dei prodotti con quantità           │\n");
        printf("│     inferiore ad un riferimento                                       │\n");
        printf("│  2) Modifiche: per un prodotto, di cui viene fornito il codice,       │\n");
        printf("│     il prezzo (a sostituzione) o la quantità (a incremento)           │\n");
        printf("│  3) Cancellazione: cancellare tutte le informazioni di un prodotto    │\n");
        printf("│     di cui è fornito il codice solo se la quantità è inferiore a 10   │\n");
        printf("│  4) Percentuale: dei prodotti con prezzo superiore a 30 euro          │\n");
        printf("│  5) Media: dei prezzi dei prodotti con quantità > 150                 │\n");
        printf("│  6) Massimo dei prezzi per i prodotti con una quantità maggiore di    │\n");
        printf("│     un riferimento. Si visualizzino i codici.                         │\n");
        printf("│  7) Fine                                                              │\n");
        printf("└───────────────────────────────────────────────────────────────────────┘\n");
        printf("Seleziona un'opzione: ");
        scanf("%d", &scelta);
        printf("\n");
        
        switch (scelta) {
            case 0:
                for (i=0; i<n; i++) {
                    printf("\n");
                    printf("Informazioni prodotto %d\n", i+1);
                    printf("Codice: %s\n", Prodotto[i].codice);
                    printf("Prezzo unitario: %f\n", Prodotto[i].prezzo);
                    printf("Quantità: %d\n", Prodotto[i].quantità);
                    printf("Fornitore: %s\n", Prodotto[i].fornitore);
                }
                break;

            case 1:
                int j, rif;
                do {
                    printf("Riferimento: ");
                    scanf("%d", &rif);
                } while (rif<0);

                for (j=0; j<n; j++) {
                    if (Prodotto[j].quantità<rif) {
                        printf("Codice: %s\n", Prodotto[j].codice);
                    }
                }
                break;

            case 2:
                int scelta2;
                char cverifica[15];

                printf("Codice prodotto: ");
                scanf("%s", cverifica);

                for (i=0; i<n; i++) {
                    if (strcmp(Prodotto[i].codice, cverifica)==0) {
                        printf("1. Il prezzo (a sostituzione)\n");
                        printf("2. La quantità (a incremento)\n");
                        printf("Cosa modificare: ");
                        scanf("%d", &scelta2);

                        switch (scelta2) {
                            case 1:
                                float prezzo_nuovo;

                                do {
                                    printf("Prezzo nuovo: ");
                                    scanf("%f", &prezzo_nuovo);

                                } while (prezzo_nuovo<=0||prezzo_nuovo==Prodotto[i].prezzo);

                                Prodotto[i].prezzo=prezzo_nuovo;
                            break;

                            case 2:
                                int quantità_incr;

                                do {
                                    printf("Quantità da incrementare: ");
                                    scanf("%d", &quantità_incr);

                                } while (quantità_incr<=0||quantità_incr==Prodotto[i].quantità);

                                Prodotto[i].quantità+=quantità_incr;
                            break;
                        }
                    }
                    break;
                }
        }
    } while (scelta!=7);

    return 0;
}