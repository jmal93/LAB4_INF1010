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
	insere(arvore, 15);
	return 0;
}

// cria um nó vazio
t_no* criaNo(void)
{
	t_no* novoNo = (t_no*) malloc(sizeof(t_no));
	novoNo->ndesc = 3;
	for (int i = 0; i < MAX + 1; i++)
		novoNo->ramo[i] = NULL;
	for (int i = 0; i < 3; i++)
		novoNo->chave[i] = (i+1)*10;
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
	if (chave < arv->chave[j]) busca(arv->ramo[j], chave);
	for (j = 1; j < MAX; j++)
	{
		if (arv->chave[j] < chave && chave < arv->chave[j + 1])
			busca(arv->ramo[j], chave);
	}
	if (arv->chave[j] < chave) busca(arv->ramo[j], chave);

	return NULL;
}

void insereNaPos(t_no* arv, int chave)
{
	if (arv->chave[arv->ndesc-1] < chave)
	{
		arv->chave[arv->ndesc] = chave;
		arv->ndesc++;
		return;
	}
	
	int i;
	for (i = 0; i < arv->ndesc; i++)
	{
		if (arv->chave[i] > chave) break;
	}

	int j = arv->ndesc;
	while (j > i)
	{
		arv->chave[j] = arv->chave[j - 1];
		j--;
	}
	arv->chave[j] = chave;
	arv->ndesc++;
}

t_no* insere(t_no* arv, int chave)
{
	insereNaPos(arv, chave);
}
