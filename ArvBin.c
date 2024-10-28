#include "ArvBin.h"

No* novoNo(contato elemento) {
   No* novo = (No*) malloc(sizeof(No));
   novo->elemento = elemento;
   novo->esq = NULL;
   novo->dir = NULL;
   return novo;
}

void create_arvbin(ArvBin *arv){
   arv->raiz = NULL;
}

contato pesquisarRec(contato x, No* i){
   contato resp;
   if (i == NULL){
      resp.codigo = -1;
      return resp;
   }

   if (x.codigo == i->elemento.codigo){
      resp = i->elemento;
   }
   else if (x.codigo < i->elemento.codigo){
      resp = pesquisarRec(x, i->esq);
   }
   else{
      resp = pesquisarRec(x, i->dir);
   }
   return resp;
}

contato pesquisar(ArvBin *arv, contato x){
   return pesquisarRec(x, arv->raiz);
}

void caminharCentralRec(No* i){
   if (i != NULL) {
      caminharCentralRec(i->esq);
      printf("%d ", i->elemento.codigo);
      caminharCentralRec(i->dir);
   }
}

void caminharCentral(ArvBin *arv){
   printf("[ ");
   caminharCentralRec(arv->raiz);
   printf("]\n");
}

void caminharPreRec(No* i){
   if (i != NULL) {
      printf("%d ", i->elemento);
      caminharPreRec(i->esq);
      caminharPreRec(i->dir);
   }
}

void caminharPre(ArvBin *arv){
   printf("[ ");
   caminharPreRec(arv->raiz);
   printf("]\n");
}

void caminharPosRec(No* i){
   if (i != NULL) {
      caminharPosRec(i->esq);
      caminharPosRec(i->dir);
      printf("%d ", i->elemento);
   }
}

void caminharPos(ArvBin *arv){
   printf("[ ");
   caminharPosRec(arv->raiz);
   printf("]\n");
}

void inserirRec(contato x, No** i){
   if (*i == NULL) {
      *i = novoNo(x);

   } else if (x.codigo < (*i)->elemento.codigo){
      inserirRec(x, &((*i)->esq));

   } else if (x.codigo > (*i)->elemento.codigo){
      inserirRec(x, &((*i)->dir));

   } else{
      printf("Erro ao inserir!");
   }
}

void inserir(ArvBin *arv, contato x){
   inserirRec(x, &arv->raiz);
}

void antecessor(No** i, No** j){
   if ((*j)->dir != NULL) {
      antecessor(i, &((*j)->dir));

   } else {
      No* del = *j;
      (*i)->elemento = (*j)->elemento;
      (*j) = (*j)->esq;
      free(del);
   }
}

contato removerRec(contato x, No** i){
   contato c;
   if (*i == NULL) {
      printf("Erro ao remover!");

   } else if (x.codigo < (*i)->elemento.codigo) {
      return removerRec(x, &((*i)->esq));

   } else if (x.codigo > (*i)->elemento.codigo) {
      return removerRec(x, &((*i)->dir));

   } else if ((*i)->dir == NULL) {
      c = (*i)->elemento;
      No* del = *i;
      *i = (*i)->esq;
      free(del);

   } else if ((*i)->esq == NULL) {
      c = (*i)->elemento;
      No* del = *i;
      *i = (*i)->dir;
      free(del);

   } else {
      antecessor(i, &((*i)->esq));
   }
   return c;
}

contato remover(ArvBin *arv, contato x){
   return removerRec(x, &arv->raiz);
}

int alturaRec(No* i){
   if (i != NULL) {
      int a1 = 1 + alturaRec(i->esq);
      int a2 = 1 + alturaRec(i->dir);
      if(a1>a2) return a1;
      else return a2;
   }
   return 0;
}

int altura(ArvBin *arv){
   return alturaRec(arv->raiz)-1;
}

bool pesquisarNomeRec(char *name, char *newName, No* i){
   bool resp;
   if (i == NULL){
      resp = false;
   }

   else if (strcmp(i->elemento.nome, name) == 0){
      memset(i->elemento.nome, 0, strlen(i->elemento.nome));
      strncpy(i->elemento.nome, newName, strlen(newName));
      resp = true;
   }
   else if (strcmp(i->elemento.nome, name) < 0){
      resp = pesquisarNomeRec(name, newName, i->esq);
   }
   else{
      resp = pesquisarNomeRec(name, newName, i->dir);
   }
   return resp;
}

bool pesquisarNome(ArvBin *arv, char *name, char *newName){
   return pesquisarNomeRec(name, newName, arv->raiz);
}

nascimento pesquisarDataRec(contato x, No* i, nascimento newData){
   nascimento resp;
   if (i == NULL){
      resp.dia = -1;
   }
   else if (x.codigo == i->elemento.codigo){
      resp = newData;
   }
   else if (x.codigo == i->elemento.codigo < 0){
      resp = pesquisarDataRec(x, i->esq, newData);
   }
   else{
      resp = pesquisarDataRec(x, i->dir, newData);
   }
   return resp;
}

nascimento pesquisarData(ArvBin *arv, contato x, nascimento newData){
   return pesquisarDataRec(x, arv->raiz, newData);
}

int pesquisarTelRec(contato x, No* i, int newTel){
   int resp;
   if (i == NULL){
      resp = -1;
   }
   else if (x.codigo == i->elemento.codigo){
      resp = newTel;
   }
   else if (x.codigo == i->elemento.codigo < 0){
      resp = pesquisarTelRec(x, i->esq, newTel);
   }
   else{
      resp = pesquisarTelRec(x, i->dir, newTel);
   }
   return resp;
}

int pesquisarTel(ArvBin *arv, contato x, int newTel){
   return pesquisarTelRec(x, arv->raiz, newTel);
}

bool pesquisarEmailRec(char *email, char *newEmail, No* i){
   bool resp;
   if (i == NULL){
      resp = false;
   }

   else if (strcmp(i->elemento.email, email) == 0){
      memset(i->elemento.email, 0, strlen(i->elemento.email));
      strncpy(i->elemento.email, newEmail, strlen(newEmail));
      resp = true;
   }
   else if (strcmp(i->elemento.email, email) < 0){
      resp = pesquisarEmailRec(email, newEmail, i->esq);
   }
   else{
      resp = pesquisarEmailRec(email, newEmail, i->dir);
   }
   return resp;
}

bool pesquisarEmail(ArvBin *arv, char *email, char *newEmail){
   return pesquisarEmailRec(email, newEmail, arv->raiz);
}

