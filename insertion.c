#include "insertion.h"
#include "listaEstatica.h"
#include "listaDinamica.h"

//Mudar os métodos de ordenação
void insercaoNome(LIST *l, int size){
    for (int i = 1; i < size; i++){
      contato tmp = l->v[i];
      int j = i - 1;

      while ((j >= 0) && strcmp(l->v[j].nome, tmp.nome) > 0){
         l->v[j + 1] = l->v[j];
         j--;
      }
      l->v[j+1] = tmp;
   }
}

void swap(contato *i, contato *j){
   contato tmp = *i;
   *i = *j;
   *j = tmp;
}

void bubble(LIST *l, int n){
    int i, j;
    contato tmp;
    for (i = (n - 1); i > 0; i--) {
      for (j = 0; j < i; j++) {

         if (l->v[i].data.ano < l->v[j].data.ano) {
            swap(&l->v[j], &l->v[j + 1]);
         }
         else if(l->v[i].data.ano == l->v[j].data.ano && l->v[i].data.mes < l->v[j].data.mes){
            swap(&l->v[j], &l->v[j + 1]);
         }
         else if(l->v[i].data.mes == l->v[j].data.mes && l->v[i].data.dia < l->v[j].data.dia){
            swap(&l->v[j], &l->v[j + 1]);
         }
      }
   }
}
