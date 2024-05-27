#include <stdio.h>
#include <stdlib.h>

#define MAX 4
#define MIN 2
typedef struct no t_no;
struct no
{
	int ndesc;
	int chave[MAX]; /* não inclui overflow da chave*/
	t_no *ramo[MAX + 1];
};

void intervalo(t_no *arv, int lim_inf, int lim_sup);
void insere(t_no *raiz, t_no *no_atual, int chave_nova);
t_no *criaNo(void);
t_no *busca(t_no *raiz, int chave);

int main(void)
{
	t_no *arvore = criaNo();
	busca(arvore, 1);
	return 0;
}

t_no *criaNo(void)
{
	t_no *novoNo = (t_no *)malloc(sizeof(t_no));
	if (novoNo == NULL)
	{
		printf("Erro na alocação de memória\n");
		exit(1);
	}

	novoNo->ndesc = 0;
	for (int i = 0; i < MAX + 1; i++)
		novoNo->ramo[i] = NULL;

	return novoNo;
}

t_no *busca(t_no *raiz, int chave)
{
	if (raiz == NULL)
		return NULL;

	for (int i = 0; i < MAX; i++)
		if (raiz->chave[i] == chave)
			return raiz;

	int j = 0;
	if (chave < raiz->chave[j])
		busca(raiz->ramo[j], chave);
	for (; j < MAX - 1; j++)
	{
		if (raiz->chave[j] < chave && chave < raiz->chave[j + 1])
			return busca(raiz->ramo[j], chave);
	}
	if (raiz->chave[j] < chave)
		return busca(raiz->ramo[j], chave);

	return NULL;
}

void insere(t_no *raiz, t_no *no_atual, int chave_nova)
{
	if (raiz->ndesc < MAX)
	{
		raiz->chave[raiz->ndesc] = chave_nova;
		raiz->ndesc++;
		return;
	}

	t_no *no_novo = (t_no *)malloc(sizeof(t_no));
	no_novo->ndesc = 0;
}
