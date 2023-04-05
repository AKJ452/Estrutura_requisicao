#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"

typedef struct NO{
    Requisicao *requisicao;
    struct NO *prox;
}NO;

struct Estrutura_ {
    NO *ini;
    NO *fim;
    int size;
};

Estrutura *create(){
    Estrutura *estrutura = (Estrutura *) malloc(sizeof(Estrutura));
    if(estrutura != NULL){
        estrutura->ini = NULL;
        estrutura->fim = NULL;
        estrutura->size = 0;
    }
    return estrutura;
}

void inserir(Estrutura *estrutura, Requisicao *requisicao){
    NO *ptr = (NO*) malloc(sizeof(NO));
    if(ptr == NULL){
        printf("Erro alocação do nó.\n");
        return;
    } else {
        ptr->requisicao = requisicao;
        ptr->prox = NULL;
        if(estrutura->ini == NULL){
            estrutura->ini = ptr;
        } else {
            estrutura->fim->prox = ptr;
        }
        estrutura->fim = ptr;
    }
    estrutura->size++;

}

Requisicao *remover(Estrutura *estrutura){
    if(estrutura->ini == NULL) return 0;
    Requisicao *requisicao = estrutura->ini->requisicao;
    NO *removido = estrutura->ini;
    estrutura->ini = estrutura->ini->prox;
    estrutura->size--;
    free(removido);
    return requisicao;
}

int get_size(Estrutura *estrutura) {
    return estrutura->size;
}

