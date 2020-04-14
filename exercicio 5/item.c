#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct item_{
  int tipo;
  char op;
  float val;
};

ITEM* item_cria(int tipo, char op, float val){
  ITEM* i = malloc(sizeof(ITEM));

  if(i != NULL){
    i->tipo = tipo;
    i->op = op;
    i->val = val;
  }
  return i;
}

void item_apaga(ITEM** i){
  if(*i !=NULL){
    free(*i);
    (*i) = NULL;
  }
}

void item_set(ITEM* i, int t, char op, float val){
  i->tipo = t;
  i->op = op;
  i->val = val;
}

int item_tipo(ITEM* i){
  return (i != NULL ? i->tipo : ERRO);
}

float item_val(ITEM* i){
  return (i != NULL ? i->val : (float)ERRO);
}

char item_op(ITEM* i){
  return (i != NULL ? i->op : '#');
}

void imprime_item(ITEM* i){
  if(i != NULL)
  printf("tipo %d\nop %c\nval %.2f\n\n", item_tipo(i), i->op, i->val);
}
