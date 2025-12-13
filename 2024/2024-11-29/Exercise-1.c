/*
Si deve impostare un programma per un carcere maschile. Ogni detenuto è descritto dalle seguenti informazioni:

Matricola [max. 10 caratteri]

Stato (in attesa di giudizio, processo in corso, condannato)

Numero mesi di condanna

Numero giorni di carcerazione

Per la dichiarazione dello Stato, si scelga il tipo preferito (intero, carattere, stringa: in tutti i casi si deve chiedere all'utente cosa sceglie specificando le alternative e poi si deve controllare la risposta).

Si richiede di costruire un programma che consenta di gestire il seguente menù ripetibile:

1.       Nuovo detenuto                                                                                                                  

2.       Fine detenzione                                                                                                                                   

3.       Modifiche informazioni                                                                                                     

4.       Lista detenuti sotto processo                                                                                                         

5.       Elenco detenuti prossimi alla liberazione                                                                   

 

Il primo punto prevede di inserire in fondo al vettore un nuovo detenuto chiedendo all'utente solo le informazioni necessarie. 

La seconda richiesta prevede di cancellare i dati di un detenuto di cui è fornita la matricola, perché ha scontato la pena.

La terza richiesta prevede la possibilità di modificare stato e/o numero giorni di carcerazione per un detenuto di cui viene fornita la matricola.

La quarta richiesta prevede di costruire un vettore con la matricola e lo stato dei carcerati attualmente sotto processo o in attesa di giudizio. Dopo averlo costruito, si deve visualizzare il vettore. 

L'ultima richiesta prevede di visualizzare le matricole dei detenuti condannati se manca un solo mese al termine della pena e la percentuale dei detenuti condannati a cui manca solo un mese al termine della pena: si consideri che tutti i mesi siano lunghi 30 giorni.
*/