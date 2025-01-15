/*
Si devono acquisire per gli N allievi di una scuola elementare le seguenti informazioni:
    - Matricola (7 caratteri)
    - Altezza (in m)
    - Peso (in Kg)
    - Anni
    - Sesso (F o M)

Si deve impostare un menu ripetibile con le seguenti richieste:
    1. Visualizza i dati di tutti gli allievi
    2. Media Anni degli allievi/e con Altezza superiore ad un riferimento
    3. Percentuale allieve con Peso inferiore ad un riferimento
    4. Altezza massima per gli allievi maschi
    5. Modifica Peso o Altezza o Anni per un allievo di cui è fornita dall'utente la Matricola
    6. Trasferimento di un allievo di cui è fornita la Matricola dall'utente
    7. Vettore Matricole e anni degli allievi/e con Peso minimo. Dopo averlo costruito, si deve visualizzare il vettore
    8. Fine
*/

#include <stdio.h>
#include <string.h>

int main () {
    int n, i, scelta;

    struct Informazioni {
        char matricola[8];
        float altezza;
        float peso;
        int anni;
        char sesso;
    };

    struct Informazioni Allievo[1000];

    do {
        printf("Numero allievi:");
        scanf("%d", &n);
    } while (n<=0||n>1000);
    
    //Acquisizione informazioni
    for (i=0; i<n; i++) {
        printf("\n");
        printf("Informazioni allievo %d\n", i+1);
        printf("Matricola: ");
        scanf("%s", Allievo[i].matricola);
        do {
            printf("Altezza (in m): ");
            scanf("%f", &Allievo[i].altezza);
        } while (Allievo[i].altezza<=0 || Allievo[i].altezza>3);
        do {
            printf("Peso (in kg): ");
            scanf("%f", &Allievo[i].peso);
        } while (Allievo[i].peso<=0);
        do {
            printf("Anni: ");
            scanf("%d", &Allievo[i].anni);
        } while (Allievo[i].anni<=0 || Allievo[i].anni>125);
        do {
            printf("Sesso (M o F): ");
            scanf(" %c", &Allievo[i].sesso);
        } while (Allievo[i].sesso!='M' && Allievo[i].sesso!='F');
    }

    //Menù
    do {
        printf("\n");
        printf("┌───────────────────────────────────────────────────────────────────────┐\n");
        printf("│                             --- MENÙ ---                              │\n");
        printf("├───────────────────────────────────────────────────────────────────────┤\n");
        printf("│  1. Visualizza i dati di tutti gli allievi                            │\n");
        printf("│  2. Media anni per allievi/e con altezza superiore ad un riferimento  │\n");
        printf("│  3. Percentuale allieve con peso inferiore ad un riferimento          │\n");
        printf("│  4. Altezza massima per gli allievi maschi                            │\n");
        printf("│  5. Modifica peso, altezza o anni per un allievo tramite matricola    │\n");
        printf("│  6. Trasferimento di un allievo tramite matricola                     │\n");
        printf("│  7. Vettore matricole e anni per allievi/e con peso minimo            │\n");
        printf("│     (visualizzazione del vettore)                                     │\n");
        printf("│  8. Fine                                                              │\n");
        printf("└───────────────────────────────────────────────────────────────────────┘\n");
        printf("Seleziona un'opzione: ");
        scanf("%d", &scelta);

        //Switch case e operazioni
        switch (scelta) {
            case 1:
                for (i=0; i<n; i++) {
                    printf("\n");
                    printf("Informazioni allievo %d", i+1);
                    printf("Matricola: %s", Allievo[i].matricola);
                    printf("Altezza: %f", Allievo[i].altezza);
                    printf("Peso: %f", Allievo[i].peso);
                    printf("Anni: %d", Allievo[i].anni);
                    printf("Sesso: %c", Allievo[i].sesso);
                }
                break;

            case 2:
                float rif=0;
                int contm=0, somma=0;

                printf("riferimento: %f", rif);

                do {
                    printf("Riferimento: ");
                    scanf("%f", &rif);
                }  while (rif<=0 || rif>3);

                for (i=0; i<n; i++) {
                    if (Allievo[i].altezza>rif) {
                        contm++;
                        somma+=Allievo[i].anni;
                    }
                }

                if (contm==0) {
                    printf("Media impossibile");
                }
                else {
                    printf("Media anni: %f", (float) somma/contm);
                }
                
                break;

            case 3:
                float rif2=0;
                int contp=0;

                do {
                    printf("Riferimento: ");
                    scanf("%f", &rif2);
                } while (rif2<=0);

                for (i=0; i<n; i++){
                    if (Allievo[i].sesso=='F') {
                        if (Allievo[i].peso<rif2) {
                            contp++;
                        }
                    }
                    else {
                        printf("Nessuna femmina");
                    }
                }

                printf("Percentuale: %f", (float) contp*100/n);
                
                break;

            case 4:
                int flag=0;
                float max=0;

                for (i=0; i<n; i++) {
                    if (Allievo[i].sesso=='M') {
                        if (flag==0) {
                            max=Allievo[i].altezza;
                            flag=1;
                        }
                        else if (max<Allievo[i].altezza) {
                            max=Allievo[i].altezza;
                        }
                    }
                }

                printf("Massimo maschi: %f", max);

                break;

            case 5:
            //Modifica peso, altezza o anni per un allievo tramite matricola
            int scelta_modifica;
            char controllo[8];

            printf("Matricola per modifica: ");
            scanf("%s", controllo);

            for (i=0; i<n; i++) {
                if (strcmp(Allievo[i].matricola, controllo)==0) {
                    printf("--- MENÙ ---\n");
                    printf("1. Modifica peso\n");
                    printf("2. Modifica altezza\n");
                    printf("3. Modifica anni\n");
                    printf("Seleziona un'opzione: ");
                    scanf("%d", &scelta_modifica);
                    
                    switch (scelta_modifica) {
                        case 1:
                            float nuovo_peso;

                            printf("Nuovo peso: ");
                            scanf("%f", &)

                            break;
                    }
                }
            }

            break;
        }
    } while (scelta!=8);

    return 0;
}