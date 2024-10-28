#include "AVL.h"
//=============================================================================
NoAVL* newNo(contato elemento){
   NoAVL* novo = (NoAVL*) malloc(sizeof(NoAVL));
   novo->elemento = elemento;
   novo->esq = NULL;
   novo->dir = NULL;
   novo->nivel = 1;
   return novo;
}
//=============================================================================
void create_AVL(AVL *avl){
   avl->raiz = NULL;
}
//=============================================================================
int max(int i,int j){
    if (i > j)
       return i;
    else
      return j;
}
//=============================================================================
NoAVL* setNivel(NoAVL* no){
   no->nivel = 1 + max(getNivel(no->esq),getNivel(no->dir));
   return no;
}
//=============================================================================
int getNivel(NoAVL* no){
   return (no == NULL) ? 0 : no->nivel;
}
//=============================================================================
//Mudar como inserir na avl, isso faz com que vc mude o parametro de pesquisa
contato pesquisarAVLRec(contato *x, NoAVL* i){
    contato resp;
    if (i == NULL) {
       resp.codigo = -1;
    }
    else if (strcmp(x->email,i->elemento.email) == 0){
        resp = i->elemento;
    }
    else if (strcmp(x->email, i->elemento.email) > 0){
        return pesquisarAVLRec(x, i->dir);
    }
    else{
        return pesquisarAVLRec(x, i->esq);
    }
    return resp;
}
//=============================================================================
contato pesquisarAVL(contato *x, AVL* a){
    return pesquisarAVLRec(x, a->raiz);
}
//=============================================================================
NoAVL* inserirAVLRec(NoAVL* i, contato x){
    if (i == NULL){
        i = newNo(x);
    }
    else if (strcmp(x.email, i->elemento.email) < 0){
        i->esq = inserirAVLRec((i->esq), x);
    }
    else if (strcmp(x.email, i->elemento.email) > 0){
        i->dir = inserirAVLRec((i->dir), x);
    }
    else {
        printf("Erro ao inserir elemento!\n");
    }

    return balancear(i);
}
//=============================================================================
void inserirAVL(contato x, AVL* a){
    a->raiz = inserirAVLRec(a->raiz, x);
}
//=============================================================================
void antecessorAVL(NoAVL** i, NoAVL** j){
   if ((*j)->dir != NULL) {
      antecessorAVL(i, &((*j)->dir));

   } else {
      NoAVL* del = *j;
      (*i)->elemento = (*j)->elemento;
      (*j) = (*j)->esq;
      free(del);
   }
}
//=============================================================================
contato removerAVLRec(contato x, NoAVL** i){
   contato c;
   if (*i == NULL) {
      printf("Erro ao remover!");

   } else if (x.codigo < (*i)->elemento.codigo) {
      return removerAVLRec(x, &((*i)->esq));

   } else if (x.codigo > (*i)->elemento.codigo) {
      return removerAVLRec(x, &((*i)->dir));

   } else if ((*i)->dir == NULL) {
      c = (*i)->elemento;
      NoAVL* del = *i;
      *i = (*i)->esq;
      free(del);

   } else if ((*i)->esq == NULL) {
      c = (*i)->elemento;
      NoAVL* del = *i;
      *i = (*i)->dir;
      free(del);

   } else {
      antecessorAVL(i, &((*i)->esq));
   }
   return c;
}
//=============================================================================
contato removerAVL(AVL *avl, contato x){
   return removerAVLRec(x, &avl->raiz);
}
//=============================================================================
NoAVL* balancear(NoAVL* i){
    if(i != NULL){
    int fator = getNivel(i->dir) - getNivel(i->esq);
         //Se balanceada
    if (abs(fator) <= 1){
       i = setNivel(i);
    //Se desbalanceada para a direita
    }else if (fator == 2){
        int fatorFilhoDir = getNivel(i->dir->dir) - getNivel(i->dir->esq);
        //Se o filho a direita tambem estiver desbalanceado
        if (fatorFilhoDir == -1) {
            i->dir = rotacionarDir(i->dir);
        }
        i = rotacionarEsq(i);
        //Se desbalanceada para a esquerda
        }else if (fator == -2){
            int fatorFilhoEsq = getNivel(i->esq->dir) - getNivel(i->esq->esq);
            //Se o filho a esquerda tambem estiver desbalanceado
            if (fatorFilhoEsq == 1) {
               i->esq = rotacionarEsq(i->esq);
            }
            i = rotacionarDir(i);
         }else{
            printf("Erro fator de balanceamento, fator invalido!\n");
         }
      }
    return i;
}
//=============================================================================
void caminharAVLPosRec(NoAVL* i){
   if (i != NULL) {
      caminharAVLPosRec(i->esq);
      caminharAVLPosRec(i->dir);
      printf("%d ", i->elemento.codigo);
   }
}
//=============================================================================
void caminharAVLPos(AVL *a){
   printf("[ ");
   caminharAVLPosRec(a->raiz);
   printf("]\n");
}
//=============================================================================
void caminharCentralAVLRec(NoAVL* i){
   if (i != NULL) {
      caminharCentralAVLRec(i->esq);
      printf("%d ", i->elemento.codigo);
      caminharCentralAVLRec(i->dir);
   }
}
//=============================================================================
void caminharCentralAVL(AVL *a){
   printf("[ ");
   caminharCentralAVLRec(a->raiz);
   printf("]\n");
}
//=============================================================================
NoAVL* rotacionarDir(NoAVL* no){
    NoAVL* noEsq = no->esq;
    NoAVL* noEsqDir = noEsq->dir;
    noEsq->dir = no;
    no->esq = noEsqDir;
    no = setNivel(no);
    noEsq = setNivel(noEsq);
    return noEsq;
}
//=============================================================================
NoAVL* rotacionarEsq(NoAVL* no){
    NoAVL* noDir = no->dir;
    NoAVL* noDirEsq = noDir->esq;
    noDir->esq = no;
    no->dir = noDirEsq;
    no = setNivel(no);
    noDir = setNivel(noDir);
    return noDir;
}
//=============================================================================
bool pesquisarNomeAVLRec(char *name, char *newName, NoAVL* i){
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
      resp = pesquisarNomeAVLRec(name, newName, i->esq);
   }
   else{
      resp = pesquisarNomeAVLRec(name, newName, i->dir);
   }
   return resp;
}
//=============================================================================
bool pesquisarNomeAVL(AVL *arv, char *name, char *newName){
   return pesquisarNomeAVLRec(name, newName, arv->raiz);
}
//=============================================================================
nascimento pesquisarDataAVLRec(contato x, NoAVL* i, nascimento newData){
   nascimento resp;
   if (i == NULL){
      resp.dia = -1;
   }
   else if (x.codigo == i->elemento.codigo){
      resp = newData;
   }
   else if (x.codigo == i->elemento.codigo < 0){
      resp = pesquisarDataAVLRec(x, i->esq, newData);
   }
   else{
      resp = pesquisarDataAVLRec(x, i->dir, newData);
   }
   return resp;
}
//=============================================================================
nascimento pesquisarDataAVL(AVL *arv, contato x, nascimento newData){
   return pesquisarDataAVLRec(x, arv->raiz, newData);
}
//=============================================================================
int pesquisarTelAVLRec(contato x, NoAVL* i, int newTel){
   int resp;
   if (i == NULL){
      resp = -1;
   }
   else if (x.codigo == i->elemento.codigo){
      resp = newTel;
   }
   else if (x.codigo == i->elemento.codigo < 0){
      resp = pesquisarTelAVLRec(x, i->esq, newTel);
   }
   else{
      resp = pesquisarTelAVLRec(x, i->dir, newTel);
   }
   return resp;
}

int pesquisarTelAVL(AVL *arv, contato x, int newTel){
   return pesquisarTelAVLRec(x, arv->raiz, newTel);
}

bool pesquisarEmailAVLRec(char *email, char *newEmail, NoAVL* i){
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
      resp = pesquisarEmailAVLRec(email, newEmail, i->esq);
   }
   else{
      resp = pesquisarEmailAVLRec(email, newEmail, i->dir);
   }
   return resp;
}

bool pesquisarEmailAVL(AVL *arv, char *email, char *newEmail){
   return pesquisarEmailAVLRec(email, newEmail, arv->raiz);
}

