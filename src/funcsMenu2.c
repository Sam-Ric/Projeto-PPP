/*
    Funções da segunda opção do menu
    >> [2] Eliminar um doente existente
*/

#include <stdio.h>
#include "../lib/funcsMisc.h"
#include "../lib/listaDoentes.h"
#include "../lib/listaRegistos.h"

void removerDoente(list_doentes_t *list){
    if(list -> num_elems == 0){
        printf("[!] Não há doentes para eliminar.\n");
    } else {
        listNomes(list);
        printf("\nInsira o ID do doente que pretende remover:\n");
        char input[50];
        inputFunction(input, 50);
        int id = convertToInteger(input);
        printf("[DEBUG] verifyID(%d) = %d\n", id, verifyID(list, id));
        if(!verifyID(list, id)){
            printf("[!] ID inválido.\n");
        } else {
            // Remover o doente selecionado da lista dos doentes
            removeListaDoentes(list, id);

            // Atualizar o ficheiro 'doentes.txt'
            updateDoentes(list);
            // Atualizar o ficheiro 'registos.txt'
            updateRegistos(list);
        }
    }
}