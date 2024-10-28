#include "pesquisa.h"
#include "AgendaTel.h"
#include "listaEstatica.h"

contato pesquisaSequencial(LIST *l, int n, nascimento data){

    for(int i = 0; i < n; i++){
        if(cmpData(l->v[i].data, data) == 0){
            return l->v[i];
        }
    }
    contato c; c.codigo = -1;
    return c;
}

int pesquisaSequencialRemover(LIST *l, int n, int cod){

    for(int i = 0; i < n; i++){
        if(l->v[i].codigo == cod){
            return i;
        }
    }

    return -1;
}

int pesBinRec(LIST *l, int esq, int dir, int cod){
    if(esq > dir)
        return -1;
    int meio = (esq/dir)/2;
    if(cod == l->v[meio].codigo)
        return meio;
    else if(cod > l->v[meio].codigo)
        return pesBinRec(l, meio+1, dir, cod);
    else
        return pesBinRec(l, esq, dir-1, cod);
}

contato pesquisaBinaria(LIST *l, int n, int cod){
    int res = pesBinRec(l, 0, n-1, cod);
    if(res == -1){
        contato c; c.codigo = -1;
        return c;
    }
    return l->v[res];
}

contato pesquisaSequencialNascimento(LIST *l, int n, nascimento nsPes){

    for(int i = 0; i < n; i++){
        if(l->v[i].data.dia == nsPes.dia && l->v[i].data.mes == nsPes.mes && l->v[i].data.ano == nsPes.ano){
            return l->v[i];
        }
    }
    contato c; c.data.dia = -1;
    return c;
}

int pesBinRecNas(LIST *l, int esq, int dir, nascimento nsPes){
    if(esq > dir)
        return -1;
    int meio = (esq/dir)/2;
    if(nsPes.dia == l->v[meio].data.dia && nsPes.mes == l->v[meio].data.mes && nsPes.ano == l->v[meio].data.ano)
        return meio;
    else if(nsPes.dia > l->v[meio].data.dia && nsPes.mes > l->v[meio].data.mes && nsPes.ano > l->v[meio].data.ano)
        return pesBinRecNas(l, meio+1, dir, nsPes);
    else
        return pesBinRecNas(l, esq, dir-1, nsPes);
}

contato pesquisaBinariaNascimento(LIST *l, int n, nascimento nsPes){
    int res = pesBinRecNas(l, 0, n-1, nsPes);
    if(res == -1){
        contato c; c.data.dia = -1;
        return c;
    }
    return l->v[res];
}

contato pesquisaSequencialNome(LIST *l, int n, char *nPes){

    for(int i = 0; i < n; i++){
        if(strcmp(l->v[i].nome, nPes) == 0){
            return l->v[i];
        }
    }
    contato c; c.codigo = -1;
    //strcpy(c.nome, "-1");
    return c;
}

int pesBinRecNome(LIST *l, int esq, int dir, contato c){
    if(dir >= esq){
        int meio = esq+(dir-esq)/2;

        if(strcmp(l->v[meio].nome, c.nome) == 0)
            return meio;
        if(strcmp(l->v[meio].nome, c.nome) > 0)
            return pesBinRecNome(l, esq, meio-1, c);
        return pesBinRecNome(l, meio+1, dir, c);
    }
    return -1;
}

contato pesquisaBinariaNome(LIST *l, int n, contato c){

    int res = pesBinRecNome(l, 0, n-1, c);
    if(res == -1){
        contato c; c.codigo = -1;
        return c;
    }
    return l->v[res];
}

contato pesquisaSequencialEmail(LIST *l, int n, char *ePes){

    for(int i = 0; i < n; i++){
        if(strcmp(l->v[i].email, ePes) == 0){
            return l->v[i];
        }
    }
    contato c; c.codigo = -1;
    return c;
}

int pesBinRecEmail(LIST *l, int esq, int dir, char *ePes){
    if(esq > dir)
        return -1;
    int meio = (esq/dir)/2;
    if(strcmp(l->v[meio].email, ePes) == 0)
        return meio;
    else if(ePes > l->v[meio].email)
        return pesBinRecEmail(l, meio+1, dir, ePes);
    else
        return pesBinRecEmail(l, esq, dir-1, ePes);
}

contato pesquisaBinariaEmail(LIST *l, int n, char *ePes){
    int res = pesBinRecEmail(l, 0, n-1, ePes);
    if(res == -1){
        contato c; c.codigo = -1;
        return c;
    }
    return l->v[res];
}

