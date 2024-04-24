/*
    Diversas funções
*/

#include <stdio.h>
#include <string.h>
#include "../lib/listaDoentes.h"
#include "../lib/listaRegistos.h"

int convertToInteger(char *str){
    int len = strlen(str);
    //printf("[DEBUG] Input string = %s\n[DEBUG] String length = %d\n", str, len);
    int res = 0;
    for(int i = 0; i < len; ++i){
        if(str[i] != '\0' || str[i] != '\n'){
            res = res*10 + (str[i] - '0');
            //printf("[DEBUG] Char in convertToInteger = %c || ASCII = %.3d\n", str[i], str[i]);
        }
    }
    return res;
}

void inputFunction(char str[], int size){
    printf(">> ");
    fgets(str, size, stdin);
    int len = strlen(str);
    if(str[len-1] == '\n'){
        str[len-1] = '\0';
    }
    else {
        int ch;
        while((ch = getchar()) != EOF && ch != '\n')
            ;
    }
}

void loadDoentes(list_doentes_t *list){
    // Carregar os dados do ficheiro 'doentes.txt' para uma lista
    FILE * ficheiroDoentes;
    ficheiroDoentes = fopen("doentes.txt", "r"); // Abrir o ficheiro 'doentes.txt'
    char buffer[50]; // String que irá armazenar o conteúdo da linha que está a ser lida
    int count = 0; // Variável/Contador que identifica o tipo de dados de uma determinada linha
    if(ficheiroDoentes != NULL){
        // Variáveis que irão armazenar os diferentes tipos de dados do ficheiro
        int id;
        char nome[50], data_de_nascimento[50], num_cc[50], email[50], contacto[50];
        while(fgets(buffer, 50, ficheiroDoentes)){ // Percorrer o ficheiro todo, uma linha de cada vez
            int len = strlen(buffer);
            buffer[len-1] = '\0';
            buffer[len-2] = '\0';
            if(count % 6 == 0){ // Caso se trate de um ID, carregá-lo para a variável 'id'
                id = convertToInteger(buffer);
                //printf("[DEBUG] ID: %d\n", id);
            }
            if(count % 6 == 1){ // Caso se trate de um nome, carregá-lo para a variável 'nome'
                strcpy(nome, buffer);
                //printf("[DEBUG] Nome: %s\n", nome);
            }
            if(count % 6 == 2){ // Caso se trate de uma data de nascimento, carregá-la para a variável 'data_de_nascimento'
                strcpy(data_de_nascimento, buffer);
                //printf("[DEBUG] Data de nascimento: %s\n", data_de_nascimento);
            }
            if(count % 6 == 3){ // Caso se trate de um número de CC, carregá-lo para a variável 'num_cc'
                strcpy(num_cc, buffer);
                //printf("[DEBUG] Número do CC: %s\n", num_cc);
            }
            if(count % 6 == 4){ // Caso se trate de um número de telefone, carregá-lo para a variável 'contacto'
                strcpy(contacto, buffer);
                //printf("[DEBUG] Contacto: %s\n", contacto);
            }
            if(count % 6 == 5){ // Caso se trate de um email, carregá-lo para a variável 'email' e inserir todos os dados na lista dos dados dos doentes
                strcpy(email, buffer);
                //printf("[DEBUG] Email: %s\n", email);
                insertListaDoentes(list, id, nome, data_de_nascimento, num_cc, contacto, email);
            }
            ++count;
        }
    } else {
        printf("[!] Não foi possível abrir o ficheiro.\n");
    }
    printf("[DEBUG] Dados do ficheiro 'doentes.txt' carregados.\n");
    fclose(ficheiroDoentes); // Fechar o ficheiro 'doentes.txt'
}

void loadRegistos(list_registos_t *list){
    // Carregar os dados do ficheiro 'registos.txt' para uma lista
    FILE * ficheiroRegistos;
    ficheiroRegistos = fopen("registos.txt", "r"); // Abrir o ficheiro 'registos.txt'
    char buffer[50]; // String que irá armazenar o conteúdo da linha que está a ser lida
    int count = 0; // Variável/Contador que identifica o tipo de dados de uma determinada linha
    if(ficheiroRegistos != NULL){
        // Variáveis que irão armazenar os diferentes tipos de dados do ficheiro
        int id, tensaoMax, tensaoMin, peso, altura;
        char data[50];
        while(fgets(buffer, 50, ficheiroRegistos)){ // Percorrer o ficheiro todo, uma linha de cada vez
            int len = strlen(buffer);
            buffer[len-1] = '\0';
            buffer[len-2] = '\0';
            if(count % 6 == 0){ // Caso se trate de um ID, carregá-lo para a variável 'id'
                id = convertToInteger(buffer);
                //printf("[DEBUG] ID: %d\n", id);
            }
            if(count % 6 == 1){ // Caso se trate de uma data, carregá-la para a variável 'data'
                strcpy(data, buffer);
                //printf("[DEBUG] Data: %s\n", data);
            }
            if(count % 6 == 2){ // Caso se trate de uma tensão máxima, carregá-la para a variável 'tensaoMax'
                tensaoMax = convertToInteger(buffer);
                //printf("[DEBUG] Tensão máxima: %d\n", tensaoMax);
            }
            if(count % 6 == 3){ // Caso se trate de uma tensão mínima, carregá-lo para a variável 'tensaoMin'
                tensaoMin = convertToInteger(buffer);
                //printf("[DEBUG] Tensão mínima: %d\n", tensaoMin);
            }
            if(count % 6 == 4){ // Caso se trate de um peso, carregá-lo para a variável 'peso'
                peso = convertToInteger(buffer);
                //printf("[DEBUG] Peso: %d\n", peso);
            }
            if(count % 6 == 5){ // Caso se trate de uma altura, carregá-la para a variável 'altura' e inserir todos os dados na lista dos registos
                altura = convertToInteger(buffer);
                //printf("[DEBUG] Altura: %d\n", altura);
                insertListaRegistos(list, id, data, tensaoMax, tensaoMin, peso, altura);
            }
            ++count;
        }
    } else {
        printf("[!] Não foi possível abrir o ficheiro.\n");
    }
    printf("[DEBUG] Dados do ficheiro 'registos.txt' carregados.\n");
    fclose(ficheiroRegistos); // Fechar o ficheiro 'registos.txt'
}

void updateDoentes(list_doentes_t *list){
    FILE * ficheiro;
    ficheiro = fopen("doentes.txt", "w");
    if(ficheiro != NULL){
        l_noDoentes_t *temp = list -> front;
        while(temp != NULL){
            fprintf(ficheiro, "%d\n", temp -> id);
            fprintf(ficheiro, "%s\n", temp -> nome);
            fprintf(ficheiro, "%s\n", temp -> data_de_nascimento);
            fprintf(ficheiro, "%s\n", temp -> num_cc);
            fprintf(ficheiro, "%s\n", temp -> contacto);
            fprintf(ficheiro, "%s\n", temp -> email);
            temp = temp -> next;
        }
        printf("[DEBUG] Ficheiro 'doentes.txt' atualizado!\n");
    } else {
        printf("[!] Não foi possível atualizar o ficheiro.\n");
    }
    fclose(ficheiro);
}

void updateRegistos(list_registos_t *list){
    FILE * ficheiro;
    ficheiro = fopen("registos.txt", "w");
    if(ficheiro != NULL){
        l_noRegistos_t *temp = list -> front;
        while(temp != NULL){
            fprintf(ficheiro, "%d\n", temp -> id);
            fprintf(ficheiro, "%s\n", temp -> data);
            fprintf(ficheiro, "%d\n", temp -> tensaoMax);
            fprintf(ficheiro, "%d\n", temp -> tensaoMin);
            fprintf(ficheiro, "%d\n", temp -> peso);
            fprintf(ficheiro, "%d\n", temp -> altura);
            temp = temp -> next;
        }
        printf("[DEBUG] Ficheiro 'doentes.txt' atualizado!\n");
    } else {
        printf("[!] Não foi possível atualizar o ficheiro.\n");
    }
    fclose(ficheiro);
}

int verifyID(list_doentes_t *list, int id){
    l_noDoentes_t *node = list -> front;
    for(int i = 0; i < (int)list -> num_elems; ++i){
        if(id == node -> id) return 1;
    }
    return 0;
}