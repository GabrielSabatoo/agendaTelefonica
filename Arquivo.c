#include "arquivo.h"

void writeArq(LIST *l){
    FILE *file;
    file = fopen(NomeArq, "w");

    if(!file){
        printf("Nao foi possivel criar o aquivo txt");
        return;
    }

    while(!empty(l)){
        contato c = removeBeg(l);
        fprintf(file, "%d ", c.codigo);
        fprintf(file, "%s ", c.nome);
        fprintf(file, "%d/%d/%d ", c.data.dia, c.data.mes, c.data.ano);
        fprintf(file, "%d ", c.telefone);
        fprintf(file, "%s\n", c.email);
    }

    fclose(file);
}

void readArq(LIST *l, ArvBin *av, AVL *avl, TabelaHash *th){
    FILE *file;
    file = fopen(NomeArq, "r");

    if(file == NULL){
        printf("Nao foi possivel achar o aquivo txt");
        return;
    }

    int nL = line_acc();

    for(int i = 0;i < nL; i++){
        contato c;
        fscanf(file, "%d\n", &c.codigo);
        fscanf(file, "%s\n", c.nome);
        fscanf(file, "%d/%d/%d\n", &c.data.dia, &c.data.mes, &c.data.ano);
        fscanf(file, "%d\n", &c.telefone);
        fscanf(file, "%s\n", c.email);
        insertEndList(l, c);
        inserir(av, c);
        inserirAVL(c, avl);
        add_hash(th, c);
    }

    fclose(file);
}

int line_acc(){
    FILE *file;
    file = fopen(NomeArq, "r");

    int n = 0;
    char c;

    while((c = getc(file)) != EOF){
        if(c == '\n')
            ++n;
    }

    fclose(file);
    return n;
}

