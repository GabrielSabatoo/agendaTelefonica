#ifndef listaDinamica_H
#define listaDinamica_H
#include "AgendaTel.h"
//=============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

typedef struct Celula{
  contato dado;
  struct Celula *prox;
}Celula;

Celula *new_Celula(contato dado);

typedef struct Lista{
  Celula *inicio, *fim;
  int tam;
}Lista;

void startLD(Lista *l);

void printListaD(Lista *l);

bool addEnd(Lista *l, contato dado);

bool vazia(Lista *l);

contato removeBeg(Lista *l);

void delLista(Lista *l);

void alteraCodD(Celula *tmp, int newCod);

contato pesquisa_lista(Lista *l, int tel);

#endif
