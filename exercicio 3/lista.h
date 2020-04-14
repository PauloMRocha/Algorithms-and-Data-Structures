#ifndef LISTA_H
#define LISTA_H
#define FALSE 0
#define TRUE 1

/*
A lista dinamica foi feita de maneira simplesmente encadeada, pois
não é necessario percorrer a lista nas duas direções, alem disso com
a lista simplesmente encadeada economizamos o espaço de um ponteiro
por elemento.
*/

typedef struct aba_ Aba;
typedef struct lista_ Lista;
typedef int bool;

//cria uma nova lista de abas
Lista* cria_lista();
//insere uma nova aba a uma lista e retorna TRUE caso tudo ocorra corretamente
bool insere_aba(Lista* lista, char* nome, char* url);
//printa todos os elementos da lista
void print_lista(Lista* lista);
//encontra um elemento buscando pelo nome e insere em um lugar especifico da lista
void troca_aba(Lista* lista, char* nome, int lugar);
//apaga uma lista
void apaga_lista(Lista** lista);

#endif
