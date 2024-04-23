/*
	Declaração das estruturas e das funções da lista dos doentes
*/

#ifndef LISTA_DOENTES_H
#define LISTA_DOENTES_H

typedef struct l_noDoentes { // Estrutura de um node da lista
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

void initDoentes(list_doentes_t *list); // Função que inicializa a lista
int emptyDoentes(list_doentes_t *list); // Função que verifica se a lista está vazia
void clearDoentes(list_doentes_t *list); // Função que elimina todos os elementos da lista
void insertDoentes(list_doentes_t *list, int id, char nome[50], char data_de_nascimento[50], char num_cc[50], char contacto[50], char email[50]); // Função que insere um elemento na lista
void searchDoentes(list_doentes_t *list, int val, l_noDoentes_t **prev, l_noDoentes_t **cur); // Função que procura um elemento na lista com base no seu ID
void removeDoentes(list_doentes_t *list, int var); // Função que remove um elemento da lista

#endif