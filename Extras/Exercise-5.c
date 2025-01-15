/*
Si deve fornire un programma in C, con vettori di strutture, ad una società che gestisce le farmacie di una città.
Tale programma prevede di poter inserire le seguenti informazioni:
    - Codice farmaco (max. 15 caratteri)
    - Fascia (A oppure C oppure H)
    - Costo
    - Quantita disponibile

Ogni farmaco è caratterizzato da una fascia:
    - La fascia C indica i farmaci a carico del sistema sanitario nazionale (quindi gratuiti per gli assistiti)
    - La fascia H indica i prodotti ospedalieri (quindi acquistabili solo dagli ospedali)
    - La fascia A che indica i prodotti da banco completamente a carico degli assistiti.
In ogni caso ogni farmaco ha un costo inserito.


Si deve impostare un menu ripetibile che consenta di effettuare le seguenti operazioni:
    1. Inserimento farmaco
    2. Modifiche
    3. Massimo costo farmaco
    4. Elenco per quantità
    5. Vendita farmaci
    6. Fine

La prima richiesta prevede l'inserimento di un nuovo farmaco e di tutte le informazioni che lo riguardano, chiedendo all'utente solo quelle necessarie.
Il nuovo farmaco si deve inserire in fondo al vettore.

La seconda richiesta prevede di modificare un farmaco di cui è fornito il codice: l'utente deve poter sostituire il costo con un nuovo valore oppure incrementare la quantità disponibile con un valore inserito dall'utente.

La terza richiesta prevede di trovare e visualizzare il costo massimo dei farmaci ospedalieri.

La quarta richiesta prevede di costruire un vettore con i codici e la fascia dei farmaci che hanno una quantità inferiore rispetto ad un riferimento fornito dall'utente.
Dopo averlo costruito, si deve visualizzare il vettore.

La quinta richiesta prevede di gestire la vendita di uno o più farmaci: il programma deve controllare che il farmaco non sia ospedaliero, deve poi aggiornarne la quantità e calcolare il costo totale che l'assistito deve pagare. Si osserva che il cliente può acquistare farmaci con codice differente ed in quantità maggiore o uguale a una confezione (per esempio: 3 confezioni di un farmaco con codice ADFR5672SWE2901, 2 confezioni di un farmaco con codice JHTR3278BNM90V5, ecc.) Se non si è in grado di risolvere questa richiesta si può semplificarla: il cliente acquista farmaci con codice diverso, ma sempre con quantità pari a una confezione, oppure il cliente acquista un solo farmaco.
*/