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
    3. Modifica dati: prevede, per l’istruttore di cui è fornito il codice fiscale, la modifica del livello e del costo orario 
        oppure delle ore fatte, incrementandole con un numero fornito dall’utente       
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

float costo (){
    float x;
    do{
        printf("fornire il costo orario");
        scanf("%f", &x);
    }while (x<=0);
    return x;
}

void Aggiunta () {
    ip = fopen("ISTRUTTORI.h", "a");

    printf("Codice fiscale: ");
    scanf("%s", A.fiscale);
    printf("Nazionalità: ");
    scanf("%s", A.nazionalita);
    A.livello = 1;
    A.costo=costo();
    A.ore = 0;

    fwrite(&A, sizeof(A), 1, ip);

    fclose(ip);
}

void Licenziamento(void) {

    FILE *ip, *temp, *tp;
    struct istruttore A;
    struct licenziato L;
    char cf[17];
    int mesi;

    printf("Codice fiscale: ");
    scanf("%16s", cf);

    do {
        printf("Numero mesi: ");
        scanf("%d", &mesi);
    } while (mesi <= 0);

    /* FASE 1: copia filtrata su TEMP */
    ip   = fopen("ISTRUTTORI.dat", "rb");
    temp = fopen("TEMP.dat", "wb");
    tp   = fopen("TFR.dat", "ab");

    if (ip == NULL || temp == NULL || tp == NULL) {
        printf("Errore apertura file\n");
        return;
    }

    while (fread(&A, sizeof(A), 1, ip) == 1) {

        if (strcmp(A.fiscale, cf) == 0 && A.ore > 25) {

            /* calcolo liquidazione */
            strcpy(L.fiscale, A.fiscale);
            L.liquidazione = (A.costo * A.ore) / mesi;

            fwrite(&L, sizeof(L), 1, tp);

            printf("Guadagno: %.2f\n", A.costo * A.ore);

        } else {
            fwrite(&A, sizeof(A), 1, temp);
        }
    }

    fclose(ip);
    fclose(temp);
    fclose(tp);

    /* FASE 2: copia TEMP → ISTRUTTORI */
    ip   = fopen("ISTRUTTORI.dat", "wb");
    temp = fopen("TEMP.dat", "rb");

    if (ip == NULL || temp == NULL) {
        printf("Errore riapertura file\n");
        return;
    }

    while (fread(&A, sizeof(A), 1, temp) == 1) {
        fwrite(&A, sizeof(A), 1, ip);
    }

    fclose(ip);
    fclose(temp);
}

void modifica() {
    int incremento;
    int nuovo_valore;
    int scelta;
    int trovato = 0;
    char codice_modifica[17];
    struct istruttore A;

    ip = fopen("ISTRUTTORI.dat", "rb+");

    printf("fornire il codice fiscale per la modifica: ");
    scanf("%16s", codice_modifica);

    while (fread(&A, sizeof(A), 1, ip) == 1) {
        if (strcmp(codice_modifica, A.fiscale) == 0) {
            trovato = 1;

            printf("1) livello\n");
            printf("2) numero di ore fatte\n");
            scanf("%d", &scelta);

            if (scelta == 1) {
                printf("fornire il nuovo livello: ");
                scanf("%d", &nuovo_valore);
                A.livello = nuovo_valore;
            } else {
                printf("fornire incremento ore: ");
                scanf("%d", &incremento);
                A.ore = A.ore + incremento;
            }

            fseek(ip, -(long)sizeof(A), SEEK_CUR);
            fwrite(&A, sizeof(A), 1, ip);
            break;
        }
    }

    if (!trovato) {
        printf("istruttore non trovato\n");
    }

    fclose(ip);
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
                    printf("---AGGIUNTA---");
                    Aggiunta(A);
                    break;
                }
    
                case 2: {
                    printf("---CANCELLAZIONE---");
                    Licenziamento(A);
                    break;
                }
                    
                case 3: {
                    printf("---MODIFICA---");
                    modifica();
                    break;
                }
                
                case 4: {
                    printf("---PERCENTUALE DI ISTRUTTORI CON UN DETERMIANTO LIVELLO---");
                    
                    int livello_riferiemento;
                    int contatore_istruttori=0;
                    int contatore_percentuale=0;
                    float percentuale;

                    ip=fopen("ISTRUTTORI.dat", "rb");

                    do{
                        printf("fornire il livello di riferimento");
                        scanf("%d", &livello_riferiemento);
                    }while(livello_riferiemento<=0 || livello_riferiemento>8);

                    while(fread(&A, sizeof(A), 1, ip)>0){
                        contatore_istruttori++;
                        if (A.livello==livello_riferiemento){
                            contatore_percentuale++;
                        }
                    }
                    
                    fclose(ip);

                    if (contatore_percentuale==0){
                        printf("non ci sono istruttori con questo livello, quindi percentuale = 0%");
                    } else {
                        percentuale=((float)contatore_percentuale*100)/(float)contatore_istruttori;
                        printf("percentuale=%f", percentuale);
                    }

                    break;
                }
                
                case 5: {
                    
                    printf("---MASSIMO ORE---");
                    int trovato=0;
                    int max_ore=-1;
                    int livello_indicato;

                    do{
                        printf("fornire il livello");
                        scanf("%d", &livello_indicato);
                    }while(livello_indicato<=0 || livello_indicato>8);

                    ip=fopen("ISTRUTTORI.dat","rb");

                    while (fread(&A, sizeof(A),1, ip)==1){
                        if (A.livello==livello_indicato){
                             trovato = 1;
                            if (A.ore > max_ore) {
                                max_ore = A.ore;
                            }
                        }
                    }

                    if (!trovato) {
                        printf("Nessun istruttore trovato per questo livello.\n");
                        break;
                    }
                    
                    printf("Numero massimo di ore: %d\n", max_ore);

                    printf("Codici fiscali con il massimo di ore:\n");

                    while (fread(&A, sizeof(A), 1, fp) == 1) {
                        if (A.livello == livello && A.ore == max_ore) {
                            printf("%s\n", A.fiscale);
                        }
                    }

                    fclose(ip);

                    break;
                }
            }
        } while (scelta!=6);
    }

    return 0;
}