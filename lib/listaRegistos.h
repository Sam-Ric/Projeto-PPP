/*
	Declaração de funções e estruturas relativas à lista dos registos
*/
#ifndef LISTA_REGISTOS_H
#define LISTA_REGISTOS_H

typedef struct {
	int dia, mes, ano;
} data_registos;

typedef struct l_noRegistos { // Estrutura de um node da lista do registos
	int id;
	data_registos data_registo;
	int tensaoMax;
    int tensaoMin;
    int peso;
    int altura;
	struct l_noRegistos *next;
} l_noRegistos_t;

typedef struct list_registos{ // Estrutura da lista
	size_t num_elems;
	l_noRegistos_t *front;
} list_registos_t;

void initListaRegistos(list_registos_t *list); // Função que inicializa a lista
int emptyListaRegistos(list_registos_t *list); // Função que verifica se a lista está vazia
void clearListaRegistos(list_registos_t *list); // Função que elimina todos os elementos da lista
void insertListaRegistos(list_registos_t *list, int id, data_registos data_registo, int tensaoMax, int tensaoMin, int peso, int altura); // Função que insere um elemento na lista
void searchListaRegistos(list_registos_t *list, int id, l_noRegistos_t **prev, l_noRegistos_t **cur); // Função que procura um elemento na lista com base no seu ID
void removeListaRegistos(list_registos_t *list, int id); // Função que remove um elemento da lista
void printRegistos(list_registos_t *list); // Função que imprime todos os registos de um determinado doente

#endif