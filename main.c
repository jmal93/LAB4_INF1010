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

int main(void) {
	return 0;
}

