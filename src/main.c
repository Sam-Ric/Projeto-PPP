#include <stdio.h>
#include <string.h>
#include "../lib/funcsMisc.h"
#include "../lib/funcsMenu.h"
#include "../lib/listaDoentes.h"

int main(){
    int status = 1;
    list_doentes_t doentes;
    initDoentes(&doentes); // Inicializar a lista que irá armazenar os dados do ficheiro 'doentes.txt'
    loadDoentes(&doentes); // Carregar os dados do ficheiro 'doentes.txt' para a lista

    // Permitir que o utilizador selecione o que pretende fazer enquanto a condição se verificar
    while(status){
        printf("\n-------------------------------- MENU ----------------------------------\n");
        printf("[1] Introduzir dados de um novo doente\n");
        printf("[2] Eliminar um doente existente\n");
        printf("[3] Listar todos os doentes por ordem alfabética\n");
        printf("[4] Listar os doentes com tensões máximas acima de um determinado valor\n");
        printf("[5] Apresentar toda a informação de um determinado doente\n");
        printf("[6] Registar as tensões, o peso e a altura de um determinado doente\n");
        printf("[0] Sair da aplicação\n");
        int input = inputFunction(); // Input do utilizador
        printf("Input = %d\n", input);
        if(input == 1){ // Introduzir dados de um novo doente
            novoDoente(&doentes);
        }
        else if(input == 2){ // Eliminar um doente existente

        }
        else if(input == 3){ // Listar todos os doentes por ordem alfabética

        }
        else if(input == 4){ // Listar os doentes com tensões máximas acima de um determinado valor

        }
        else if(input == 5){ // Apresentar toda a informação de um determinado doente

        }
        else if(input == 6){ // Registar as tensões, o peso e a altura de um determinado doente

        }
        else if(input == 0){ // Sair da aplicação
            status = 0;
        }
        else { // Inputs inválidos.
            printf("\n[!] Opção inválida.\n");
        }
    }
}