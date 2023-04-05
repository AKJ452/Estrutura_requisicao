#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "requisicao.h"

struct Requisicao_ {
    char nome[41];
    int inscricao;
    char procedimento[11];
};

struct Requisicao_ *cria_requisicao(char *nome, int inscricao, char *procedimento) {
    struct Requisicao_ *c = (struct Requisicao_ *) calloc(1, sizeof(struct Requisicao_));
    if(c != NULL){
        strcpy(c->nome, nome);
        c->inscricao = inscricao;
        strcpy(c->procedimento, procedimento);
    }
    return c;
}

int set_nome(struct Requisicao_ *requisicao, char nome[]) {
    int i;
    for(i = 0; i < 40 && i < strlen(nome); i++) {
        requisicao->nome[i] = nome[i];
    }
    requisicao->nome[i] = '\0';
    if(strlen(nome) > 40) return 1;
    return 0;
}

char* get_nome(struct Requisicao_ *requisicao) {
    return requisicao->nome;
}

int set_inscricao(struct Requisicao_ *requisicao, int inscricao){
    requisicao->inscricao = inscricao;
}

int get_inscricao(struct Requisicao_ *requisicao){
    return requisicao->inscricao;
}

int set_procedimento(struct Requisicao_ *requisicao, char procedimento[]) {
    if(strlen(procedimento) > 10) return 2;
    int i;
    for(i = 0; i < strlen(procedimento); i++) requisicao->procedimento[i] = procedimento[i];
    requisicao->procedimento[i] = '\0';
    return 0;
}

char* get_procedimento(struct Requisicao_ *requisicao) {
    return requisicao->procedimento;
}

void libera(struct Requisicao_ *requisicao){
    free(requisicao);
}