/*
	Declaração das estruturas e das funções da lista dos doentes por ordem alfabética
*/

#ifndef LISTA_DOENTES_OA_H
#define LISTA_DOENTES_OA_H
#include "../lib/listaDoentes.h"

typedef struct l_noDoentesOA { // Estrutura de um node da lista dos doentes
	l_noDoentes_t *ref;
	struct l_noDoentesOA *next;
} l_noDoentesOA_t;

typedef struct list_doentesOA_t{ // Estrutura da lista
	size_t num_elems;
	l_noDoentesOA_t *front;
} list_doentesOA_t;

void initListaDoentesOA(list_doentesOA_t *list); // Função que inicializa a lista
int emptyListaDoentesOA(list_doentesOA_t *list); // Função que verifica se a lista está vazia
void clearListaDoentesOA(list_doentesOA_t *list); // Função que elimina todos os elementos da lista
void insertListaDoentesOA(list_doentesOA_t *list, l_noDoentes_t *elem); // Função que insere um elemento na lista
void searchListaDoentesOA(list_doentesOA_t *list, l_noDoentes_t *elem, l_noDoentesOA_t **prev, l_noDoentesOA_t **cur);
void removeListaDoentesOA(list_doentesOA_t *list, l_noDoentes_t *elem); // Função que remove um elemento da lista

#endif