#ifndef PESQUISA_H
#define PESQUISA_H
//=============================================================================
#include "AgendaTel.h"
#include "listaEstatica.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

contato pesquisaSequencial(LIST *l, int n, nascimento data);

int pesquisaSequencialRemover(LIST *l, int n, int cod);

int pesBinRec(LIST *l, int esq, int dir, int cod);

contato pesquisaBinaria(LIST *l, int n, int cod);

contato pesquisaSequencialNascimento(LIST *l, int n, nascimento nsPes);

int pesBinRecNas(LIST *l, int esq, int dir, nascimento nsPes);

contato pesquisaBinariaNascimento(LIST *l, int n, nascimento nsPes);

contato pesquisaSequencialNome(LIST *l, int n, char *nPes);

int pesBinRecNome(LIST *l, int esq, int dir, contato c);

contato pesquisaBinariaNome(LIST *l, int n, contato c);

contato pesquisaSequencialEmail(LIST *l, int n, char *ePes);

int pesBinRecEmail(LIST *l, int esq, int dir, char *ePes);

contato pesquisaBinariaEmail(LIST *l, int n, char *ePes);

#endif
