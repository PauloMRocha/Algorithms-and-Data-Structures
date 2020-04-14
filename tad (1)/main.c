#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ponto.h"
#include "circulo.h"

int main(void){
PONTO  *pt;
CIRCULO *circ;
float dist;
//variaveis auxiliares para que seja possivel receber os valores do stdin
float x, y, r;

  scanf("%f %f", &x, &y);
  pt = ponto_criar(x, y);

  scanf("%f %f %f", &x, &y, &r);
  circ = circulo_criar(x, y, r);

  dist = distancia(pt, circ);

  if(dist < circulo_raio(circ)){
    printf("O ponto é interior à circunferência.\nDistância: %.2f\n", dist);
  }else{
    if(dist == circulo_raio(circ)){
      printf("O ponto pertence à circunferência.\nDistância: %.2f\n", dist);
    }else{
      printf("O ponto é exterior à circunferência.\nDistância: %.2f\n", dist);
    }
  }

  return 0;
}
