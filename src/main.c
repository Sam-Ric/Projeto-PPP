#include <stdio.h>
#include <string.h>
#include "../lib/funcsMisc.h"
#include "../lib/funcsMenu1.h"
#include "../lib/funcsMenu2.h"
#include "../lib/funcsMenu3.h"
#include "../lib/funcsMenu6.h"
#include "../lib/listaDoentes.h"
#include "../lib/listaRegistos.h"
#include "../lib/listaDoentesOA.h"

int main(){
    int status = 1; // Variável que define se o programa está em execução
    list_doentes_t doentes;
    initListaDoentes(&doentes); // Inicializar a lista que irá armazenar os dados do ficheiro 'doentes.txt'
    loadDoentes(&doentes); // Carregar os dados do ficheiro 'doentes.txt' para a repetiva lista
    list_registos_t registos;
    initListaRegistos(&registos); // Inicializar a lista que irá armazenar os dados do ficheiro 'registos.txt'
    loadRegistos(&registos); // Carregar os dados do ficheiro 'registos.txt' para a respetiva lista

    while(status){
        printf("\n================================= MENU ==================================\n");
        printf("[1] Introduzir dados de um novo doente\n");
        printf("[2] Eliminar um doente existente\n");
        printf("[3] Listar todos os doentes por ordem alfabética\n");
        printf("[4] Listar os doentes com tensões máximas acima de um determinado valor\n");
        printf("[5] Apresentar toda a informação de um determinado doente\n");
        printf("[6] Registar as tensões, o peso e a altura de um determinado doente\n");
        printf("[0] Sair da aplicação\n");
        
        // Input do utilizador
        char s[5];
        inputFunction(s, 5);
        int menu = convertToInteger(s);

        if(menu == 1){ // Introduzir dados de um novo doente
            novoDoente(&doentes);
        }
        else if(menu == 2){ // Eliminar um doente existente
            removerDoente(&doentes);
        }
        else if(menu == 3){ // Listar todos os doentes por ordem alfabética
            list_doentesOA_t doentesOA;
            initListaDoentesOA(&doentesOA);
            loadDoentesOA(&doentesOA, &doentes);
            printDoentesOA(&doentesOA);
            clearListaDoentesOA(&doentesOA);
        }
        else if(menu == 4){ // Listar os doentes com tensões máximas acima de um determinado valor

        }
        else if(menu == 5){ // Apresentar toda a informação de um determinado doente

        }
        else if(menu == 6){ // Registar as tensões, o peso e a altura de um determinado doente
            novoRegisto(&registos, &doentes);
        }
        else if(menu == 0){ // Sair da aplicação
            clearListaDoentes(&doentes); // Libertar a memória alocada para a lista dos dados dos doentes
            clearListaRegistos(&registos); // Libertar a memória alocada para a lista dos registos dos doentes
            status = 0; // Terminar a execução do ciclo while
            printf("\n[DEBUG] Execução terminada.\n");
        }
        else { // Inputs inválidos.
            printf("\n[!] Opção inválida.\n");
        }
    }
    return 0;
}