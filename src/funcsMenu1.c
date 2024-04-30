/*
    Funções da primeira opção do menu
    >> [1] Introduzir dados de um novo doente
*/

#include <stdio.h>
#include <string.h>
#include "../lib/listaDoentes.h"
#include "../lib/funcsMisc.h"

void novoDoente(list_doentes_t *list){
    // Procurar um ID disponível para o novo doente
    l_noDoentes_t *temp = list -> front;
    int id = 1;
    for(int i = 0; i < (int)list -> num_elems; ++i)
        if(id == temp -> id){
            ++id;
            temp = temp -> next;
        }
    //printf("\n[DEBUG] ID disponível: %d\n", id);

    // Caso existam doentes registados, imprimi-los na consola
    if(list -> front != NULL)
        listNomes(list);

    // Pedir ao utilizador os dados do novo doente
    printf("\nNome do doente:\n>> ");
    char nome[50];
    inputFunction(nome, 50);
    
    printf("Data de nascimento:\n");
    char data_de_nascimento[50] = "";
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
    strcat(data_de_nascimento, dia);
    strcat(data_de_nascimento, "/");
    strcat(data_de_nascimento, mes);
    strcat(data_de_nascimento, "/");
    strcat(data_de_nascimento, ano);

    printf("Cartão de cidadão:\n");
    char num_cc[50];
    int validCC = 0;
    while(!validCC){
        printf(">> _________-_-___\r>> ");
        inputFunction(num_cc, 50);
        for(int i = 0; i < (int)strlen(num_cc); ++i){
            if((((i >= 0 && i < 9) || i == 10 || i == 14) && (num_cc[i] < '0' || num_cc[i] > '9')) || num_cc[9] != '-' || num_cc[11] != '-' || !isLetter(&num_cc[12]) || !isLetter(&num_cc[13])){
                validCC = 0;
            } else validCC = 1;
        }
        if(!validCC) printf("[!] Insira um número de identificação válido.\n");
    }
    

    printf("Telefone:\n");
    char contacto[50] = "VOID";
    while(!isInteger(contacto) || (int)strlen(contacto) != 9){
        printf(">> _________\r>> ");
        inputFunction(contacto, 50);
        if(!isInteger(contacto) || (int)strlen(contacto) != 9) printf("[!] Insira um contacto válido.\n");
    }

    printf("Email:\n>> ");
    char email[50];
    inputFunction(email, 50);

    // Adicionar o novo doente à lista
    insertListaDoentes(list, id, nome, data_de_nascimento, num_cc, contacto, email);

    // Atualizar o ficheiro 'doentes.txt'
    updateDoentes(list);
}