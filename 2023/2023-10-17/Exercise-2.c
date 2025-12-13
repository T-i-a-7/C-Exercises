//Acquisiti 110 valori numerici trovare e visualizzare:
//a) Minimo e quante volte compare
//b) Media dei dispari
//c) Percentuale valori fuori da [-18;130]

#include<stdio.h>

int main() {
  int Cont, Val, Min;
  int ContMin=0;
  int Somma=0;
  int ContM=0;
  int ContP=0;
  for(Cont=0;Cont<110;Cont=Cont+1) {
    printf("Fornisci valore/n");
    scanf("%d", &Val);
    if(Cont==0) {
      Min=Val;
      ContMin=ContMin+1;
    }
    else {
      if(Min>Val) {
        Min=Val;
        ContMin=1;
      }
      else {
        if(Val==Min) {
        ContMin=ContMin+1;
        }
      }
    }
    if(Val%2==1) {
      Somma=Somma+Val;
      ContM=ContM+1;
    }
    if(Val<18||Val>130) {
      ContP=ContP+1;
    }
  } //fine del for
  printf("Min=%d e compare %d volte./n", Min, ContMin);
  if(ContM==0) {
    printf("Media impossibile/n");
  }
  else {
    printf("Media=%d/n", Somma/ContM);
  }
  printf("Percentuale=%d/n", ContP*100/Cont);
  return 0;
}