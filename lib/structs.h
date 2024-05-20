/*
    Estruturas
*/

#ifndef STRUCTS_H
#define STRUCTS_H

// Estrutura das datas
typedef struct {
	int dia, mes, ano;
} struct_data;

// Estrutura de um node da lista do registos
typedef struct l_noRegistos {
	int id;
	struct_data data_registo;
	int tensaoMax;
    int tensaoMin;
    int peso;
    int altura;
	struct l_noRegistos *next;
} l_noRegistos_t;

// Estrutura da lista dos registos
typedef struct list_registos {
	size_t num_elems;
	l_noRegistos_t *front;
} list_registos_t;

// Estrutura de um node da lista dos doentes
typedef struct l_noDoentes {
	int id;
	char nome[50];
	struct_data data_de_nascimento;
	char num_cc[50];
	char contacto[50];
	char email[50];
	list_registos_t registos;
	struct l_noDoentes *next;
} l_noDoentes_t;

// Estrutura da lista dos doentes
typedef struct list_doentes_t {
	size_t num_elems;
	l_noDoentes_t *front;
} list_doentes_t;

// Estrutura de um node da lista dos doentes por ordem alfabética
typedef struct l_noDoentesOA {
	l_noDoentes_t *ref;
	struct l_noDoentesOA *next;
} l_noDoentesOA_t;

// Estrutura da lista dos doentes por ordem alfabética
typedef struct list_doentesOA_t{
	size_t num_elems;
	l_noDoentesOA_t *front;
} list_doentesOA_t;

// Estrutura de um node da lista dos doentes ordenada com base num valor de tensão
typedef struct l_noHipertensos {
	l_noRegistos_t *ref;
	struct l_noHipertensos *next;
} l_noHipertensos_t;

// Estrutura da lista dos doentes ordenada com base num valor de tensão
typedef struct list_Hipertensos_t {
	size_t num_elems;
	l_noHipertensos_t *front;
} list_hipertensos_t;

#endif