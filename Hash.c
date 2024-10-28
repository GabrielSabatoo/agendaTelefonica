#include "Hash.h"

void new_hash(TabelaHash *th){
  for(int i=0; i<MAX; i++)
    startLD(&th->tabela[i]);
}

void print_tabela_hash(TabelaHash *th){

  for(int i=0; i<MAX; i++){
    printf("%i\t", i);
    printListaD(&th->tabela[i]);
  }
}

int hash(int chave){
  return chave%MAX;
}

void add_hash(TabelaHash *th, contato dado){

  int pos = hash(dado.telefone);
  addEnd(&th->tabela[pos], dado);
}

contato pesquisa_hash(TabelaHash *th, int telefone){

  int pos = hash(telefone);

  return pesquisa_lista(&th->tabela[pos], telefone);

}

