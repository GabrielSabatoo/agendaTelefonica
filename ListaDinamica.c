#include "AgendaTel.h"
#include "listaDinamica.h"

Celula *new_Celula(contato dado){
  Celula *tmp = (Celula*)malloc(sizeof(Celula));
  if(tmp == NULL) return NULL;
  tmp->dado = dado;
  tmp->prox = NULL;
  return tmp;
}

void startLD(Lista *l){
  Celula *tmp = malloc(sizeof(Celula));
  tmp->prox = NULL;
  l->inicio = l->fim = tmp;
  l->tam = 0;
}

void printListaD(Lista *l){
  Celula *tmp = l->inicio->prox;
  while(tmp != NULL){
    printContato(tmp->dado);
    tmp = tmp->prox;
  }
}

bool addEnd(Lista *l, contato dado){
  Celula *tmp = new_Celula(dado);
  if(tmp == NULL) return false;

  l->fim->prox = tmp;
  l->fim = tmp;
  l->tam++;
  return true;
}

bool vazia(Lista *l){
  return l->inicio == l->fim;
}

contato removeBeg(Lista *l){
  if(vazia(l)){
      contato p;
      p.codigo = -1;
      return p;
  }
  Celula *tmp = l->inicio;
  l->fim = l->fim->prox;
  contato res = tmp -> dado;
  free(tmp);
  return res;
}

void delLista(Lista *l){
    while (!NULL)
    {
        removeEndList(l);
    }
    free(l->inicio);
}

contato pesquisa_lista(Lista *l, int tel){

    Celula *tmp = l->inicio->prox;

    while(tmp != NULL){

      if(tmp->dado.telefone == tel)
        return tmp->dado;

      tmp = tmp->prox;
    }

    contato c;
    c.telefone = -1;
    return c;
}

