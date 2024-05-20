/*
    Declaração das funções relativas à quarta opção do menu
    >> [4] Listar os doentes com tensões máximas acima de um determinado valor
*/

#ifndef FUNCSMENU4_H
#define FUNCSMENU4_H

void printTensoes(list_hipertensos_t *hipertensos, list_doentes_t *doentes, int tensao);
void loadTensoes(list_hipertensos_t *hipertensos, list_doentes_t *doentes, int tensao);

#endif