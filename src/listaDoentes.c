/*
    Funções relativas à lista que contém os dados do ficheiro doentes.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/listaDoentes.h"

void initListaDoentes(list_doentes_t *list){
	list -> num_elems = 0;
	list -> front = NULL;
}

int emptyListaDoentes(list_doentes_t *list){
	return list -> front == NULL;
}

void clearListaDoentes(list_doentes_t *list){
	l_noDoentes_t *node;
	while(list -> front != NULL){
		node = list -> front;
		list -> front = list -> front -> next;
		free(node);
	}
	initListaDoentes(list);
}

void insertListaDoentes(list_doentes_t *list, int id, char nome[50], char data_de_nascimento[50], char num_cc[50], char contacto[50], char email[50]){
	l_noDoentes_t *node = (l_noDoentes_t*)malloc(sizeof(l_noDoentes_t));
	l_noDoentes_t *prev, *cur;
	if(node != NULL){
		node -> id = id;
        strcpy(node -> nome, nome);
        strcpy(node -> data_de_nascimento, data_de_nascimento);
        strcpy(node -> num_cc, num_cc);
        strcpy(node -> contacto, contacto);
        strcpy(node -> email, email);
		searchListaDoentes(list, id, &prev, &cur);
		if(prev != NULL){
			prev -> next = node;
			node -> next = cur;
		} else {
			list -> front = node;
			node -> next = cur;
		}
		list -> num_elems++;
	}
	printf("[DEBUG] Doente inserido na lista!\n");
}

void searchListaDoentes(list_doentes_t *list, int val, l_noDoentes_t **prev, l_noDoentes_t **cur){
	*prev = NULL;
	*cur = list -> front;
	while(*cur != NULL && (*cur) -> id < val){
		*prev = *cur;
		*cur = (*cur) -> next;
	}
}

void removeListaDoentes(list_doentes_t *list, int val){
	l_noDoentes_t *prev, *cur;
	searchListaDoentes(list, val, &prev, &cur);
	if(cur != NULL && cur -> id == val){
        if(prev != NULL)
            prev -> next = cur -> next;
        else
            list -> front = cur -> next;
		free(cur);
		list -> num_elems--;
    }
	printf("[DEBUG] Doente removido da lista!\n");
}