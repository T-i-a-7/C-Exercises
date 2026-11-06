#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LANCI 120
#define 

int inizializzazione ();
int lanci ();

int main () {
    int seed = inizializzazione();
    int N;
    int d1[MAX_LANCI];
    int d2[MAX_LANCI];

    if (seed > 0) {
        srand(seed);
    } else if (!seed) {
        srand(time(NULL));
    }

    do {
        printf("\n-------- MENU --------\nG - Genera una nuova sequenza\nV - Visualizza tutti i lanci\nS - Calcola le statistiche\nI - Visualizza l'istogramma\nM - Modifica un lancio\nB - Visualizza la codifica binaria\nQ - Termina il programma\n");

        switch () {
            case 'G': {


                break;
            }

            case 'V': {
                

                break;
            }

            case 'S': {
                

                break;
            }

            case 'I': {
                

                break;
            }

            case 'M': {
                

                break;
            }

            case 'B': {
                

                break;
            }

            case 'Q': {
                

                break;
            }

            default: {
                

                break;
            }
        }
    }

    N = rand % 119 + 1;
    lanci (d1, d2, N);
    
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

void lanci (int d1[], int d2[], int N) {
    for (int i=0; i<N; i++) {
        d1[i] = rand % 6 + 1;
        d2[i] = rand % 6 + 1;
    }
}