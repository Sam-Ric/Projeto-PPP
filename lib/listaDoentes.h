/*
	Declaração das estruturas e das funções da lista dos doentes
*/

#ifndef LISTA_DOENTES_H
#define LISTA_DOENTES_H

typedef struct l_noDoentes { // Estrutura de um node da lista dos doentes
	int id;
	char nome[50];
	char data_de_nascimento[50];
	char num_cc[50];
	char contacto[50];
	char email[50];
	struct l_noDoentes *next;
} l_noDoentes_t;

typedef struct list_doentes_t{ // Estrutura da lista
	size_t num_elems;
	l_noDoentes_t *front;
} list_doentes_t;

void initListaDoentes(list_doentes_t *list); // Função que inicializa a lista
int emptyListaDoentes(list_doentes_t *list); // Função que verifica se a lista está vazia
void clearListaDoentes(list_doentes_t *list); // Função que elimina todos os elementos da lista
void insertListaDoentes(list_doentes_t *list, int id, char nome[50], char data_de_nascimento[50], char num_cc[50], char contacto[50], char email[50]); // Função que insere um elemento na lista
void searchListaDoentes(list_doentes_t *list, int id, l_noDoentes_t **prev, l_noDoentes_t **cur); // Função que procura um elemento na lista com base no seu ID
void removeListaDoentes(list_doentes_t *list, int id); // Função que remove um elemento da lista

#endif