//Acquisiti 50 caratteri trovare e visualizzare carattere Max, percentuale, alfabetici maiuscoli

#include <stdio.h>

int main() {
  char Val, Max;
  int Cont, ContP, Perc;
  ContP = 0;
  for(Cont=0;Cont<50;Cont=Cont+1) {
    printf("Fornisci un carattere");
    scanf("%c", &Val);
    if(Cont=0)
      Max=Val;
    else
      if(Max<Val)
      Max=Val;
    if(Val>="A"&&Val<="Z")
      ContP=ContP+1;
  }      
  printf("Max=%c", Max);
  Perc=ContP*100/50;
  printf("Percentuale=%d", Perc);
return 0;
}