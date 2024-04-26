/*
    Declaração das funções relativas à terceira opção do menu
    >> [3] Listar todos os doentes por ordem alfabética
*/
#ifndef FUNCSMENU3_H
#define FUNCSMENU3_H
#include "../lib/listaDoentes.h"
#include "../lib/listaDoentesOA.h"

void printDoentesOA(list_doentesOA_t *list);
void loadDoentesOA(list_doentesOA_t *doentesOA, list_doentes_t *doentes);

#endif