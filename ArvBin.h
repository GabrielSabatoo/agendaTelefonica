#ifndef ArvBin_H
#define ArvBin_H
#include "AgendaTel.h"
#include "listaDinamica.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct No {
    contato elemento;
	struct No *esq, *dir;
} No;

No* novoNo(contato elemento);

typedef struct ArvBin {
    No *raiz;
} ArvBin;

void create_arvbin(ArvBin *arv);

contato pesquisarRec(contato x, No* i);

contato pesquisar(ArvBin *arv, contato x);

void caminharCentralRec(No* i);

void caminharCentral(ArvBin *arv);

void caminharPreRec(No* i);

void caminharPre(ArvBin *arv);

void caminharPosRec(No* i);

void caminharPos(ArvBin *arv);

void inserirRec(contato x, No** i);

void inserir(ArvBin *arv, contato x);

void antecessor(No** i, No** j);

contato removerRec(contato x, No** i);

contato remover(ArvBin *arv, contato x);

int alturaRec(No* i);

int altura(ArvBin *arv);

bool pesquisarNomeRec(char *name, char *newName, No* i);

bool pesquisarNome(ArvBin *arv, char *name, char *newName);

nascimento pesquisarDataRec(contato x, No* i, nascimento newData);

nascimento pesquisarData(ArvBin *arv, contato x, nascimento newData);

int pesquisarTelRec(contato x, No* i, int newTel);

int pesquisarTel(ArvBin *arv, contato x, int newTel);

bool pesquisarEmailRec(char *email, char *newEmail, No* i);

bool pesquisarEmail(ArvBin *arv, char *email, char *newEmail);

#endif
