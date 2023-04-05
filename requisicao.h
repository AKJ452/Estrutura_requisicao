typedef struct Requisicao_ Requisicao;

Requisicao *cria_requisicao();

int set_nome(Requisicao *requisicao, char nome[]);

char* get_nome(Requisicao *requisicao);

int set_inscricao(Requisicao *requisicao, int inscricao);

int get_inscricao(Requisicao *requisicao);

int set_procedimento(Requisicao *requisicao, char procedimento[]);

char* get_procedimento(Requisicao *requisicao);

void libera(Requisicao *requisicao);