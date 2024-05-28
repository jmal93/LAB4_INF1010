#include <stdio.h>
#include <stdlib.h>

#define MAX 4
#define MIN 2
typedef struct no t_no;
struct no
{
	int ndesc;
	int chave[MAX]; /* não inclui overflow da chave*/
	t_no *ramo[MAX+1];
};

void intervalo(t_no *arv, int lim_inf, int lim_sup);
t_no* busca(t_no *arv, int chave);
t_no* criaNo(void);
t_no* insere(t_no* arv, int chave);

int main(void) {
	t_no* arvore = criaNo();
	busca(arvore, 5);
	return 0;
}

// cria um nó vazio
t_no* criaNo(void)
{
	t_no* novoNo = (t_no*) malloc(sizeof(t_no));
	novoNo->ndesc = 0;
	for (int i = 0; i < MAX + 1; i++)
		novoNo->ramo[i] = NULL;
	return novoNo;
}

// retorna a página na qual a chave foi encontrada, retorna nulo caso não ache
t_no* busca(t_no *arv, int chave)
{
	if (arv == NULL)
		return NULL;
	for (int i = 0; i < MAX; i++)
	{
		if (arv->chave[i] == chave)
			return arv;
	}

	int j = 0;
	if (chave < arv->chave[j])
		busca(arv->ramo[j], chave);
	for (j = 1; j < MAX; j++)
	{
		if (arv->chave[j] < chave && chave < arv->chave[j + 1])
			busca(arv->ramo[j], chave);
	}
	if (arv->chave[j] < chave)
		busca(arv->ramo[j], chave);

	return NULL;
}

t_no* insere(t_no* arv, int chave)
{
	
}
