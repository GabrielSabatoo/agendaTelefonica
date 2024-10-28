#ifndef AGENDATEL_H
#define AGENDATEL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nascimento{
    int dia;
    int mes;
    int ano;
}nascimento;

typedef struct Contato{
    int telefone;
    int codigo;
    nascimento data;
    char nome[50];
    char email[50];
}contato;

void printContato(contato c);

int cmpData(nascimento data, nascimento data2);

#endif
