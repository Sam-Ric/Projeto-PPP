/*
    Funções da primeira opção do menu
    >> [5] Apresentar toda a informação de um determinado doente
*/

#include <stdio.h>
#include <string.h>
#include "../lib/listaDoentes.h"
#include "../lib/funcsMisc.h"

void printInfo(list_doentes_t *list){
    if(list -> front != NULL){
        listNomes(list);
        printf("\nInsira o ID do doente pretendido:\n>> ");
        char input[50];
        inputFunction(input, 50);
        int id = convertToInteger(input);
        if(verifyID(list, id)){
            l_noDoentes_t *node = list -> front;
            while(node -> next != NULL && node -> id != id){
                node = node -> next;
            }
            printf("\n\033[90m================================= \033[37mID %d \033[90m==================================\033[0m\n", id);
            printf("\033[90mNome: \033[0m %s\n", node -> nome);
            printf("\033[90mData de nascimento: \033[0m %d/%d/%d\n", node -> data_de_nascimento.dia, node -> data_de_nascimento.mes, node -> data_de_nascimento.ano);
            printf("\033[90mCartão de cidadão: \033[0m %s\n", node -> num_cc);
            printf("\033[90mContacto: \033[0m %s\n", node -> contacto);
            printf("\033[90mEmail: \033[0m %s\n", node -> email);
            printf("\033[90mRegistos do doente:\033[0m\n");
            l_noRegistos_t *registo = node -> registos.front;
            if(registo != NULL){
                while(registo != NULL){
                    printf("\n\033[90m>> Data do registo:\033[0m %d/%d/%d\n", registo -> data_registo.dia, registo -> data_registo.mes, registo -> data_registo.ano);
                    printf("\033[90m   Tensão máxima:\033[0m %d\n", registo -> tensaoMax);
                    printf("\033[90m   Tensão mínima:\033[0m %d\n", registo -> tensaoMin);
                    printf("\033[90m   Peso:\033[0m %d\n", registo -> peso);
                    printf("\033[90m   Altura:\033[0m %d\n", registo -> altura);
                    registo = registo -> next;
                }
            } else {
                printf("\033[90m>>\033[0m [!] Não existem registos deste doente.\n");
            }

        } else {
            printf("\033[31m[!]\033[0m ID inválido.\n");
        }
    } else {
        printf("\n\033[31m[!]\033[0m Não há doentes para imprimir.\n");
    }    
}