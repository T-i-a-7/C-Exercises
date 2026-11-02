/*
============================================================================
LABORATORIO 2 - ESERCIZIO 1
Tema: Matrici quadrate, trasposta, simmetria e rotazione
Task: Scrivere un programma in C che gestisce una matrice quadrata N x N di interi
(costante MAX = 8) e ne esegue trasformazioni geometriche tramite funzioni.

1. Input e Validazione: leggere N con 2 <= N <= 8. Se l'input non e' valido,
   richiedere l'inserimento.
2. Funzioni da implementare (le matrici hanno MAX colonne):
   - void fill_matrix(int m[][MAX], int n, int lo, int hi)
       riempie la matrice con valori casuali in [lo, hi]
   - void print_matrix(int m[][MAX], int n)
       stampa la matrice con i valori allineati (%3d)
   - void transpose(int m[][MAX], int n)
       trasposta IN PLACE (senza matrici ausiliarie)
   - int is_symmetric(int m[][MAX], int n)
       restituisce 1 se m[i][j] == m[j][i] per ogni coppia, 0 altrimenti
   - void rotate90(int src[][MAX], int dst[][MAX], int n)
       scrive in dst la rotazione ORARIA di 90 gradi di src
   - int equal_matrices(int a[][MAX], int b[][MAX], int n)
       restituisce 1 se le due matrici sono uguali, 0 altrimenti
3. Nel main: riempire con valori in [0, 3] (cosi' la simmetria puo' capitare),
   stampare la matrice, dire se e' simmetrica, stampare la rotazione di 90
   gradi, poi verificare che QUATTRO rotazioni consecutive riportino alla
   matrice di partenza ("Verifica OK" / "Verifica FALLITA"). Infine stampare
   la trasposta.

Esempio con matrice 3 x 3 (1 2 3 / 4 5 6 / 7 8 9):
  Rotazione di 90 gradi:  7 4 1 / 8 5 2 / 9 6 3
  Trasposta:              1 4 7 / 2 5 8 / 3 6 9

Esempio di esecuzione (i valori sono casuali):
Dimensione N della matrice (2-8): 4

Matrice:
  0  0  1  3
  2  0  1  3
  0  3  1  2
  1  3  1  0
Simmetrica: no

Rotazione di 90 gradi (oraria):
  1  0  2  0
  3  3  0  0
  1  1  1  1
  0  2  3  3

Quattro rotazioni consecutive: Verifica OK

Trasposta (in place):
  0  2  0  1
  0  0  3  3
  1  1  1  1
  3  3  2  0
*/




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 8

void fill_matrix (int m[][MAX], int n, int lo, int hi);
void print_matrix(int m[][MAX], int n);
void transpose(int m[][MAX], int n);
int is_symmetric(int m[][MAX], int n);

int main () {
    srand(time(NULL));

    int N=0;
    int m[MAX][MAX];
    int lo, hi;

    do {
        printf("Valore N dimensione matrice: ");
        scanf("%d", &N);
    } while (N<2||N>8);

    printf("Limite inferiore: ");
    scanf("%d", &lo);
    printf("Limite superiore: ");
    scanf("%d", &hi);

    return 0;
}

void fill_matrix (int m[][MAX], int n, int lo, int hi) {
    for (int i=0; i<n; i++) {
        m[i][] = rand
    }
}