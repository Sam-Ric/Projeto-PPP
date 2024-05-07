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
    /*
    printf("[DEBUG] String = '%s'\n", data);
    char *dia = strtok(data, "/");
    printf("[DEBUG] Dia = %s\n", dia);
    data_de_nascimento.dia = convertToInteger(dia);
    char *mes = strtok(NULL, "/");
    printf("[DEBUG] Mês = %s\n", mes);
    data_de_nascimento.mes = convertToInteger(mes);
    char *ano = strtok(NULL, "/");
    printf("[DEBUG] Ano = %s\n", ano);
    data_de_nascimento.ano = convertToInteger(ano);
    */
    printf("Cartão de cidadão:\n");
    char num_cc[50];
    int validCC = 0;
    while(!validCC){
        printf(">> _________-_-___\r>> ");
        inputFunction(num_cc, 50);
        for(int i = 0; i < (int)strlen(num_cc); ++i){
            if((((i >= 0 && i < 9) || i == 10 || i == 14) && (num_cc[i] < '0' || num_cc[i] > '9')) || num_cc[9] != '-' || num_cc[11] != '-' || !isLetter(&num_cc[10]) ||!isLetter(&num_cc[12]) || !isLetter(&num_cc[13])){
                validCC = 0;
            } else validCC = 1;
        }
        if(!validCC) printf("\033[31m[!]\033[0m Insira um número de identificação válido.\n");
    }
    

    printf("Telefone:\n");
    char contacto[50] = "VOID";
    while(!isInteger(contacto) || (int)strlen(contacto) != 9){
        printf(">> _________\r>> ");
        inputFunction(contacto, 50);
        if(!isInteger(contacto) || (int)strlen(contacto) != 9) printf("\033[31m[!]\033[0m Insira um contacto válido.\n");
    }

    printf("Email:\n>> ");
    char email[50];
    inputFunction(email, 50);

    // Adicionar o novo doente à lista
    insertListaDoentes(list, id, nome, data_de_nascimento, num_cc, contacto, email);

    // Atualizar o ficheiro 'doentes.txt'
    FILE * ficheiro = fopen("doentes.txt", "a");
    fprintf(ficheiro, "%d\n", id);
    fprintf(ficheiro, "%s\n", nome);
    fprintf(ficheiro, "%d/%d/%d\n", data_de_nascimento.dia, data_de_nascimento.mes, data_de_nascimento.ano);
    fprintf(ficheiro, "%s\n", num_cc);
    fprintf(ficheiro, "%s\n", contacto);
    fprintf(ficheiro, "%s\n", email);
    fclose(ficheiro);
}