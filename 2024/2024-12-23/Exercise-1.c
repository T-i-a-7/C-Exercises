/*
Si devono gestire le informazioni rilevate da N centraline meteorologiche di una località sciistica. Per
ciascuna centralina vengono forniti
il codice che la identifica (stringa di 10 caratteri)
la precipitazione nevosa rilevata (in cm)
la precipitazione piovosa rilevata (in cm)
la temperatura (°C)
Si deve prevedere un menu ripetibile con le seguenti elaborazioni:
1. inserire una nuova centralina: aggiungere nel vettore una nuova struttura con il codice ed i dati
forniti dall&#39;utente
2. visualizzare tutti i dati delle centraline
3. trovare la percentuale delle centraline che non hanno rilevato alcuna precipitazione nevosa
4. modifica valore di temperatura per una centralina di cui è fornito il codice: per la centralina indicata
si deve richiedere all&#39;utente un nuovo valore e sostituire il vecchio
5. modifica valore di precipitazione nevosa e/o piovosa (a scelta dell&#39;utente) per una centralina di cui
è fornito il codice: per la centralina indicata si deve richiedere all&#39;utente un valore con il quale
incrementare il precedente
6. costruire un vettore che contiene i codici e la precipitazione nevosa delle centraline che hanno, fino
a quel momento, rilevato la temperatura massima. Si deve, poi, visualizzare il vettore
7. cancellare tutte le informazioni di una centralina di cui è fornito il codice
8. percentuale centraline con la temperatura rilevata negativa
9. media delle precipitazioni nevose (quindi diverse da 0) e visualizzazione dei codici delle centraline
con valore maggiore della media
*/