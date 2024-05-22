/*
	Declaração das estruturas e das funções da lista dos doentes
*/

#ifndef LISTA_DOENTES_H
#define LISTA_DOENTES_H
#include "../lib/funcsMisc.h"
#include "../lib/structs.h"

void initListaDoentes(list_doentes_t *list); // Função que inicializa a lista
void clearListaDoentes(list_doentes_t *list); // Função que elimina todos os elementos da lista
void insertListaDoentes(list_doentes_t *list, l_noDoentes_t *node); // Função que insere um elemento na lista
void searchListaDoentes(list_doentes_t *list, int id, l_noDoentes_t **prev, l_noDoentes_t **cur); // Função que procura um elemento na lista com base no seu ID
void removeListaDoentes(list_doentes_t *list, int id); // Função que remove um elemento da lista

#endif