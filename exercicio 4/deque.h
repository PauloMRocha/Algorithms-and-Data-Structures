#ifndef DEQUE_H
#define DEQUE_H
#define ERRO -32000
#define TRUE 1
#define FALSE 0
#define TAM 100

typedef int bool;
typedef struct deque_ DEQUE;

/*
Foi escolhida a estrutura de dados deque para resolver o exercicio pois
nela podemos retirar elemntos das duas pontas e compará-los tornando fácil a
verificação de uma frase ser palindroma ou não. A estrutura foi feita de
maneira circular pois ésta é mais eficiente.
*/

DEQUE* deque_cria(); //cria um deque
int deque_tam(DEQUE* d); //retorna o tamanho atual de um deque
bool deque_vazio(DEQUE* d); //verifica se o deque esta vazio
bool deque_cehio(DEQUE* d); // verifica se o deque esta cheio
bool deque_insere_fim(DEQUE* d, char c); //insere um elemento no fim do deque
bool deque_insere_inicio(DEQUE* d, char c); //insere um elemento no inicio do deque
char deque_remove_fim(DEQUE* d); //retira um alemento do fim do deque
char deque_remove_inicio(DEQUE* d); //retira um elemento do inicio do deque

#endif
