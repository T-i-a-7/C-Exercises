#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_MAX 20
#define VAL_MAX 30

void fill_random(int a[], int n, int lo, int hi);
void print_array(int a[], int n);
void reverse_in_place(int a[], int n);
int linear_search(int a[], int n, int target);
int sanitize_duplicates(int a[], int n);
void rotate_right(int a[], int n, int k);
int is_sorted (int a[], int n);

int main(void) {
    int v[N_MAX];
    int n = 0;
    int target = 0;

    srand(time(NULL));

    printf("=== LABORATORIO 2: ESERCIZIO 0 (ARRAY E FUNZIONI) ===\n");

    while (n < 1 || n > N_MAX) {
        printf("Quanti elementi (1-%d)? ", N_MAX);
        if (scanf("%d", &n) != 1) {
            while (getchar() != '\n'); // Pulisce il buffer
            n = 0;
        }
    }

    fill_random(v, n, 1, VAL_MAX);
    printf("\nOriginale : ");
    print_array(v, n);

    reverse_in_place(v, n);
    printf("Invertito : ");
    print_array(v, n);
	

    printf("\nValore da cercare: ");
    scanf("%d", &target);
    int pos = linear_search(v, n, target);
    if (pos >= 0) {
        printf("-> %d trovato in posizione %d\n", target, pos);
    } else {
        printf("-> %d non presente\n", target);
    }
	
	int duplicate = sanitize_duplicates(v, n);
	printf("\nDopo la sanificazione (duplicati = %d): ", duplicate);
	print_array(v, n);
	printf("Valori distinti: %d\n", n - duplicate);
	
	int k;
	printf("\nInserire valore k per ruotare l'array: ");
	scanf("%d", &k);
	rotate_right(v, n, k);
	printf("Ruotato a destra di %d: ", k);
	print_array(v, n);

    printf("\nArray in ordine crescente: ");
    if (is_sorted(v, n) == 0) {
        printf("si\n");
    } else {
        printf("no\n");
    }
	
    return 0;
}

// Riempie i primi n elementi con interi casuali in [lo, hi].
void fill_random(int a[], int n, int lo, int hi) {
    for (int i = 0; i < n; i++) {
        a[i] = lo + rand() % (hi - lo + 1);
    }
}

// Stampa i primi n elementi su una riga.
void print_array(int a[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("]\n");
}

void reverse_in_place(int a[], int n) {
	int tmp[n];
    for (int i = 0; i < n; i++) {
        tmp[i] = a[n-1-i];
    }
	for (int i = 0; i < n; i++) {
        a[i] = tmp[i];
    }
}

// Restituisce l'indice della prima occorrenza di target, oppure -1.
int linear_search(int a[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            return i;
        }
    }
    return -1;
}

int sanitize_duplicates (int a[], int n) {
	int d=0;
	for (int i = 0; i < n; i++) {
        int flag=0;
        for (int j = 0; j < i; j++){
			if (a[i]==a[j]){
				a[i]=0;
                if (flag==0) {
                    d++;
                    flag=1;
                }
			}
		}
    }
	return d;
}

void rotate_right (int a[], int n, int k) {
	int tmp[n];
	for (int i=0; i < n; i++) {
		if (i < k) {
			tmp[i] = a[n-k+i];
		} else if (i >= k) {
			tmp[i] = a[i-k];
		}
	}
	for (int i = 0; i < n; i++) {
        a[i] = tmp[i];
    }
}

int is_sorted (int a[], int n) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++){
			if (a[i] < a[j]){
				flag ++;
			}
		}
    }
    if (flag == 0) {
        return 0;
    } else {
        return 1;
    }
}