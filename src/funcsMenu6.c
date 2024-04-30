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
            printf("Data do registo:\n");
            char data[50] = "";
            char dia[50] = "VOID";
            char mes[50] = "VOID";
            char ano[50] = "VOID";
            printf("  - Dia:\n");
            while(!isInteger(dia) || convertToInteger(dia) < 1 || convertToInteger(dia) > 31){
                printf("  >> "); // (Formatação do texto)
                inputFunction(dia, 50);
                if(!isInteger(dia) || convertToInteger(dia) < 1 || convertToInteger(dia) > 31) printf("[!] Insira um dia válido.\n");
            }
            printf("  - Mês:\n");
            while(!isInteger(mes) || convertToInteger(mes) < 1 || convertToInteger(mes) > 12){
                printf("  >> "); // (Formatação do texto)
                inputFunction(mes, 50);
                if(!isInteger(mes) || convertToInteger(mes) < 1 || convertToInteger(mes) > 12) printf("[!] Insira um mês válido.\n");
            }
            printf("  - Ano:\n");
            while(!isInteger(ano) || convertToInteger(ano) < 1900 || convertToInteger(ano) > 2024){
                printf("  >> "); // (Formatação do texto)
                inputFunction(ano, 50);
                if(!isInteger(ano) || convertToInteger(ano) < 1900 || convertToInteger(ano) > 2024) printf("[!] Insira um ano válido.\n");
            }
            strcat(data, dia);
            strcat(data, "/");
            strcat(data, mes);
            strcat(data, "/");
            strcat(data, ano);

            printf("Tensão máxima:\n");
            char tempTensaoMax[50];
            inputFunction(tempTensaoMax, 50);
            int tensaoMax = convertToInteger(tempTensaoMax);

            printf("Tensão mínima:\n");
            char tempTensaoMin[50];
            inputFunction(tempTensaoMin, 50);
            int tensaoMin = convertToInteger(tempTensaoMin);

            printf("Peso:\n>> ");
            char tempPeso[50];
            inputFunction(tempPeso, 50);
            int peso = convertToInteger(tempPeso);

            printf("Altura:\n>> ");
            char tempAltura[50];
            inputFunction(tempAltura, 50);
            int altura = convertToInteger(tempAltura);

            // Adicionar o novo registo à lista
            while(node != NULL){
                if(node -> id == id) break;
                node = node -> next;
            }
            insertListaRegistos(&(node -> registos), id, data, tensaoMax, tensaoMin, peso, altura);

            // Imprimir todos os elementos dos registos
            l_noDoentes_t *nodeDoentes = list -> front;
            while(nodeDoentes != NULL){
                list_registos_t *listRegistos = &(nodeDoentes -> registos);
                printRegistos(listRegistos);
                nodeDoentes = nodeDoentes -> next;
            }   

            // Atualizar o ficheiro 'doentes.txt'
            updateRegistos(list);
        } else {
            printf("[!] Não foi possível selecionar o doente.\n");
        }
    } else {
        printf("[!] Não há doentes registados.\n");
    }
    
}