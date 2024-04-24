/*

*/

#include <stdio.h>
#include "../lib/listaDoentesOA.h"
#include "../lib/listaDoentes.h"

void printDoentesOA(list_doentesOA_t *doentesOA){
	l_noDoentesOA_t *node = doentesOA -> front;
    if(node != NULL){
        while(node != NULL){
		    printf("\n===== ID %2d =====\n", node -> ref -> id);
            printf("Nome:\n>> %s\n", node -> ref -> nome);
            printf("Data de nascimento:\n>> %s\n", node -> ref -> data_de_nascimento);
            printf("Cartão de cidadão:\n>> %s\n", node -> ref -> num_cc);
            printf("Telefone:\n>> %s\n", node -> ref -> contacto);
            printf("Email:\n>> %s\n", node -> ref -> email);
		    node = node -> next;
    	}
        printf("\n[DEBUG] Todos os elementos foram imprimidos.\n");
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