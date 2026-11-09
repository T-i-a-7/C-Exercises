#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LANCI 120

int inizializzazione ();
int controllo (int flag);
void lanci (int d1[], int d2[], int N);
void visualizzazione (int d1[], int d2[], int N);
void statistica (int d1[], int d2[], int N);
void istogramma (int d1[], int d2[], int N);
void modifica (int d1[], int d2[], int N);
void binaria (int d1[], int d2[], int N);

int main () {
    int seed = inizializzazione();
    int N;
    int flag = 0;
    int d1[MAX_LANCI];
    int d2[MAX_LANCI];
    char scelta;

    if (seed > 0) {
        srand(seed);
    } else if (!seed) {
        srand(time(NULL));
    }

    do {
        printf("\n----------- MENU -----------\nG - Genera una nuova sequenza\nV - Visualizza tutti i lanci\nS - Calcola le statistiche\nI - Visualizza l'istogramma\nM - Modifica un lancio\nB - Visualizza la codifica binaria\nQ - Termina il programma\n");
        printf("\nScelta: ");
        scanf(" %c", &scelta);

        switch (scelta) {
            case 'g':
            case 'G': {
                N = rand() % 120 + 1;
                lanci (d1, d2, N);
                flag = 1;

                break;
            }

            case 'v':
            case 'V': {
                if (controllo (flag)) {
                    visualizzazione (d1, d2, N);
                }

                break;
            }

            case 's':
            case 'S': {
                if (controllo (flag)) {
                    statistica (d1, d2, N);
                }

                break;
            }

            case 'i':
            case 'I': {
                if (controllo (flag)) {
                    istogramma (d1, d2, N);
                }

                break;
            }

            case 'm':
            case 'M': {
                if (controllo (flag)) {
                    modifica (d1, d2, N);
                }

                break;
            }

            case 'b':
            case 'B': {
                if (controllo (flag)) {
                    binaria (d1, d2, N);
                }

                break;
            }

            case 'q':
            case 'Q': {
                break;
            }

            default: {
                printf("Scelta non riconosciuta.\n");

                break;
            }
        }
    } while (scelta!='q'&&scelta!='Q');
    
    return 0;
}

int inizializzazione () {
    int seed;

    do {
        printf("Inserire seed: ");
        scanf("%d", &seed);
    } while (seed < 0);

    return seed;
}

int controllo (int flag) {
    if (!flag) {
        printf("\nNessun lancio effettuato.\nGenerare una nuova sequenza prima di procedere.\n");
        return 0;
    } else {
        return 1;
    }
}

void lanci (int d1[], int d2[], int N) {
    for (int i=0; i<N; i++) {
        d1[i] = rand() % 6 + 1;
        d2[i] = rand() % 6 + 1;
    }
    printf("\nNuova sequenza generata!\n");
}

void visualizzazione (int d1[], int d2[], int N) {
    printf("\n------------------------------------------------------------");
    printf("\n| Lancio | 1 Dado | 2 Dado | Somma | Pari/Dispari  | Uguali |");
    printf("\n------------------------------------------------------------");
    for (int i=0; i<N; i++) {
        int sum = d1[i]+d2[i];
        printf("\n|   %d    |   %d    |   %d    |   %d   |", i+1, d1[i], d2[i], sum);
        if (sum % 2 == 0) {
            printf("  Pari   |");
        } else {
            printf(" Dispari |");
        }
        if (d1[i] == d2[i]) {
            printf("      Si      |");
        } else {
            printf("      No      |");
        }
        printf("\n------------------------------------------------------------");
    }
    printf("\n");
}

void statistica (int d1[], int d2[], int N) {
    int sum[N];
    int sumtot = 0;
    float media = 0;
    int min, max, flag = 0;
    int cont = 0;
    float percentuale = 0;
    int pari = 0, dispari = 0;
    int cont7 = 0;
    int len[N], flag2 = 0, k = 0;

    for (int i=0; i<N; i++) {
        sum[i] = d1[i] + d2[i];
        sumtot += sum[i];
        if (!flag) {
            min = sum[i];
            max = sum[i];
            flag = 1;
        } else {
            if (sum[i] < min) {
                min = sum[i];
            }
            if (sum[i] > max) {
                max = sum[i];
            }
        }
        if (d1[i] == d2[i]) {
            cont ++;
        }
        if (sum[i] % 2 == 0) {
            pari ++;
        } else {
            dispari ++;
        }
        if (sum[i] >= 7) {
            cont7 ++;
        }
        if (!flag2) {
            len[k] = 1;
            flag2 = 1;
        } else {
            if (sum[i] == sum[i-1]) {
                len[k] ++;
            } else {
                k++;
                len[k] = 0;
                len[k] ++;
            }
        }
    }

    printf("\n--- STATISTICHE ---\n");
    printf("Lanci totali: %d\n", N);
    printf("Somma totale: %d\n", sumtot);
    media = (float) sumtot / N;
    printf("Media somme: %.2f\n", media);
    printf("Minimo somme: %d\n", min);
    printf("Massimo somme: %d\n", max);
    printf("Lanci con risultato uguale: %d\n", cont);
    percentuale = (float) cont * 100 / N;
    printf("Percentuale lanci con risultato uguale: %.1f %%\n", percentuale);
    printf("Somme pari: %d\n", pari);
    printf("Somme dispari: %d\n", dispari);
    printf("Somme >= 7: %d\n", cont7);
    
    flag = 0;
    max = 0;
    for (int j=0; j<=k; j++) {
        if (!flag) {
            max = len[j];
            flag = 1;
        } else if (len[j] > max) {
            max = len[j];
        }
    }
    printf("Lunghezza sequenza lanci con stessa somma più lunga: %d\n", max);
}

void istogramma (int d1[], int d2[], int N) {
    int sum[N];
    int frq[11];
    
    for (int i=0; i<N; i++) {
        sum[i] = d1[i] + d2[i];
    }
    for (int j=0; j<11; j++) {
        frq[j] = 0;
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<11; j++) {
            if (sum[i] == j+2) {
                frq[j] ++;
            }
        }
    }
    
    printf("\n--- ISTOGRAMMA ---");
    for (int j=0; j<11; j++) {
        printf("\n%d (%d)\t", j+2, frq[j]);
        for (int k=0; k<frq[j]; k++) {
            printf("*");
        }
    }
    printf("\n");
}

void modifica (int d1[], int d2[], int N) {
    int lancio, mod1, mod2;

    do {
        printf("Lancio da modificare: ");
        scanf("%d", &lancio);
    } while (lancio<1 || lancio>N);

    do {
        printf("Modifica dado 1: ");
        scanf("%d", &mod1);
    } while (mod1<1 || mod1>6);
    do {
        printf("Modifica dado 2: ");
        scanf("%d", &mod2);
    } while (mod2<1 || mod2>6);

    d1[lancio-1] = mod1;
    d2[lancio-1] = mod2;
}

void binaria (int d1[], int d2[], int N) {
    int lancio, sum, tmp, bin[4];

    do {
        printf("Lancio da convertire: ");
        scanf("%d", &lancio);
    } while (lancio<1 || lancio>N);

    sum = d1[lancio-1] + d2[lancio-1];

    tmp = sum;
    for (int i=0; i<4; i++) {
        bin[i] = tmp % 2;
        tmp = tmp / 2;
    }

    printf("Somma (%d) in binario: %d%d%d%d", sum, bin[3], bin[2], bin[1], bin[0]);
}