#include "requisicao.h"

typedef struct Estrutura_ Estrutura;

Estrutura *create();

void inserir(Estrutura *estrutura, Requisicao *requisicao);

Requisicao *remover(Estrutura *estrutura);

int get_size(Estrutura *estrutura);