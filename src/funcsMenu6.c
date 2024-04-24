/*
    Funções da primeira opção do menu
    >> [6] Registar as tensões, o peso e a altura de um determinado doente
*/

#include <stdio.h>
#include "../lib/listaRegistos.h"
#include "../lib/funcsMisc.h"

void novoRegisto(list_registos_t *registos, list_doentes_t *doentes){
    // Pedir ao utilizador os dados para criar um novo registo
    printf("\nID do doente:\n");
    char tempId[50];
    inputFunction(tempId, 50);
    int id = convertToInteger(tempId);
    // Verificar se o ID é válido
    printf("ID = %d\n", id);
    if(verifyID(doentes, id)){
        printf("Data do registo:\n");
        char data[50];
        inputFunction(data, 50);

        printf("Tensão máxima:\n");
        char tempTensaoMax[50];
        inputFunction(tempTensaoMax, 50);
        int tensaoMax = convertToInteger(tempTensaoMax);

        printf("Tensão mínima:\n");
        char tempTensaoMin[50];
        inputFunction(tempTensaoMin, 50);
        int tensaoMin = convertToInteger(tempTensaoMin);

        printf("Peso:\n");
        char tempPeso[50];
        inputFunction(tempPeso, 50);
        int peso = convertToInteger(tempPeso);

        printf("Altura:\n");
        char tempAltura[50];
        inputFunction(tempAltura, 50);
        int altura = convertToInteger(tempAltura);

        // Adicionar o novo doente à lista
        insertListaRegistos(registos, id, data, tensaoMax, tensaoMin, peso, altura);

        // Atualizar o ficheiro 'doentes.txt'
        updateRegistos(registos);
    } else {
        printf("[!] Não foi possível selecionar o doente.\n");
    }
}