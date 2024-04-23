/*
    Funções diversas
*/

#ifndef FUNCS_H
#define FUNCS_H
#include "../lib/listaDoentes.h"

int convertToInteger(char *str); // Função que converte números em formato de string para números inteiros
void inputFunction(char str[], int size); // Função que obtém o input do utilizador usando a função 'fgets()'
void loadDoentes(list_doentes_t *list); // Função que carrega os dados do ficheiro 'doentes.txt' para uma lista
void updateDoentes(list_doentes_t *list); // Função que atualiza o ficheiro 'doentes.txt'

#endif