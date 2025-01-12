//Acquisiti 350 valori numerici, trovare e visualizzare il valore minimo e l'ultima posizione in cui compare.
//Per esempio se la sequenza fosse 7,12,7,36,54,19,9,7,21 dovreste ottenere che il minimo è 7 e compare l'ultima volta alla posizione 8.


#include <stdio.h>

int main() {
    int a;
    int min;
    int cont;
    int lastp=0;

    for (cont=0; cont<350; cont++) {
        printf("Fornisci un valore: ");
        scanf("%d", &a);
        printf("\n");
        
        if (cont==0) {
            min=a;
            lastp=cont;
        }
        else {
            if (min>a) {
                min=a;
            }
            if (min==a) {
                lastp=cont;
            }
        }
    }

    printf("Il valore minimo è %d e compare l'ultima volta alla posizione %d.\n", min, lastp+1);

    return 0;
}