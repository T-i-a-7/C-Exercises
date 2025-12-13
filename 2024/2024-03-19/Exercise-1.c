//Si acquisiscano 5 valori che rappresentano i numeri di mail giornaliere gestite da un grosso operatore di posta elettronica e si memorizzino in un vettore.
//Successivamente si trovino e visualizzino
//a) La media delle mail se in (12000;50000)
//b) La percentuale dei giorni in cui le mail sono state inferiori ad un riferimento
//c) Il numero massimo di mail e tutte le posizioni in cui compare
//d) Il numero minimo di mail se superiori a 150000
//e) Ogni volta che le mail sono state inferiori a 100 visualizzare “Traffico inesistente”



#include <stdio.h>

int main () 
{
    int i,contp,flag=0,
    float m[5], somma=0,rif,max,min,

    printf("fornisci riferimento\n");
    scanf("%f"&,rif);
    for(i=0;i<5;i++)
    {
        do{printf("fornisci valore\n");scanf("%f",&m[i]);
        }while(m[i]<=0)
    }
    for(i=0;i<5;i++)
    {
        if(m[i]>12000&&m[i]<50000)
            somma=somma+m[i];
        if(m[i]<rif)
            contp++;
        if(i==0)
            m[i]=max;
        else if(m[i]>max)
            m[i]=max;
        if(m[i]>150000)
            if(flag==0)
            {
                m[i]=min;
                flag=1;
            }
            else if(m[i]<min)
                m[i]=min;
         if(m[i]<100)
            printf("traffico inesistente\n");
    }



    for(i=0;i<5;i++)
    {
        if(m[i]==max)
            printf("posizione max=%f\n",i+1);
    }




} 