/*
    Estruturas
*/

#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
	int dia, mes, ano;
} struct_data;

typedef struct l_noRegistos { // Estrutura de um node da lista do registos
	int id;
	struct_data data_registo;
	int tensaoMax;
    int tensaoMin;
    int peso;
    int altura;
	struct l_noRegistos *next;
} l_noRegistos_t;

typedef struct list_registos{ // Estrutura da lista
	size_t num_elems;
	l_noRegistos_t *front;
} list_registos_t;

typedef struct l_noDoentes { // Estrutura de um node da lista dos doentes
	int id;
	char nome[50];
	struct_data data_de_nascimento;
	char num_cc[50];
	char contacto[50];
	char email[50];
	list_registos_t registos;
	struct l_noDoentes *next;
} l_noDoentes_t;

typedef struct list_doentes_t{ // Estrutura da lista
	size_t num_elems;
	l_noDoentes_t *front;
} list_doentes_t;

typedef struct l_noDoentesOA { // Estrutura de um node da lista dos doentes
	l_noDoentes_t *ref;
	struct l_noDoentesOA *next;
} l_noDoentesOA_t;

typedef struct list_doentesOA_t{ // Estrutura da lista
	size_t num_elems;
	l_noDoentesOA_t *front;
} list_doentesOA_t;

typedef struct l_noHipertensos { // Estrutura de um node da lista dos doentes
	l_noDoentes_t *ref;
	struct l_noHipertensos *next;
} l_noHipertensos_t;

typedef struct list_Hipertensos_t { // Estrutura da lista
	size_t num_elems;
	l_noHipertensos_t *front;
} list_hipertensos_t;

#endif