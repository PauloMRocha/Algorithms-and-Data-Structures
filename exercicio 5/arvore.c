#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "item.h"

struct no_{
  ITEM* item;
  struct no_ *fd;
  struct no_ *fe;
};

struct arv_{
  NO* raiz;
  int prof;
};

ARV* arv_cria(void){
  ARV* r = malloc(sizeof(ARV));

  if(r != NULL){
    r->raiz = NULL;
    r->prof = -1;
  }
  return r;
}

NO* arv_cria_raiz(ARV* a, ITEM* item){
  if(a != NULL){
    a->raiz = (NO*) malloc(sizeof(NO));
    if(a->raiz != NULL){
      a->raiz->item = item;
      a->raiz->fd = NULL;
      a->raiz->fe = NULL;
      a->prof ++;
    }
  }
  return a->raiz;
}

NO* arv_insert_f(int f, NO* no, NO* item){

  if(f == 1){
    no->fd = item;
  }else{
    no->fe = item;
  }
  return item;
}

int arv_apaga(ARV** a){
  if(*a != NULL){
    no_apaga(&(*a)->raiz);
    free(*a);
    (*a) = NULL;
    return 1;
  }
  return 0;
}

void no_apaga(NO** raiz){
  if((*raiz) != NULL){
    no_apaga(&(*raiz)->fd);
    no_apaga(&(*raiz)->fe);
    item_apaga(&(*raiz)->item);
    free(*raiz);
    (*raiz) = NULL;
  }
}


float no_resolve(NO* raiz){
  float a, b;

  //se é um operando retorna o valor dele
  if(item_tipo(raiz->item) == 1){
    return item_val(raiz->item);
  }

  //caso contrio chama a função recursivamente pare os dois filhos
  a = no_resolve(raiz->fe);
  b = no_resolve(raiz->fd);

  //realisa as operações
  if(item_op(raiz->item) == '+') return a+b;
  else if(item_op(raiz->item) == '-') return a-b;
  else if(item_op(raiz->item) == '*') return a*b;
  else{
    if(b == 0){
      printf("Não foi possível realizar a operação.\n");
      exit(0);
    }
    return a/b;
  }
}

float arv_resolve(ARV* a){
  return (a != NULL && a->raiz != NULL) ? no_resolve(a->raiz) : -32000.0;
}

void no_print(NO* raiz){
  if(raiz != NULL){
    imprime_item(raiz->item);
    no_print(raiz->fe);
    no_print(raiz->fd);
  }else{
    printf("RAIZ NULA\n");
  }
}

void arv_print(ARV* a){
  if(a != NULL){
    no_print(a->raiz);
  }
}
