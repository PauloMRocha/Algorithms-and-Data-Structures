#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "item.h"
#include "stack.h"

int trata_entada(ITEM** l, char* f){
  int cont_l = 0, cont_f = 0, cont_n = 0;
  char n[5];
  float num;

  //marcando o final da string
  f[strlen(f)+1] = '\0';

  //repartindo a string em items e fazendo as devidas conversoes de valores
  while(f[cont_f] != '\0'){
    //adição de operadores
    if(f[cont_f]<'0' || f[cont_f]>'9'){
      l[cont_l] = item_cria(0, f[cont_f], 0);
      cont_l ++;
      cont_f +=2;
    }else{
      cont_n = 0;
      //adição de operandos
      while(f[cont_f] != ' '){
        n[cont_n] = f[cont_f];
        cont_n ++;
        cont_f ++;
      }
      n[cont_n] = '\0';
      num = atof(n);
      l[cont_l] = item_cria(1, '#', num);
      cont_l ++;
      cont_f ++;
    }
  }
  return cont_l;
}

int main(void){
  int n;
  char func[50];
  ITEM* lista[15];
  ARV* arvore = arv_cria();
  Stack* stk = stack_create();
  NO *t, *t1, *t2;

  //escaniando a entrada
  scanf("%[^\n\r]", func);

  //tratando a entrada
  n = trata_entada(lista, func);

  //montando a arvore
  for(int i = 0; i<n; i++){
		if(item_tipo(lista[i])){
			t = arv_cria_raiz(arvore, lista[i]);
			stack_push(stk,t);
		}
		else{
			t = arv_cria_raiz(arvore, lista[i]);
			t1 = stack_pop(stk);
			t2 = stack_pop(stk);

			arv_insert_f(1, t, t1);
			arv_insert_f(0, t, t2);

			stack_push(stk, t);
		}
	}

  //resolvendo a arvore
  printf("O resultado da operação é %.2f.\n" , arv_resolve(arvore));

  stack_erase(&stk);

  arv_apaga(&arvore);


  return 0;
}
