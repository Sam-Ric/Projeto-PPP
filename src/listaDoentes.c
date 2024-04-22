/*
    Funções relativas à lista que contém os dados do ficheiro doentes.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/listaDoentes.h"

void initDoentes(listaDoentes_t *list){
	list -> num_elems = 0;
	list -> front = NULL;
}

int emptyDoentes(listaDoentes_t *list){
	return list -> front == NULL;
}

void clearDoentes(listaDoentes_t *list){
	noDoentes_t *node;
	while(list -> front != NULL){
		node = list -> front;
		list -> front = list -> front -> next;
		free(node);
	}
	initDoentes(list);
}

void insertDoentes(listaDoentes_t *list, int id, char nome[50], char data_de_nascimento[50], char num_cc[50], int contacto, char email[50]){
	noDoentes_t *node = (noDoentes_t*)malloc(sizeof(noDoentes_t));
	noDoentes_t *prev, *cur;
	if(node != NULL){
		node -> id = id;
        strcpy(node -> nome, nome);
        strcpy(node -> data_de_nascimento, data_de_nascimento);
        strcpy(node -> num_cc, num_cc);
        node -> contacto = contacto;
        strcpy(node -> email, email);
		searchDoentes(list, id, &prev, &cur);
		if(prev != NULL){
			prev -> next = node;
			node -> next = cur;
		} else {
			list -> front = node;
			node -> next = cur;
		}
		list -> num_elems++;
	}
}

void searchDoentes(listaDoentes_t *list, int val, noDoentes_t **prev, noDoentes_t **cur){
	*prev = NULL;
	*cur = list -> front;
	while(*cur != NULL && (*cur) -> id < val){
		*prev = *cur;
		*cur = (*cur) -> next;
	}
}

void removeDoentes(listaDoentes_t *list, int val){
	noDoentes_t *prev, *cur;
	searchDoentes(list, val, &prev, &cur);
	if(cur != NULL && cur -> id == val){
        if(prev != NULL)
            prev -> next = cur -> next;
        else
            list -> front = cur -> next;
		free(cur);
		list -> num_elems--;
    }
}