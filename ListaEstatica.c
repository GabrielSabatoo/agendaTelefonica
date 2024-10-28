#include "AgendaTel.h"
#include "listaEstatica.h"

void startL(LIST *l, int N){
    l->max = N;
    l->v = (contato*)malloc(N * sizeof(contato));
    l->n = 0;
}

void freeList(LIST *l){
    free(l->v);
}

bool empty(LIST *l){
    return l->n == 0;
}

bool insertEndList(LIST *l, contato x)
{
    if (l->n == l->max)
        return false;
    l->v[l->n++] = x;
    return true;
}

contato removeEndList(LIST *l)
{
    if (empty(l)){
        contato c; c.codigo = -1;
        return c;
    }
    return l->v[--l->n];
}

contato removePosList(LIST *l,int pos)
{
    if (empty(l)){
        contato c; c.codigo = -1;
        return c;
    }
    return l->v[--l->n-pos];
}

int tam(LIST *l){
    return l->n;
}

void printLista(LIST *l){
    printf("\n");
    for (int i = 0; i < tam(l); i++){
        printf("Codigo: %d\n", l->v[i].codigo);
        printf("Nome: %s\n", l->v[i].nome);
        printf("Data de nascimento: %d/%d/%d\n", l->v[i].data.dia, l->v[i].data.mes, l->v[i].data.ano);
        printf("Telefone: %d\n", l->v[i].telefone);
        printf("E-mail: %s\n", l->v[i].email);
        printf("-------------------------------------\n");
        printf("\n");
    }
     printf("\n");
}

void alteraCod(LIST *l, int codAnt, int newCod){
    for(int i = 0; i < l->n; i++){

        if(l->v[i].codigo == codAnt)
            l->v[i].codigo = newCod;
    }
}
void alteraNome(LIST *l, char *name, char *newName){
    for(int i = 0; i < l->n; i++){
        if(strcmp(l->v[i].nome, name) == 0){
            memset(l->v[i].nome, 0, strlen(l->v[i].nome));
            strcpy(l->v[i].nome, newName);
        }
    }
}

void alteraDataN(LIST *l, contato x, nascimento newData){
    for(int i = 0; i < l->n; i++){
        if(x.codigo == l->v[i].codigo)
            l->v[i].data = newData;
    }
}

void alteraEmail(LIST *l, char *email, char *newEmail){
    for(int i = 0; i < l->n; i++){
        if(strcmp(l->v[i].email, email) == 0){

            memset(l->v[i].email, 0, strlen(l->v[i].email));
            strcpy(l->v[i].email, newEmail);
        }
    }
}

void alteraTel(LIST *l, contato x, int newTel){
    for(int i = 0; i < l->n; i++){
        if(x.codigo == l->v[i].codigo)
            l->v[i].telefone = newTel;
    }

}

