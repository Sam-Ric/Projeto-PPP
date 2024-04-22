#include <stdio.h>
#include <stdlib.h>
#include "lib/lista.h"

void init(list_t *list){
	list -> num_elems = 0;
	list -> front = NULL;
}

int empty(list_t *list){
	return list -> front == NULL;
}

void clear(list_t *list){
	l_node_t *node;
	while(list -> front != NULL){
		node = list -> front;
		list -> front = list -> front -> next;
		free(node);
	}
	init(list);
}

void print_list(list_t *list){
	l_node_t *node = list -> front;
	while(node != NULL){
		printf("%3d", node -> num); // Os argumentos podem ser alterados
		node = node -> next;
	}
}

void search(list_t *list, int val, l_node_t **prev, l_node_t **cur){
	*prev = NULL;
	*cur = list -> front;
	while(*cur != NULL && (*cur) -> num < val){
		*prev = *cur;
		*cur = (*cur) -> next;
	}
}

void insert(list_t *list, int val){
	l_node_t *node = (l_node_t*)malloc(sizeof(l_node_t));
	l_node_t *prev, *cur;
	if(node != NULL){
		node -> num = val;
		search(list, val, &prev, &cur);
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

void remove_node(list_t *list, int val){
	l_node_t *prev, *cur;
	search(list, val, &prev, &cur);
	if(cur != NULL && cur -> num == val){
        if(prev != NULL)
            prev -> next = cur -> next;
        else
            list -> front = cur -> next;
		free(cur);
		list -> num_elems--;
    }
}