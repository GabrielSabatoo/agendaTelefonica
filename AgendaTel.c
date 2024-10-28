#include "AgendaTel.h"
#include "listaEstatica.h"

void printContato(contato c){
    printf("Codigo: %d\n", c.codigo);
    printf("Nome: %s\n", c.nome);
    printf("Data de nascimento: %d/%d/%d\n", c.data.dia, c.data.mes, c.data.ano);
    printf("Telefone: %d\n", c.telefone);
    printf("E-mail: %s\n", c.email);
    printf("\n");
}

int cmpData(nascimento data, nascimento data2){
    if(data.ano == data2.ano && data.dia == data2.dia && data.mes == data2.mes)
        return 0;
    if(data2.ano > data.ano)
        return 1;
    else if(data2.mes > data.mes)
        return 1;
    else if(data2.dia > data.dia)
        return 1;
    return -1;
}

