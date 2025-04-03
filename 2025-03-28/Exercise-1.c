/*
Si deve impostare un programma con almeno 6 funzioni, di cui 3 con il return e 3 con il passaggio parametri per indirizzo.
Per un supermercato si vogliono gestire le informazioni relative ai prodotti in vendita.
Ciascun prodotto è descritto dalle informazioni:
    Codice (14 caratteri)
    Prezzo unitario
    Quantità 
    Fornitore (10 caratteri)

Quindi si deve impostare un menù ripetibile con le seguenti richieste:
    1) Aggiunta: si devono inserire tutte le informazioni in fondo al vettore, chiedendo all'utente le sole informazioni necessarie, per un prodotto. 
    2) Ordine: si devono visualizzare i codici dei prodotti con quantità inferiore ad un riferimento. 
    3) Modifiche: si devono modificare per un prodotto, di cui viene fornito il codice, il prezzo (a sostituzione) e/o la quantità (a incremento)
    4) Cancellazione: si devono cancellare tutte le informazioni di un prodotto di cui è fornito il codice solo se la quantità è inferiore a 10
    5) Percentuale: dei prodotti con prezzo superiore a 30 euro
    6) Media: dei prezzi dei prodotti con quantità > 150
    7) Vettore dei codici e delle quantità dei prodotti di un fornitore specificato dall'utente. Si deve poi visualizzare il vettore costruito
    8) Massimo dei prezzi per i prodotti con una quantità maggiore di un riferimento. Si visualizzino i codici dei prodotti con tale massimo
    9) Fine
*/



#include <stdio.h>
#include <string.h>

struct Prodotto {
    char Codice[15];
    float Prezzo;
    int Quantita;
    char Fornitore[11];
};

struct Prodotto prodotti[10000];

//funzioni
void Codice (char *CodiceTemp[15]) {
    printf("Codice: ");
    scanf("%s", *CodiceTemp);
}

float Prezzo () {
    float PrezzoTemp;
    do {
        printf("Prezzo: ");
        scanf("%f", &PrezzoTemp);
    } while (PrezzoTemp<=0);
    return PrezzoTemp;
}

int Quantita () {
    int QuantitaTemp;
    do {
        printf("Quantità: ");
        scanf("%d", &QuantitaTemp);
    } while (QuantitaTemp<=0);
    return QuantitaTemp;
}

void Fornitore (char *FornitoreTemp[11]) {
    printf("Fornitore: ");
    scanf("%s", *FornitoreTemp);
}

int main () {
    int scelta, n=0, QuantitaTemp;
    float PrezzoTemp;
    char CodiceTemp[15], FornitoreTemp[11];

    do {
        printf("Menù\n");
        do {
            printf("Scelta: ");
            scanf("%d", &scelta);
        } while (scelta<=0 || scelta>9);
        
        switch (scelta) {
            case 1: {
                Codice(&CodiceTemp);
                strcpy(prodotti[n].Codice, CodiceTemp);
                do {
                    printf("Prezzo: ");
                    scanf("%f", &prodotti[n].Prezzo);
                } while (prodotti[n].Prezzo<=0);
                prodotti[n].Quantita=Quantita;
                Fornitore(&FornitoreTemp);
                strcpy(prodotti[n].Fornitore, FornitoreTemp);

                break;
            }
    
            case 2: {
                int rif, i;

                do {
                    printf("Riferimento: ");
                    scanf("%d", &rif);
                } while (rif<=0);

                for (i=0; i<n; i++) {
                    if (prodotti[i].Quantita < rif) {
                        printf("%s", prodotti[i].Codice);
                    }
                }

                break;
            }
    
            case 3: {
                Codice(&CodiceTemp);
                Prezzo(&PrezzoTemp);
                Quantita(&QuantitaTemp);

                for (int i=0; i<n; i++) {
                    if (prodotti[i].Codice==CodiceTemp) {
                        prodotti[i].Prezzo=PrezzoTemp;
                        prodotti[i].Quantita+=QuantitaTemp;
                    }
                }

                break;
            }
    
            case 4: {
    
                break;
            }
    
            case 5: {
    
                break;
            }
    
            case 6: {
    
                break;
            }
    
            case 7: {
    
                break;
            }
    
            case 8: {
    
                break;
            }
        }
    } while (scelta!=9);

    return 0;
}