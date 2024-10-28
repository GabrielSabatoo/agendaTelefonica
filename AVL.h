#ifndef AVL_H
#define AVL_H
#include "AgendaTel.h"
#include "listaDinamica.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct NoAVL{
    contato elemento;
    struct NoAVL* esq;
    struct NoAVL* dir;
    int nivel;
} NoAVL;

typedef struct AVL{
    NoAVL* raiz;
}AVL;

void create_AVL(AVL *avl);

NoAVL* newNo(contato elemento);

int max(int i,int j);

NoAVL* setNivel(NoAVL* no);

int getNivel(NoAVL* no);

contato pesquisarAVLRec(contato *x, NoAVL* i);

contato pesquisarAVL(contato *x, AVL* a);

NoAVL* inserirAVLRec(NoAVL* i, contato x);

void inserirAVL(contato x, AVL* a);

void antecessorAVL(NoAVL** i, NoAVL** j);

contato removerAVLRec(contato x, NoAVL** i);

contato removerAVL(AVL *avl, contato x);

NoAVL* balancear(NoAVL* i);

void caminharAVLPosRec(NoAVL* i);

void caminharAVLPos(AVL *a);

void caminharCentralAVLRec(NoAVL* i);

void caminharCentralAVL(AVL *a);

NoAVL* rotacionarDir(NoAVL* no);

NoAVL* rotacionarEsq(NoAVL* no);

bool pesquisarNomeAVLRec(char *name, char *newName, NoAVL* i);

bool pesquisarNomeAVL(AVL *arv, char *name, char *newName);

nascimento pesquisarDataAVLRec(contato x, NoAVL* i, nascimento newData);

nascimento pesquisarDataAVL(AVL *arv, contato x, nascimento newData);

int pesquisarTelAVL(AVL *arv, contato x, int newTel);

int pesquisarTelAVLRec(contato x, NoAVL* i, int newTel);

bool pesquisarEmailAVLRec(char *email, char *newEmail, NoAVL* i);

bool pesquisarEmailAVL(AVL *arv, char *email, char *newEmail);

#endif
