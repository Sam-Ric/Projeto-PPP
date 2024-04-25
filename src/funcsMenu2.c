/*
    Funções da segunda opção do menu
    >> [2] Eliminar um doente existente
*/

#include <stdio.h>
#include "../lib/funcsMisc.h"
#include "../lib/listaDoentes.h"

void removerDoente(list_doentes_t *list){
    printf("\nInsira o ID do doente que pretende remover:\n");
    char input[50];
    inputFunction(input, 50);
    int id = convertToInteger(input);
    if(verifyID(list, id)){
        printf("[!] ID inválido.\n");
    } else {
        // Remover o doente selecionado da lista
        removeListaDoentes(list, id);
        // Atualizar o ficheiro 'doentes.txt'
        updateDoentes(list);
    }
}