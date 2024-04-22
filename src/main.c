#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/funcs.h"
#include "../lib/lista.h"

int main(){
    char menuStr[4];
    int status = 1;
    while(status){
        printf("\n-------------------------------- MENU ----------------------------------\n");
        printf("[1] Introduzir dados de um novo doente\n");
        printf("[2] Eliminar um doente existente\n");
        printf("[3] Listar todos os doentes por ordem alfabética\n");
        printf("[4] Listar os doentes com tensões máximas acima de um determinado valor\n");
        printf("[5] Apresentar toda a informação de um determinado doente\n");
        printf("[6] Registar as tensões, o peso e a altura de um determinado doente\n");
        printf(" >> Para sair da aplicação escreva 'sair'\n");
        fgets(menuStr, 4, stdin);
        int menuInt = convertToInteger("1"); // Input do utilizador
        if(menuInt == 1){ // Introduzir dados de um novo doente

        }
        else if(menuInt == 2){ // Eliminar um doente existente

        }
        else if(menuInt == 3){ // Listar todos os doentes por ordem alfabética

        }
        else if(menuInt == 4){ // Listar os doentes com tensões máximas acima de um determinado valor

        }
        else if(menuInt == 5){ // Apresentar toda a informação de um determinado doente

        }
        else if(menuInt == 6){ // Registar as tensões, o peso e a altura de um determinado doente

        }
        else if(menuInt == 0){ // Sair da aplicação
            status = 0;
        }
        else { // Inputs inválidos.
            printf("\n[!] Opção inválida.\n");
        }
    }
}