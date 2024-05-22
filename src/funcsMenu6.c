/*
    Funções da primeira opção do menu
    >> [6] Registar as tensões, o peso e a altura de um determinado doente
*/

#include <stdio.h>
#include <string.h>
#include "../lib/listaRegistos.h"
#include "../lib/funcsMisc.h"

void novoRegisto(list_doentes_t *list){
    l_noDoentes_t *node = list -> front;
    if(node != NULL){
        listNomes(list);
        // Pedir ao utilizador os dados para criar um novo registo
        printf("\nID do doente:\n");
        char tempId[50];
        printf(">> ");
        inputFunction(tempId, 50);
        int id = convertToInteger(tempId);
        // Verificar se o ID é válido
        if(verifyID(list, id)){

            // Obter a data do registo
            struct_data data_registo;
            char data[50];
            int validData = 0;
            printf("Data: (formato DD/MM/YYYY)\n");
            while(!validData){
                printf(">> __/__/____\r>> ");
                inputFunction(data, 50);
                validData = verifyData(data, &data_registo);
                if(validData == 0) printf("\033[31m[!]\033[0m Insira uma data válida.\n");
            }

            // Obter o valor da tensão máxima
            printf("Tensão máxima:\n");
            char tempTensaoMax[50] = "VOID";
            while(!isInteger(tempTensaoMax)){
                printf(">> "); // (Formatação do texto)
                inputFunction(tempTensaoMax, 50);
                if(!isInteger(tempTensaoMax)) printf("\033[31m[!]\033[0m Insira um valor válido.\n");
            }
            int tensaoMax = convertToInteger(tempTensaoMax);

            // Obter o valor da tensão mínima
            printf("Tensão mínima:\n");
            char tempTensaoMin[50] = "VOID";
            while(!isInteger(tempTensaoMin)){
                printf(">> "); // (Formatação do texto)
                inputFunction(tempTensaoMin, 50);
                if(!isInteger(tempTensaoMin)) printf("\033[31m[!]\033[0m Insira um valor válido.\n");
            }
            int tensaoMin = convertToInteger(tempTensaoMin);

            // Obter o valor do peso
            printf("Peso:\n");
            char tempPeso[50] = "VOID";
            while(!isInteger(tempPeso)){
                printf(">> "); // (Formatação do texto)
                inputFunction(tempPeso, 50);
                if(!isInteger(tempPeso)) printf("\033[31m[!]\033[0m Insira um valor válido.\n");
            }
            int peso = convertToInteger(tempPeso);

            // Obter o valor da altura
            printf("Altura:\n");
            char tempAltura[50] = "VOID";
            while(!isInteger(tempAltura)){
                printf(">> "); // (Formatação do texto)
                inputFunction(tempAltura, 50);
                if(!isInteger(tempAltura)) printf("\033[31m[!]\033[0m Insira um valor válido.\n");
            }
            int altura = convertToInteger(tempAltura);

            // Adicionar o novo registo à lista
            while(node != NULL){
                if(node -> id == id) break;
                node = node -> next;
            }
            insertListaRegistos(&(node -> registos), id, data_registo, tensaoMax, tensaoMin, peso, altura);

            // Atualizar o ficheiro 'registos.txt'
            updateRegistos(list);
        } else {
            printf("\033[31m[!]\033[0m Não foi possível selecionar o doente.\n");
        }
    } else {
        printf("\033[31m[!]\033[0m Não há doentes registados.\n");
    }
    
}