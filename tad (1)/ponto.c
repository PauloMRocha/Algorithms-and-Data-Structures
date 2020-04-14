#include "ponto.h"
#include <stdlib.h>
#include <math.h>
struct ponto_{
 float x;
 float y;
};

float ponto_x(PONTO *p){
  return p->x;
};

float ponto_y(PONTO *p){
  return p->y;
};

PONTO *ponto_criar (float x, float y){
  PONTO *p = malloc(sizeof(PONTO));

  p->x = x;
  p->y = y;

  return p;
};

void ponto_apagar (PONTO *p){
  free(p);
};

int ponto_set (PONTO *p, float x, float y){
  p->x = x;
  p->y = y;

  if(p->x == x && p->y == y) return 1;
  else return 0;
};
