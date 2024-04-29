/*
    Funções relativas à lista que contém os dados do ficheiro doentes.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/listaDoentes.h"
#include "../lib/listaDoentesOA.h"

void initListaDoentesOA(list_doentesOA_t *list){
	list -> num_elems = 0;
	list -> front = NULL;
}

int emptyListaDoentesOA(list_doentesOA_t *list){
	return list -> front == NULL;
}

void clearListaDoentesOA(list_doentesOA_t *list){
	l_noDoentesOA_t *node;
	while(list -> front != NULL){
		node = list -> front;
		list -> front = list -> front -> next;
		free(node);
	}
	initListaDoentesOA(list);
}

void insertListaDoentesOA(list_doentesOA_t *list, l_noDoentes_t *elem){
	l_noDoentesOA_t *node = (l_noDoentesOA_t*)malloc(sizeof(l_noDoentesOA_t));
	l_noDoentesOA_t *prev, *cur;
	if(node != NULL){
        node -> ref = elem;
		searchListaDoentesOA(list, elem, &prev, &cur);
		if(prev != NULL){
			prev -> next = node;
			node -> next = cur;
		} else {
			list -> front = node;
			node -> next = cur;
		}
		list -> num_elems++;
	}
	printf("[DEBUG] Doente inserido na lista por ordem alfabética!\n");
}

void searchListaDoentesOA(list_doentesOA_t *list, l_noDoentes_t *elem, l_noDoentesOA_t **prev, l_noDoentesOA_t **cur){
	*prev = NULL;
	*cur = list -> front;
	while(*cur != NULL && strcmp(elem -> nome, (*cur) -> ref -> nome) > 0){
		*prev = *cur;
		*cur = (*cur) -> next;
	}
}

void removeListaDoentesOA(list_doentesOA_t *list, l_noDoentes_t *elem){
	l_noDoentesOA_t *prev, *cur;
	searchListaDoentesOA(list, elem, &prev, &cur);
	if(cur != NULL && cur -> ref -> id == elem -> id){
        if(prev != NULL)
            prev -> next = cur -> next;
        else
            list -> front = cur -> next;
		free(cur);
		list -> num_elems--;
    }
	printf("[DEBUG] Doente removido da lista por ordem alfabética!\n");
}