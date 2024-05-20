/*
    Funções relativas à quarta opção do menu
    >> [4] Listar os doentes com tensões máximas acima de um determinado valor
*/
/*

#include <stdio.h>
#include "../lib/structs.h"
#include "../lib/listaHipertensos.h"

void printTensoes(list_hipertensos_t *hipertensos){
	l_noHipertensos_t *node = hipertensos -> front;
    if(node != NULL){
        printf("\n\033[90m================ \033[37m  \033[90m================\033[0m\n"); //////////////////////// ADICIONAR TEXTO
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

void loadTensoes(list_hipertensos_t *hipertensos, list_doentes_t *doentes){
    l_noHipertensos_t *toLoad = doentes -> front;
    if(toLoad != NULL){
        while(toLoad != NULL){
            insertListaDoentesH(hipertensos, toLoad);
            toLoad = toLoad -> next;
        }
        printf("[DEBUG] Elementos inseridos na lista por ordem alfabética.\n");
    }
}

*/