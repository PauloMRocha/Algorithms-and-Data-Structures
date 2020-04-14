#include "circulo.h"
#include <stdlib.h>
#include <math.h>
#define PI 3.14159
struct circulo_{
 PONTO *ponto_c;
 float raio;
};

CIRCULO *circulo_criar (float x, float y, float raio){
  CIRCULO* c = (CIRCULO*)malloc(sizeof(CIRCULO));

  c->ponto_c = ponto_criar(x,y);
  c->raio = raio;

  return c;
};

void circulo_apagar (CIRCULO *circulo){
  free(circulo);
};

float circulo_area (CIRCULO *circulo){
  float area = PI * pow(circulo->raio, 2);
  return area;
};

float circulo_raio(CIRCULO *circulo){
  return circulo->raio;
};

float distancia(PONTO* p, CIRCULO* c){
  float distancia;

  distancia = sqrt((pow((ponto_x(p)-ponto_x(c->ponto_c)), 2)+pow((ponto_y(p)-ponto_y(c->ponto_c)), 2)));
  return distancia;
};
