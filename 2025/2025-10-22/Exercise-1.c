/*
Si deve impostare un programma che costruisca un file, il cui nome fisico è INTERI, inserendo all'interno N valori.
Si imposti il programma nel seguente modo:
- se il file non esiste crearlo ed inserire N valori
- se il file esiste si deve chiedere all’utente se vuole mantenerlo oppure cancellare tutti i dati; in quest’ultimo caso si deve effettuare la cancellazione e l’inserimento di N valori

Successivamente si deve impostare un menu ripetibile con le seguenti richieste:
    1. Visualizzazione dei dati presenti nel file
    2. Aggiunta valori, con il quale si devono aggiungere in fondo N (ovviamente chiedendolo all'utente) valori forniti dall'utente
    3. Calcolo della media dei valori positivi e visualizzazione
    4. Calcolo della percentuale dei valori multipli di 3 maggiori di 8
    5. Visualizzazione del valore massimo pari, quante volte compare e l'ultima posizione
    6. Cancellazione di un valore fornito dall'utente
    7. Modifica di un valore fornito dall'utente, la prima volta che compare. L'utente fornisce il nuovo valore. Si deve segnalare se la modifica non è stata effettuata

Si provi a scrivere il programma con 5 funzioni di cui almeno una con il return ed una con il passaggio parametri per indirizzo.
Si lavori leggendo e scrivendo su file un valore scalare alla volta. Si ricorda che per gestire degli interi, è necessario usare nella modalità di apertura il carattere b (per esempio “rb”, oppure “wb+”, ecc.)
*/



#include <stdio.h>
#include <stdlib.h>

FILE *F;

void visualizza () {
    int val;
    F=fopen ("INTERI.bin","rb");
    while (fread (&val, sizeof(int), 1, F)>0) {
        printf ("%d\n", val);
    }
    fclose (F);
}

void aggiunta () {
    int n=0, val;
    do {
        printf("Quanti valori: ");
        scanf("%d", &n);
    } while (n<=0);
    F=fopen ("INTERI.bin","ab+");
    for (int i=0; i<n; i++) {
        printf ("Fornisci valore: ");
        scanf ("%d", &val);
        fwrite (&val, sizeof(int), 1, F);
    }
    fclose(F);
}

float media () {
    int contm=0, somma=0.0, val;
    float m;
    F=fopen ("INTERI.bin","rb");
    while (fread (&val, sizeof(val), 1, F)>0) {
        if (val>0) {
            contm++;
            somma+=val;
        }
    }
    if (contm!=0) {
        m = somma/contm;
    }
    else printf ("media imp");
    fclose (F);
    return m;
}

void percentuale () {
    int contp=0, val, cont=0;
    F=fopen ("INTERI.bin","rb");
    while (fread (&val, sizeof(int), 1, F)>0) {
        cont++;
        if (val%3==0 && val>8) {
            contp++;
        }
    }
    printf ("Percentuale: %d\n", contp*100/cont);
    fclose (F);
}

int main() {
    FILE *F;
    int scelta;
    
    F=fopen ("INTERI.bin","rb");
    if (F!=NULL) {
        do {
            printf ("Scelta: ");
            scanf ("%d", &scelta);
            switch (scelta) {
                case 1: {
                    visualizza();
                    break;
                }

                case 2: {
                    aggiunta();
                    break;
                }

                case 3: {
                    float m;
                    m = media();
                    printf ("Media: %f\n", m);
                    break;
                }

                case 4: {
                    percentuale();
                    break;
                }

                case 5: {
                    
                    break;
                }
            }
        } while (scelta!=8);
        fclose (F);
    }
    if (F==NULL) {
        printf ("Il file non esiste");
    }

    return 0;
}
