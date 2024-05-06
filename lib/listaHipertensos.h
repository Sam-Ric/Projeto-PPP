/*
    Declaração das estruturas e das funções da lista ordenada por tensõe crescentes
*/

#ifndef LISTAHIPERTENSOS_H
#define LISTAHIPERTENSOS_H
#include "../lib/listaDoentesOA.h"
#include "../lib/listaDoentes.h"

typedef struct l_noHipertensos { // Estrutura de um node da lista dos doentes
	l_noDoentes_t *ref;
	struct l_noHipertensos *next;
} l_noHipertensos_t;

typedef struct list_Hipertensos_t{ // Estrutura da lista
	size_t num_elems;
	l_noHipertensos_t *front;
} list_doentesOA_t;

#endif