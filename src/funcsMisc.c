/*
    Diversas funções
*/

#include <stdio.h>
#include <string.h>
#include "../lib/listaDoentes.h"
#include "../lib/listaRegistos.h"

int convertToInteger(char *str){
    int len = strlen(str);
    int res = 0;
    for(int i = 0; i < len; ++i){
        if(str[i] != '\0' || str[i] != '\n'){
            res = res*10 + (str[i] - '0');
        }
    }
    return res;
}

void inputFunction(char str[], int size){
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
    //printf("[DEBUG] Input = %s\n", str);
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
        char nome[50], num_cc[50], email[50], contacto[50];
        struct_data data_de_nascimento;
        while(fgets(buffer, 50, ficheiroDoentes)){ // Percorrer o ficheiro todo, uma linha de cada vez
            int len = strlen(buffer);
            buffer[len-1] = '\0';
            if(count % 6 == 0){ // Caso se trate de um ID, carregá-lo para a variável 'id'
                id = convertToInteger(buffer);
                //printf("[DEBUG] ID: %d\n", id);
            }
            if(count % 6 == 1){ // Caso se trate de um nome, carregá-lo para a variável 'nome'
                strcpy(nome, buffer);
                //printf("[DEBUG] Nome: %s\n", nome);
            }
            if(count % 6 == 2){ // Caso se trate de uma data de nascimento, carregá-la para a variável 'data_de_nascimento'
                char *dia = strtok(buffer, "/");
                data_de_nascimento.dia = convertToInteger(dia);
                char *mes = strtok(NULL, "/");
                data_de_nascimento.mes = convertToInteger(mes);
                char *ano = strtok(NULL, "/");
                data_de_nascimento.ano = convertToInteger(ano);
                //printf("[DEBUG] Data de nascimento: %s/%s/%s\n", dia, mes, ano);
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

void loadRegistos(list_doentes_t *list){
    // Carregar os dados do ficheiro 'registos.txt' para uma lista
    FILE * ficheiroRegistos;
    ficheiroRegistos = fopen("registos.txt", "r"); // Abrir o ficheiro 'registos.txt'
    char buffer[50]; // String que irá armazenar o conteúdo da linha que está a ser lida
    int count = 0; // Variável/Contador que identifica o tipo de dados de uma determinada linha
    if(ficheiroRegistos != NULL){
        // Variáveis que irão armazenar os diferentes tipos de dados do ficheiro
        int id, tensaoMax, tensaoMin, peso, altura;
        struct_data data;
        while(fgets(buffer, 50, ficheiroRegistos)){ // Percorrer o ficheiro todo, uma linha de cada vez
            int len = strlen(buffer);
            buffer[len-1] = '\0';
            if(count % 6 == 0){ // Caso se trate de um ID, carregá-lo para a variável 'id'
                id = convertToInteger(buffer);
                //printf("[DEBUG] ID: %d\n", id);
            }
            if(count % 6 == 1){ // Caso se trate de uma data, carregá-la para a variável 'data'
                char *dia = strtok(buffer, "/");
                data.dia = convertToInteger(dia);
                char *mes = strtok(NULL, "/");
                data.mes = convertToInteger(mes);
                char *ano = strtok(NULL, "/");
                data.ano = convertToInteger(ano);
                //printf("[DEBUG] Data: %s/%s/%s\n", dia, mes, ano);
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
                l_noDoentes_t *node = list -> front;
                while(node != NULL){
                    if(node -> id == id){
                        insertListaRegistos(&(node -> registos), id, data, tensaoMax, tensaoMin, peso, altura);
                    }
                    node = node -> next;
                }
                
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
            fprintf(ficheiro, "%d/%d/%d\n", temp -> data_de_nascimento.dia, temp -> data_de_nascimento.mes, temp -> data_de_nascimento.ano);
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

void updateRegistos(list_doentes_t *list){
    FILE * ficheiro;
    ficheiro = fopen("registos.txt", "w");
    if(ficheiro != NULL){
        l_noDoentes_t *nodeDoentes = list -> front;
        if(nodeDoentes != NULL){
            while(nodeDoentes != NULL){
                list_registos_t *listRegistos = &(nodeDoentes -> registos);
                l_noRegistos_t *nodeRegistos = listRegistos -> front;
                while(nodeRegistos != NULL){
                    fprintf(ficheiro, "%d\n", nodeRegistos -> id);
                    fprintf(ficheiro, "%d/%d/%d\n", nodeRegistos -> data_registo.dia, nodeRegistos -> data_registo.mes, nodeRegistos -> data_registo.ano);
                    fprintf(ficheiro, "%d\n", nodeRegistos -> tensaoMax);
                    fprintf(ficheiro, "%d\n", nodeRegistos -> tensaoMin);
                    fprintf(ficheiro, "%d\n", nodeRegistos -> peso);
                    fprintf(ficheiro, "%d\n", nodeRegistos -> altura);
                    nodeRegistos = nodeRegistos -> next;
                }
                nodeDoentes = nodeDoentes -> next;
            }
            printf("[DEBUG] Ficheiro 'registos.txt' atualizado!\n");
        }
    } else {
        printf("[!] Não foi possível atualizar o ficheiro.\n");
    }
    fclose(ficheiro);
}

int verifyID(list_doentes_t *list, int id){
    l_noDoentes_t *node = list -> front;
    for(int i = 0; i < (int)list -> num_elems; ++i){
        if(id == node -> id) return 1;
        node = node -> next;
    }
    return 0;
}

int isInteger(char *str){
    int len = strlen(str);
    for(int i = 0; i < len; ++i){
        if(str[i] < '0' || str[i] > '9') return 0;
    }
    return 1;
}

void listNomes(list_doentes_t *list){
    l_noDoentes_t *node = list -> front;
    printf("\n\033[90m============================== \033[37mDOENTES \033[90m===============================\033[0m");
    printf("\n ID \033[90m|\033[0m NOME\n");
    while(node != NULL){
        printf("%3d \033[90m|\033[0m %s\n", node -> id, node -> nome);
        node = node -> next;
    }
}

int isLetter(char *ch){
    if((ch[0] >= 'A' && ch[0] <= 'Z') || (ch[0] >= 'a' && ch[0] <= 'z')){
        if(ch[0] >= 'a' && ch[0] <= 'z') ch[0] -= 32;
        return 1;
    }
    return 0;
}

int verifyData(char *str, struct_data *data){
    if(str[2] == '/' || str[5] == '/' || (int)strlen(str) != 10){
        char *dia = strtok(str, "/");
        char *mes = strtok(NULL, "/");
        char *ano = strtok(NULL, "/");
        if(!isInteger(dia) || !isInteger(mes) || !isInteger(ano))
            return 0;
        else {
            data -> dia = convertToInteger(dia);
            data -> mes = convertToInteger(mes);
            data -> ano = convertToInteger(ano);
        }
    } else
        return 0;

    if(data -> dia < 1 || data -> dia > 31 || data -> mes < 1 || data -> mes > 12 || data -> ano < 1900 || data -> ano > 2024){
        return 0;
    } else {
        if((data -> mes == 1 || data -> mes == 3 || data -> mes == 5 || data -> mes == 7 || data -> mes == 8 || data -> mes == 10 || data -> mes == 12) && (data -> dia < 1 || data -> dia > 31))
            return 0;
        if((data -> mes == 4 || data -> mes == 6 || data -> mes == 9 || data -> mes == 11) && (data -> dia < 1 || data -> dia > 30))
            return 0;
        if(data -> mes == 2 && (data -> dia < 1 || data -> dia > 29))
            return 0;
        return 1;
    }
}

int verifyEmail(char *str){
    int len = strlen(str);
    int flag1 = 0, flag2 = 0;
    for(int i = 0; i < len; ++i){
        if(str[i] == '@') ++flag1;
        if(str[i] == '.') ++flag2;
    }
    if(flag1 == 1 && flag2 >= 1) return 1;
    return 0;
}