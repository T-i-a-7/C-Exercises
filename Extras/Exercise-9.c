/*
Impostare un programma in C che consenta di gestire in modo informatico le attività proposte durante una crociera.
Per ogni passeggero si devono gestire i seguenti dati:
    - Cognome (max. 15 caratteri)
    - Nome (max. 10 caratteri)
    - Sesso (M/F)
    - Numero attività giornaliere (Numero di attività extra che il cliente paga)

Costruire una lista dinamica che preveda l’inserimento di N passeggeri prenotati.  
Quindi, prevedere un menu ripetibile con le seguenti richieste, senza utilizzare la N:
    1) Nuovo passeggero
    2) Annullamento viaggio
    3) Modifiche
    4) Statistiche
    5) Fine

- La prima richiesta si effettua al momento della vendita di un pacchetto viaggio presso le agenzie mandatarie. Richiedere le sole informazioni necessarie.  
- La seconda richiesta, effettuata in agenzia, prevede la cancellazione delle informazioni che riguardano un passeggero di cui viene fornito il cognome perché questo ha dovuto annullare il viaggio.  
- La terza richiesta prevede di modificare per il passeggero di cui è fornito il cognome, il numero di attività giornaliere. La modifica è a sostituzione.
  Viene fornito il costo di ogni attività e si deve visualizzare quanto il cliente deve pagare in sovrapprezzo.  
- La quarta richiesta prevede di calcolare la percentuale dei passeggeri maschi che hanno numero di attività giornaliere inferiore a 5 e di visualizzare tutti i cognomi delle passeggere con attività giornaliere massime.
*/


#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "malloc.h"
#include <inttypes.h>


struct Passeggero {
    char cognome[16];
    char nome[11];
    char sesso;
    int attivita;
    struct Passeggero *next;
};


// funzioni
struct Passeggero *nuovo (struct Passeggero *head) {
    char cognome[16], nome[11], sesso;
    struct Passeggero *cur = head;

    printf("Cognome: ");
    scanf("%s", cognome);
    printf("Nome: ");
    scanf("%s", nome);
    do {
        printf("Sesso: ");
        scanf(" %c", &sesso);
    } while (sesso!='M'&&sesso!='F');
    
    if (head==NULL) {
        head = malloc(sizeof(struct Passeggero));
        strcpy(head->cognome, cognome);
        strcpy(head->nome, nome);
        head->sesso = sesso;
        head->attivita = 0;
        head->next = NULL;
        return head;
    } else {
        while (cur != NULL && cur->next != NULL) {
        cur = cur->next;
        }
        
        cur->next = malloc(sizeof(struct Passeggero));
        cur = cur->next;
    
        strcpy(cur->cognome, cognome);
        strcpy(cur->nome, nome);
        cur->sesso = sesso;
        cur->attivita = 0;
        cur->next = NULL;
    }

    return head;
}

struct Passeggero *cancellazione (struct Passeggero *head) {
    struct Passeggero *cur = head;
    char cognome[16];

    printf("Cognome: ");
    scanf("%s", cognome);

    if (strcmp(cognome, cur->cognome)==0&&cur==head) {
        
    } else { 
        while (cur!=NULL) {
            struct Passeggero *prec = cur
            cur = cur->next
            if (strcmp(cognome, cur->cognome)==0) {
                prec = cur->next;
                free(cur);
            }
        }
    }

    return head;
}



int main () {
    int scelta,i=0,n;
    struct Passeggero *head, *cur;

    do {
        printf("Passeggeri: ");
        scanf("%d", &n);
    } while (n<0);

    if (n==0) {
        head=NULL;
    } else {
        for (i=0; i<n; i++) {
            if (i==0) {
                head = malloc(sizeof(struct Passeggero));
                cur = head;
            } else {
                cur->next = malloc(sizeof(struct Passeggero));
                cur = cur->next;
            }
            printf("Cognome: ");
            scanf("%s", cur->cognome);
            printf("Nome: ");
            scanf("%s", cur->nome);
            do {
                printf("Sesso: ");
                scanf(" %c", &cur->sesso);
            } while (cur->sesso!='M'&&cur->sesso!='F');
            cur->attivita=0;
        }
        cur->next = NULL;
    }

    do {
        do {
            printf("\nScelta: ");
            scanf("%d", &scelta);
        } while (scelta<=0||scelta>5);

        switch (scelta) {
            case 1: {
                head = nuovo(head);
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
        };
    } while (scelta!=5);

    return 0;
}
