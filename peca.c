#include <time.h>
#include <stdlib.h>
#include "bloco.h"
#include "peca.h"

///Função interna que faz a atualização das coordenadas internas dos blocos das peças baseando-se em seu tipo. Não deve ser utilizada externamente, então não foi declarada no peca.h.
void move_blocos_peca(Peca* peca, int x, int y)
{
	int i;
	for(i=0;i<4;i++)
	{
		peca->bloco[i].x += x;
		peca->bloco[i].y += y;
	}
}

int peca_touching(Peca* p, Tela* t)
{
	int result = 0, i;
	for(i = 0; i<4; ++i)
		if(t->bloco[p->x][p->y + 1].tipo == VISIVEL)
			result++;
	return result;
}

Peca nova_peca (Tela* tela, int x, int y)
{
	Peca peca;
	int i;

	peca.x = x;
	peca.y = y;

	for(i=0;i<4;i++) 
		peca.bloco[i] = novo_bloco(0, 0, INVISIVEL);

	peca.tipo = rand() % TOT_PECA_TIPOS;

	switch(peca.tipo)
	{
		case QUADRADO:
			peca.bloco[0].x = x+1;
			peca.bloco[1].x = x+2;
			peca.bloco[2].x = x+1;
			peca.bloco[3].x = x+2;

			peca.bloco[0].y = y+1;
			peca.bloco[1].y = y+1;
			peca.bloco[2].y = y+2;
			peca.bloco[3].y = y+2;
		break;
	}
	
	return peca;
}

void peca_move_x (Peca* peca, int x)
{
	peca->x += x;
	move_blocos_peca(peca, x, 0);
}

void peca_move_y (Peca* peca, int y)
{
	peca->y += y;
	move_blocos_peca(peca, 0, y);
}

void mostra_peca(Peca* p)
{
	int i;
	for(i=0; i<4; ++i)
		mostra_bloco(&(p->bloco[i]));
}

void prende_peca(Peca* p, Tela* t)
{
	int i;
	while(!peca_touching(p, t))
		peca_move_y(p, p->y+1);
	for(i=0;i<4;++i)
		t->bloco[p->x][p->y].tipo = VISIVEL;
}
