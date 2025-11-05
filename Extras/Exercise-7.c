/*
Scrivere un programma in C che preveda alcune elaborazioni su un file (il cui nome è fornito dall'utente) che contiene solo valori reali, solo se il file esiste.
Si preveda un menù ripetibile per le seguenti elaborazioni:
    1. Visualizzare tutti i valori, memorizzati nel file, che sono maggiori di un riferimento fornito dall'utente. Visualizzare quanti sono i valori trovati.
    2. Modificare il valore massimo presente nel file supponendo sia unico. La modifica prevede di sostituirlo con la sua metà, se si tratta di un valore maggiore di 500, altrimenti con 0.
    3. Cancellare un valore fornito dall'utente, solo se non si trova in prima posizione.
    4. Trovare la percentuale dei valori che sono fuori dall'intervallo [7:90) e la media totale. Entrambi i valori devono essere scritti in fondo al file VALORI.DAT nell'ordine preferito.
    5. Visualizzare le percentuali o le medie del file VALORI.DAT in base alla scelta dell'utente, sapendo che l'ordine in cui sono scritti i valori è, ovviamente, quello scelto nel punto 4.
    6. Fine
Si preveda di effettuare almeno una funzione per punto del menù.
Si preveda di effettuare almeno due funzioni con il return e due con il passaggio parametri per indirizzo.
Solo i file sono variabili globali.
*/


#include <stdio.h>
#include <stdlib.h>

FILE *fp;

void visualizzazione (char nome[30], int *cont) {
    float val, rif;
    fp = fopen(nome, "rb");

    printf("Riferimento: ");
    scanf("%f", &rif);

    printf("Valori memorizzati:\n");
    while (fread(&val, sizeof(val), 1, fp)==1) {
        if (val>rif) {
            printf("%f\n", val);
            (*cont)++;
        }
    }

    fclose(fp);
}

void modifica (char nome[30], float max) {
    float val;
    fp = fopen(nome, "rb+");
    
    while (fread(&val, sizeof(val), 1, fp)==1) {
        if (val==max) {
            if (val>500) {
                val=val/2;
            } else {
                val=0;
            }
        }
    }

    fclose(fp);
}

int main () {
    int scelta;
    char nome[30];

    printf("Nome file: ");
    scanf("%s", nome);

    if ((fp = fopen(nome, "rb")) == NULL) {
        printf("Impossibile aprire il file.\n");
        return 1;
    } else {
        fclose(fp);

        do {
            printf("Menù\n");
            do {
                printf("Scelta (1-6): ");
                scanf("%d", &scelta);
            } while (scelta<=0||scelta>7);
        
            switch (scelta) {
                case 1: {
                    int cont=0;
                    visualizzazione(nome, &cont);
                    printf("Numero valori: %d", cont);
                    break;
                }
                    
                case 2: {
                    fp = fopen(nome, "rb");
                    float max, val;
                    int flag=0;
                    while (fread(&val, sizeof(val), 1, fp)==1) {
                        if (flag==0) {
                            max=val;
                            flag=1;
                        } else if (val>max) {
                            max=val;
                        }
                    }
                    fclose(fp);
                    modifica(nome, max);
                    break;
                }
        
                case 3: {
    
                    break;
                }
        
                case 4: {
    
                    break;
                }
        
                case 5:{
    
                    break;
                }
        
                case 6: {
                    printf("Fine");
                    break;
                }
            }
        } while (scelta!=6);
    }

    return 0;
}