/*
    Funções da segunda opção do menu
    >> [2] Eliminar um doente existente
*/

#include <stdio.h>
#include "../lib/funcsMisc.h"
#include "../lib/listaDoentes.h"
#include "../lib/listaRegistos.h"

void removerDoente(list_doentes_t *doentes, list_registos_t *registos){
    printf("\nInsira o ID do doente que pretende remover:\n");
    char input[50];
    inputFunction(input, 50);
    int id = convertToInteger(input);
    printf("[DEBUG] verifyID(%d) = %d\n", id, verifyID(doentes, id));
    if(!verifyID(doentes, id)){
        printf("[!] ID inválido.\n");
    } else {
        // Remover o doente selecionado da lista dos doentes
        removeListaDoentes(doentes, id);
        // Remover todos os registos do doente selecionado
        printf("Num elems registos: %d\n", (int)registos -> num_elems);
        for(int i = 0; i < (int)registos -> num_elems; ++i){
            l_noRegistos_t *node = registos -> front;
            if(node -> id == id){
                removeListaRegistos(registos, id);
                printf("[DEBUG] Registo eliminado.\n");
            }
            node = node -> next;
        }
        // Atualizar o ficheiro 'doentes.txt'
        updateDoentes(doentes);
        // Atualizar o ficheiro 'registos.txt'
        updateRegistos(registos);
    }
}