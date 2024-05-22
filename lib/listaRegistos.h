/*
	Declaração de funções e estruturas relativas à lista dos registos
*/
#ifndef LISTA_REGISTOS_H
#define LISTA_REGISTOS_H
#include "../lib/funcsMisc.h"
#include "../lib/structs.h"

void initListaRegistos(list_registos_t *list); // Função que inicializa a lista
void clearListaRegistos(list_registos_t *list); // Função que elimina todos os elementos da lista
void insertListaRegistos(list_registos_t *list, int id, struct_data data_registo, int tensaoMax, int tensaoMin, int peso, int altura); // Função que insere um elemento na lista
void searchListaRegistos(list_registos_t *list, struct_data data, l_noRegistos_t **prev, l_noRegistos_t **cur); // Função que procura um elemento na lista com base no seu ID

#endif