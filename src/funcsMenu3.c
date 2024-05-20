/*

*/

#include <stdio.h>
#include "../lib/listaDoentesOA.h"
#include "../lib/listaDoentes.h"

void printDoentesOA(list_doentesOA_t *doentesOA){
	l_noDoentesOA_t *node = doentesOA -> front;
    if(node != NULL){
        printf("\n\033[90m================ \033[37mDOENTES POR ORDEM ALFABÉTICA \033[90m================\033[0m\n");
        printf(" ID \033[90m|\033[0m NOME\n");
        while(node != NULL){
            printf("%3d \033[90m|\033[0m %-s\n", node -> ref -> id, node -> ref -> nome);
		    node = node -> next;
    	}
        printf("\n[DEBUG] Todos os elementos foram imprimidos.\n");
    } else {
        printf("\033[31m[!]\033[0m Não há elementos para imprimir.\n");
    }
}

void loadDoentesOA(list_doentesOA_t *doentesOA, list_doentes_t *doentes){
    l_noDoentes_t *toLoad = doentes -> front;
    if(toLoad != NULL){
        for(int i = 0; i < (int)(doentes -> num_elems); ++i){
            insertListaDoentesOA(doentesOA, toLoad);
            toLoad = toLoad -> next;
        }
        printf("[DEBUG] Elementos inseridos na lista por ordem alfabética.\n");
    }
}