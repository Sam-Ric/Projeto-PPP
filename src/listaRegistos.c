/*
    Funções relativas à lista que contém os dados do ficheiro registos.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/listaRegistos.h"

void initListaRegistos(list_registos_t *list){
	list -> num_elems = 0;
	list -> front = NULL;
}

int emptyListaRegistos(list_registos_t *list){
	return list -> front == NULL;
}

void clearListaRegistos(list_registos_t *list){
	l_noRegistos_t *node;
	while(list -> front != NULL){
		node = list -> front;
		list -> front = list -> front -> next;
		free(node);
	}
	initListaRegistos(list);
}

void insertListaRegistos(list_registos_t *list, int id, char data[50], int tensaoMax, int tensaoMin, int peso, int altura){
	l_noRegistos_t *node = (l_noRegistos_t*)malloc(sizeof(l_noRegistos_t));
	l_noRegistos_t *prev, *cur;
	if(node != NULL){
		node -> id = id;
        strcpy(node -> data, data);
        node -> tensaoMax = tensaoMax;
        node -> tensaoMin = tensaoMin;
        node -> peso = peso;
        node -> altura = altura;
		searchListaRegistos(list, id, &prev, &cur);
		if(prev != NULL){
			prev -> next = node;
			node -> next = cur;
		} else {
			list -> front = node;
			node -> next = cur;
		}
		list -> num_elems++;
	}
	printf("[DEBUG] Registo inserido na lista!\n");
}

void searchListaRegistos(list_registos_t *list, int id, l_noRegistos_t **prev, l_noRegistos_t **cur){
	*prev = NULL;
	*cur = list -> front;
	while(*cur != NULL && (*cur) -> id < id){
		*prev = *cur;
		*cur = (*cur) -> next;
	}
}

void removeListaRegistos(list_registos_t *list, int id){
	l_noRegistos_t *prev, *cur;
	searchListaRegistos(list, id, &prev, &cur);
	if(cur != NULL && cur -> id == id){
        if(prev != NULL)
            prev -> next = cur -> next;
        else
            list -> front = cur -> next;
		free(cur);
		list -> num_elems--;
    }
	printf("[DEBUG] Registo removido da lista!\n");
}