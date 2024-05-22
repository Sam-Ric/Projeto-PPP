/*
    Declaração das estruturas e das funções da lista ordenada por tensõe crescentes
*/

#ifndef LISTAHIPERTENSOS_H
#define LISTAHIPERTENSOS_H

void initListaDoentesH(list_hipertensos_t *list); // Função que inicializa a lista
void clearListaDoentesH(list_hipertensos_t *list); // Função que elimina todos os elementos da lista
void insertListaDoentesH(list_hipertensos_t *list, l_noRegistos_t *registo); // Função que insere um elemento na lista
void searchListaDoentesH(list_hipertensos_t *list, int tensao, l_noHipertensos_t **prev, l_noHipertensos_t **cur);

#endif