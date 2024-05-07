/*
    Funções relativas à lista que contém os dados do ficheiro doentes.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/listaDoentes.h"
#include "../lib/listaRegistos.h"

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
		clearListaRegistos(&(node -> registos));
		free(node);
	}
	initListaDoentes(list);
}

void insertListaDoentes(list_doentes_t *list, int id, char nome[50], struct_data data_de_nascimento, char num_cc[50], char contacto[50], char email[50]){
	l_noDoentes_t *node = (l_noDoentes_t*)malloc(sizeof(l_noDoentes_t));
	l_noDoentes_t *prev, *cur;
	if(node != NULL){
		// Inserir as informações dadas num nó
		node -> id = id;
        strcpy(node -> nome, nome);
		node -> data_de_nascimento.dia = data_de_nascimento.dia;
		node -> data_de_nascimento.mes = data_de_nascimento.mes;
		node -> data_de_nascimento.ano = data_de_nascimento.ano;
        strcpy(node -> num_cc, num_cc);
        strcpy(node -> contacto, contacto);
        strcpy(node -> email, email);
		initListaRegistos(&(node -> registos)); // Inicializar a lista dos registos do doente
		searchListaDoentes(list, id, &prev, &cur); // Procurar o local correto para inserir o nó criado
		// Inserir o nó na lista dos doentes
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

void searchListaDoentes(list_doentes_t *list, int id, l_noDoentes_t **prev, l_noDoentes_t **cur){
	*prev = NULL;
	*cur = list -> front;
	while(*cur != NULL && (*cur) -> id < id){
		*prev = *cur;
		*cur = (*cur) -> next;
	}
}

void removeListaDoentes(list_doentes_t *list, int id){
	l_noDoentes_t *prev, *cur;
	searchListaDoentes(list, id, &prev, &cur);
	if(cur != NULL && cur -> id == id){
        if(prev != NULL)
            prev -> next = cur -> next;
        else
            list -> front = cur -> next;
		clearListaRegistos(&(cur -> registos));
		free(cur);
		list -> num_elems--;
    }
	printf("[DEBUG] Doente removido da lista!\n");
}