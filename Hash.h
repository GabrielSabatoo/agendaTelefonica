#ifndef HASH_H
#define HASH_H

#include "AgendaTel.h"
#include "listaDinamica.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct TabelaHash{
  Lista tabela[MAX];
}TabelaHash;

void new_hash(TabelaHash *th);

void print_tabela_hash(TabelaHash *th);

int hash(int chave);

void add_hash(TabelaHash *th, contato dado);

contato pesquisa_hash(TabelaHash *th, int telefone);

#endif
