/*
Impostare un programma per il centro Rafting Val di Sole. Per ciascun istruttore gestire le seguenti informazioni:
    Codice fiscale (max 16 caratteri)
    Nazionalità (max 10 caratteri)
    Livello (da 1 a 10)
    Costo orario
    Ore effettuate

Le informazioni sono salvate nel file ISTRUTTORI.
Gestire il seguente menu ripetibile:
    1. Aggiungi nuovo istruttore: prevede che l’utente aggiunga i dati di un nuovo istruttore, chiedendo i soli dati necessari all’utente.                                                              
    2. Licenziamento istruttore: cancellazione di tutte le informazioni di un istruttore (di cui viene fornito il codice fiscale), solo se ha fatto almeno 25 ore.
       Visualizzare quanto ha guadagnato. Salvare in fondo al file TFR il codice fiscale e il calcolo della liquidazione
       (Costo orario * ore effettuate / numero di mesi (chiesti all’utente) in cui l’istruttore ha prestato il suo servizio).
    3. Modifica dati: prevede, per l’istruttore di cui è fornito il codice fiscale, la modifica del livello e del costo orario oppure delle ore fatte, incrementandole con un numero fornito dall’utente       
    4. Percentuale istruttori di un livello indicato                                                         
    5. Massimo ore: prevede di trovare e visualizzare il numero massimo di ore effettuate dagli istruttori di un livello indicato dall’utente. Si devono, poi, visualizzare tutti i codici fiscali degli istruttori indicati che hanno tale valore massimo di ore
*/



#include <stdio.h>
#include <string.h>

FILE *ip;
FILE *tp;

struct istruttore {
    char fiscale[17];
    char nazionalita[11];
    int livello;
    float costo;
    int ore;
};

struct licenziato {
    char fiscale[17];
    float liquidazione;
};

void Aggiunta (struct istruttore A) {
    ip = fopen("ISTRUTTORI.h", "a");

    printf("Codice fiscale: ");
    scanf("%s", A.fiscale);
    printf("Nazionalità: ");
    scanf("%s", A.nazionalita);
    A.livello = 1;
    printf("Costo orario: ");
    scanf("%f", A.costo);
    A.ore = 0;

    fclose(ip);
}

void Licenziamento (struct istruttore A) {
    FILE *temp;
    char tf[17];
    float liquidazione = 0;
    int mesi;

    struct licenziato L;

    printf("Codice fiscale: ");
    scanf("%s", tf);

    do {
        printf("Numero mesi: ");
        scanf("%d", &mesi);
    } while (mesi<=0);

    ip = fopen("ISTRUTTORI.h", "r");
    temp = fopen("TEMP.h", "w");
    tp = fopen("TFR.h", "a+");

    while(fread(&A, sizeof(A), 1, ip)==1) {
        if (strcmp(A.fiscale, tf)==0 && A.ore>25) {
            printf("Guadagno: %f\n", A.costo*A.ore);
            L.liquidazione = (A.costo*A.ore)/mesi;
            fwrite(L.fiscale, sizeof(L.fiscale), 1, tp);
            fwrite(L.liquidazione, sizeof(L.liquidazione), 1, tp);
        } else {
            fwrite(&A, sizeof(A), 1, temp);
        }
    }

    fclose(ip);
    fclose(temp);
    ip = fopen("ISTRUTTORI.h", "w");
    temp = fopen("TEMP.h", "r");

    while(fread(&A, sizeof(A), 1, ip)==1) {
        fwrite(&A, sizeof(A), 1, ip);
    }

    fclose(ip);
    fclose(temp);
}

int main () {
    int scelta;
    struct istruttore A;

    if ((ip = fopen("ISTRUTTORI.h", "rb")) == NULL) {
        printf("Errore nell'apertura del file.\n");
        return 1;
    } else {
        fclose(ip);

        do {
            printf("\nMenù\n");
            do {
                printf("\nScelta: ");
                scanf("%d", &scelta);
            } while (scelta<=0||scelta>8);
    
            switch (scelta) {
                case 1: {
                    Aggiunta(A);
                    break;
                }
    
                case 2: {
                    Licenziamento(A);
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
}