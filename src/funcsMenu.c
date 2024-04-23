/*
    Funções das diferentes funcionalidades da aplicação
*/

#include <stdio.h>
#include "../lib/listaDoentes.h"

void novoDoente(list_doentes_t *list){
    // Procurar um ID disponível para o novo doente
    l_noDoentes_t *temp = list -> front;
    int id = 1;
    while(temp -> next != NULL){
        if(id == temp -> id){
            ++id;
            temp = temp -> next;
        }
        else break;
    }
    printf("ID disponível: %d\n", id);
}