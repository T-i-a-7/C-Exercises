/*
Gestire il file "CLIENTI" per una società specializzata nel franchising per le gelaterie.
Per ogni cliente, la società deve gestire le seguenti informazioni:
- codice cliente (al massimo 20 caratteri)
- fee d'ingresso (quota fissa di affiliazione)
- royalties (% sul guadagno annuale della gelateria)
- totale pagato al franchisor dal cliente
- numero anni dall'apertura

Se il file esiste, si deve prevedere un menù ripetitibile con le seguenti richieste:
    1. Inserimento nuovo cliente (punti 1)
    2. Chiusura contratto (punti 2)
    3. Fine anno (punti 2)
    4. Guadagno totale (punti 1.5)
    5. Elaborazioni (punti 1.5)
    6. Fine

Descrizione delle operazioni:
1) Inserimento dei dati di un nuovo cliente in fondo al file chiedendo all'utente solo ciò che è necessario
2) Ricevuto il codice del cliente e controllato che sia stato aperto da almeno 5 anni, cancellare tutte le informazioni.
   Aggiungere in fondo al file GUADAGNI il codice del cliente cancellato ed il guadagno totale del franchisor su tale cliente.
3) Aggiornare il numero di anni dall'apertura (per un cliente di cui viene fornito il codice)
   Chiedendo all'utente il guadagno annuale della gelateria, si deve aggiungere il totale pagato al franchisor.
4) Calcolare il totale del guadagno del franchisor su tutti i clienti, compresi quelli cancellati, fino a quel momento.
5) Visualizzare il totale dei guadagni per i clienti con maggior numero di anni di apertura e la percentuale dei clienti con meno di 3 anni d'apertura.

Effettuare almeno una funzione per punto del menu.
Eeffettuare almeno 2 funzioni con il return e 2 con il passaggio parametri per indirizzo.
*/



#include <stdio.h>
#include <string.h>


FILE *cp;
FILE *gp;

struct cliente {
   char codice[21];
   float fee;
   int royalties;
   float totale;
   int anni;
};

struct cancellato {
   char codice[21];
   float totale;
};

//funzioni
void Aggiunta () {
   struct cliente C;

   cp = fopen("CLIENTI.dat", "a+");
   
   printf("Codice cliente: ");
   scanf("%s", C.codice);
   do {
      printf("Fee d'ingresso: ");
      scanf("%f", &C.fee);
   } while (C.fee<0);
   do {
      printf("Royalties: ");
      scanf("%d", &C.royalties);
   } while (C.royalties<0||C.royalties>100);
   C.totale = C.fee;
   C.anni = 0;

   fwrite(&C, sizeof(C), 1, cp);

   fclose(cp);
}

void Codice (char Tcodice[21]) {
   printf("Codice: ");
   scanf("%s", Tcodice);
}

int Chiusura () {
   struct cliente C;
   struct cancellato X;
   FILE *tp;
   char Tcodice[21];

   Codice(Tcodice);
   
   if ((gp = fopen("GUADAGNI.dat", "a+")) == NULL) {
      return 0;
   }
   
   cp = fopen("CLIENTI.dat", "r");
   tp = fopen("TEMP.dat", "w");
   
   while (fread(&C, sizeof(C), 1, cp) == 1) {
      if (!(strcmp(Tcodice, C.codice)==0 && C.anni>=5)) {
         fwrite(&C, sizeof(C), 1, tp);
      } else if (strcmp(Tcodice, C.codice)==0){         
         strcpy(X.codice, Tcodice);
         X.totale = C.totale;
      }
   }

   fclose(cp);
   fclose(tp);
   cp = fopen("CLIENTI.dat", "w");
   tp = fopen("TEMP.dat", "r");

   while (fread(&C, sizeof(C), 1, tp) == 1) {
      fwrite(&C, sizeof(C), 1, cp);
   }

   fwrite(&X, sizeof(X), 1, gp);
   fclose(cp);
   fclose(tp);
   fclose(gp);
}

void Fine () {
   struct cliente C;
   char Tcodice[21];
   float Tguadagno;
   int flag=0;
   
   cp = fopen("CLIENTI.dat", "r+");
   Codice(Tcodice);

   while ((fread(&C, sizeof(C), 1, cp) == 1) && flag == 0) {
      if (strcmp(Tcodice, C.codice) == 0) {
         C.anni++; 

         printf("Guadagno annuale gelateria: ");
         scanf("%f", &Tguadagno);
      
         C.totale += Tguadagno * (float)C.royalties/100;
      
         fseek(cp, -sizeof(C), SEEK_CUR);
         fwrite(&C, sizeof(C), 1, cp);
         fclose(cp);

         flag=1;
      }
   }

   fclose(cp);
}

float Guadagno () {
   struct cliente C;
   struct cancellato X;
   float guadagno=0;

   cp = fopen("CLIENTI.dat", "r");
   if ((gp = fopen("GUADAGNI.dat", "r")) == NULL) {
      return 0;
   }

   while (fread(&C, sizeof(C), 1, cp) == 1) {
      guadagno += C.totale;
   }

   while (fread(&X, sizeof(X), 1, gp) == 1) {
      guadagno += X.totale;
   }

   fclose(cp);
   fclose(gp);

   return guadagno;
}

float Percentuale () {
   struct cliente C;
   float percentuale;

   return percentuale;
}

int main () {
   int scelta;
   struct cliente C;

   if ((cp = fopen("CLIENTI.dat", "r")) == NULL) {
      printf("Errore nell'apertura del file");
      return 1;
   } else {
      fclose(cp);

      do {
         printf("\nMenù\n");
         printf("1. Inserimento nuovo cliente\n2. Chiusura contratto\n3. Fine anno\n4. Guadagno totale\n5. Elaborazioni\n6. Fine\n");
         do {
            printf("\nScelta: ");
            scanf("%d", &scelta);
         } while (scelta<=0||scelta>6);

         switch (scelta) {
            case 1: {
               Aggiunta();
               break;
            }

            case 2: {
               Chiusura();
               break;
            }

            case 3: {
               Fine();
               break;
            }

            case 4: {
               printf("Guadagno: %f\n", Guadagno());
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

