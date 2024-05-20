/*
    Funções relativas à lista que contém os doentes com tensões máximas acima de um determinado valor
*/
/*
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

void insertListaDoentesH(list_hipertensos_t *list, l_noHipertensos_t *elem, int tensao){
	l_noHipertensos_t *node = (l_noHipertensos_t*)malloc(sizeof(l_noHipertensos_t));
	l_noHipertensos_t *prev, *cur;
	if(node != NULL){
        node -> ref = elem;
		searchListaDoentesH(list, tensao, &prev, &cur);
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
	int maiorTensao = 0;
	l_noRegistos_t *temp = (*cur) -> ref -> registos.front;
	while(temp -> next != NULL){
		if(temp -> tensaoMax > maiorTensao) maiorTensao = temp -> tensaoMax;
		temp = temp -> next;
	}
	while(*cur != NULL && maiorTensao > tensao){
		*prev = *cur;
		*cur = (*cur) -> next;
	}
}

void removeListaDoentesH(list_hipertensos_t *list, l_noDoentes_t *elem){
	l_noHipertensos_t *prev, *cur;
	searchListaDoentesH(list, elem, &prev, &cur);
	if(cur != NULL && cur -> ref -> id == elem -> id){
        if(prev != NULL)
            prev -> next = cur -> next;
        else
            list -> front = cur -> next;
		free(cur);
		list -> num_elems--;
    }
	printf("[DEBUG] Doente removido da lista dos hipertensos!\n");
}
*/