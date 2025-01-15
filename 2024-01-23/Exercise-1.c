//Acquisita una sequenza di valori che rappresentano il numero dei visitatori di una mostra per il tempo di apertura, sapendo che la sequenza termina con il
//primo valore maggiore di 10000, senza comprendere il valore di fine sequenza, trovare e visualizzare:
//1. La media dei visitatori
//2. La percentuale dei giorni in cui i visitatori sono stati inferiori a 1000
//3. Il primo giorno in cui si è verificata la massima affluenza e quante volte si è avuta tale affluenza
//4. Ogni volta che il numero di visitatori è nullo, visualizzare "nessun visitatore"


int main() {
    int cont=0, contp=0, contm=0, firstp=0, contmax=0;
    float nv, max, somma=0;

    do {
        printf("Numero visitatori: ");
        scanf("%f", &nv);
    } while (nv<0);

    while (nv<=10000) {
        contm++;
        somma=somma+nv;

        if (nv<1000) {
            contp++;
        }

        if (cont==0||max<nv) {
            max=nv;
            firstp=cont+1;
            contmax=1;
        }
        else if (max==nv) {
            contmax++;
        }

        if (nv==0) {
            printf("Nessun visitatore\n");
        }

        cont++;

        do {
            printf("Numero visitatori: ");
            scanf("%f", &nv);
        } while (nv<0);
    }

    if(contm==0) {
        printf("Media impossibile\n");
    }
    else {
        printf("Media: %f", (float) somma/contm);
    }

    printf("Percentuale: %f", (float) contp*100/cont);

    printf("Primo giorno: %d", firstp);

    printf("Quante volte: %d", contmax);

    return 0;
}
