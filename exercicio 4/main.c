#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "deque.h"



int main(void){
  DEQUE* d = deque_cria();
  char frase[100];
  int flag = 1;

  if(d == NULL) return 1;
  
  //recebe a frase;
  scanf("%[^\n]", frase);

  //o for a seguir verifica quais caracteres devem ser colocados no deque
  for(int i= 0; i<strlen(frase); i++){
    if(frase[i]>='a' && frase[i]<='z'){
      deque_insere_fim(d, frase[i]);
    }else{
      if(frase[i]>='A' && frase[i]<='Z'){//converte letas maiusculas em minusculas ao colocalas no deque
        deque_insere_fim(d, (char)(frase[i]+32));
      }
    }
  }

  //verifica se é palindromo
  while(deque_tam(d)>1 && flag){
    if(deque_remove_fim(d)!= deque_remove_inicio(d)){
      flag = 0;
    }
  }

  //printa a resposta
  if(flag) printf("É palíndromo.\n");
  else printf("Não é palíndromo.\n");

  return 0;
}
