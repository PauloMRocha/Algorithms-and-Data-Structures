#ifndef PONTO_H
 #define PONTO_H
 typedef struct ponto_ PONTO;
 PONTO *ponto_criar (float x, float y);
 void ponto_apagar (PONTO *p);
 int ponto_set (PONTO *p, float x, float y);

 /*
 funçoes para retornar os valores das coordenadas do ponto
 para que seja possivel usa-las na função distancia localizada
 no arquivo circulo.c
 */
 float ponto_x(PONTO *p);
 float ponto_y(PONTO *p);
#endif
