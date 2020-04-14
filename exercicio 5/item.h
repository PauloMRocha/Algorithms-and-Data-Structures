#ifndef ITEM_H
#define ITEM_H
#define ERRO -32000

typedef struct item_ ITEM;

//cria um item
ITEM* item_cria(int tipo, char op, float val);
//apaga um item
void item_apaga(ITEM** i);
//seta os valores de um item
void item_set(ITEM* i, int t, char op, float val);
//retorna o tipo do item
int item_tipo(ITEM* i);
//retorna o valor de um item
float item_val(ITEM* i);
//retorna a operação de um item
char item_op(ITEM* i);
//imprime um item
void imprime_item(ITEM* i);

#endif
