#ifndef LISTA_H
#define LISTA_H

typedef struct l_node {
	int num;
	struct l_node *next;
} l_node_t;

typedef struct list{
	size_t num_elems;
	l_node_t *front;
} list_t;

void init(list_t *list);
int empty(list_t *list);
void clear(list_t *list);
void print_list(list_t *list);
void search(list_t *list, int val, l_node_t **prev, l_node_t **cur);
void insert(list_t *list, int val, char nome[50], char data_de_nascimento[10], char num_cc[14], int contacto, char email[50]);
void remove_node(list_t *list, int var);

#endif
