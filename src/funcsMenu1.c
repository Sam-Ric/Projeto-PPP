/*
    Funções da primeira opção do menu
    >> [1] Introduzir dados de um novo doente
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/listaDoentes.h"
#include "../lib/listaDoentesOA.h"
#include "../lib/funcsMisc.h"

void novoDoente(list_doentes_t *list){
    l_noDoentes_t *node = (l_noDoentes_t*)malloc(sizeof(l_noDoentes_t));
    // Procurar um ID disponível para o novo doente
    l_noDoentes_t *temp = list -> front;
    int id;
    if(temp != NULL){
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        id = temp -> id + 1;
    } else {
        id = 1;
    }
    node -> id = id;
    
    // Caso existam doentes registados, imprimi-los na consola
    if(list -> front != NULL)
        listNomes(list);

    // Pedir ao utilizador os dados do novo doente
    char nome[50];
    int validName = 0;
    while(!validName){
        printf("\nNome do doente:\n>> ");
        inputFunction(nome, 50);
        validName = verifyName(nome);
        if(!validName) printf("\033[31m[!]\033[0m Insira um nome válido.\n");
    }
    strcpy(node -> nome, nome);
    
    struct_data data_de_nascimento;
    char data[50];
    int validData = 0;
    printf("Data: (formato DD/MM/YYYY)\n");
    while(!validData){
        printf(">> __/__/____\r>> ");
        inputFunction(data, 50);
        validData = verifyData(data, &data_de_nascimento);
        if(validData == 0) printf("\033[31m[!]\033[0m Insira uma data válida.\n");
    }
    node -> data_de_nascimento = data_de_nascimento;
    
    printf("Cartão de cidadão:\n");
    char num_cc[50];
    int validCC = 0;
    while(!validCC){
        printf(">> _________-_-___\r>> ");
        inputFunction(num_cc, 50);
        for(int i = 0; i < (int)strlen(num_cc); ++i){
            if((((i >= 0 && i < 9) || i == 10 || i == 14) && (num_cc[i] < '0' || num_cc[i] > '9')) || (num_cc[10] < '0' || num_cc[10] > '9') || num_cc[9] != '-' || num_cc[11] != '-' ||!isLetter(&num_cc[12]) || !isLetter(&num_cc[13])){
                validCC = 0;
            } else validCC = 1;
        }
        if(!validCC) printf("\033[31m[!]\033[0m Insira um número de identificação válido.\n");
    }
    strcpy(node -> num_cc, num_cc);
    

    printf("Telefone:\n");
    char contacto[50] = "VOID";
    while(!isInteger(contacto) || (int)strlen(contacto) != 9){
        printf(">> _________\r>> ");
        inputFunction(contacto, 50);
        if(!isInteger(contacto) || (int)strlen(contacto) != 9) printf("\033[31m[!]\033[0m Insira um contacto válido.\n");
    }
    strcpy(node -> contacto, contacto);

    printf("Email:\n");
    char email[50];
    int validEmail = 0;
    while(!validEmail){
        printf(">> ");
        inputFunction(email, 50);
        validEmail = verifyEmail(email);
        if(validEmail == 0) printf("\033[31m[!]\033[0m Insira um endereço de email válido.\n");
    }
    strcpy(node -> email, email);
    

    // Adicionar o novo doente à lista
    insertListaDoentes(list, node);

    // Atualizar o ficheiro 'doentes.txt'
    updateDoentes(list);
}