/*
Scrivere un programma in ANSI C che preveda un menu ripetibile nel quale ogni opzione permette
di eseguire uno degli esercizi indicati:
    1. Acquisiti 3 numeri a, b, c reali e positivi, controllare siano tutti maggiori di 12 e tutti diversi.
       Se le condizioni sono verificate, visualizzare il valore più piccolo.
    2. Acquisti tre valori reali, controllare siano i lati di un triangolo e visualizzare un messaggio
       relativo. Visualizzare l'area se è un triangolo equilatero. Tutti i messaggi devono essere
       effettuati nel main.
    3. Si acquisiscano N valori reali positivi. Senza usare vettori e senza chiedere più volte i
       valori, si trovi il massimo dei valori minori di un riferimento e la media totale. Visualizzare
       i risultati dal main.
    4. Si memorizzino in un vettore N valori reali positivi. Dopo aver controllato che un valore di
       riferimento compare solo una volta, cancellarlo dal vertore. Si visualizzi il nuovo vettore dal main.

È richiesto di utilizzare le funzioni che si prestano, per più esercizi.
Si preveda di impostare almeno 6 funzioni di cui almeno tre con la restituzione di un valore (per restituzione
si intende tramite il return) e almeno due con il passaggio parametri per indirizzo (non si possono
conteggiare i vettori).
*/



#include <stdio.h>

void acquisizione3val(float *pA, float *pB, float *pC) {
    do {
        printf("Fornisci primo valore: %f", *pA);
        scanf("%f", &*pA);
        printf("Fornisci secondo valore: %f", *pB);
        scanf("%f", &*pB);
        printf("Fornisci terzo valore: %f", *pC);
        scanf("%f", &*pC);
    } while (*pA<=0 || *pB<=0 || *pC<=0);
}

int controllo1(float a, float b, float c) {
    if ((a>12 && b>12 && c>12) && (a!=b && b!=c && c!=a)) {
        return 1;
    } else {
        return 0;
    }
}

int controllo2(float a, float b, float c) {
    if (a+b>c && b+c>a && c+a>b) {
        return 1;
    } else {
        return 0;
    }
}

float calcoloArea(float a) {
    return ((sqrt(3)/4)*a*a);
}   

void acquisizioneN(int *pN) {
    do {
        printf("Fornisci numero di valori: ");
        scanf("%d", &*pN);
    } while (*pN<=0);

int main() {
    int choice;
    
    do {
        printf("menu");
        do {
            printf("\nScelta: %d");
            scanf("%d", choice);
        } while (choice<=0 || choice>5);
        
        switch (choice) {
            case 1: {
                float a, b, c;
                
                acquisizione3val(&a, &b, &c);
                if (controllo1(a, b, c)==1) {
                    if (a>b && a>c) {
                        printf("Il valore minimo è: %f", a);
                    } else if (b>a && b>c) {
                        printf("Il valore minimo è: %f", b);
                    } else if (c>a && c>b) {
                        printf("Il valore minimo è: %f", c);
                    }
                } else {
                    printf("I valori non rispettano le condizioni.\n");
                }
                
                break;
            }
            
            case 2: {
                float a, b, c, area;
                
                acquisizione3val(&a, &b ,&c);
                if(controllo2(a, b, c)==1) {
                    printf ("I valori forniti sono i lati di un triangolo.\n");
                    if (a==b && b==c && c==a) {
                        area = calcoloArea(a);
                        printf("Area: %f", area);
                    }
                } else {
                    printf ("I valori forniti non sono i lati di un triangolo.\n");
                }
                
                break;
            }
        
            case 3: {
                float x, rif, sum=0, max;
                int n, count=0, i=0, flag=0;

                acquisizioneN(n);

                do {
                    printf("Fornisci riferimento: ");
                    scanf("%f", &rif);
                } while (rif<=0);

                while (i<n) {
                    do {
                        printf("Fornisci valore %d: ", i+1);
                        scanf("%f", &x);
                    } while (x<=0);

                    if (x<rif) {
                        if (flag==0) {
                            max = x;
                            flag=1;
                        } else if (max<x) {
                           max=x;
                        }
                    }
                    
                    i++;
                }
                        
                break;
            }
        
            case 4: {
        
                break;
            }
        }
    } while (choice!=5);

    return 0;
}
