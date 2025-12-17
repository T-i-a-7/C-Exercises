/*
Impostare un programma per un'agenzia immobiliare che si occupa di affittare appartamenti per l’anno intero.
Per ciascun appartamento si devono gestire i seguenti dati (salvati nel file "APP.h"): 
    Codice appartamento (7 caratteri)
    Cognome proprietario (15 caratteri)
    Numero posti letto
    Prezzo annuo
    Stato (prenotato/disponibile)

Si deve impostare un programma che preveda le seguenti opzioni:
    1) Inserimento nuovo appartamento                                                                 
    2) Cancellazione appartamento                                                                     
    3) Prenotazione appartamento                                                                    
    4) Statistiche                                                                                               
    5) Fine stagione                                                                                                                                                                             

1 richiesta: inserimento di un nuovo appartamento chiedendo le sole informazioni necessarie all’utente.
2 richiesta: cancellazione delle informazioni di un appartamento di cui viene fornito il codice.
3 richiesta: trovare il primo appartamento disponibile con un numero di posti letto inserito dall'utente, prenotarlo e visualizzarne il prezzo.
4 richiesta: calcolare e visualizzare la percentuale degli appartamenti prenotati e la media dei prezzi degli appartamenti disponibili.
5.1 richiesta: predisporre le informazioni per il nuovo anno, cioè eliminare tutte le prenotazioni.
5.2 richiesta: aggiornare gli incassi dei proprietari di cui l'utente fornisce il cognome, per l'anno conluso (fornito una sola volta).
               Operare con il file PROPRIETARI, in cui sono presenti i campi Cognome, Anno ed Incasso totale per ciascun proprietario.
Usare almeno 4 funzioni: 2 con il return e 2 con il passaggio parametri per indirizzo.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE *ap;
FILE *pp;

struct Appartamento {
    char codice[8];
    char cognome[16];
    int posti;
    float prezzo;
    char stato;
};

struct Proprietario {
    char cognome[16];
    int anno;
    float incasso;
};


void Aggiunta (struct Appartamento A) {
    ap = fopen("APP.h", "r+");
}


int main () {
    int scelta;
    struct Appartamento A;

    if ((ap = fopen("APP.h", "r")) == NULL) {
        printf("Errore nell'apertura del file.");
        return 1;
    } else {
        fclose(ap);

        do {
            printf("\nMenù\n");
            printf("1) Inserimento nuovo appartamento\n2) Cancellazione appartamento\n3) Prenotazione appartamento\n4) Statistiche\n5) Fine stagione\n");
            do {
                printf("Scelta: ");
                scanf("%d", &scelta);
            } while (scelta<=0||scelta>7);

            switch (scelta) {
                case 1: {

                    break;
                }

                case 2: {

                    break;
                }

                case 3: {

                    break;
                }

                case 4: {

                    break;
                }

                case 5: {

                    break;
                }
            }
        } while (scelta!=6);
    }

    return 0;
} 