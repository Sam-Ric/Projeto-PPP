/*
    Diversas funções
*/

#include <stdio.h>
#include <string.h>
#include "../lib/listaDoentes.h"

int convertToInteger(char *str){
    int len = strlen(str);
    printf("[DEBUG] Input string = %s\n[DEBUG] String length = %d\n", str, len);
    int res = 0;
    for(int i = 0; i < len; ++i){
        if(str[i] != '\0' || str[i] != '\n')
            res = res*10 + (str[i] - '0');
    }
    return res;
}

int inputFunction(){
    char str[5];
    fgets(str, 5, stdin);
    int len = strlen(str);
    if(str[len-1] == '\n'){
        str[len-1] = '\0';
    }
    else {
        int ch;
        while((ch = getchar()) != EOF && ch != '\n')
            ;
    }
    return convertToInteger(str);
}

void loadDoentes(list_doentes_t *list){
    // Carregar os dados do ficheiro 'doentes.txt' para uma lista
    FILE * ficheiroDoentes;
    ficheiroDoentes = fopen("doentes.txt", "r"); // Abrir o ficheiro 'doentes.txt'
    char buffer[50];
    int count = 0;
    if(ficheiroDoentes != NULL){
        int id, contacto;
        char nome[50], data_de_nascimento[50], num_cc[50], email[50];
        while(fgets(buffer, 50, ficheiroDoentes)){
            int len = strlen(buffer);
            if(buffer[len-1] == '\n'){
                buffer[len-1] = '\0';
            } else {
            int ch;
            while((ch = getchar()) != EOF && ch != '\n')
                ;
            }
            if(count % 6 == 0){
                for(int i = 0; i < (int)strlen(buffer); ++i)
                    printf("%c\n", buffer[i]);
                id = convertToInteger(buffer);
                printf("ID: %d\n", id);
            }
            if(count % 6 == 1){
                strcpy(nome, buffer);
                printf("Nome: %s\n", nome);
            }
            if(count % 6 == 2){
                strcpy(data_de_nascimento, buffer);
                printf("Data de nascimento: %s\n", data_de_nascimento);
            }
            if(count % 6 == 3){
                strcpy(num_cc, buffer);
                printf("Número do CC: %s\n", num_cc);
            }
            if(count % 6 == 4){
                contacto = convertToInteger(buffer);
                printf("Contacto: %d\n", contacto);
            }
            if(count % 6 == 5){
                strcpy(email, buffer);
                printf("Email: %s\n", email);
                insertDoentes(list, id, nome, data_de_nascimento, num_cc, contacto, email);
            }
            ++count;
        }
    } else {
        printf("[!] Não foi possível abrir o ficheiro.\n");
    }
    fclose(ficheiroDoentes); // Fechar o ficheiro 'doentes.txt'
}