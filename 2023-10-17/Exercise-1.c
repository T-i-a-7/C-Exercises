//Acquisiti 75 numeri che rappresentano i lati di altrettanti quadrati, trovare e visualizzare area e 
//perimetro per ciascun quadrato. Al termine visualizzare la media de perimetri in (100;130]

#include<stdio.h>

int main() {
  int Cont;
  int ContM=0;
  float Lato, Area, Perimetro;
  float Somma=0;
  for(Cont=0;Cont<75;Cont=Cont+1) {
    printf("Fornisci lato: ");
    scanf("%f",&Lato);
    if(Lato>0) {
      Area=Lato*Lato;
      Perimetro=4*Lato;
      printf("Area= %f\n", Area);
      printf("Perimetro= %f\n", Perimetro);
      if(Perimetro>100&&Perimetro<=130) {
        Somma=Somma+Perimetro;
        ContM=ContM+1;
      }
    }      
  else {
      printf("Valore non geometrico\n");
  }
  }
  if(ContM==0) {
      printf("Media impossibile\n");
  }
  else {
      printf("Media=%f\n", Somma/ContM);
  }
  return 0;
}