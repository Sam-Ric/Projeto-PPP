/*

*/

#include <stdio.h>
#include "../lib/listaDoentesOA.h"
#include "../lib/listaDoentes.h"

void printDoentesOA(list_doentesOA_t *doentesOA){
	l_noDoentesOA_t *node = doentesOA -> front;
    printf("[DEBUG] Primeiro elemento da lista por OA: %d\n", node -> ref -> id);
    if(node != NULL){
        printf("\n================ DOENTES POR ORDEM ALFABÉTICA ================\n");
        printf(" ID | NOME\n");
        while(node != NULL){
            printf("%3d | %-s\n", node -> ref -> id, node -> ref -> nome);
		    node = node -> next;
    	}
        printf("\n[DEBUG] Todos os elementos foram imprimidos.\n");
    } else {
        printf("[!] Não foi possível imprimir a lista por ordem alfabética.\n");
    }
}

void loadDoentesOA(list_doentesOA_t *doentesOA, list_doentes_t *doentes){
    l_noDoentes_t *toLoad = doentes -> front;
    if(toLoad != NULL){
        while(toLoad != NULL){
            insertListaDoentesOA(doentesOA, toLoad);
            toLoad = toLoad -> next;
        }
        printf("[DEBUG] Elementos inseridos na lista por ordem alfabética.\n");
    }
}