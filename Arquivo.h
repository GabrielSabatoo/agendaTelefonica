#ifndef ARQUIVO_H
#define ARQUIVO_H
static char  NomeArq[] = "AgendaTel.txt";

#include "listaEstatica.h"
#include "AgendaTel.h"
#include "ArvBin.h"
#include "AVL.h"
#include "Hash.h"

#include <stdio.h>
#include <stdlib.h>

void writeArq(LIST *l);

void readArq(LIST *l, ArvBin *av, AVL *avl, TabelaHash *th);

int line_acc();

#endif
