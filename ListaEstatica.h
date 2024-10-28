#ifndef listaEstatica_H
#define listaEstatica_H
#include "AgendaTel.h"
//=============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
//=============================================================================
typedef struct LIST
{
    contato *v;
    int n;
    int max;
} LIST;

void startL(LIST *l, int N);

void freeList(LIST *l);

bool empty(LIST *l);

bool insertEndList(LIST *l, contato x);

contato removeEndList(LIST *l);

contato RemovePosList(LIST *l);

int tam(LIST *l);

void printLista(LIST *l);

void alteraCod(LIST *l, int codAnt, int newCod);

void alteraNome(LIST *l, char *name, char *newName);

void alteraDataN(LIST *l, contato x, nascimento newData);

void alteraEmail(LIST *l, char *name, char *newEmail);

void alteraTel(LIST *l, contato x, int newTel);

#endif
