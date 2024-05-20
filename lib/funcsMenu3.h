/*
    Declaração das funções relativas à terceira opção do menu
    >> [3] Listar todos os doentes por ordem alfabética
*/

#ifndef FUNCSMENU3_H
#define FUNCSMENU3_H

void printDoentesOA(list_doentesOA_t *list); // Função que imprime todos os doentes na consola, por ordem alfabética
void loadDoentesOA(list_doentesOA_t *doentesOA, list_doentes_t *doentes); // Função que armazena ponteiros para os doentes na lista dos doentes, mas ordena-os por ordem alfabética

#endif