#ifndef ARVORE_H
#define ARVORE_H
#include "item.h"

typedef ITEM ITEM;
typedef struct arv_ ARV;
typedef struct no_ NO;

//cria arvore
ARV* arv_cria(void);
//cria raiz da arvore
NO* arv_cria_raiz(ARV* a, ITEM* item);
//insere um no filho a um nó (f=1 insere na direita, f=0 insere na esquerda)
NO* arv_insert_f(int f, NO* no, NO* item);
//apaga uma arvore
int arv_apaga(ARV** a);
//apaga um nó
void no_apaga(NO** raiz);
//resolve a arvore e retorna o resultado
float arv_resolve(ARV* a);
//printa uma arvore
void arv_print(ARV* a);

#endif
