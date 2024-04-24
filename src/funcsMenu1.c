/*
    Funções da primeira opção do menu
    >> [1] Introduzir dados de um novo doente
*/

#include <stdio.h>
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

    // Pedir ao utilizador os dados do novo doente
    printf("\nNome do doente:\n");
    char nome[50];
    inputFunction(nome, 50);
    
    printf("Data de nascimento:\n");
    char data_de_nascimento[50];
    inputFunction(data_de_nascimento, 50);

    printf("Cartão de cidadão:\n");
    char num_cc[50];
    inputFunction(num_cc, 50);

    printf("Telefone:\n");
    char contacto[50];
    inputFunction(contacto, 50);

    printf("Email:\n");
    char email[50];
    inputFunction(email, 50);

    // Adicionar o novo doente à lista
    insertListaDoentes(list, id, nome, data_de_nascimento, num_cc, contacto, email);

    // Atualizar o ficheiro 'doentes.txt'
    updateDoentes(list);
}