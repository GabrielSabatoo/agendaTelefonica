#include "listaEstatica.h"
#include "AgendaTel.h"
#include "insertion.h"
#include "pesquisa.h"
#include "arquivo.h"
#include "ArvBin.h"
#include "AVL.h"
#include "Hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(void){

    int func,funcaltera,n = 100, pos;
    contato c;
    LIST l;
    ArvBin arv;
    AVL avl;
    TabelaHash th;

    new_hash(&th);
    create_arvbin(&arv);
    create_AVL(&avl);
    startL(&l, n);

    readArq(&l, &arv, &avl, &th);
    do{
        printf(" Agenda de contatos \n");
        printf("1 - Inserir novo contato\n");
        printf("2 - Remover contato\n");
        printf("3 - Alterar dados de um contato\n");
        printf("4 - Imprimir os contatos ordenados por nome\n");
        printf("5 - Imprimir os contatos ordenados por ordem de nascimento\n");
        printf("6 - Pesquisar contato por codigo\n");
        printf("7 - Pesquisar contato por nome\n");
        printf("8 - Pesquisar contato por data de nascimento\n");
        printf("9 - Pesquisar contato por e-mail\n");
        printf("10 - Pesquisar contato por telefone\n");
        printf("11 - Mostar lista de contatos nao ordenadas\n");
        printf("0 - Sair\n");
        scanf("%d", &func);
        switch (func)
        {
        case 1:
            printf("Insira o codigo: \n");
            scanf("%d", &c.codigo);
            fflush(stdin);
            printf("Insira o nome: \n");
            fgets(c.nome, 50, stdin);
            c.nome[strlen(c.nome)-1] = '\0';
            printf("Insira a data de nascimento no seguinte formato: dd/mm/aa: \n");
            scanf("%d %d %d", &c.data.dia, &c.data.mes, &c.data.ano);
            fflush(stdin);
            printf("Insira o numero de telefone: ");
            scanf("%d", &c.telefone);
            fflush(stdin);
            printf("Insira o e-mail: ");
            fgets(c.email, 50, stdin);
            c.email[strlen(c.email)-1] = '\0';
            insertEndList(&l, c);
            inserir(&arv, c);
            inserirAVL(c, &avl);
            add_hash(&th, c);
        break;
        case 2:{
            contato rem;
            printf("Insira qual codigo será removido ");
            scanf("%d", &rem.codigo);

            int lRem = pesquisaSequencialRemover(&l, n, rem.codigo);
            removePosList(&l, lRem);
            remover(&arv, rem);
            removerAVL(&avl, rem);

            printf("Removido com sucesso!\n");
        }
        break;
        case 3:{
            printf("===> Alterar contatos <===\n");
    printf("1 - Alterar codigo\n");
    printf("2 - Alterar nome\n");
    printf("3 - Alterar data de nascimento\n");
    printf("4 - Alterar telefone\n");
    printf("5 - Alterar e-mail\n");
    scanf("%d", &funcaltera);
            getchar();
            switch (funcaltera){
            case 1:{
                int cod;
                contato rem, extrair, extrairAVL;
                printf("Qual codigo deseja alterar?\n");
                scanf("%d", &cod);
                rem.codigo = cod;
                extrair = remover(&arv, rem);
                extrairAVL = removerAVL(&avl, rem);
                int newCod;
                printf("Insira o novo código\n");
                scanf("%d", &newCod);

                extrair.codigo = newCod;
                extrairAVL.codigo = newCod;
                alteraCod(&l, cod, newCod);
                inserir(&arv, extrair);
                inserirAVL(extrairAVL, &avl);
            }
            break;
            case 2:{
                char newName[50], name[50];

                printf("Insira o nome que será alterado.\n");
                fgets(name, 50, stdin);
                name[strlen(name)-1] = '\0';

                printf("Insira o novo nome.\n");
                fgets(newName, 50, stdin);
                newName[strlen(newName)-1] = '\0';

                alteraNome(&l, name, newName);
                pesquisarNome(&arv, name, newName);
                pesquisarNomeAVL(&avl, name, newName);
            }
            break;
            case 3:{
                nascimento newData;

                printf("Digite o código da data de nascimento a ser alterada. \n");
                scanf("%d", &c.codigo);

                printf("Insira a nova data de nascimento no seguinte formato: dd/mm/aa");
                scanf("%d %d %d", &newData.dia, &newData.mes, &newData.ano);

                alteraDataN(&l, c, newData);
                pesquisarData(&arv, c, newData);
                pesquisarDataAVL(&avl, c, newData);
            }
            break;
            case 4:{
                int newTel;

                printf("Insira o codigo do numero de telefone a ser alterado.\n");
                scanf("%d", &c.codigo);

                printf("Insira o novo numero de telefone.\n");
                scanf("%d", &newTel);

                alteraTel(&l, c, newTel);
                pesquisarTel(&arv, c, newTel);
                pesquisarTelAVL(&avl, c, newTel);
            }
            break;
            case 5:{
                char newEmail[50], email[50];

                printf("Insira o e mail a ser alterado\n");
                fgets(email, 50, stdin);
                email[strlen(email)-1] = '\0';

                printf("Digite o novo email\n");
                fgets(newEmail, 50, stdin);
                newEmail[strlen(newEmail)-1] = '\0';

                alteraEmail(&l, email, newEmail);
                pesquisarEmail(&arv, email, newEmail);
                pesquisarEmailAVL(&avl, email, newEmail);
            }
            break;
            default: printf("Opcao invalida");
                break;
            }
        }
        break;
        case 4:
            insercaoNome(&l, tam(&l));
            printLista(&l);
        break;
        case 5:
            bubble(&l, tam(&l));
            printLista(&l);
        break;
        case 6:{
            contato a;
            printf("Insira o codigo a ser procurado\n");
            scanf("%d", &a.codigo);
            a = pesquisar(&arv, a);
            if(c.codigo == -1){
                printf("Contato nao encontrado %d\n", a.codigo);
            }
            else{
                printf("Contato encontrado: \n");
                printContato(a);
            }
        }
        break;
        case 7:{
            contato a;
            printf("Insira o nome do usuario\n");
            fflush(stdin);
            fgets(c.nome, 50, stdin);
            a.nome[strlen(c.nome)-1] = '\0';

            a = pesquisaBinariaNome(&l, tam(&l), a);

            if(a.codigo == -1){
                printf("Contato nao encontrado %s\n", a.nome);
            }
            else{
                printf("Contato encontrado:\n");
                printContato(a);
            }
        }
        break;
        case 8:{
            contato a;
            printf("Qual a data de nascimento deseja procurar?\n");
            scanf("%d %d %d", &a.data.dia, &a.data.mes, &a.data.ano);
            a = pesquisaSequencial(&l, tam(&l), a.data);
            if(a.codigo == -1){
                printf("Usuario nao encontrado.\n");
            }
            else{
                printf("Usuario encontrado:\n");
                printContato(a);
            }
        }
        break;
        case 9:{
            contato a;
            printf("Qual email deseja procurar?\n");
            scanf("%s", c.email);

            a = pesquisarAVL(&a, &avl);

            if(a.codigo == -1){
                printf("Contato nao encontrado %s\n", a.email);
            }
            else{
                printf("Contato encontrado:\n");
                printContato(a);
            }
        }
        break;
        case 10:{
            contato a;
            printf("Insira o telefone a ser procurado\n");
            scanf("%d", &a.telefone);

            a = pesquisa_hash(&th, a.telefone);

            if(c.telefone == -1){
                printf("Contato nao encontrado %d\n", a.telefone);
            }
            else{
                printf("Usuario encontrado:\n");
                printContato(a);
            }
        }
        break;
        case 11:
            printLista(&l);
        break;
        default: printf("Opcao invalida, tenta novamente!");
            break;
        case 0:
            printf("Fechando o programa!");
        break;
        }
    }while(func != 0);
    writeArq(&l);
    freeList(&l);
    return 0;
}
