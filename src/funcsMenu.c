/*
    Funções das diferentes funcionalidades da aplicação
*/

#include <stdio.h>
#include "../lib/listaDoentes.h"

void novoDoente(list_doentes_t *list){
    // Procurar um ID disponível para o novo doente
    l_noDoentes_t *temp = list -> front;
    int id = 1;
    for(int i = 0; i < (int)list -> num_elems; ++i)
        if(id == temp -> id){
            ++id;
            temp = temp -> next;
        }
    printf("ID disponível: %d\n", id);
}