#include <stdio.h>
#include "lib/funcs.h"
#include "lib/lista.h"

int main(){
    int status = 1; // Variável que define se o programa está em execução (0 = parado | 1 = em execução)
    int menu; // Variável que armazena a escolha

    while(status){
        printf("\n==================================== MENU ====================================\n");
        printf("1 - Adicionar dados de um doente\n");
        printf("2 - Eliminar dados de um doente\n");
        printf("3 - Listar todos os doentes por ordem alfabética\n");
        printf("4 - Listar todos os doentes com tensões máximas acima de um determinado valor\n");
        printf("5 - Apresentar os dados de um doente\n");
        printf("6 - Registar as tensões, o peso e a altura de um doente\n");
        // Input do utilizador
        
        if(menu == 1){ // Adicionar dados de um doente

        }
        else if(menu == 2){ // Eliminar dados de um doente

        }
        else if(menu == 3){ // Listar todos os doentes por ordem alfabética

        }
        else if(menu == 4){ // Listar todos os doentes com tensões máximas acima de um determinado valor

        }
        else if(menu == 5){ // Apresentar os dados de um doente

        }
        else if(menu == 6){ // Registar as tensões, o peso e a altura de um doente
            
        } else if(menu != 0){ // Resposta a inputs inválidos do utilizador
            printf("\nEscolha inválida.\n");
        }
        menu = 0;
    }
    return 0;
}