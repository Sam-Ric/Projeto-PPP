/*
    Declaração de funções diversas
*/

#ifndef FUNCS_H
#define FUNCS_H
#include "../lib/listaDoentes.h"
#include "../lib/listaRegistos.h"

int convertToInteger(char *str); // Função que converte números em formato de string para números inteiros
void inputFunction(char str[], int size); // Função que obtém o input do utilizador usando a função 'fgets()'
void loadDoentes(list_doentes_t *list); // Função que carrega os dados do ficheiro 'doentes.txt' para a respetiva lista
void loadRegistos(list_doentes_t *list); // Função que carrega os dados do ficheiro 'registos.txt' para a respetiva lista
void updateDoentes(list_doentes_t *list); // Função que atualiza o ficheiro 'doentes.txt'
void updateRegistos(list_doentes_t *list); // Função que atualiza o ficheiro 'registos.txt'
int verifyID(list_doentes_t *list, int id); // Função que verifica a existência de um ID
int isInteger(char *str); // Função que verifica se há um inteiro armazenado numa string
void listNomes(list_doentes_t *list); // Função que imprime os nomes e IDs de todos os doentes
int isLetter(char *ch); // Função que verifica se um caracter dado é uma letra e, se for, converte as letras minúsculas em maiúsculas

#endif