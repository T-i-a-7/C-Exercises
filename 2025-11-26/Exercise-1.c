/*
Impostare un programma che elabora il file STUDIO, in cui sono memorizzate le seguenti informazioni:
    Matricola (8 caratteri)
    Classe (3 caratteri)
    Numero presenze
    Numero assenze

Gestire il seguente menù ripetibile:
    1. Aggiunta nuovo allievo: chiedere all'utente le sole informazioni necessarie ed inserirle in fondo al file
    2. Visualizzazione di tutte le informazioni
    3. Cancellazione allievo: viene fornita la matricola. Visualizzare il numero dei giorni in cui è stato presente e quello in cui era assente
    4. Modifica: viene fornita la matricola. Modificare il numero presenze o il numero assenze
    5. Statistiche: per una classe indicata, trovare il numero massimo di presenze, quali matricole lo hanno avuto, la media delle assenze e la percentuale degli allievi senza assenze. Visualizzare i risultati.
    6. File ASSENZE: aggiungere in fondo al file le matricole ed il numero di assenze per gli allievi di una classe indicata. Visualizzare il file
    7. Fine
*/


#include <stdio.h>
#include <string.h>

FILE *sp;
FILE *ap;

struct allievo {
    char matricola[9];
    char classe[4];
    int presenze;
    int assenze;
};

void Aggiunta (struct allievo A) {
    sp = fopen("STUDIO.h", "a+");

    printf("Matricola: ");
    scanf("%s", A.matricola);
    printf("Classe: ");
    scanf("%s", A.classe);
    A.presenze = 0;
    A.assenze = 0;

    fclose(sp);
}

void Visualizzazione (struct allievo A) {
    sp = fopen("STUDIO.h", "r");
    
    while (fread(&A, sizeof(A), 1, sp)==1) {
        printf("Matricola: %s\nClasse: %s\nPresenze: %d\nAssenze: %d", A.matricola, A.classe, A.presenze, A.assenze);
    }

    fclose(sp);
}

void Cancellazione (struct allievo A) {
    FILE *temp;
    char mat[9];

    printf("Matricola: ");
    scanf("%s", mat);

    sp = fopen("STUDIO.h", "r");
    temp = fopen("TEMP.h", "w");

    while(fread(&A, sizeof(A), 1, sp)==1) {
        if (strcmp(A.matricola, mat)==0) {
            printf("Numero giorni di presenza: %d\n", A.presenze);
            printf("Numero giorni di assenza: %d\n", A.assenze);
        } else {
            fwrite(&A, sizeof(A), 1, temp);
        }
    }

    fclose(sp);
    fclose(temp);
    sp = fopen("STUDIO.h", "w");
    temp = fopen("TEMP.h", "r");

    while(fread(&A, sizeof(A), 1, sp)==1) {
        fwrite(&A, sizeof(A), 1, sp);
    }

    fclose(sp);
    fclose(temp);
}

int main () {
    int scelta;
    struct allievo A;

    if ((sp = fopen("STUDIO.h", "rb")) == NULL) {
        printf("Errore nell'apertura del file.\n");
        return 1;
    } else {
        fclose(sp);

        do {
            printf("\nMenù\n");
            printf("1. Aggiunta nuovo allievo\n2. Visualizzazione di tutte le informazioni\n3. Cancellazione allievo\n4. Modifica\n5. Statistiche\n6. File ASSENZE\n7. Fine\n");
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
                    Visualizzazione(A);
                    break;
                }
                    
                case 3: {
                    Cancellazione(A);
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
            }
        } while (scelta!=7);
    }
}