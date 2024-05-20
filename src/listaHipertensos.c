/*
    Funções relativas à lista que contém os doentes com tensões máximas acima de um determinado valor
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/structs.h"
#include "../lib/listaDoentes.h"
#include "../lib/listaHipertensos.h"

void initListaDoentesH(list_hipertensos_t *list){
	list -> num_elems = 0;
	list -> front = NULL;
}

int emptyListaDoentesH(list_hipertensos_t *list){
	return list -> front == NULL;
}

void clearListaDoentesH(list_hipertensos_t *list){
	l_noHipertensos_t *node;
	while(list -> front != NULL){
		node = list -> front;
		list -> front = list -> front -> next;
		free(node);
	}
	initListaDoentesH(list);
}

void insertListaDoentesH(list_hipertensos_t *list, l_noRegistos_t *registo){
	l_noHipertensos_t *node = (l_noHipertensos_t*)malloc(sizeof(l_noHipertensos_t));
	l_noHipertensos_t *prev, *cur;
	if(node != NULL){
        node -> ref = registo;
		searchListaDoentesH(list, node -> ref -> tensaoMax, &prev, &cur);
		if(prev != NULL){
			prev -> next = node;
			node -> next = cur;
		} else {
			list -> front = node;
			node -> next = cur;
		}
		list -> num_elems++;
	}
	printf("[DEBUG] Doente inserido na lista dos hipertensos!\n");
}

void searchListaDoentesH(list_hipertensos_t *list, int tensao, l_noHipertensos_t **prev, l_noHipertensos_t **cur){
	*prev = NULL;
	*cur = list -> front;
	while(*cur != NULL && (*cur) -> ref -> tensaoMax > tensao){
		*prev = *cur;
		*cur = (*cur) -> next;
	}
}