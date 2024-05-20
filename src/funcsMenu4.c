/*
    Funções relativas à quarta opção do menu
    >> [4] Listar os doentes com tensões máximas acima de um determinado valor
*/

#include <stdio.h>
#include "../lib/structs.h"
#include "../lib/listaHipertensos.h"

void printTensoes(list_hipertensos_t *hipertensos, list_doentes_t *doentes, int tensao){
	l_noHipertensos_t *node = hipertensos -> front;
    if(node != NULL){
        printf("\n\033[90m================ \033[37m DOENTES COM TENSÃO MÁXIMA ACIMA DE %d \033[90m================\033[0m\n", tensao); //////////////////////// ADICIONAR TEXTO
        printf(" ID \033[90m|\033[0m NOME                              \033[90m|\033[0m TENSÃO\n");
        while(node != NULL){
            printf("%3d \033[90m|\033[0m", node -> ref -> id);
            l_noDoentes_t *doente = doentes -> front;
            while(doente != NULL && doente -> id != node -> ref -> id){
                doente = doente -> next;
            }
            printf(" %-33s \033[90m|\033[0m %5d\n", doente -> nome, node -> ref -> tensaoMax);
		    node = node -> next;
    	}
        printf("\n[DEBUG] Todos os elementos foram imprimidos.\n");
    } else {
        printf("\033[31m[!]\033[0m Não há elementos para imprimir.\n");
    }
}

void loadTensoes(list_hipertensos_t *hipertensos, list_doentes_t *doentes, int tensao){
    l_noDoentes_t *toLoad = doentes -> front;
    while(toLoad != NULL){
        l_noRegistos_t *registo = toLoad -> registos.front;
        while(registo != NULL){
                if(registo -> tensaoMax > tensao) insertListaDoentesH(hipertensos, registo);
            registo = registo -> next;
        }
        toLoad = toLoad -> next;
    }
}