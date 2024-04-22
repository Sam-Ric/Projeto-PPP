/*
	Declaração das estruturas e das funções da lista dos doentes
*/

#ifndef LISTA_DOENTES_H
#define LISTA_DOENTES_H

typedef struct noDoentes { // Estrutura de um node da lista
	int id;
	char nome[50];
	char data_de_nascimento[50];
	char num_cc[50];
	int contacto;
	char email[50];
	struct noDoentes *next;
} noDoentes_t;

typedef struct listaDoentes{ // Estrutura da lista
	size_t num_elems;
	noDoentes_t *front;
} listaDoentes_t;

void initDoentes(listaDoentes_t *list); // Função que inicializa a lista
int emptyDoentes(listaDoentes_t *list); // Função que verifica se a lista está vazia
void clearDoentes(listaDoentes_t *list); // Função que elimina todos os elementos da lista
void insertDoentes(listaDoentes_t *list, int id, char nome[50], char data_de_nascimento[50], char num_cc[50], int contacto, char email[50]); // Função que insere um elemento na lista
void searchDoentes(listaDoentes_t *list, int val, noDoentes_t **prev, noDoentes_t **cur); // Função que procura um elemento na lista com base no seu ID
void removeDoentes(listaDoentes_t *list, int var); // Função que remove um elemento da lista

#endif